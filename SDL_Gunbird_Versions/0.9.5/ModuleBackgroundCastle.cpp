#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleBackgroundCastle.h"
#include "ModuleCharacterSelection.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"
#include "ModuleSaveScore.h"
#include "ModuleEndScene.h"
#include "SDL\include\SDL_timer.h"
#include <math.h>


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
	soldier2.speed = 0.01f;
	soldier2_x = 50;
	soldier2_y = 1237;

	soldier3.PushBack({ 127,69,15,25 });
	soldier3.PushBack({ 146,69,15,25 });
	soldier3.PushBack({ 166,68,15,25 });
	soldier3.PushBack({ 186,68,15,25 });

	soldier3.speed = 0.1f;
	soldier3_x = 23;
	soldier3_y = 340;

	building.PushBack({ 32,182,62,52 });

	floor.PushBack({ 749,185,57,13 });
	floor.loop = false;

	trump.PushBack({ 0,500,224,222 });
	trump.PushBack({ 224,500,224,222 });
	trump.PushBack({ 448,500,224,222 });
	trump.PushBack({ 0,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 224,722,224,222 });
	trump.PushBack({ 448,722,224,222 });
	trump.speed = 0.2f;
	trump.loop = false;
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
	choose_character = true;
	trump_scene = false;
	App->render->activateScroll = true;
	App->input->activateDebug = true;
	boss_dead = false;
	time_scene_trump = 0;
	door.Reset();
	trump.Reset();

	graphics = App->textures->Load("assets/backgrounds/Background castle.png");
	animation_door = App->textures->Load("assets/particles/animations.png");
	animation_soldier= App->textures->Load("assets/particles/animations.png");
	animation_building= App->textures->Load("assets/particles/animations.png");
	graphics_trump = App->textures->Load("assets/UI/characters_text.png");

	selection_yuan_nang_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-020_YungNang_Selection.wav");
	selection_ash_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-023_Ash_Selection.wav");
	selection_tetsu_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-022_Tetsu_Selection.wav");
	selection_valnus_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-021_Valnus_Selection.wav");
	selection_marion_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-019_Marion_Selection.wav");
	selection_kyoko_fx = App->audio->LoadWAV("assets/audio/sound/Kyoko_Selection.wav");
	change_selection_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-050_Change_Character.wav");

	App->ui->Enable();
	App->player->Enable();
	App->collision->Enable();
	App->enemies->Enable();
	App->particles->Enable();

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		App->savescore->saveScore[i] = 0;
		App->savescore->saveCharacter[i] = 0;
	}

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

	if (App->characterselection->selection == KYOKO)
		App->player->AddCharacter(CHARACTER_TYPES::KYOKO, App->render->camera.x + 50, abs(App->render->camera.y / SCREEN_SIZE) + 240, 0);

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

		if (App->characterselection->selection_P2 == KYOKO)
			App->player->AddCharacter(CHARACTER_TYPES::KYOKO, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);

		App->ui->activatePlayer2_ui = true;
	}


	
	//ENEMIES
	App->enemies->AddEnemy(ENEMY_TYPES::BALLOON, BALLOON_CASTLE, 95, 1255);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET, NO_MOVE, 162, 1241);
	App->enemies->AddEnemy(ENEMY_TYPES::BOSS, NO_MOVE, 36, 9);

	//App->enemies->AddEnemy(ENEMY_TYPES::ROBOT, NO_MOVE, 80, 1400);
	//App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, NO_MOVE, 93, 1415);
	//App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, NO_MOVE, 129, 1415);


	//BUILDING
	App->enemies->AddEnemy(ENEMY_TYPES::BUILDING, BUILDING_CASTLE, 147, 1059);
	App->enemies->AddEnemy(ENEMY_TYPES::BUILDING2, BUILDING_CASTLE, 78, 799);
	if (App->enemies->building_destroyed = true) {
		if (App->render->camera.y <= -1140 * SCREEN_SIZE) {

		}
	}

	//MISILE
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_1, 90, 1130);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_1, 60, 1100);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_1, 30, 1070);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_1, 10, 1040);

	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 36 + 228, 539); //636
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 72 + 228, 539);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 108 + 228, 539);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 144 + 228, 539);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 180 + 228, 539);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_2, 216 + 228, 539);


	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 14, 218);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 58, 218);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 152, 218);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 200, 218);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 20, 206);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 64, 206);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 158, 206);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 206, 206);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 78, 230);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE, MISSILE_3, 128, 230);

	//ROBOT

	App->enemies->AddEnemy(ENEMY_TYPES::ROBOT, _ROBOT, 80, 574);
	App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, _CANNON, 93, 540); //589
	App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, _CANNON, 129, 540);
	App->enemies->AddEnemy(ENEMY_TYPES::ROBOT, _ROBOT, 80, 1118);
	App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, _CANNON, 93, 1084);
	App->enemies->AddEnemy(ENEMY_TYPES::RCANNON, _CANNON, 129, 1084);

	/*App->enemies->AddEnemy(MISSILE, MISSILE_3, 550, );
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 540,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 540, );
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 540, );
	App->enemies->AddEnemy(MISSILE, MISSILE_3,197, 540,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3,5, 530,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3,53, 530,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3,49, 530,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 197, 530,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3,75, 520,);
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 520);
	App->enemies->AddEnemy(MISSILE, MISSILE_3, 515 );*/

	//App->enemies->AddEnemy(MISSILE, 75, 550, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 123, 550, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 5, 540, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 53, 540, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 149, 540, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 197, 540, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 5, 530, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 53, 530, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 149, 530, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 197, 530, 3, 2);
	//App->enemies->AddEnemy(MISSILE, 75, 520, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 123, 520, 3, 1);
	//App->enemies->AddEnemy(MISSILE, 99, 515, 3, 2);

	//TURRET2
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_1, -75, 1185);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_1, -50, 1145);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_1, -75, 1105);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_1, -75, 740);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 25, 770);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_2, 270, 740);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 170, 770);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 26, 430);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, NO_MOVE, 170, 430);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_2, 250, 340);
	//App->enemies->AddEnemy(ENEMY_TYPES::TURRET2, TURRET_2, 100, 1480);

	//TURRET3
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, NO_MOVE, 16, 826);
	App->enemies->AddEnemy(ENEMY_TYPES::TURRET3, NO_MOVE, 176, 826);

	//VASE
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 690);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 690);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 10, 475);
	App->enemies->AddEnemy(ENEMY_TYPES::VASE, NO_MOVE, 185, 475);

	//DRONE
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 30, 1042);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 60, 1060);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 90, 1042);

	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 30, 983);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 60, 1001);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 90, 983);

	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 30, 950);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 60, 968);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE1, 90, 950);

	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 30, 900);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 60, 918);
	App->enemies->AddEnemy(ENEMY_TYPES::DRONE, DRONE2, 90, 900);

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

	App->ui->printPlayer2 = false;
	App->ui->selectPlayer2_ui = false;
	App->render->activateScroll = false;
	App->input->activateDebug = false;

	LOG("Unloading castle stage");
	App->textures->Unload(graphics);
	App->textures->Unload(animation_door);
	App->textures->Unload(animation_soldier);
	App->textures->Unload(animation_building);
	App->textures->Unload(graphics_trump);

	LOG("Destroying SDL audio");
	App->audio->StopMusic();
	App->audio->UnloadWAV(selection_yuan_nang_fx);
	App->audio->UnloadWAV(selection_ash_fx);
	App->audio->UnloadWAV(selection_tetsu_fx);
	App->audio->UnloadWAV(selection_valnus_fx);
	App->audio->UnloadWAV(selection_marion_fx);
	App->audio->UnloadWAV(selection_kyoko_fx);
	App->audio->UnloadWAV(change_selection_fx);

	return true;
}

