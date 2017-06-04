#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Globals.h"
#include "Module.h"
#include "SDL_mixer/include/SDL_mixer.h"

class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio();

	bool Init();
	bool CleanUp();

	bool PlayMusic(const char* path);
	bool StopMusic();

	uint LoadWAV(const char* path);
	bool PlayWAV(uint wav, int repeat = 0);
	bool UnloadWAV(uint wav);

private:
	Mix_Music* music = nullptr;
	Mix_Chunk* fx[500];
	uint last_fx = 1;
}; 

#endif // __ModuleAudio_H__ 