#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleBackgroundMine.h"
#include "ModuleBackgroundSea.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"


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
	App->render->camera.y = (-2036 + SCREEN_HEIGHT) * SCREEN_SIZE;
	App->render->camera.x = 0 * SCREEN_SIZE;

	App->player->position.x = 50;
	App->player->position.y = 2000;
	App->player2->position.x = 150;
	App->player2->position.y = 2000;

	LOG("Loading background mine assets");
	bool ret = true;
	graphics = App->textures->Load("assets/backgrounds/Background Mine.png");
	graphics2 = App->textures->Load("assets/backgrounds/mine_background2.png");

	App->player->Enable();
	App->player2->Enable();
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
		music = Mix_LoadMUS("assets/audio/music/gunbird-005_Mine.ogg");
		Mix_PlayMusic(music, -1);
	}

	return ret;
}

bool ModuleBackgroundMine::CleanUp()
{
	App->collision->Disable();
	App->player2->Disable();
	App->player->Disable();

	LOG("Unloading mine stage");
	App->textures->Unload(graphics);

	LOG("Destroying SDL audio");
	Mix_FreeMusic(music);

	return true;
}

// Update: draw background
update_status ModuleBackgroundMine::Update()
{
	// Draw everything --------------------------------------

	/*App->render->Blit(graphics, 0, backscroll, &background2, 0.75f);
	App->render->Blit(graphics2, 0, backscroll2, &background2, 0.75f);
	backscroll += 2;
	backscroll2 += 1;
	if (backscroll == 1750) {
		backscroll = 250;
	}
	if (backscroll2 == 1750) {
		backscroll2 = 250;
	}
*/

	App->render->camera.y += 0.7 * SCREEN_SIZE;

	App->render->Blit(graphics, 0, 0, NULL); 
	App->render->Blit(graphics2, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->background, 1);
	}


	return UPDATE_CONTINUE;
}