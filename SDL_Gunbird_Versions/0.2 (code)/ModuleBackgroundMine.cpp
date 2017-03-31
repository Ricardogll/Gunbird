#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundMine.h"
#include "ModuleScoreScreen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudioMine.h"
#include "ModuleAudioScore.h"


ModuleBackgroundMine::ModuleBackgroundMine()
{
	background2.x = 0;
	background2.y = 0;
	background2.w = 224; 
	background2.h = 2036; 
}

ModuleBackgroundMine::~ModuleBackgroundMine()
{}

// Load assets
bool ModuleBackgroundMine::Start()
{
	App->render->camera.y = -6985;
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Background Mine.png");
	App->player->Enable();
	return ret;
}

bool ModuleBackgroundMine::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleBackgroundMine::Update()
{
	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, backscroll, &background2, 0.75f); 
	backscroll += 2;
	if (backscroll == 1750) {
		backscroll = 250;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		//App->fade->gate = true;
		App->audiomine->Disable();
		App->fade->FadeToBlack(this, App->scorescreen, 1);
		App->audioscore->Enable();
	}


	return UPDATE_CONTINUE;
}