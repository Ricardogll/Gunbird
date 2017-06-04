#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio()
{}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	/*LOG("Loading Audio");
	SDL_Init(0);
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);*/

	LOG("Loading Audio Mixer");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_INIT_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// load support for the OGG format
	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("Could not initialize Mixer lib. Mix_Init: %s", Mix_GetError());
		ret = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		ret = false;
	}

	return ret;

	//return true;
}

bool ModuleAudio::CleanUp()
{
	LOG("Unload Audio");
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);

	return true;
}

bool ModuleAudio::PlayMusic(const char* path)
{
	music = Mix_LoadMUS(path);
	Mix_PlayMusic(music, -1);

	return true;
}

bool ModuleAudio::StopMusic() {
	Mix_FreeMusic(music);
	music = nullptr;
	Mix_HaltMusic();
	return true;
}

uint ModuleAudio::LoadWAV(const char* path)
{
	uint ret = 0;
	Mix_Chunk* audio = Mix_LoadWAV(path);

	if (audio == nullptr)
	{
		LOG("Cannot load wav %s. Mix_GetError(): %s", path, Mix_GetError());
	}
	else
	{
		fx[last_fx] = audio;
		ret = last_fx++;
		if (last_fx == 500) {
			last_fx = 0;
			ret = last_fx;
		}
	}

	return ret;
}

bool ModuleAudio::PlayWAV(uint wav, int repeat)
{
	bool ret = false;

	if (fx[wav] != nullptr)
	{
		Mix_PlayChannel(-1, fx[wav], repeat);
		ret = true;
	}

	return true;
}

bool ModuleAudio::UnloadWAV(uint wav)
{
	bool ret = false;

	if (fx[wav] != nullptr)
	{
		Mix_FreeChunk(fx[wav]);
		fx[wav] = nullptr;
		ret = true;
		last_fx--;
	}

	return true;
}