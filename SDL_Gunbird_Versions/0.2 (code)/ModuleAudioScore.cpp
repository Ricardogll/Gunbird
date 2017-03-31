#include "Globals.h"
#include "Application.h"
#include "ModuleAudioScore.h"
#include "SDL/include/SDL.h"

ModuleAudioScore::ModuleAudioScore()
{
}

ModuleAudioScore::~ModuleAudioScore()
{
}

bool ModuleAudioScore::Start()
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
		music = Mix_LoadMUS("gunbird-014_Scores.ogg");
		Mix_PlayMusic(music, -1);
	}
	return ret;
}

bool ModuleAudioScore::CleanUp()
{
	LOG("Destroying SDL audio");

	Mix_FreeMusic(music);

	return true;
}