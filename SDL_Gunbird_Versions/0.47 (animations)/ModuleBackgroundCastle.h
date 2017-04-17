#ifndef __ModuleBackgroundCastle_H__
#define __ModuleBackgroundCastle_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleBackgroundCastle : public Module
{
public:
	ModuleBackgroundCastle();
	~ModuleBackgroundCastle();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* animation_door = nullptr;
	Animation idle;
	Animation door;
	SDL_Rect background;
	bool gate;

};

#endif
