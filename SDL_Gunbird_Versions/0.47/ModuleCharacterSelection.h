#ifndef __ModuleCharacterSelection_H__
#define __ModuleCharacterSelection_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleCharacterSelection : public Module
{
public:
	ModuleCharacterSelection();
	~ModuleCharacterSelection();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics_character = nullptr;
	SDL_Rect screen1;
	SDL_Rect screen2;
	SDL_Rect screen_sky;
	SDL_Rect player1;
	SDL_Rect portrait_yuan_nang;
	SDL_Rect portrait_marion;
	SDL_Rect portrait_valnus;
	SDL_Rect portrait_tetsu;
	SDL_Rect portrait_ash;
	Animation sprite_yuan_nang;
	Animation sprite_marion;
	Animation sprite_valnus;
	Animation sprite_ash;
	Animation sprite_tetsu;
	Animation yuan_nang;
	Animation valnus;
	Animation ash;
	Animation tetsu;
	Animation marion;
	int scroll;
	int pos1p_x;
	int pos1p_y;
	uint selection;

	uint selection_yuan_nang_fx;
	uint selection_marion_fx;
	uint selection_valnus_fx;
	uint selection_ash_fx;
	uint selection_tetsu_fx;
	uint change_selection_fx;
};

#endif

