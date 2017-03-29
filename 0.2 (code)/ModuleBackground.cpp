#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackground.h"
#include "ModuleBackground2.h"
#include "ModulePlayer.h"


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
	App->player->Enable();
	return ret;
}

bool ModuleBackground::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
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

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && gate == true) {
		gate = false;
		//App->fade->FadeToBlack(this, App->scene_ken, 3);
		App->background->Disable();
		App->background2->Enable();
	}

	return UPDATE_CONTINUE;
}