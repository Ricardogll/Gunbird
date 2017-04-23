#ifndef __ModuleScoreScreen_H__
#define __ModuleScoreScreen_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleScoreScreen : public Module
{
public:
	ModuleScoreScreen();
	~ModuleScoreScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Mix_Music* music = nullptr;
	SDL_Rect scorescreen;
};

#endif