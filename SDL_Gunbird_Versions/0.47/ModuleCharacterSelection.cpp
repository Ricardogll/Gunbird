#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleUI.h"
#include "ModuleCharacterSelection.h"
#include "ModuleBackgroundCastle.h"
#include "ModuleFadeToBlack.h"


ModuleCharacterSelection::ModuleCharacterSelection()
{
	screen1.x = 16;
	screen1.y = 8;
	screen1.w = 224;
	screen1.h = 144;

	screen2.x = 16;
	screen2.y = 156;
	screen2.w = 224;
	screen2.h = 80; 

	screen_sky.x = 16;
	screen_sky.y = 240;
	screen_sky.w = 432;
	screen_sky.h = 97;

	player1.x = 264;
	player1.y = 12;
	player1.w = 32;
	player1.h = 52;

	player2.x = 321;
	player2.y = 12;
	player2.w = 32;
	player2.h = 52;

	//PORTRAITS
	portrait_yuan_nang.x = 18;
	portrait_yuan_nang.y = 659;
	portrait_yuan_nang.w = 96;
	portrait_yuan_nang .h = 96;

	portrait_marion.x = 18;
	portrait_marion.y = 451;
	portrait_marion.w = 96;
	portrait_marion.h = 96;

	portrait_ash.x = 18;
	portrait_ash.y = 347;
	portrait_ash.w = 96;
	portrait_ash.h = 96;

	portrait_valnus.x = 18;
	portrait_valnus.y = 555;
	portrait_valnus.w = 96;
	portrait_valnus.h = 96;

	portrait_tetsu.x = 18;
	portrait_tetsu.y = 763;
	portrait_tetsu.w = 96;
	portrait_tetsu.h = 96;

	//NAMES
	name_yuan_nang.x = 130;
	name_yuan_nang.y = 673;
	name_yuan_nang.w = 49;
	name_yuan_nang.h = 43;

	name_yuan_nang_2P.x = 264;
	name_yuan_nang_2P.y = 82;
	name_yuan_nang_2P.w = 83;
	name_yuan_nang_2P.h = 21;

	name_marion.x = 131;
	name_marion.y = 466;
	name_marion.w = 54;
	name_marion.h = 21;

	name_ash.x = 130;
	name_ash.y = 364;
	name_ash.w = 27;
	name_ash.h = 21;

	name_valnus.x = 131;
	name_valnus.y = 570;
	name_valnus.w = 53;
	name_valnus.h = 22;

	name_tetsu.x = 130;
	name_tetsu.y = 779;
	name_tetsu.w = 44;
	name_tetsu.h = 20;

	//ANIMATIONS SPRITES
	sprite_yuan_nang.PushBack({ 233, 384 ,135, 124 }); //1
	sprite_yuan_nang.PushBack({ 375, 385, 135, 123 }); //2
	sprite_yuan_nang.PushBack({ 516, 384, 136, 124 }); //3
	sprite_yuan_nang.PushBack({ 663, 384, 136, 125 }); //4
	sprite_yuan_nang.PushBack({ 804, 384, 136, 124 }); //5
	sprite_yuan_nang.PushBack({ 945, 384, 136, 123 }); //6 
	sprite_yuan_nang.PushBack({ 233, 537, 136, 124 }); //7
	sprite_yuan_nang.PushBack({ 371, 537, 135, 124 }); //8
	sprite_yuan_nang.PushBack({ 527, 537, 135, 124 }); //9
	sprite_yuan_nang.PushBack({ 669, 538, 135, 123 }); //10
	sprite_yuan_nang.PushBack({ 804, 537, 136, 124 }); //11
	sprite_yuan_nang.PushBack({ 945, 538, 136, 124 }); //12 
	sprite_yuan_nang.PushBack({ 233, 689, 136, 124 }); //13
	sprite_yuan_nang.PushBack({ 371, 690, 136, 123 }); //14
	sprite_yuan_nang.PushBack({ 527, 689, 136, 124 }); //15
	sprite_yuan_nang.PushBack({ 669, 689 ,135, 124 }); //16  
	sprite_yuan_nang.speed = 0.25f;

	sprite_marion.PushBack({ 602, 153, 128, 103  }); //1
	sprite_marion.PushBack({ 765, 152, 128, 103 }); //2
	sprite_marion.PushBack({ 927, 154, 128, 103 }); //3
	sprite_marion.speed = 0.25f;

	sprite_ash.PushBack({ 509, 18, 96, 101 }); //1
	sprite_ash.PushBack({ 659, 18, 104, 108 }); //2
	sprite_ash.PushBack({ 824, 18, 104, 101 }); //3
	sprite_ash.PushBack({ 981, 18, 104, 101 }); //4
	sprite_ash.speed = 0.25f;

	sprite_valnus.PushBack({ 17, 884, 120, 118 }); //1
	sprite_valnus.PushBack({ 169, 884, 120, 118 }); //2
	sprite_valnus.PushBack({ 321, 884, 120, 118 }); //3
	sprite_valnus.PushBack({ 472, 884, 120, 116 }); //4
	sprite_valnus.speed = 0.25f;

	sprite_tetsu.PushBack({ 1137, 19, 121, 111 }); //1
	sprite_tetsu.PushBack({ 1285, 18, 120, 112 }); //2
	sprite_tetsu.PushBack({ 1432, 18, 120, 112 }); //3
	sprite_tetsu.PushBack({ 1595, 18, 119, 111 }); //4
	sprite_tetsu.PushBack({ 1744, 18, 119, 112 }); //5
	sprite_tetsu.PushBack({ 1894, 18, 117, 111 }); //6
	sprite_tetsu.PushBack({ 1137, 195, 125, 111 }); //7
	sprite_tetsu.PushBack({ 1285, 196, 125, 111 }); //8
	sprite_tetsu.PushBack({ 1432, 194, 125, 112 }); //9
	sprite_tetsu.PushBack({ 1596, 195, 125, 112 }); //10
	sprite_tetsu.PushBack({ 1744, 195, 124, 112 }); //11
	sprite_tetsu.PushBack({ 1891, 195, 122, 112 }); //12
	sprite_tetsu.PushBack({ 1137, 379, 122, 111 }); //13
	sprite_tetsu.PushBack({ 1285, 379, 122, 111 }); //14
	sprite_tetsu.PushBack({ 1432, 379, 128, 111 }); //15
	sprite_tetsu.PushBack({ 1596, 379, 128, 111 }); //16
	sprite_tetsu.PushBack({ 1744, 378, 127, 112 }); //17
	sprite_tetsu.PushBack({ 1891, 377, 128, 112 }); //18
	sprite_tetsu.PushBack({ 1131, 530, 127, 112 }); //19
	sprite_tetsu.PushBack({ 1285, 529, 127, 112 }); //20
	sprite_tetsu.PushBack({ 1432, 530, 125, 111 }); //21
	sprite_tetsu.PushBack({ 1596, 531, 125, 111 }); //22
	sprite_tetsu.PushBack({ 1744, 531, 123, 111 }); //23
	sprite_tetsu.PushBack({ 1897, 531, 122, 111 }); //24
	sprite_tetsu.PushBack({ 1131, 678, 122, 112 }); //25
	sprite_tetsu.PushBack({ 1285, 678, 123, 112 }); //26
	sprite_tetsu.PushBack({ 1432, 678, 122, 112 }); //27
	sprite_tetsu.PushBack({ 1593, 678, 122, 114 }); //28
	sprite_tetsu.PushBack({ 1744, 676, 122, 112 }); //29
	sprite_tetsu.PushBack({ 1897, 676, 122, 112 }); //30
	sprite_tetsu.speed = 0.25f;

	//CHARACTERS
	yuan_nang.PushBack({ 9, 6, 27, 48 }); //1
	yuan_nang.PushBack({ 107, 7, 27, 48 }); //2
	yuan_nang.PushBack({ 61, 96, 27, 48 }); //3
	yuan_nang.PushBack({ 112, 97, 27, 48 }); //4
	yuan_nang.PushBack({ 159, 5, 27, 48 }); //5
	yuan_nang.PushBack({ 53, 6, 27, 48 }); //6
	yuan_nang.PushBack({ 14, 95, 27, 48 }); //7
	yuan_nang.PushBack({ 163, 99, 27, 48 }); //8
	yuan_nang.speed = 0.25f;

	valnus.PushBack({ 218, 443, 31, 30 }); //1
	valnus.PushBack({ 256, 443, 31, 30 }); //2
	valnus.speed = 0.2f;

	marion.PushBack({ 216, 71, 20, 32 }); //1
	marion.PushBack({ 248, 71, 20, 32 }); //2
	marion.PushBack({ 279, 71, 20, 32 }); //3
	marion.PushBack({ 312, 71, 20, 32 }); //4
	marion.speed = 0.25f;

	ash.PushBack({ 217, 223, 19, 32 }); //1
	ash.PushBack({ 246, 223, 19, 32 }); //2
	ash.speed = 0.2f;

	tetsu.PushBack({ 574, 0, 26, 37 }); //1
	tetsu.PushBack({ 614, 0, 26, 37 }); //2
	tetsu.PushBack({ 654, 0, 30, 37 }); //3
	tetsu.PushBack({ 694, 0, 26, 37 }); //4
	tetsu.PushBack({ 732 , 0, 30, 37 }); //5
	tetsu.PushBack({ 574, 47, 26, 37 }); //6
	tetsu.PushBack({ 614, 47, 30, 37 }); //7
	tetsu.PushBack({ 654, 47, 26, 37 }); //8
	tetsu.PushBack({ 694, 47, 26, 37 }); //9
	tetsu.PushBack({ 734, 47, 26, 37 }); //10
	tetsu.PushBack({ 572, 94, 30, 37 }); //11
	tetsu.PushBack({ 614, 94, 30, 37 }); //12
	tetsu.PushBack({ 652, 94, 30, 37 }); //13
	tetsu.PushBack({ 692, 94, 26, 37 }); //14
	tetsu.PushBack({ 732, 94, 30, 37 }); //15
	tetsu.PushBack({ 574, 141, 26, 37 }); //16
	tetsu.PushBack({ 614, 141, 26, 37 }); //17
	tetsu.PushBack({ 654, 141, 26, 37 }); //18
	tetsu.PushBack({ 692, 141, 30, 37 }); //19
	tetsu.PushBack({ 734, 141, 26, 37 }); //20
	tetsu.PushBack({ 572, 188, 30, 37 }); //21
	tetsu.PushBack({ 614, 188, 26, 37 }); //22
	tetsu.PushBack({ 652, 188, 30, 37 }); //23
	tetsu.PushBack({ 694, 188, 26, 37 }); //24
	tetsu.speed = 0.2f;
}   

