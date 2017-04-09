#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundSea.h"
#include "ModuleBackgroundMine.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"

ModuleBackgroundSea::ModuleBackgroundSea()
{
	background.x = 0;
	background.y = 0;
	background.w = 288;
	background.h = 2036;

}

ModuleBackgroundSea::~ModuleBackgroundSea()
{}

// Load assets
bool ModuleBackgroundSea::Start()
{
	App->render->camera.y = (-2036 + SCREEN_HEIGHT) * SCREEN_SIZE;
	App->render->camera.x = 0 * SCREEN_SIZE;

	App->player->position.x = 50;
	App->player->position.y = 2000;

	LOG("Loading background sea assets");
	bool ret = true;
	graphics = App->textures->Load("assets/Background Sea.png");

	App->player->Enable();
	App->player2->Enable();
	App->enemies->Enable();
	App->collision->Enable();

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
		music = Mix_LoadMUS("assets/gunbird-008_Ocean.ogg");
		Mix_PlayMusic(music, -1);
	}


	return ret;
}

bool ModuleBackgroundSea::CleanUp()
{
	App->player->Disable();
	App->player2->Disable();
	App->enemies->Disable();
	App->collision->Disable();

	LOG("Unloading sea stage");
	App->textures->Unload(graphics);

	LOG("Destroying SDL audio");
	Mix_FreeMusic(music);

	return true;
}

// Update: draw background
update_status ModuleBackgroundSea::Update()
{
	// Draw everything --------------------------------------

	/*App->render->Blit(graphics, 0, backscroll, &background, 0.75f);
	backscroll += 2;
	if (backscroll == 1750) {
		backscroll = 250;
	}*/

	App->render->camera.y += 0.01 * SCREEN_SIZE;

	App->render->Blit(graphics, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->background2, 1);
	}

	return UPDATE_CONTINUE;
}

