#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

// TODO 2: Init the library and check for possible error
// using SDL_GetError()
bool ModuleWindow::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	bool return_value = true;
	window = SDL_CreateWindow(WINDOW_TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SHOWN);
	renderer = SDL_CreateRenderer(window, -1, NOFLAG);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	if (window == nullptr) {
		LOG(SDL_GetError());
		return_value = false;
	}
	return return_value;
};
bool ModuleWindow::CleanUp()
{
    SDL_DestroyWindow(window);
	SDL_Quit();
	return true;
};
// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

