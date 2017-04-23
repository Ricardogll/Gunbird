#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleInput.h"
#include "ModuleCharacterSelection.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "SDL/include/SDL_render.h"

#include "ModuleBackgroundCastle.h"

ModuleUI::ModuleUI()
{
	start.PushBack({ 92, 14, 68, 15 });
	start.PushBack({ 12, 12, 68, 15 });
	start.PushBack({ 0, 0, 0, 0 });
	start.PushBack({ 0, 0, 0, 0 });
	start.speed = 0.08f;

	insert_coins.PushBack({ 86, 59, 77, 13 });
	insert_coins.PushBack({ 86, 59, 77, 13 });
	insert_coins.PushBack({ 0, 0, 0, 0 });
	insert_coins.PushBack({ 0, 0, 0, 0 });
	insert_coins.speed = 0.08f;


	//CONTINUE 
	gameover_continue.x = 86;
	gameover_continue.y = 40;
	gameover_continue.w = 71;
	gameover_continue.h = 12;

	gameover_icon.x = 124;
	gameover_icon.y = 235;
	gameover_icon.w = 124;
	gameover_icon.h = 16;


	//ICONS PLAYERS
	iconP1.x = 12;
	iconP1.y = 38;
	iconP1.w = 15;
	iconP1.h = 12;

	iconP2.x = 33;
	iconP2.y = 38;
	iconP2.w = 16;
	iconP2.h = 12; 

	//BOMB
	bombPlayer.x = 3;
	bombPlayer.y = 239;
	bombPlayer.w = 12;
	bombPlayer.h = 15;

	credit.x = 167;
	credit.y = 20;
	credit.w = 36;
	credit.h = 8;

	select.x = 86;
	select.y = 76;
	select.w = 35;
	select.h = 18;

	time_icon.x = 212;
	time_icon.y = 20;
	time_icon.w = 29;
	time_icon.h = 8;


	//PORTRAITS
	portraits[0].x = 73; //YUAN NANG
	portraits[0].y = 98;
	portraits[0].w = 48;
	portraits[0].h = 48;

	portraits[1].x = 4; //MARION
	portraits[1].y = 54;
	portraits[1].w = 48;
	portraits[1].h = 48;

	portraits[2].x = 73; //ASH
	portraits[2].y = 149;
	portraits[2].w = 48;
	portraits[2].h = 48;

	portraits[3].x = 4; //TETSU
	portraits[3].y = 156;
	portraits[3].w = 48;
	portraits[3].h = 48;

	portraits[4].x = 4; //VALNUS
	portraits[4].y = 105;
	portraits[4].w = 48;
	portraits[4].h = 48;

	//LIVES
	live[0].x = 21; //YUAN NANG
	live[0].y = 240;
	live[0].w = 15;
	live[0].h = 12;

	live[1].x = 37; //MARION
	live[1].y = 238;
	live[1].w = 15;
	live[1].h = 13;

	live[2].x = 53; //ASH
	live[2].y = 239;
	live[2].w = 11;
	live[2].h = 13;

	live[3].x = 85; //TETSU
	live[3].y = 242;
	live[3].w = 15;
	live[3].h = 9;

	live[4].x = 67; //VALNUS
	live[4].y = 240;
	live[4].w = 15;
	live[4].h = 12;

	credit_number1.PushBack({ 181, 37, 8, 11 });
	credit_number2.PushBack({ 183, 57, 8, 11 });
	credit_number3.PushBack({ 183, 78, 8, 11 });
	credit_number4.PushBack({ 183, 98, 8, 11 });
	credit_number5.PushBack({ 183, 118, 8, 11 });
	credit_number6.PushBack({ 183, 138, 8, 11 });
	credit_number7.PushBack({ 182, 159, 8, 11 });
	credit_number8.PushBack({ 183, 179, 8, 11 });
	credit_number9.PushBack({ 183, 200, 8, 11 });

	black_screen = { 0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE };
}

ModuleUI::~ModuleUI()
{}

