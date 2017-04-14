#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	Collider* collider = nullptr;
	Animation idle;
	Animation right;
	Animation mright;
	Animation left;
	Animation mleft;
	iPoint position;
	bool movement = false;
	int levelPlayer1;
	bool shot;
	uint time = 0;

};

#endif