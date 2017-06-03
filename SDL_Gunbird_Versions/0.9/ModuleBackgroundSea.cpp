#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleBackgroundSea.h"
#include "ModuleScoreScreen.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"

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

	//App->player->position.x = 50;
	//App->player->position.y = 2000;
	//App->player2->position.x = 150;
	//App->player2->position.y = 2000;

	LOG("Loading background sea assets");
	bool ret = true;
	graphics = App->textures->Load("assets/backgrounds/Background Sea.png");

	App->enemies->Enable();
	App->collision->Enable();
	App->ui->Enable();

	App->audio->PlayMusic("assets/audio/music/gunbird-008_Ocean.ogg");

	return ret;
}

bool ModuleBackgroundSea::CleanUp()
{
	App->collision->Disable();
	App->enemies->Disable();
	App->player->Disable();
	App->ui->Disable();

	LOG("Unloading sea stage");
	App->textures->Unload(graphics);

	LOG("Destroying SDL audio");
	App->audio->StopMusic();

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

	App->render->camera.y += 0.7 * SCREEN_SIZE;

	App->render->Blit(graphics, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_DOWN && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->scorescreen, 1);
	}

	return UPDATE_CONTINUE;
}

