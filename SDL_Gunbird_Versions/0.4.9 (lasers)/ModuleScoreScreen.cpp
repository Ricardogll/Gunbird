#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleTitleScreen.h"
#include "ModuleScoreScreen.h"
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

	App->audio->PlayMusic("assets/audio/music/gunbird-014_Scores.ogg");

	LOG("Loading score screen assets");
	bool ret = true;
	graphics = App->textures->Load("assets/screens/Score.png");

	return ret;
}

bool ModuleScoreScreen::CleanUp()
{
	LOG("Destroying SDL audio");
	App->audio->StopMusic();

	LOG("Unloading score screen");
	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleScoreScreen::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &scorescreen, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->titlescreen, 1);
	}

	return UPDATE_CONTINUE;
}