#ifndef __ModuleAudioScore_H__
#define __ModuleAudioScore_H__
#include "Globals.h"
#include "Application.h"
#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
class ModuleAudioScore : public Module
{
public:
	ModuleAudioScore();
	~ModuleAudioScore();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

public:

	Mix_Music* music = nullptr;
	Mix_Chunk* fx_shoot = nullptr;

};

#endif