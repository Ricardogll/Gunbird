#include "Application.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "SDL_mixer/include/SDL_mixer.h"

ModuleAudio::ModuleAudio()
{}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Init()
{
	LOG("Loading Audio");
	SDL_Init(0);
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(24000, MIX_DEFAULT_FORMAT, 2, 2048);

	return true;
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
	//Mix_HaltMusic();
	return true;
}

uint ModuleAudio::LoadWAV(const char* path)
{
	uint ret = 0;
	Mix_Chunk* audio = Mix_LoadWAV(path);
	fx[last_fx] = audio;
	ret = last_fx++;

	return ret;
}

bool ModuleAudio::PlayWAV(uint wav, int repeat)
{
	Mix_PlayChannel(-1, fx[wav], repeat);

	return true;
}

bool ModuleAudio::UnloadWAV(uint wav)
{
	Mix_FreeChunk(fx[wav]);
	fx[wav] = nullptr;
	last_fx--;

	return true;
}

