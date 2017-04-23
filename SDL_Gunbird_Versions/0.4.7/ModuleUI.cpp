#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleCharacterSelection.h"

ModuleUI::ModuleUI()
{
	start.PushBack({ 92, 14, 68, 15 });
	start.PushBack({ 12, 12, 68, 15 });
	start.PushBack({ 0, 0, 0, 0 });
	start.PushBack({ 0, 0, 0, 0 });
	start.speed = 0.15f;

	start_selection.PushBack({ 92, 14, 68, 15 });
	start_selection.PushBack({ 12, 12, 68, 15 });
	start_selection.PushBack({ 0, 0, 0, 0 });
	start_selection.PushBack({ 0, 0, 0, 0 });
	start_selection.speed = 0.08f;

	insert_coins.PushBack({ 86, 59, 77, 13 });
	insert_coins.PushBack({ 86, 59, 77, 13 });
	insert_coins.PushBack({ 0, 0, 0, 0 });
	insert_coins.PushBack({ 0, 0, 0, 0 });
	insert_coins.speed = 0.15f;

	insert_coins_selection.PushBack({ 86, 59, 77, 13 });
	insert_coins_selection.PushBack({ 86, 59, 77, 13 });
	insert_coins_selection.PushBack({ 0, 0, 0, 0 });
	insert_coins_selection.PushBack({ 0, 0, 0, 0 });
	insert_coins_selection.speed = 0.08f;

	liveYuanNang.x = 21;
	liveYuanNang.y = 240;
	liveYuanNang.w = 15;
	liveYuanNang.h = 12;

	liveMarion.x = 37;
	liveMarion.y = 238;
	liveMarion.w = 15;
	liveMarion.h = 13;

	liveAsh.x = 53;
	liveAsh.y = 239;
	liveAsh.w = 11;
	liveAsh.h = 13;

	liveValnus.x = 67;
	liveValnus.y = 240;
	liveValnus.w = 15;
	liveValnus.h = 12;

	liveTetsu.x = 85;
	liveTetsu.y = 242;
	liveTetsu.w = 15;
	liveTetsu.h = 9;

	iconP1.x = 12;
	iconP1.y = 38;
	iconP1.w = 15;
	iconP1.h = 12;

	iconP2.x = 33;
	iconP2.y = 38;
	iconP2.w = 16;
	iconP2.h = 12; 

	bombPlayer.x = 3;
	bombPlayer.y = 239;
	bombPlayer.w = 12;
	bombPlayer.h = 15;

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

	if (App->player->characters[1] == nullptr)
		activatePlayer2_ui = false;

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
	titlecredit_x = 0;

	if (activatePlayer2_ui == false) {
		if (characterselection_ui == false && titlescreen_ui == false && App->player->coins != 0) {
			//Animation START
			Animation* current_animation = &start;
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, 120, abs(App->render->camera.y / SCREEN_SIZE) + 5, &r);
		}
		if (characterselection_ui == true && App->player->coins != 0 && App->player->activatePlayer2 == false) {
			//Animation START
			Animation* current_animation = &start_selection;
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, 120, abs(App->render->camera.y / SCREEN_SIZE) + 5, &r);
		}
		if (titlescreen_ui == true) {
			Animation* current_animation = &start_selection;
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, 75, abs(App->render->camera.y / SCREEN_SIZE) + 224, &r);
		}
		if (titlescreen_ui == false)
			titlecredit_x = 74;

		//Credit
		if (App->player->coins != 0) {
			App->render->Blit(graphics, 81 + titlecredit_x, abs(App->render->camera.y / SCREEN_SIZE) + 306, &credit, 1.0f);
			SDL_Rect r1 = current_animation_credit->GetCurrentFrame();
			App->render->Blit(graphics, 121 + titlecredit_x, abs(App->render->camera.y / SCREEN_SIZE) + 304, &r1);
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
		if (App->player->coins == 0 && App->player->activatePlayer2 == false) {
			if (characterselection_ui == true) {
				Animation* current_animation2 = &insert_coins_selection;
				SDL_Rect r2 = current_animation2->GetCurrentFrame();
				App->render->Blit(graphics, 118, abs(App->render->camera.y / SCREEN_SIZE) + 6, &r2, 1.0f);
			}
			else {
				Animation* current_animation3 = &insert_coins;
				SDL_Rect r3 = current_animation3->GetCurrentFrame();
				App->render->Blit(graphics, 118, abs(App->render->camera.y / SCREEN_SIZE) + 6, &r3, 1.0f);
			}
		}
	}

	//Player 1 icons
	if (App->player->characters[0] != nullptr) {
		(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 5, &iconP1, 1.0f));
		liveCharacter(0);
		if (App->player->characters[0]->bombs >= 1) {
			(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		}

		if (App->player->characters[0]->bombs >= 2) {
			(App->render->Blit(graphics, 20, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		}

		if (App->player->characters[0]->bombs >= 3) {
			(App->render->Blit(graphics, 35, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
		} //NO SE CUAL ES EL NUMERO MAXIMO DE BOMBS QUE UN PLAYER PUEDE TENER XD
	}
	//Player 2 icons 
	if (activatePlayer2_ui == true) {
		if (time > 1) { 
			(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 5, &iconP2, 1.0f));
			liveCharacter(1); 
			if (App->player->characters[1]->bombs >= 1) {
				(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
			}

			if (App->player->characters[1]->bombs >= 2) {
				(App->render->Blit(graphics, 127, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
			}
			if (App->player->characters[1]->bombs >= 3) {
				(App->render->Blit(graphics, 142, abs(App->render->camera.y / SCREEN_SIZE) + 300, &bombPlayer, 1.0f));
			}
		}
		if (time < 20)
			time++;
	}
	return UPDATE_CONTINUE;
}

void ModuleUI::liveCharacter(uint player) 
{
	cont = 0;
	if (player == 1) {
		cont = 107;
	}

	if (App->player->characters[player]->type == YUAN_NANG) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveYuanNang, 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveYuanNang, 1.0f));
		}
	}

	if (App->player->characters[player]->type == MARION) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveMarion, 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveMarion, 1.0f));
		}
	}

	if (App->player->characters[player]->type == ASH) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveAsh, 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveAsh, 1.0f));
		}
	}

	if (App->player->characters[player]->type == TETSU) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveTetsu, 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 22 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveTetsu, 1.0f));
		}
	}

	if (App->player->characters[player]->type == VALNUS) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveValnus, 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 22 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 20, &liveValnus, 1.0f));
		}
	}

}