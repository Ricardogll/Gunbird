#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"


ModuleBackground::ModuleBackground()
{
	background.x = 0;
	background.y = 0;
	background.w = 288;
	background.h = 2036;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Background Sea.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(graphics, 0, backscroll, &background, 0.75f); // sea and sky
	backscroll += 2;
	if (backscroll == 1750) {
		backscroll = 250;
	}

	return UPDATE_CONTINUE;
}