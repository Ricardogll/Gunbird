#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 19

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModuleRender; 
class ModuleBackgroundCastle;
class ModuleBackgroundSea;
class ModuleBackgroundMine;
class ModuleTitleScreen;
class ModuleScoreScreen; 
class ModuleCharacterSelection;
class ModuleParticles;
class ModulePlayer;
class ModuleEnemies;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleUI;
class ModuleFonts;
class ModuleSaveScore; 
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleAudio* audio;
	ModuleTitleScreen* titlescreen;
	ModuleCharacterSelection* characterselection;
	ModuleBackgroundCastle* background3;
	ModuleBackgroundMine* background2;
	ModuleBackgroundSea* background;
	ModuleScoreScreen* scorescreen;
	ModulePlayer* player;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleFadeToBlack* fade;
	ModuleUI* ui;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;
	ModuleSaveScore* savescore;

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