ModuleCharacterSelection::~ModuleCharacterSelection()
{}

// Load assets
bool ModuleCharacterSelection::Start()
{
	LOG("Loading title screen assets");
	bool ret = true;
	gate_selection = true;
	gate_selection_P2 = true;
	gate = false;
	loadP2 = false;
	scroll = 0;
	pos1p_x = 56;
	selection = 0;
	selection_P2 = 0;
	pos2p_x = 0;

	App->player->Enable();
	App->ui->Enable();
	App->ui->characterselection_ui = true;;

	graphics = App->textures->Load("assets/UI/character_selection.png");
	graphics_character = App->textures->Load("assets/characters/Characters.png");

	App->audio->PlayMusic("assets/audio/music/gunbird-001_Character_Select.ogg");
	
	selection_yuan_nang_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-020_YungNang_Selection.wav");
	selection_ash_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-023_Ash_Selection.wav");
	selection_tetsu_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-022_Tetsu_Selection.wav");
	selection_valnus_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-021_Valnus_Selection.wav");
	selection_marion_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-019_Marion_Selection.wav");
	change_selection_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-050_Change_Character.wav");

	return ret;
}

bool ModuleCharacterSelection::CleanUp()
{
	LOG("Destroying SDL audio");
	App->audio->StopMusic(); 
	App->audio->UnloadWAV(selection_yuan_nang_fx);
	App->audio->UnloadWAV(selection_ash_fx);
	App->audio->UnloadWAV(selection_tetsu_fx);
	App->audio->UnloadWAV(selection_valnus_fx);
	App->audio->UnloadWAV(selection_marion_fx);
	App->audio->UnloadWAV(change_selection_fx);
	
	LOG("Unloading title screen");
	App->textures->Unload(graphics);
	App->textures->Unload(graphics_character);
	App->ui->Disable();

	App->ui->characterselection_ui = false;

	return true;
}

