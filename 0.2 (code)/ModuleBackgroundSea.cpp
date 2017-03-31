#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundSea.h"
#include "ModuleBackgroundMine.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudioSea.h"
#include "ModuleAudioMine.h"

ModuleBackgroundSea::ModuleBackgroundSea()
{
	background.x = 0;
	background.y = 0;
	background.w = 224;
	background.h = 2036;
}

ModuleBackgroundSea::~ModuleBackgroundSea()
{}

// Load assets
bool ModuleBackgroundSea::Start()
{
	App->render->camera.y = -6985;
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Background Sea.png");
	App->player->Enable();
	App->player2->Enable();
	return ret;
}

bool ModuleBackgroundSea::CleanUp()
{
	LOG("Unloading honda stage");
	App->player->Disable();
	App->player2->Disable();
	return true;
}

// Update: draw background
update_status ModuleBackgroundSea::Update()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(graphics, 0, backscroll, &background, 0.75f); 
	backscroll += 2;
	if (backscroll == 1750) {
		backscroll = 250;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		//App->fade->gate = false;
		App->audiosea->Disable();
		App->fade->FadeToBlack(this, App->background2, 1);
		App->audiomine->Enable();
	}

	return UPDATE_CONTINUE;
}