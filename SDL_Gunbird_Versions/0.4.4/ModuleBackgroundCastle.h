#ifndef __ModuleBackgroundCastle_H__
#define __ModuleBackgroundCastle_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL/include/SDL.h"

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

	//void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Animation idle;
	Mix_Music* music = nullptr;
	SDL_Rect background;
	bool gate = true;

};

#endif
