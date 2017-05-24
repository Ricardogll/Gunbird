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

	void Portraits2P();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics_character = nullptr;
	SDL_Rect screen1;
	SDL_Rect screen2;
	SDL_Rect screen_sky;
	SDL_Rect player1;
	SDL_Rect player2;
	SDL_Rect portrait_yuan_nang;
	SDL_Rect portrait_marion;
	SDL_Rect portrait_valnus;
	SDL_Rect portrait_tetsu;
	SDL_Rect portrait_ash;
	SDL_Rect portrait_kyoko;
	SDL_Rect name_yuan_nang;
	SDL_Rect name_yuan_nang_2P;
	SDL_Rect name_marion;
	SDL_Rect name_valnus;
	SDL_Rect name_tetsu;
	SDL_Rect name_ash;
	SDL_Rect name_kyoko;

	Animation sprite_yuan_nang;
	Animation sprite_marion;
	Animation sprite_valnus;
	Animation sprite_ash;
	Animation sprite_tetsu;
	Animation sprite_kyoko;
	Animation yuan_nang;
	Animation valnus;
	Animation ash;
	Animation tetsu;
	Animation marion;
	Animation kyoko;

	int scroll;
	int pos1p_x;
	int pos2p_x;
	bool gate;
	uint selection;
	uint selection_P2;
	bool gate_selection;
	bool gate_selection_P2;
	bool loadP2;
	int pos_select;
	int pos_select_2;


	uint selection_yuan_nang_fx;
	uint selection_marion_fx;
	uint selection_valnus_fx;
	uint selection_ash_fx;
	uint selection_tetsu_fx;
	uint selection_kyoko_fx;
	uint change_selection_fx;
};

#endif