// Update: draw background
update_status ModuleBackgroundCastle::Update()
{
	//CREATE NEW PLAYER 2
	choosePlayer2();

	// Draw everything --------------------------------------
	if (App->render->camera.y == -21 * SCREEN_SIZE) {
		App->audio->StopMusic();
		App->audio->PlayMusic("assets/audio/music/gunbird-010_Boss_A.ogg");
	}

	if (App->render->camera.y == -20 * SCREEN_SIZE) {
		App->render->activateScroll = false;
		App->render->camera.y = -20 * SCREEN_SIZE;
		trump_scene = true;

		for (uint i = 0; i < 2; ++i) { //CHARACTER STOP MOVE
			if(App->player->characters[1] != nullptr)
			App->player->characters[i]->movement = true;
			else
				App->player->characters[0]->movement = true;
		}

		if (boss_dead == true){
			for (uint i = 0; i < 2; ++i) {
				if (App->player->characters[i] != nullptr) {
					App->player->characters[i]->movement = true;
					App->player->characters[i]->desactivateInput = true;
					App->player->characters[i]->desactivateLimit = true;
					App->player->characters[i]->position.y -= 3; 

				}
			}
			App->fade->FadeToBlack(this, App->endscene, 1);
		}
	}

	else {
		if (App->render->scroll == 1.5) 
			App->render->camera.y += 1 * SCREEN_SIZE;
	}

	App->render->Blit(graphics, 0, 0, NULL);

	//BUILDING
	//App->render->Blit(animation_building, 147, 1091, &(building.GetCurrentFrame()));
	//BRIDGE
	if (App->render->camera.y >= -980 * SCREEN_SIZE) {
		App->render->Blit(animation_door, 87, 966, &(floor.GetCurrentFrame()));
		App->render->Blit(animation_door, 66, 955, &(door.GetCurrentFrame()));

	}
	if (App->render->camera.y >= -950 * SCREEN_SIZE) {
		App->render->Blit(animation_door, 67, 907, &(door2.GetCurrentFrame()));
	}
	//SOLDIER
	if (App->render->camera.y <= -1140 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, 79, abs(App->render->camera.y / SCREEN_SIZE - 150), &(soldier.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, 107, abs(App->render->camera.y / SCREEN_SIZE - 120), &(soldier.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, soldier2_x + 220, soldier2_y - 318 + SCREEN_HEIGHT, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, soldier2_x + 240, soldier2_y - 318 + SCREEN_HEIGHT, &(soldier2.GetCurrentFrame()));
		

	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, soldier2_x + 260, soldier2_y - 318 + SCREEN_HEIGHT, &(soldier2.GetCurrentFrame()));
	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, soldier2_x, soldier2_y - 4 + SCREEN_HEIGHT, &(soldier2.GetCurrentFrame()));

	}
	if (App->render->camera.y <= -1170 * SCREEN_SIZE) {
		App->render->Blit(animation_soldier, soldier2_x + 40, soldier2_y - 20 + SCREEN_HEIGHT, &(soldier2.GetCurrentFrame()));
	}

		App->render->Blit(animation_soldier, soldier3_x, soldier3_y + SCREEN_HEIGHT, &(soldier3.GetCurrentFrame()));
		/*soldier3_x += -0.5;
		soldier3_y += -0.5;*/

	
	if (background.y < SCREEN_HEIGHT) {
		soldier2_x += -0.5;
	}
	/*if ( App->render->camera.y <= -360 * SCREEN_SIZE) {
		soldier3_x += -0.5;
		soldier3_y += -0.5;
		
	}*/
	if (App->render->camera.y >= -644 * SCREEN_SIZE) {
		soldier3_x += -0.5;
		soldier3_y += -0.5;

	}

	if (App->player->characters[0] != nullptr) {
		for (uint i = 0; i < MAX_ENEMIES; ++i) {
			if (App->enemies->enemies[i] != nullptr) {
				App->enemies->enemies[i]->id = i;
				var_x[i] = ((App->player->characters[0]->position.x) - App->enemies->enemies[i]->position.x);
				var_y[i] = ((App->player->characters[0]->position.y) - App->enemies->enemies[i]->position.y);
				vec_u[i] = sqrt((var_x[i] * var_x[i]) + (var_y[i] * var_y[i]));
				res_x[i] = 3* (var_x[i] / vec_u[i]);
				res_y[i] = 3* (var_y[i] / vec_u[i]);
			}
		}
	}

	if (App->render->camera.y >= -25 * SCREEN_SIZE) {
		for (uint i = 0; i < MAX_ENEMIES; ++i) {
			if (App->enemies->enemies[i] != nullptr) {
				if (App->enemies->enemies[i]->type == ENEMY_TYPES::TURRET2) {
					delete App->enemies->enemies[i];
					App->enemies->enemies[i] = nullptr;
				}
				else if (App->enemies->enemies[i]->type == ENEMY_TYPES::RCANNON) {
					delete App->enemies->enemies[i];
					App->enemies->enemies[i] = nullptr;
				}
				else if (App->enemies->enemies[i]->type == ENEMY_TYPES::ROBOT) {
					delete App->enemies->enemies[i];
					App->enemies->enemies[i] = nullptr;
				}
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN)
		App->render->camera.y = (-800 + SCREEN_HEIGHT) * SCREEN_SIZE; /////////////////////////////

	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN)
		App->render->activateScroll = false; //////////////

	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN)
		App->render->activateScroll = true; //////////////

	if (App->input->keyboard[SDL_SCANCODE_Y] == KEY_STATE::KEY_DOWN)
		boss_dead = true; //////////////

	return UPDATE_CONTINUE;
}

