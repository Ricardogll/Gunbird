#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTitleScreen.h"
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

	LOG("Loading score screen assets");
	bool ret = true;
	graphics = App->textures->Load("assets/screens/Score.png");

	LOG("Init SDL audio");
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_AUDIO could not initialize! SDL_Error:\n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{
		Mix_Init(MIX_INIT_OGG);
		Mix_OpenAudio(24000, MIX_DEFAULT_FORMAT, 2, 2048);
		music = Mix_LoadMUS("assets/audio/music/gunbird-014_Scores.ogg");
		Mix_PlayMusic(music, -1);
	}

	return ret;
}

bool ModuleScoreScreen::CleanUp()
{
	LOG("Destroying SDL audio");
	Mix_FreeMusic(music);

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