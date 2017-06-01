#ifndef __ModuleEndScene_H__
#define __ModuleEndScene_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#define TIME_END_SCENE 480

struct SDL_Texture;
struct SDL_RenderCopy;

class ModuleEndScene : public Module
{
public:
	ModuleEndScene();
	~ModuleEndScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics_text = nullptr;

	SDL_Rect screen_sky;
	SDL_Rect screen_up;
	SDL_Rect screen_down;

	SDL_Rect ash_scene1;
	SDL_Rect ash_scene2;
	SDL_Rect ash_scene3;
	SDL_Rect marion_scene1;
	SDL_Rect marion_scene2;
	SDL_Rect marion_scene3;
	SDL_Rect rabbit_scene1;
	SDL_Rect tetsu_scene1;
	SDL_Rect tetsu_scene2;
	SDL_Rect tetsu_scene3;
	SDL_Rect tetsu_scene4;
	SDL_Rect valnus_scene1;
	SDL_Rect valnus_scene2;
	SDL_Rect valnus_scene3;
	SDL_Rect yuan_nang_scene1;
	SDL_Rect yuan_nang_scene2;
	SDL_Rect yuan_nang_scene3;
	SDL_Rect yuan_nang_scene4;

	Animation* animation = nullptr;
	Animation mirror;
	Animation break_mirror;

	SDL_Rect text_ash;
	SDL_Rect text_marion;
	SDL_Rect text_yuan_nang;
	SDL_Rect text_tetsu;
	SDL_Rect text_valnus;
	SDL_Rect text_rabbit;
	SDL_Rect text_ash_tetsu1;
	SDL_Rect text_ash_tetsu2;
	SDL_Rect text_ash_valnus1;
	SDL_Rect text_ash_valnus2;
	SDL_Rect text_ash_valnus3;
	SDL_Rect text_ash_marion1;
	SDL_Rect text_ash_marion2;
	SDL_Rect text_ash_yuan1;
	SDL_Rect text_ash_yuan2;
	SDL_Rect text_valnus_marion1;
	SDL_Rect text_valnus_marion2;
	SDL_Rect text_valnus_yuan1;
	SDL_Rect text_valnus_yuan2;
	SDL_Rect text_valnus_yuan3;
	SDL_Rect text_valnus_tetsu1;
	SDL_Rect text_valnus_tetsu2;
	SDL_Rect text_marion_tetsu1;
	SDL_Rect text_marion_tetsu2;
	SDL_Rect text_marion_yuan1;
	SDL_Rect text_marion_yuan2;
	SDL_Rect text_marion_yuan3;
	SDL_Rect text_tetsu_yuan1;
	SDL_Rect text_tetsu_yuan2;

	int scroll;
	int cont_left;
	int cont_mirror;
	int cont_right;
	int cont_rabbit;
	int time;

	uint music;
};

#endif