#ifndef __ModuleBackgroundCastle_H__
#define __ModuleBackgroundCastle_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#include "ModuleEnemies.h"

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

	void choosePlayer2();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* animation_door = nullptr;
	SDL_Texture* animation_soldier = nullptr;
	SDL_Texture* animation_building = nullptr;
	SDL_Texture* graphics_trump = nullptr;
	Animation idle;
	Animation door;
	Animation door2;
	Animation floor;
	Animation building;
	Animation soldier;
	Animation soldier2;
	float soldier2_x;
	float soldier2_y;
	Animation soldier3;
	float soldier3_x;
	float soldier3_y;
	Animation trump;

	SDL_Rect background;
	bool gate;
	bool choose_character;
	bool trump_scene;
	bool boss_dead;
	uint time_scene_trump;

	//Audio Characters P2
	uint selection_yuan_nang_fx;
	uint selection_marion_fx;
	uint selection_valnus_fx;
	uint selection_ash_fx;
	uint selection_tetsu_fx;
	uint selection_kyoko_fx;
	uint change_selection_fx;

	float var_x[MAX_ENEMIES];
	float var_y[MAX_ENEMIES];
	float vec_u[MAX_ENEMIES];
	float res_x[MAX_ENEMIES];
	float res_y[MAX_ENEMIES];

};

#endif