// Load assets
bool ModuleUI::Start()
{
	bool ret = true;

	activatePlayer1_ui = true;

	if (App->player->characters[1] == nullptr)
		activatePlayer2_ui = false;

	assignCharacter = false;
	activateGameOver_ui == false;
	selection_character = 0;
	characterP2 = 0;
	
	LOG("Loading screen UI");
	graphics = App->textures->Load("assets/UI/interface.png");
	font_score = App->fonts->Load("assets/fonts/score.png", "0123456789", 1);

	if (graphics == nullptr) {
		LOG("Cannot load the texture");
		ret = false;
	}

	return ret;
}

bool ModuleUI::CleanUp()
{
	bool ret = true;

	activateGameOver_ui = false;

	LOG("Unloading screen UI");
	App->textures->Unload(graphics);
	App->fonts->UnLoad(font_score);

	return false;
}

// Update: draw background
update_status ModuleUI::Update()
{
	titlecredit_x = 0;

	if (activatePlayer2_ui == false && activateGameOver_ui == false) {
		if (characterselection_ui == false && titlescreen_ui == false && App->player->coins != 0) {
			//Animation START
			Animation* current_animation = &start;
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, 120, abs(App->render->camera.y / SCREEN_SIZE) + 5, &r);
		}
		if (characterselection_ui == true && App->player->coins != 0 && App->player->activatePlayer2 == false) {
			//Animation START
			Animation* current_animation = &start;
			SDL_Rect r = current_animation->GetCurrentFrame();
			App->render->Blit(graphics, 120, abs(App->render->camera.y / SCREEN_SIZE) + 5, &r);
		}
		if (titlescreen_ui == true) {
			Animation* current_animation = &start;
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
				Animation* current_animation2 = &insert_coins;
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
	if (activatePlayer1_ui == true) {
		if (App->player->characters[0] != nullptr) {
			(App->render->Blit(graphics, 5, abs(App->render->camera.y / SCREEN_SIZE) + 6, &iconP1, 1.0f));

			scoreCharacter(0);
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
	}
	
	//Player 2 icons 
	if (activatePlayer2_ui == true) {
		if (selectPlayer2_ui == true) {
			App->render->Blit(graphics, 122, abs(App->render->camera.y / SCREEN_SIZE) + 11, &select, 1.0f);
			choosePlayer2();
		}

		if (selectPlayer2_ui == false && printPlayer2 == true) {
			if (time > 1) {
				(App->render->Blit(graphics, 112, abs(App->render->camera.y / SCREEN_SIZE) + 6, &iconP2, 1.0f));
		
				scoreCharacter(1);
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
	}

	if (App->player->characters[0] != nullptr) {
		if (App->player->characters[0]->live == -1)
			activateGameOver_ui = true;
	}
	if (App->player->characters[1] != nullptr) {
		if (App->player->characters[1]->live == -1)
			activateGameOver_ui = true;
	}

	//GAME OVER
	if (activateGameOver_ui == true) {
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(130.0f));
		SDL_RenderFillRect(App->render->renderer, &black_screen);

		App->render->activateScroll = false;

		activatePlayer1_ui = false;
		activatePlayer2_ui = false;

		App->render->Blit(graphics, 50, abs(App->render->camera.y / SCREEN_SIZE) + 104, &gameover_icon, 1.0f);
		App->render->Blit(graphics, 50, abs(App->render->camera.y / SCREEN_SIZE) + 140, &gameover_continue, 1.0f);

		Animation* current_animation4 = &insert_coins;
		SDL_Rect r4 = current_animation4->GetCurrentFrame();
		App->render->Blit(graphics, 118, abs(App->render->camera.y / SCREEN_SIZE) + 6, &r4, 1.0f); 
		App->render->Blit(graphics, 6, abs(App->render->camera.y / SCREEN_SIZE) + 6, &r4, 1.0f);

		if (App->player->characters[0]->live == -1) {
			if (App->player->characters[0]->position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
				App->player->characters[0]->position.y = ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE; //ARREGLAR ESTO
			if (App->player->characters[1] != nullptr) {
				App->player->characters[1]->playerDead = true;
				if (App->player->characters[1]->position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
					App->player->characters[1]->position.y = ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE; //ARREGLAR ESTO
			}
		}

		if (App->player->characters[1] != nullptr) {
			if (App->player->characters[1]->live == -1) {
				if (App->player->characters[1]->position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
					App->player->characters[1]->position.y = ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE; //ARREGLAR ESTO
				App->player->characters[0]->playerDead = true;
				if (App->player->characters[0]->position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
					App->player->characters[0]->position.y = ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE; //ARREGLAR ESTO
				
			}
		}

		if (App->player->characters[0]->live == -1) {
			if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN && App->player->coins > 0) {
				activatePlayer1_ui = true;
				App->player->coins--;
				if (App->player->characters[1] != nullptr)
					activatePlayer2_ui = true;

				App->player->characters[0]->live = 2;

				if (App->player->characters[1] != nullptr)
					App->player->characters[1]->live = 2;

				App->render->activateScroll = true;

				//App->player->characters[0]->position.x = App->render->camera.x; 
				//App->player->characters[0]->position.y = abs(App->render->camera.y / SCREEN_SIZE) + 240;

				activateGameOver_ui = false;
			}
		}

		if (App->player->characters[1] != nullptr) {
			if (App->player->characters[1]->live == -1) {
				if ((App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN || App->input->keyboard[SDL_SCANCODE_BACKSPACE] == KEY_STATE::KEY_DOWN) && App->player->coins > 0) {
					activatePlayer1_ui = true;
					App->player->coins--;
					if (App->player->characters[1] != nullptr)
						activatePlayer2_ui = true;

					App->player->characters[0]->live = 2;

					if (App->player->characters[1] != nullptr)
						App->player->characters[1]->live = 2;

					App->render->activateScroll = true;

					activateGameOver_ui = false;
				}
			}
		}

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
	}
	
	return UPDATE_CONTINUE;
}

void ModuleUI::choosePlayer2() 
{
	if (App->player->characters[0]->type == YUAN_NANG)
	{
		App->render->Blit(graphics, 164, abs(App->render->camera.y / SCREEN_SIZE), &portraits[order_yuan_nang[selection_character] - 1], 1.0f);
		App->render->Blit(graphics, 133, abs(App->render->camera.y / SCREEN_SIZE) + 32, &live[order_yuan_nang[selection_character] - 1], 1.0f);
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
			if (selection_character < 4)
				selection_character += 1;
			if (selection_character == 4)
				selection_character = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
			if (selection_character > -1)
				selection_character -= 1;
			if (selection_character == -1)
				selection_character = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			characterP2 = order_yuan_nang[selection_character];
			selectPlayer2_ui = false;
			assignCharacter = true;
		}
	}

	if (App->player->characters[0]->type == MARION)
	{
		App->render->Blit(graphics, 164, abs(App->render->camera.y / SCREEN_SIZE), &portraits[order_marion[selection_character] - 1], 1.0f);
		App->render->Blit(graphics, 133, abs(App->render->camera.y / SCREEN_SIZE) + 32, &live[order_marion[selection_character] - 1], 1.0f);
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
			if (selection_character < 4)
				selection_character += 1;
			if (selection_character == 4)
				selection_character = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
			if (selection_character > -1)
				selection_character -= 1;
			if (selection_character == -1)
				selection_character = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			characterP2 = order_marion[selection_character];
			selectPlayer2_ui = false;
			assignCharacter = true;
		}
	}

	if (App->player->characters[0]->type == ASH)
	{
		App->render->Blit(graphics, 164, abs(App->render->camera.y / SCREEN_SIZE), &portraits[order_ash[selection_character] - 1], 1.0f);
		App->render->Blit(graphics, 133, abs(App->render->camera.y / SCREEN_SIZE) + 32, &live[order_ash[selection_character] - 1], 1.0f);
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
			if (selection_character < 4)
				selection_character += 1;
			if (selection_character == 4)
				selection_character = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
			if (selection_character > -1)
				selection_character -= 1;
			if (selection_character == -1)
				selection_character = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			characterP2 = order_ash[selection_character];
			selectPlayer2_ui = false;
			assignCharacter = true;
		}
	}

	if (App->player->characters[0]->type == TETSU)
	{
		App->render->Blit(graphics, 164, abs(App->render->camera.y / SCREEN_SIZE), &portraits[order_tetsu[selection_character] - 1], 1.0f);
		App->render->Blit(graphics, 133, abs(App->render->camera.y / SCREEN_SIZE) + 32, &live[order_tetsu[selection_character] - 1], 1.0f);
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
			if (selection_character < 4)
				selection_character += 1;
			if (selection_character == 4)
				selection_character = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
			if (selection_character > -1)
				selection_character -= 1;
			if (selection_character == -1)
				selection_character = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			characterP2 = order_tetsu[selection_character];
			selectPlayer2_ui = false;
			assignCharacter = true;
		}
	}

	if (App->player->characters[0]->type == VALNUS)
	{
		App->render->Blit(graphics, 164, abs(App->render->camera.y / SCREEN_SIZE), &portraits[order_valnus[selection_character] - 1], 1.0f);
		App->render->Blit(graphics, 133, abs(App->render->camera.y / SCREEN_SIZE) + 32, &live[order_valnus[selection_character] - 1], 1.0f);
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN) {
			if (selection_character < 4)
				selection_character += 1;
			if (selection_character == 4)
				selection_character = 0;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN) {
			if (selection_character > -1)
				selection_character -= 1;
			if (selection_character == -1)
				selection_character = 3;
		}
		if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN) {
			characterP2 = order_valnus[selection_character];
			selectPlayer2_ui = false;
			assignCharacter = true;
		}
	}
}

