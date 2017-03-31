#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundMine.h"
#include "ModuleScoreScreen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"


ModuleScoreScreen::ModuleScoreScreen()
{
	scorescreen.x = 0;
	scorescreen.y = 0;
	scorescreen.w = 224;
	scorescreen.h = 320;
}

ModuleScoreScreen::~ModuleScoreScreen()
{}

// Load assets
bool ModuleScoreScreen::Start()
{
	App->render->camera.x = 0;
	App->render->camera.y = 0;
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Score.png");
	return ret;
}

bool ModuleScoreScreen::CleanUp()
{
	LOG("Unloading honda stage");
	return true;
}

// Update: draw background
update_status ModuleScoreScreen::Update()
{
	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, 0, &scorescreen, 0.75f);

	return UPDATE_CONTINUE;
}