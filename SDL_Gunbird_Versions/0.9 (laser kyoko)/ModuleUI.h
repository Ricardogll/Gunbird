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

	void choosePlayer2();
	void liveCharacter(uint player);
	void scoreCharacter(uint player);
	void scene_Trump();

public:

	SDL_Texture* graphics = nullptr;

	SDL_Rect iconP1;
	SDL_Rect iconP2;
	SDL_Rect bombPlayer;
	SDL_Rect credit;
	SDL_Rect select;
	SDL_Rect time_icon;
	SDL_Rect gameover_continue;
	SDL_Rect gameover_icon;
	SDL_Rect portraits[6];
	SDL_Rect live[6];
	SDL_Rect black_screen;

	Animation start;
	Animation insert_coins;
	Animation credit_number1;
	Animation credit_number2;
	Animation credit_number3;
	Animation credit_number4;
	Animation credit_number5;
	Animation credit_number6;
	Animation credit_number7;
	Animation credit_number8;
	Animation credit_number9;

	Animation time_rect;

	Animation* current_animation_credit = &credit_number1;

	uint characterP2;
	int selection_character;
	bool activatePlayer1_ui;
	bool activatePlayer2_ui;
	bool characterselection_ui;
	bool titlescreen_ui;
	bool selectPlayer2_ui;
	bool printPlayer2;
	bool assignCharacter;
	bool activateGameOver_ui;

	int font_score = -1;
	char score_text[10];

private:
	uint cont;
	uint time = 0;
	uint countdown;
	uint timeover;
	int titlecredit_x;
	uint order_yuan_nang[5] = { 2,5,4,3,6 };
	uint order_marion[5] = { 1,5,4,3,6 };
	uint order_ash[5] = { 2,1,5,4,6 };
	uint order_tetsu[5] = { 2,1,5,3,6 };
	uint order_valnus[5] = { 2,1,4,3,6 };
	uint order_kyoko[5] = { 2,1,5,4,3 };

};

#endif