// Update: draw background
update_status ModuleCharacterSelection::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &screen1, 0.75f);
	App->render->Blit(graphics, 0, 241, &screen2, 0.75f);
	App->render->Blit(graphics_character, 138, 252, &(yuan_nang.GetCurrentFrame()));
	App->render->Blit(graphics_character, 23, 260, &(ash.GetCurrentFrame()));
	App->render->Blit(graphics_character, 62, 260, &(marion.GetCurrentFrame()));
	App->render->Blit(graphics_character, 97, 262, &(valnus.GetCurrentFrame()));
	App->render->Blit(graphics_character, 179, 260, &(tetsu.GetCurrentFrame()));
	App->render->Blit(graphics, scroll, 144, &screen_sky, 0.75f);
	App->render->Blit(graphics, pos1p_x, 248, &player1, 0.75f);

	//SKY SCROLL
	if (scroll == -192)
		scroll = 0;
	else
		scroll--;

	//Portraits 1 PLAYER
	if (App->player->activatePlayer2 == false) {
		if (pos1p_x == 16) {
			App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
			App->render->Blit(graphics, 51, 165, &name_ash, 0.75f);
			App->render->Blit(graphics, 96, 129, &(sprite_ash.GetCurrentFrame()));
			selection = ASH;
		}

		if (pos1p_x == 56) {
			App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
			App->render->Blit(graphics, 21, 166, &name_marion, 0.75f);
			App->render->Blit(graphics, 80, 134, &(sprite_marion.GetCurrentFrame()));
			selection = MARION;
		}

		if (pos1p_x == 96) {
			App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
			App->render->Blit(graphics, 22, 166, &name_valnus, 0.75f);
			App->render->Blit(graphics, 94, 120, &(sprite_valnus.GetCurrentFrame()));
			selection = VALNUS;
		}

		if (pos1p_x == 136) {
			App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
			App->render->Blit(graphics, 8, 168, &name_yuan_nang, 0.75f);
			App->render->Blit(graphics, 72, 115, &(sprite_yuan_nang.GetCurrentFrame()));
			selection = YUAN_NANG;
		}

		if (pos1p_x == 176) {
			App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
			App->render->Blit(graphics, 46, 166, &name_tetsu, 0.75f);
			App->render->Blit(graphics, 96, 131, &(sprite_tetsu.GetCurrentFrame()));
			selection = TETSU;
		}

	}
	
	//PLAYER 1 CHOOSE
	if (gate_selection == true)
	{
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN)
		{
			pos1p_x -= 40;
			App->audio->PlayWAV(change_selection_fx);
			if (pos1p_x == -24)
				pos1p_x = 176;

			if (pos1p_x == pos2p_x) {
				if (pos2p_x != 16)
					pos1p_x -= 40;

				if (pos2p_x == 16)
					pos1p_x == 176;
			}
			if (pos2p_x == 16 && pos1p_x == 16)
				pos1p_x = 176;
		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
		{
			pos1p_x += 40;
			App->audio->PlayWAV(change_selection_fx);
			if (pos1p_x == 216)
				pos1p_x = 16;

			if (pos1p_x == pos2p_x) {
				if (pos2p_x != 176)
					pos1p_x += 40;

				if (pos2p_x == 176)
					pos1p_x == 16;
			}
			if (pos2p_x == 176 && pos1p_x == 176)
				pos1p_x = 16;
		}
	}

	//PLAYER 2 CHOOSE
	if (App->player->activatePlayer2 == true) {
		if (gate_selection_P2 == true) {
			if (gate == false) {
				if (pos1p_x != 176) {
					pos2p_x = pos1p_x + 40;
				}
				if (pos1p_x == 176) {
					pos2p_x = 16;
				}
				gate = true;
			}

			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN)
			{
				pos2p_x -= 40;
				App->audio->PlayWAV(change_selection_fx);
				if (pos2p_x == -24)
					pos2p_x = 176;

				if (pos2p_x == pos1p_x) {
					if (pos1p_x != 16)
						pos2p_x -= 40;

					if (pos1p_x == 16)
						pos2p_x == 176;
				}
				if (pos1p_x == 16 && pos2p_x == 16)
					pos2p_x = 176;
			}

			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN)
			{
				pos2p_x += 40;
				App->audio->PlayWAV(change_selection_fx);
				if (pos2p_x == 216)
					pos2p_x = 16;

				if (pos2p_x == pos1p_x) {
					if (pos1p_x != 176)
						pos2p_x += 40;

					if (pos1p_x == 176)
						pos2p_x == 16;
				}
				if (pos1p_x == 176 && pos2p_x == 176)
					pos2p_x = 16;
			}
		}

		Portraits2P();

		if (App->input->keyboard[SDL_SCANCODE_LCTRL]) {
			if (gate_selection_P2 == true) {
				if (selection_P2 == VALNUS)
					App->audio->PlayWAV(selection_valnus_fx);

				if (selection_P2 == TETSU)
					App->audio->PlayWAV(selection_tetsu_fx);

				if (selection_P2 == MARION)
					App->audio->PlayWAV(selection_marion_fx);

				if (selection_P2 == YUAN_NANG)
					App->audio->PlayWAV(selection_yuan_nang_fx);

				if (selection_P2 == ASH)
					App->audio->PlayWAV(selection_ash_fx);
			}
			gate_selection_P2 = false;
			loadP2 = true;

			if (gate_selection == false)
				App->fade->FadeToBlack(this, App->background3, 1.8);
		}
		
		App->render->Blit(graphics, pos2p_x, 248, &player2, 0.75f);
		
	}

	//CHOOSE PLAYER 1
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		if (gate_selection == true) {
			if (selection == VALNUS)
				App->audio->PlayWAV(selection_valnus_fx);

			if (selection == TETSU)
				App->audio->PlayWAV(selection_tetsu_fx);

			if (selection == MARION)
				App->audio->PlayWAV(selection_marion_fx);

			if (selection == YUAN_NANG)
				App->audio->PlayWAV(selection_yuan_nang_fx);

			if (selection == ASH)
				App->audio->PlayWAV(selection_ash_fx);
		}
		gate_selection = false;

		if (App->player->activatePlayer2 == false)
		App->fade->FadeToBlack(this, App->background3, 1.8);

		if (App->player->activatePlayer2 == true && gate_selection_P2 == false)
			App->fade->FadeToBlack(this, App->background3, 1.8);


	}

	return UPDATE_CONTINUE;
}

