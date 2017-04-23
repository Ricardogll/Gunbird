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
	SDL_Texture* animation_soldier = nullptr;
	SDL_Texture* animation_building = nullptr;
	Animation idle;
	Animation door;
	Animation door2;
	Animation floor;
	Animation building;
	Animation soldier;
	Animation soldier2;
	SDL_Rect background;
	bool gate;
	float scroll;

};

#endif
