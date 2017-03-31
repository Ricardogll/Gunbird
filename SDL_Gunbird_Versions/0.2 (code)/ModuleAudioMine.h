#ifndef __ModuleAudioMine_H__
#define __ModuleAudioMine_H__
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
class ModuleAudioMine : public Module
{
public:
	ModuleAudioMine();
	~ModuleAudioMine();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx_shoot = nullptr;

};

#endif