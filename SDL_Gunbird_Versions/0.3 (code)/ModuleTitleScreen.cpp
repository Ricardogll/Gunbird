#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundSea.h"
#include "ModuleTitleScreen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"


ModuleTitleScreen::ModuleTitleScreen()
{
	titlescreen.x = 0;
	titlescreen.y = 0;
	titlescreen.w = 224;
	titlescreen.h = 320;
}

ModuleTitleScreen::~ModuleTitleScreen()
{}

// Load assets
bool ModuleTitleScreen::Start()
{
	LOG("Loading title screen assets");
	bool ret = true;
	graphics = App->textures->Load("assets/Title.png");

	LOG("Init SDL audio");
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error:\n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		Mix_Init(MIX_INIT_OGG);
		Mix_OpenAudio(24000, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("assets/gunbird-002_Title_Castle.ogg");
		Mix_PlayMusic(music, -1);
	}

	return ret;
}

bool ModuleTitleScreen::CleanUp()
{
	LOG("Destroying SDL audio");
	Mix_FreeMusic(music);
	App->textures->Unload(graphics);
	return true;
}

// Update: draw background
update_status ModuleTitleScreen::Update()
{
	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, 0, &titlescreen, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, App->background, 1);
		LOG("Init SDL audio");

		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			LOG("SDL_AUDIO could not initialize! SDL_Error:\n");
			LOG(SDL_GetError());
		}
		else
		{
			Mix_Init(MIX_INIT_MP3);
			Mix_OpenAudio(44000, MIX_DEFAULT_FORMAT, 2, 2048);
			insertcoin = Mix_LoadWAV("assets/InsertCoin.wav");
			Mix_PlayChannel(-1, insertcoin, 0);
	
		}
		Mix_FreeChunk(insertcoin);
	}

	return UPDATE_CONTINUE;
}