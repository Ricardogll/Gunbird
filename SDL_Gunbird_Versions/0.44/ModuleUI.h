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

public:

	SDL_Texture* graphics = nullptr;

	SDL_Rect livePlayer1;
	SDL_Rect iconPlayer1;
	SDL_Rect iconPlayer2;
	SDL_Rect livePlayer2;
	SDL_Rect bombPlayer;
	SDL_Rect credit;
	SDL_Rect credit1;
	SDL_Rect credit2;
	SDL_Rect credit3;
	SDL_Rect credit4;
	SDL_Rect credit5;
	SDL_Rect credit6;
	SDL_Rect credit7;
	SDL_Rect credit8;
	SDL_Rect credit9;

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

};

#endif