void ModuleCharacterSelection::Portraits2P() {
	if (pos2p_x == 56 && pos1p_x == 16) { //ASH & MARION
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 47, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 12, 129, &(sprite_ash.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 112, 133, &(sprite_marion.GetCurrentFrame()));
		selection = ASH;
		selection_P2 = MARION;
	}

	if (pos2p_x == 96 && pos1p_x == 16) { //ASH & VALNUS 
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 47, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 12, 129, &(sprite_ash.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 114, 115, &(sprite_valnus.GetCurrentFrame()));
		selection = ASH;
		selection_P2 = VALNUS;
	}

	if (pos2p_x == 136 && pos1p_x == 16) { //ASH & YUAN NANG
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 47, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 12, 129, &(sprite_ash.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 123, 5, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 104, 118, &(sprite_yuan_nang.GetCurrentFrame()));
		selection = ASH;
		selection_P2 = YUAN_NANG;
	}

	if (pos2p_x == 176 && pos1p_x == 16) { //ASH & TETSU
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 47, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 12, 129, &(sprite_ash.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 143, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 117, 128, &(sprite_tetsu.GetCurrentFrame()));
		selection = ASH;
		selection_P2 = TETSU;
	}

	if (pos2p_x == 16 && pos1p_x == 56) { //MARION & ASH
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 0, 134, &(sprite_marion.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 151, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 124, 129, &(sprite_ash.GetCurrentFrame()));
		selection = MARION;
		selection_P2 = ASH;
	}

	if (pos2p_x == 96 && pos1p_x == 56) { //MARION & VALNUS
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 0, 134, &(sprite_marion.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 114, 115, &(sprite_valnus.GetCurrentFrame()));
		selection = MARION;
		selection_P2 = VALNUS;
	}

	if (pos2p_x == 136 && pos1p_x == 56) { //MARION & YUAN NANG
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 0, 134, &(sprite_marion.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 123, 5, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 104, 118, &(sprite_yuan_nang.GetCurrentFrame()));
		selection = MARION;
		selection_P2 = YUAN_NANG;
	}

	if (pos2p_x == 176 && pos1p_x == 56) { //MARION & TETSU
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 0, 134, &(sprite_marion.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 143, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 117, 128, &(sprite_tetsu.GetCurrentFrame()));
		selection = MARION;
		selection_P2 = TETSU;
	}

	if (pos2p_x == 16 && pos1p_x == 96) { //VALNUS & ASH
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 2, 115, &(sprite_valnus.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 151, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 124, 129, &(sprite_ash.GetCurrentFrame()));
		selection = VALNUS;
		selection_P2 = ASH;
	}

	if (pos2p_x == 56 && pos1p_x == 96) { //VALNUS & MARION
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 2, 115, &(sprite_valnus.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 112, 133, &(sprite_marion.GetCurrentFrame()));
		selection = VALNUS;
		selection_P2 = MARION;
	}

	if (pos2p_x == 136 && pos1p_x == 96) { //VALNUS & YUAN NANG
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 2, 115, &(sprite_valnus.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 123, 5, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 104, 118, &(sprite_yuan_nang.GetCurrentFrame()));
		selection = VALNUS;
		selection_P2 = YUAN_NANG;
	}

	if (pos2p_x == 176 && pos1p_x == 96) { //VALNUS & TETSU
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 34, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 2, 115, &(sprite_valnus.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 143, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 117, 128, &(sprite_tetsu.GetCurrentFrame()));
		selection = VALNUS;
		selection_P2 = TETSU;
	}


	if (pos2p_x == 16 && pos1p_x == 136) { //YUAN NANG & ASH
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 19, 6, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 0, 117, &(sprite_yuan_nang.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 151, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 124, 129, &(sprite_ash.GetCurrentFrame()));
		selection = YUAN_NANG;
		selection_P2 = ASH;
	}

	if (pos2p_x == 56 && pos1p_x == 136) { //YUAN NANG & MARION
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 19, 6, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 0, 117, &(sprite_yuan_nang.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 112, 133, &(sprite_marion.GetCurrentFrame()));
		selection = YUAN_NANG;
		selection_P2 = MARION;
	}

	if (pos2p_x == 96 && pos1p_x == 136) { //YUAN NANG & VALNUS
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 19, 6, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 0, 117, &(sprite_yuan_nang.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 114, 115, &(sprite_valnus.GetCurrentFrame()));
		selection = YUAN_NANG;
		selection_P2 = VALNUS;
	}

	if (pos2p_x == 176 && pos1p_x == 136) { //YUAN NANG & TETSU
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 19, 6, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 0, 117, &(sprite_yuan_nang.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 143, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 117, 128, &(sprite_tetsu.GetCurrentFrame()));
		selection = YUAN_NANG;
		selection_P2 = TETSU;
	}

	if (pos2p_x == 16 && pos1p_x == 176) { //TETSU & ASH
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 39, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 8, 128, &(sprite_tetsu.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 151, 5, &name_ash, 0.75f);
		App->render->Blit(graphics, 124, 129, &(sprite_ash.GetCurrentFrame()));
		selection = TETSU;
		selection_P2 = ASH;
	}

	if (pos2p_x == 56 && pos1p_x == 176) { //TETSU & MARION
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 39, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 8, 128, &(sprite_tetsu.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_marion, 0.75f);
		App->render->Blit(graphics, 112, 133, &(sprite_marion.GetCurrentFrame()));
		selection = TETSU;
		selection_P2 = MARION;
	}

	if (pos2p_x == 96 && pos1p_x == 176) { //TETSU & VALNUS
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 39, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 8, 128, &(sprite_tetsu.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 138, 5, &name_valnus, 0.75f);
		App->render->Blit(graphics, 114, 115, &(sprite_valnus.GetCurrentFrame()));
		selection = TETSU;
		selection_P2 = VALNUS;
	}

	if (pos2p_x == 136 && pos1p_x == 176) { //TETSU & YUAN NANG 
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 39, 6, &name_tetsu, 0.75f);
		App->render->Blit(graphics, 8, 128, &(sprite_tetsu.GetCurrentFrame()));

		App->render->Blit(graphics, 116, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 123, 5, &name_yuan_nang_2P, 0.75f);
		App->render->Blit(graphics, 104, 118, &(sprite_yuan_nang.GetCurrentFrame()));
		selection = TETSU;
		selection_P2 = YUAN_NANG;
	}
}