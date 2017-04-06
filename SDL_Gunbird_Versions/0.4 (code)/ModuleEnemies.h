#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL.h"

struct SDL_Texture;
struct Collider;

class ModuleEnemies : public Module
{
public:
	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Collider* collider = nullptr;
	Animation balloon;
	Animation explosion_balloon;
	iPoint position;

};

#endif