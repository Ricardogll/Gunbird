#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <windows.h>
#include <stdio.h>

#define LOG(txt) OutputDebugString(txt)

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Configuration -----------
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define FULLSCREEN SDL_WINDOW_FULLSCREEN
#define WINDOW_TITLE "Wiko"
#define SHOWN SDL_WINDOW_SHOWN
#define NOBORDER SDL_WINDOW_BORDERLESS
#define HIDDEN SDL_WINDOW_HIDDEN 
#define RESIZABLE SDL_WINDOW_RESIZABLE
#define MINIMIZED SDL_WINDOW_MINIMIZED
#define MAXIMIZED SDL_WINDOW_MAXIMIZED
#define NOFLAG 0
#endif // __GLOBALS_H__
