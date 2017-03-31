#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundSea.h"
#include "ModuleTitleScreen.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudioTitle.h"
#include "ModuleAudioSea.h"


ModuleTitleScreen::ModuleTitleScreen()
{
	titlescreen.x = 0;
	titlescreen.y = 0;
	titlescreen.w = 224;
	titlescreen.h = 320;
}

ModuleTitleScreen::~ModuleTitleScreen()
{}

// Load assets
bool ModuleTitleScreen::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Title.png");
	return ret;
}

bool ModuleTitleScreen::CleanUp()
{
	LOG("Unloading honda stage");
	return true;
}

// Update: draw background
update_status ModuleTitleScreen::Update()
{
	// Draw everything --------------------------------------

	App->render->Blit(graphics, 0, 0, &titlescreen, 0.75f); 

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		//App->fade->gate = true;
		App->audiotitle->Disable();
		App->fade->FadeToBlack(this, App->background, 1);
		App->audiosea->Enable();
	}

	return UPDATE_CONTINUE;
}