void ModuleUI::liveCharacter(uint player) 
{
	cont = 0;
	if (player == 1) {
		cont = 107;
	}

	if (App->player->characters[player]->type == YUAN_NANG) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[0], 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[0], 1.0f));
		}
	}

	if (App->player->characters[player]->type == MARION) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[1], 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[1], 1.0f));
		}
	}

	if (App->player->characters[player]->type == ASH) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[2], 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 20 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[2], 1.0f));
		}
	}

	if (App->player->characters[player]->type == TETSU) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[3], 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 22 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[3], 1.0f));
		}
	}

	if (App->player->characters[player]->type == VALNUS) {
		if (App->player->characters[player]->live >= 1) {
			(App->render->Blit(graphics, 5 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[4], 1.0f));
		}

		if (App->player->characters[player]->live >= 2) {
			(App->render->Blit(graphics, 22 + cont, abs(App->render->camera.y / SCREEN_SIZE) + 21, &live[4], 1.0f));
		}
	}
}

void ModuleUI::scoreCharacter(uint player)
{
	if (player == 0)
	{
		char str[10];
		sprintf_s(str, "%i", App->player->characters[0]->score);
		if (App->player->characters[0]->score == 0) 
			App->fonts->BlitText(68, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 10 && App->player->characters[0]->score >= 0)
			App->fonts->BlitText(76, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 100 && App->player->characters[0]->score >= 10)
			App->fonts->BlitText(68, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 1000 && App->player->characters[0]->score >= 100)
			App->fonts->BlitText(60, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 10000 && App->player->characters[0]->score >= 1000)
			App->fonts->BlitText(52, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 100000 && App->player->characters[0]->score >= 10000)
			App->fonts->BlitText(44, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[0]->score < 1000000 && App->player->characters[0]->score >= 100000)
			App->fonts->BlitText(36, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
	}

	if (player == 1)
	{
		char str[10];
		sprintf_s(str, "%i", App->player->characters[1]->score);
		if (App->player->characters[1]->score == 0)
			App->fonts->BlitText(180, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 10 && App->player->characters[1]->score >= 0)
			App->fonts->BlitText(188, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 100 && App->player->characters[1]->score >= 10)
			App->fonts->BlitText(180, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 1000 && App->player->characters[1]->score >= 100)
			App->fonts->BlitText(172, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 10000 && App->player->characters[1]->score >= 1000)
			App->fonts->BlitText(164, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 100000 && App->player->characters[1]->score >= 10000)
			App->fonts->BlitText(156, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
		if (App->player->characters[1]->score < 1000000 && App->player->characters[1]->score >= 100000)
			App->fonts->BlitText(148, abs(App->render->camera.y / SCREEN_SIZE) + 6, font_score, str);
	}
}