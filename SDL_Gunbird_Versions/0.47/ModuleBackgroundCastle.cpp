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


ModuleBackgroundCastle::ModuleBackgroundCastle()
{
	background.x = 0;
	background.y = 0;
	background.w = 228;
	background.h = 1685;

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

	graphics = App->textures->Load("assets/backgrounds/Background castle.png");

	App->ui->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();

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

	App->audio->PlayMusic("assets/audio/music/gunbird-002_Title_Castle.ogg");

	return ret;
}

bool ModuleBackgroundCastle::CleanUp()
{
	App->ui->Disable();
	App->enemies->Disable();
	App->collision->Disable();

	LOG("Unloading castle stage");
	App->textures->Unload(graphics);

	LOG("Destroying SDL audio");
	App->audio->StopMusic();

	return true;
}

// Update: draw background
update_status ModuleBackgroundCastle::Update()
{
	if (App->player->activatePlayer2 == true) {
		if (gate == true) {
			LOG("HOLAAAAAA");
			App->player->AddCharacter(CHARACTER_TYPES::MARION, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
			App->ui->activatePlayer2_ui = true;
			gate = false;
		}
		App->player->activatePlayer2 = false;
	}

	//ENEMIES
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, BALLOON_CASTLE, 95, 1255);
	}

	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::TURRET, NO_MOVE, 162, 1241);
	}
	//BUILDING
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::BUILDING, BUILDING_CASTLE, 147, 1059);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::BUILDING2, BUILDING_CASTLE, 78, 799);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLAG, BUILDING_CASTLE, 177, 1049);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::FLAG, BUILDING_CASTLE, 110, 785);
	}
	//MISILE
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, -10, 1130);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, -40, 1100);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, -70, 1070);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, BUILDING_CASTLE, -80, 1040);
	}
	//VASE
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 690);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 690);
	}if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 475);
	}
	if (App->render->camera.y == (-1355 * SCREEN_SIZE)) {
		App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 475);
	}
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
		App->render->camera.y += 1 * SCREEN_SIZE;
	}

	App->render->Blit(graphics, 0, 0, NULL);
	
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->background2, 1);
	}

	SDL_Delay(40);

	return UPDATE_CONTINUE;
}