void ModuleBackgroundCastle::choosePlayer2()
{
	if (App->player->activatePlayer2 == true && App->characterselection->loadP2 == false) {
		if (gate == true) {
			App->ui->activatePlayer2_ui = true;
			if (choose_character == true) {
				App->ui->selectPlayer2_ui = true;
				choose_character = false;
			}
			if (App->render->scroll == 0.5) {
				if (App->ui->assignCharacter == true) {
					if (App->ui->characterP2 == 1) {
						App->player->AddCharacter(CHARACTER_TYPES::YUAN_NANG, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_yuan_nang_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
					if (App->ui->characterP2 == 2) {
						App->player->AddCharacter(CHARACTER_TYPES::MARION, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_marion_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
					if (App->ui->characterP2 == 3) {
						App->player->AddCharacter(CHARACTER_TYPES::ASH, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_ash_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
					if (App->ui->characterP2 == 4) {
						App->player->AddCharacter(CHARACTER_TYPES::TETSU, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_tetsu_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
					if (App->ui->characterP2 == 5) {
						App->player->AddCharacter(CHARACTER_TYPES::VALNUS, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_valnus_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
					if (App->ui->characterP2 == 6) {
						App->player->AddCharacter(CHARACTER_TYPES::KYOKO, App->render->camera.x + 150, abs(App->render->camera.y / SCREEN_SIZE) + 240, 1);
						App->audio->PlayWAV(selection_kyoko_fx);
						gate = false;
						App->player->activatePlayer2 = false;
						App->ui->printPlayer2 = true;
					}
				}
			}
		}
	}
}