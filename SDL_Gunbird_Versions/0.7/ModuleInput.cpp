#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "SDL/include/SDL_gamecontroller.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	controller = nullptr;
	for (int i = 0; i < SDL_NumJoysticks(); ++i) {
		if (SDL_IsGameController(i)) {
			controller = SDL_GameControllerOpen(i);
			if (controller) {
				break;
			}
			else {
				LOG("Could not open gamecontroller %i: %s\n", i, SDL_GetError());
			}
		}
	}

	gate_player = false;
	gate_enemies = false;
	activateDebug = false;

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	inputGamepad();

	gamepad.left_joystick.x = ((float)SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f);
	gamepad.left_joystick.y = ((float)SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f);

	//JOYSTICK
	if (gamepad.left_joystick.x > 0.25)
	{
		joystick_right = true;
		if (time == 8) {
			joystick_right_repeat = true;
			time = 0;
		}
		else
			joystick_right_repeat = false;

		time++;
	}
	else {
		joystick_right = false;
		joystick_right_repeat = false;
	}

	if (gamepad.left_joystick.x < -0.25)
	{
		joystick_left = true;
		if (time == 8) {
			joystick_left_repeat = true;
			time = 0;
		}
		else
			joystick_left_repeat = false;

		time++;
	}
	else {
		joystick_left = false;
		joystick_left_repeat = false;
	}

	joystick_down = 0;
	joystick_up = 0;

	if (gamepad.left_joystick.y > 0.25)
	{
		joystick_down = true;
	}
	else
		joystick_down = false;
	if (gamepad.left_joystick.y < -0.25)
	{
		joystick_up = true;
	}
	else
		joystick_up = false;


	//CLOSE WINDOW
	if (keyboard[SDL_SCANCODE_ESCAPE])
			return update_status::UPDATE_STOP;
		
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);

	for (int i = 0; i < SDL_NumJoysticks(); ++i) {
		if (SDL_IsGameController(i)) {
			SDL_GameController *controller = SDL_GameControllerOpen(i);
			if (controller) {
				SDL_GameControllerClose(controller);
			}
			else {
			LOG("Could not open gamecontroller %i: %s\n", i, SDL_GetError());
			}
		}
	}

	return true;
}

void ModuleInput::inputGamepad() {
	//BUTTON A
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A) == 1) {
		if (gamepad.A == BUTTON_IDLE)
			gamepad.A = BUTTON_DOWN;
		else
			gamepad.A = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.A == BUTTON_REPEAT || (gamepad.A == BUTTON_DOWN))
			gamepad.A = BUTTON_UP;
		else
			gamepad.A = BUTTON_IDLE;
	}

	//BUTTON START
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_START) == 1) {
		if (gamepad.START == BUTTON_IDLE)
			gamepad.START = BUTTON_DOWN;
		else
			gamepad.START = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.START == BUTTON_REPEAT || (gamepad.START == BUTTON_DOWN))
			gamepad.START = BUTTON_UP;
		else
			gamepad.START = BUTTON_IDLE;
	}

	//BUTTON DPAD UP
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP) == 1) {
		if (gamepad.DPAD_UP == BUTTON_IDLE)
			gamepad.DPAD_UP = BUTTON_DOWN;
		else
			gamepad.DPAD_UP = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.DPAD_UP == BUTTON_REPEAT || (gamepad.DPAD_UP == BUTTON_DOWN))
			gamepad.DPAD_UP = BUTTON_UP;
		else
			gamepad.DPAD_UP = BUTTON_IDLE;
	}

	//BUTTON DPAD DOWN
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == 1) {
		if (gamepad.DPAD_DOWN == BUTTON_IDLE)
			gamepad.DPAD_DOWN = BUTTON_DOWN;
		else
			gamepad.DPAD_DOWN = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.DPAD_DOWN == BUTTON_REPEAT || (gamepad.DPAD_DOWN == BUTTON_DOWN))
			gamepad.DPAD_DOWN = BUTTON_UP;
		else
			gamepad.DPAD_DOWN = BUTTON_IDLE;
	}

	//BUTTON DPAD LEFT
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT) == 1) {
		if (gamepad.DPAD_LEFT == BUTTON_IDLE)
			gamepad.DPAD_LEFT = BUTTON_DOWN;
		else
			gamepad.DPAD_LEFT = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.DPAD_LEFT == BUTTON_REPEAT || (gamepad.DPAD_LEFT == BUTTON_DOWN))
			gamepad.DPAD_LEFT = BUTTON_UP;
		else
			gamepad.DPAD_LEFT = BUTTON_IDLE;
	}

	//BUTTON DPAD UP
	if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT) == 1) {
		if (gamepad.DPAD_RIGHT == BUTTON_IDLE)
			gamepad.DPAD_RIGHT = BUTTON_DOWN;
		else
			gamepad.DPAD_RIGHT = BUTTON_REPEAT;
	}
	else
	{
		if (gamepad.DPAD_RIGHT == BUTTON_REPEAT || (gamepad.DPAD_RIGHT == BUTTON_DOWN))
			gamepad.DPAD_RIGHT = BUTTON_UP;
		else
			gamepad.DPAD_RIGHT = BUTTON_IDLE;
	}
}