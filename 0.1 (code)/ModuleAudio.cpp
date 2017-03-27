#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleAudio::ModuleAudio()
{
}

ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	LOG("Init SDL audio");
	bool ret = true;

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
		music = Mix_LoadMUS("music.ogg");
		Mix_PlayMusic(music, -1);
		//fx_shoot = Mix_LoadWAV("assets/laser.wav");
	}
	return ret;
}

bool ModuleAudio::CleanUp()
{
	LOG("Destroying SDL audio");

	Mix_FreeMusic(music);
	//Mix_FreeChunk(fx_shoot);

	return true;
}