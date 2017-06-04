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
	SDL_Texture* portraits_graphics = nullptr;
	SDL_Rect scorescreen;
	int font_credit = -1;
	char score_text[10];
	SDL_Rect live[6];

};

#endif