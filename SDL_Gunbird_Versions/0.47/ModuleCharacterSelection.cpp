#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
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
}   

ModuleCharacterSelection::~ModuleCharacterSelection()
{}

// Load assets
bool ModuleCharacterSelection::Start()
{
	LOG("Loading title screen assets");
	bool ret = true;
	scroll = 0;
	pos1p_x = 56;
	pos1p_y = 248;

	App->player->Enable();

	graphics = App->textures->Load("assets/UI/character_selection.png");
	graphics_character = App->textures->Load("assets/characters/Characters.png");

	App->audio->PlayMusic("assets/audio/music/gunbird-001_Character_Select.ogg");
	
	selection_yuan_nang_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-020_YungNang_Selection");
	selection_ash_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-023_Ash_Selection.wav");
	selection_tetsu_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-022_Tetsu_Selection");
	selection_valnus_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-021_Valnus_Selection");
	selection_marion_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-019_Marion_Selection");
	change_selection_fx = App->audio->LoadWAV("assets/audio/sound/gunbird-019_Marion_Selection");

	return ret;
}

bool ModuleCharacterSelection::CleanUp()
{
	LOG("Destroying SDL audio");
	App->audio->StopMusic(); /*
	App->audio->UnloadWAV(selection_yuan_nang_fx);
	App->audio->UnloadWAV(selection_ash_fx);
	App->audio->UnloadWAV(selection_tetsu_fx);
	App->audio->UnloadWAV(selection_valnus_fx);
	App->audio->UnloadWAV(selection_marion_fx);
	App->audio->UnloadWAV(change_selection_fx);*/
	
	LOG("Unloading title screen");
	App->textures->Unload(graphics);
	App->textures->Unload(graphics_character);
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
	App->render->Blit(graphics, pos1p_x, pos1p_y, &player1, 0.75f);
	App->render->Blit(graphics, scroll, 144, &screen_sky, 0.75f);


	if (scroll == -192)
		scroll = 0;
	else
		scroll--;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN)
	{
		pos1p_x -= 40;
		App->audio->PlayWAV(change_selection_fx);
		if (pos1p_x == -24)
			pos1p_x = 176;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
	{
		pos1p_x += 40;
		App->audio->PlayWAV(change_selection_fx);
		if (pos1p_x == 216)
			pos1p_x = 16;
	}

	//Portraits
	if (pos1p_x == 16) {
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		App->render->Blit(graphics, 96, 129, &(sprite_ash.GetCurrentFrame()));
		selection = ASH;
	}

	if (pos1p_x == 56) {
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		App->render->Blit(graphics, 80, 134, &(sprite_marion.GetCurrentFrame()));
		selection = MARION;
	}

	if (pos1p_x == 96) {
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		App->render->Blit(graphics, 94, 120, &(sprite_valnus.GetCurrentFrame()));
		selection = VALNUS;
	}

	if (pos1p_x == 136) {
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		App->render->Blit(graphics, 72, 115, &(sprite_yuan_nang.GetCurrentFrame()));
		selection = YUAN_NANG;
	}

	if (pos1p_x == 176) {
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		App->render->Blit(graphics, 96, 131, &(sprite_tetsu.GetCurrentFrame()));
		selection = TETSU;
	}
	

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
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

		App->fade->FadeToBlack(this, App->background3, 1.8);
	}

	return UPDATE_CONTINUE;
}