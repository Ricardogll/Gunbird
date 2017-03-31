#ifndef __ModuleBackgroundMine_H__
#define __ModuleBackgroundMine_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL/include/SDL.h"

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
	Mix_Music* music = nullptr;
	SDL_Rect background2;
	int backscroll = 0;

};

#endif