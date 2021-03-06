#ifndef __ModuleBackgroundSea_H__
#define __ModuleBackgroundSea_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleBackgroundSea : public Module
{
public:
	ModuleBackgroundSea();
	~ModuleBackgroundSea();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	SDL_Rect background;

};

#endif