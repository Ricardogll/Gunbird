#ifndef __ModuleAudioSea_H__
#define __ModuleAudioSea_H__
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
class ModuleAudioSea : public Module
{
public:
	ModuleAudioSea();
	~ModuleAudioSea();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx_shoot = nullptr;

};

#endif 