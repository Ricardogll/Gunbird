#ifndef __ModuleBackground2_H__
#define __ModuleBackground2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleBackground2 : public Module
{
public:
	ModuleBackground2();
	~ModuleBackground2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background2;
	int backscroll = 0;
	bool gate = true;
};

#endif