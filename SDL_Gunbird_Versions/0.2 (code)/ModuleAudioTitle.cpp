#include "Globals.h"
#include "Application.h"
#include "ModuleAudioTitle.h"
#include "SDL/include/SDL.h"

ModuleAudioTitle::ModuleAudioTitle()
{
}

ModuleAudioTitle::~ModuleAudioTitle()
{
}

bool ModuleAudioTitle::Start()
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
		music = Mix_LoadMUS("gunbird-002_Title_Castle.ogg");
		Mix_PlayMusic(music, -1);
	}
	return ret;
}

bool ModuleAudioTitle::CleanUp()
{
	LOG("Destroying SDL audio");

	Mix_FreeMusic(music);

	return true;
}