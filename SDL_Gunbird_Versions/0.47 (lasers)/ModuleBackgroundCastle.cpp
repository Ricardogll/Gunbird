#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleBackgroundCastle.h"
#include "ModuleBackgroundMine.h"
#include "ModuleCharacterSelection.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"
#include "SDL\include\SDL_timer.h"

#include "ModuleScoreScreen.h"

ModuleBackgroundCastle::ModuleBackgroundCastle()
{
	background.x = 0;
	background.y = 0;
	background.w = 228;
	background.h = 1685;

	//DOOR
	door.PushBack({ 293,33,121,35 });
	door.PushBack({ 418,33,116,46 });
	door.PushBack({ 543,33,119,53 });
	door.PushBack({ 293,97,115,72 });
	door.PushBack({ 418,97,112,83 });
	door.PushBack({ 286,222,110,106 });
	door.PushBack({ 286,342,121,100 });
	door.PushBack({ 411,342,110,103 });
	door.PushBack({ 536,342,110,106 });
	door2.PushBack({ 727,297,110,162 });
	door.loop = false;
	door.speed = 0.4f;

	soldier.PushBack({ 52,39,15,24 });
	soldier.PushBack({ 72,40,15,24 });
	soldier.PushBack({ 91,39,15,24 });
	soldier.PushBack({ 111,40,15,24 });
	soldier.speed = 0.15f;

	soldier2.PushBack({ 52,67,12,25 });
	soldier2.PushBack({ 85,68,12,25 });
	soldier2.PushBack({ 68,67,12,25 });
	soldier2.PushBack({ 101,68,25,25 });
	soldier2.speed = 0.05f;

	building.PushBack({ 32,182,62,52 });


	floor.PushBack({ 749,185,57,13 });
	floor.loop = false;

}

ModuleBackgroundCastle::~ModuleBackgroundCastle()
{}

// Load assets
bool ModuleBackgroundCastle::Start()
{
	App->render->camera.y = (-1685 + SCREEN_HEIGHT) * SCREEN_SIZE;
	App->render->camera.x = 0 * SCREEN_SIZE;
	
	LOG("Loading background castle assets");
	bool ret = true;
	gate = true;
	scroll = 0;

	graphics = App->textures->Load("assets/backgrounds/Background castle.png");
	animation_door = App->textures->Load("assets/particles/animations.png");
	animation_soldier= App->textures->Load("assets/particles/animations.png");
	animation_building= App->textures->Load("assets/particles/animations.png");

	App->ui->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

	////LOAD PLAYER 1 OF CHARACTER SELECTION
	if (App->characterselection->selection == YUAN_NANG)
	App->player->AddCharacter(CHARACTER_TYPES::YUAN_NANG, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

	if (App->characterselection->selection == MARION)
		App->player->AddCharacter(CHARACTER_TYPES::MARION, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

	if (App->characterselection->selection == ASH)
		App->player->AddCharacter(CHARACTER_TYPES::ASH, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

	if (App->characterselection->selection == VALNUS)
		App->player->AddCharacter(CHARACTER_TYPES::VALNUS, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

	if (App->characterselection->selection == TETSU)
		App->player->AddCharacter(CHARACTER_TYPES::TETSU, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

	//LOAD PLAYER 2 OF CHARACTER SELECTION
	if (App->characterselection->loadP2 == true) {
		if (App->characterselection->selection_P2 == YUAN_NANG)
			App->player->AddCharacter(CHARACTER_TYPES::YUAN_NANG, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		if (App->characterselection->selection_P2 == MARION)
			App->player->AddCharacter(CHARACTER_TYPES::MARION, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		if (App->characterselection->selection_P2 == ASH)
			App->player->AddCharacter(CHARACTER_TYPES::ASH, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		if (App->characterselection->selection_P2 == VALNUS)
			App->player->AddCharacter(CHARACTER_TYPES::VALNUS, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		if (App->characterselection->selection_P2 == TETSU)
			App->player->AddCharacter(CHARACTER_TYPES::TETSU, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		App->ui->activatePlayer2_ui = true;
	}

	//ENEMIES
	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, BALLOON_CASTLE, 95, 1255);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, NO_MOVE, 162, 1241);

	//BUILDING
	App->enemies->AddEnemy(ENEMY_TYPES::BUILDING, BUILDING_CASTLE, 147, 1059);
	App->enemies->AddEnemy(ENEMY_TYPES::BUILDING2, BUILDING_CASTLE, 78, 799);


	//MISILE
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, 90, 1230);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, 60, 1200);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, 30, 1170);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, 10, 1140);

	//VASE
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 690);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 690);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 475);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 475);

	//TURRET2
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 7, 1185);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 4, 1145);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 7, 1105);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 11, 740);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 17, 770);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 195, 734);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 190, 770);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 26, 430);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 170, 430);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 178, 340);

	//DRONE
	/*if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, BUILDING_CASTLE, 42, 1042);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, BUILDING_CASTLE, 55, 1080);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, BUILDING_CASTLE, 75, 1042);
	}*/

	//App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, NO_MOVE , 12, 1241);

	App->audio->PlayMusic("assets/audio/music/gunbird-002_Title_Castle.ogg");

	return ret;
}

