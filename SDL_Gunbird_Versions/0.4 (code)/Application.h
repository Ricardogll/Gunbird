#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 13

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleBackgroundSea;
class ModuleBackgroundMine;
class ModuleTitleScreen;
class ModuleScoreScreen;
class ModuleParticles;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class ModuleCollision;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleTitleScreen *titlescreen;
	ModuleBackgroundSea* background;
	ModuleBackgroundMine* background2;
	ModuleScoreScreen *scorescreen;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleFadeToBlack* fade;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__