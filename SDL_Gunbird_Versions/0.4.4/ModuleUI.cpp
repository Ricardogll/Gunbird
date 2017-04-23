#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleUI.h"

ModuleUI::ModuleUI()
{
	start.PushBack({ 92, 14, 68, 15 });
	start.PushBack({ 12, 12, 68, 15 });
	start.PushBack({ 0, 0, 0, 0 });
	start.PushBack({ 0, 0, 0, 0 });
	start.speed = 0.15f;

	livePlayer1.x = 21;
	livePlayer1.y = 240;
	livePlayer1.w = 15;
	livePlayer1.h = 12;

	livePlayer2.x = 37;
	livePlayer2.y = 238;
	livePlayer2.w = 15;
	livePlayer2.h = 13;

	bombPlayer.x = 3;
	bombPlayer.y = 239;
	bombPlayer.w = 12;
	bombPlayer.h = 15;

	iconPlayer1.x = 12;
	iconPlayer1.y = 38;
	iconPlayer1.w = 15;
	iconPlayer1.h = 12;

	iconPlayer2.x = 33;
	iconPlayer2.y = 38;
	iconPlayer2.w = 16;
	iconPlayer2.h = 12;

	credit.x = 167;
	credit.y = 20;
	credit.w = 36;
	credit.h = 8;

	credit_number1.PushBack({ 181, 37, 8, 11 });
	credit_number2.PushBack({ 183, 57, 8, 11 });
	credit_number3.PushBack({ 183, 78, 8, 11 });
	credit_number4.PushBack({ 183, 98, 8, 11 });
	credit_number5.PushBack({ 183, 118, 8, 11 });
	credit_number6.PushBack({ 183, 138, 8, 11 });
	credit_number7.PushBack({ 182, 159, 8, 11 });
	credit_number8.PushBack({ 183, 179, 8, 11 });
	credit_number9.PushBack({ 183, 200, 8, 11 });
}

ModuleUI::~ModuleUI()
{}

// Load assets
bool ModuleUI::Start()
{
	bool ret = true;

	LOG("Loading screen UI");
	graphics = App->textures->Load("assets/UI/interface.png");

	if (graphics == nullptr) {
		LOG("Cannot load the texture");
		ret = false;
	}

	return ret;
}

bool ModuleUI::CleanUp()
{
	bool ret = true;

	LOG("Unloading screen UI");
	App->textures->Unload(graphics);

	return false;
}

// Update: draw background
update_status ModuleUI::Update()
{
	if (App->player->activatePlayer2 == false) {
		Animation* current_animation = &start;
		SDL_Rect r = current_animation->GetCurrentFrame();
		App->render->Blit(graphics, 120, abs(App->render->camera.y / SCREEN_SIZE) + 5, &r);

		App->render->Blit(graphics, 150, abs(App->render->camera.y / SCREEN_SIZE) + 305, &credit, 1.0f);
		//SE HA DE MIRAR DONDE PONEMOS LA VARIABLE COINS, AHORA ESTÁ EN PLAYER PORQUE SI
		SDL_Rect r1 = current_animation_credit->GetCurrentFrame();
		App->render->Blit(graphics, 190, abs(App->render->camera.y / SCREEN_SIZE) + 303, &r1);
		switch (App->player->coins) {
		case 1:
			current_animation_credit = &credit_number1;
			break;
		case 2:
			current_animation_credit = &credit_number2;
			break;
		case 3:
			current_animation_credit = &credit_number3;
			break;
		case 4:
			current_animation_credit = &credit_number4;
			break;
		case 5:
			current_animation_credit = &credit_number5;
			break;
		case 6:
			current_animation_credit = &credit_number6;
			break;
		case 7:
			current_animation_credit = &credit_number7;
			break;
		case 8:
			current_animation_credit = &credit_number8;
			break;
		case 9:
			current_animation_credit = &credit_number9;
			break;
		default:
			break;
		}
	}

	//Player 1 icons
	(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 5, &iconPlayer1, 1.0f));

	if (App->player->livePlayer1 >= 0) {
		(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 20, &livePlayer1, 1.0f));
	}

	if (App->player->livePlayer1 >= 1) {
		(App->render->Blit(graphics, 20, abs(App->render->camera.y / SCREEN_SIZE) + 20, &livePlayer1, 1.0f));
	}

	if (App->player->bombPlayer1 >= 1) {
		(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
	}

	if (App->player->bombPlayer1 >= 2) {
		(App->render->Blit(graphics, 20, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
	}

	if (App->player->bombPlayer1 >= 3) {
		(App->render->Blit(graphics, 35, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
	} //NO SE CUAL ES EL NUMERO MAXIMO DE BOMBS QUE UN PLAYER PUEDE TENER XD

	//Player 2 icons
	if (App->player->activatePlayer2 == true) {
		(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 5, &iconPlayer2, 1.0f));

		if (App->player2->livePlayer2 >= 0) {
			(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 20, &livePlayer2, 1.0f));
		}

		if (App->player2->livePlayer2 >= 1) {
			(App->render->Blit(graphics, 127, abs(App->render->camera.y / SCREEN_SIZE) + 20, &livePlayer2, 1.0f));
		}

		if (App->player2->bombPlayer2 >= 1) {
			(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		}

		if (App->player2->bombPlayer2 >= 2) {
			(App->render->Blit(graphics, 127, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		}

		if (App->player2->bombPlayer2 >= 3) {
			(App->render->Blit(graphics, 142, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		}
	}

	return UPDATE_CONTINUE;
}