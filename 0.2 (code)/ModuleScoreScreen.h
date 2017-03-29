#ifndef __ModuleScoreScreen_H__
#define __ModuleScoreScreen_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

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
	SDL_Rect scorescreen;
	bool gate = true;
};

#endif