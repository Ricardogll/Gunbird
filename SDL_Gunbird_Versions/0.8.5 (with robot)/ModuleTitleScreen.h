#ifndef __ModuleTitleScreen_H__
#define __ModuleTitleScreen_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleTitleScreen : public Module
{
public:
	ModuleTitleScreen();
	~ModuleTitleScreen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	uint insertcoin;
	SDL_Rect titlescreen;


};

#endif
