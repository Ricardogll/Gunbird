#ifndef __ModuleBackgroundMine_H__
#define __ModuleBackgroundMine_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleBackgroundMine : public Module
{
public:
	ModuleBackgroundMine();
	~ModuleBackgroundMine();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background2;
	int backscroll = 0;
};

#endif