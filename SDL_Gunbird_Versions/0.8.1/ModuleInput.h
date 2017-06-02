#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL/include/SDL.h"

#define MAX_KEYS 300

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum CONTROLLER_STATE {
	BUTTON_IDLE = 0,
	BUTTON_DOWN,
	BUTTON_REPEAT,
	BUTTON_UP
};

struct Gamepad {
	CONTROLLER_STATE A;
	CONTROLLER_STATE B;
	CONTROLLER_STATE Y;
	CONTROLLER_STATE X;
	CONTROLLER_STATE START;
	CONTROLLER_STATE DPAD_UP;
	CONTROLLER_STATE DPAD_DOWN;
	CONTROLLER_STATE DPAD_LEFT;
	CONTROLLER_STATE DPAD_RIGHT;
	p2Point<float> left_joystick;
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

	void inputGamepad();

public:
	KEY_STATE keyboard[MAX_KEYS];
	bool gate_player;
	bool gate_enemies;
	bool activateDebug;
	Gamepad gamepad;

	bool joystick_up;
	bool joystick_down;
	bool joystick_left;
	bool joystick_right;

	bool joystick_left_repeat;
	bool joystick_right_repeat;

private:
	SDL_GameController* controller;
	int time = 0;
};

#endif // __ModuleInput_H__