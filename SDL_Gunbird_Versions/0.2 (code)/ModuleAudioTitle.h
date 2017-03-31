#ifndef __ModuleAudioTitle_H__
#define __ModuleAudioTitle_H__
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
class ModuleAudioTitle : public Module
{
public:
	ModuleAudioTitle();
	~ModuleAudioTitle();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx_shoot = nullptr;

};

#endif 