bool ModuleBackgroundCastle::CleanUp()
{
	App->ui->Disable();
	App->enemies->Disable();
	App->collision->Disable();
	App->particles->Disable();

	App->player->Disable();

	LOG("Unloading castle stage");
	App->textures->Unload(graphics);
	App->textures->Unload(animation_door);

	LOG("Destroying SDL audio");
	App->audio->StopMusic();

	return true;
}

// Update: draw background
update_status ModuleBackgroundCastle::Update()
{
	//CREATE NEW PLAYER 2
	if (App->player->activatePlayer2 == true && App->characterselection->loadP2 == false) {
		if (gate == true) {
			App->player->AddCharacter(CHARACTER_TYPES::MARION, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
			App->ui->activatePlayer2_ui = true;
			gate = false;
		}
		App->player->activatePlayer2 = false;
	}

	// Draw everything --------------------------------------
	if (App->render->camera.y == -20 * SCREEN_SIZE) {
		App->render->camera.y = -20 * SCREEN_SIZE;
		for (uint i = 0; i < 2; ++i) {
			if(App->player->characters[1]!=nullptr)
			App->player->characters[i]->movement = true;
			else
				App->player->characters[0]->movement = true;
		}
	}

	else {
		scroll += 0.5;
		if (scroll == 1.5) {
			App->render->camera.y += 1 * SCREEN_SIZE;
			scroll = 0;
		}
	}

	/*for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (App->enemies->enemies[i]->type == BUILDING) {
			App->render->Blit(animation_flag, 177, 1049, &(flag.GetCurrentFrame()));
		}

	}*/

	App->render->Blit(graphics, 0, 0, NULL);

	//BUILDING
	//App->render->Blit(animation_building, 147, 1091, &(building.GetCurrentFrame()));
	//BRIDGE
	if (App->render->camera.y >= -1000 * SCREEN_SIZE) {
		App->render->Blit(animation_door, 87, 966, &(floor.GetCurrentFrame()));
		App->render->Blit(animation_door, 66, 955, &(door.GetCurrentFrame()));

	}
	if (App->render->camera.y >= -970 * SCREEN_SIZE) {
		App->render->Blit(animation_door, 67, 907, &(door2.GetCurrentFrame()));
	}
	//SOLDIER
	if (App->render->camera.y <= -1140 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, 79, abs(App->render->camera.y / SCREEN_SIZE - 150) , &(soldier.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, 107, abs(App->render->camera.y / SCREEN_SIZE - 120), &(soldier.GetCurrentFrame()));
	}
	if (App->render->camera.y >= -1270 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, abs(App->render->camera.x / SCREEN_SIZE-130 ), 1237, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y >= -1270 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, abs(App->render->camera.x / SCREEN_SIZE - 115), 1237, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y >= -1270 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, abs(App->render->camera.x / SCREEN_SIZE - 100), 1237, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1140 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, abs(App->render->camera.y / SCREEN_HEIGHT - 90), 1537, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, abs(App->render->camera.x / SCREEN_SIZE - 75), 1530, &(soldier2.GetCurrentFrame()));
	}

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->scorescreen, 1);
	}

	


	return UPDATE_CONTINUE;
}

