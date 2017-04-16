#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

//ESTO BORRARLO DESPUES
#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL/include/SDL.h"

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
	int livePlayer1;
	int bombPlayer1;

	bool activatePlayer2 = false;

	int coins;

	//ESTO BORRARLO DESPUES
	Mix_Chunk* insertcoin = nullptr;

private:
	bool shot;
	int time = 0;

};

#endif