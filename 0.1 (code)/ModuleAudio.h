#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	// Called before quitting
	bool Init();

	// Called before quitting
	bool CleanUp();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx_shoot = nullptr;

};

#endif 