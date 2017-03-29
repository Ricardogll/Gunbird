#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackground2.h"
#include "ModuleBackground.h"
#include "ModulePlayer.h"


ModuleBackground2::ModuleBackground2()
{
	background2.x = 0;
	background2.y = 0;
	background2.w = 288; //288
	background2.h = 2036; //2036
}

ModuleBackground2::~ModuleBackground2()
{}

// Load assets
bool ModuleBackground2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Background Mine.png");
	App->player->Enable();
	return ret;
}

bool ModuleBackground2::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleBackground2::Update()
{
	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, backscroll, &background2, 0.75f); // sea and sky
	backscroll += 2;
	if (backscroll == 1750) {
		backscroll = 250;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && gate == true) {
		gate = false;
		//App->fade->FadeToBlack(this, App->scene_ken, 3);
		App->background2->Disable();
		App->background->Enable();
	}


	return UPDATE_CONTINUE;
}