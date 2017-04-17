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

	graphics = App->textures->Load("assets/UI/character_selection.png");

	App->audio->PlayMusic("assets/audio/music/gunbird-001_Character_Select.ogg");

	return ret;
}

bool ModuleCharacterSelection::CleanUp()
{
	LOG("Destroying SDL audio");
	App->audio->StopMusic();

	LOG("Unloading title screen");
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleCharacterSelection::Update()
{
	if (scroll == -192)
		scroll = 0;
	else
		scroll--;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN)
	{
		pos1p_x -= 40;
		if (pos1p_x == -24)
			pos1p_x = 176;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN)
	{
		pos1p_x += 40;
		if (pos1p_x == 216)
			pos1p_x = 16;
	}

	//Portraits
	if (pos1p_x == 16) {
		App->render->Blit(graphics, 12, 32, &portrait_ash, 0.75f);
		selection = ASH;
	}

	if (pos1p_x == 56) {
		App->render->Blit(graphics, 12, 32, &portrait_marion, 0.75f);
		selection = MARION;
	}

	if (pos1p_x == 96) {
		App->render->Blit(graphics, 12, 32, &portrait_valnus, 0.75f);
		selection = VALNUS;
	}

	if (pos1p_x == 136) {
		App->render->Blit(graphics, 12, 32, &portrait_yuan_nang, 0.75f);
		selection = YUAN_NANG;
	}

	if (pos1p_x == 176) {
		App->render->Blit(graphics, 12, 32, &portrait_tetsu, 0.75f);
		selection = TETSU;
	}

	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &screen1, 0.75f);

	App->render->Blit(graphics, 0, 241, &screen2, 0.75f);

	App->render->Blit(graphics, pos1p_x, pos1p_y, &player1, 0.75f);

	App->render->Blit(graphics, scroll, 144, &screen_sky, 0.75f);
	

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->background3, 1.8);
	}

	return UPDATE_CONTINUE;
}