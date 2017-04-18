#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"
#include "Globals.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleUI : public Module
{

public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

	void liveCharacter(uint player);

public:

	SDL_Texture* graphics = nullptr;

	SDL_Rect iconP1;
	SDL_Rect iconP2;
	SDL_Rect liveYuanNang;
	SDL_Rect liveMarion;
	SDL_Rect liveAsh;
	SDL_Rect liveValnus;
	SDL_Rect liveTetsu;
	SDL_Rect bombPlayer;
	SDL_Rect credit;

	Animation start;
	Animation credit_number1;
	Animation credit_number2;
	Animation credit_number3;
	Animation credit_number4;
	Animation credit_number5;
	Animation credit_number6;
	Animation credit_number7;
	Animation credit_number8;
	Animation credit_number9;

	Animation* current_animation_credit = &credit_number1;

	bool activatePlayer2_ui;

private:
	uint cont;
	uint time = 0;

};

#endif
