#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleTitleScreen.h"
#include "ModuleScoreScreen.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModuleSaveScore.h"
#include <stdio.h>


ModuleScoreScreen::ModuleScoreScreen()
{
	scorescreen.x = 0;
	scorescreen.y = 0;
	scorescreen.w = 224;
	scorescreen.h = 320;

	//LIVES
	live[0].x = 21; //YUAN NANG
	live[0].y = 240;
	live[0].w = 15;
	live[0].h = 12;

	live[1].x = 37; //MARION
	live[1].y = 238;
	live[1].w = 15;
	live[1].h = 13;

	live[2].x = 53; //ASH
	live[2].y = 239;
	live[2].w = 11;
	live[2].h = 13;

	live[3].x = 85; //TETSU
	live[3].y = 242;
	live[3].w = 15;
	live[3].h = 9;

	live[4].x = 67; //VALNUS
	live[4].y = 240;
	live[4].w = 15;
	live[4].h = 12;
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
	graphics = App->textures->Load("assets/screens/ScoreBG.png");
	portraits_graphics = App->textures->Load("assets/UI/interface.png");
	font_credit = App->fonts->Load("assets/fonts/credit.png", "0123456789", 1);

	return ret;
}

bool ModuleScoreScreen::CleanUp()
{
	LOG("Destroying SDL audio");
	App->audio->StopMusic();

	LOG("Unloading score screen");
	App->textures->Unload(graphics);
	App->textures->Unload(portraits_graphics);

	App->fonts->UnLoad(font_credit);

	for (uint i = 0; i < 10; ++i) {
		App->savescore->saveScore[i] = 0;
		App->savescore->saveCharacter[i] = 0;
	}

	return true;
}

// Update: draw background
update_status ModuleScoreScreen::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &scorescreen, 0.75f);

	if ((App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_DOWN ||App->input->keyboard[SDL_SCANCODE_BACKSPACE] == KEY_STATE::KEY_DOWN) && App->fade->IsFading() == false) {
		App->fade->FadeToBlack(this, App->titlescreen, 1);
	}


	int j = 58;
	for (uint i = 0; i < 2; ++i)
	{
		char str[10];
		sprintf_s(str, "%i", App->savescore->saveScore[i]);
		if (App->savescore->saveScore[i] == 0)
			App->fonts->BlitText(160, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);
		if (App->savescore->saveScore[i] < 10 && App->savescore->saveScore[i] >= 0)
			App->fonts->BlitText(168, abs(App->render->camera.y / SCREEN_SIZE) +j, font_credit, str);
		if (App->savescore->saveScore[i] < 100 && App->savescore->saveScore[i] >= 10)
			App->fonts->BlitText(160, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);
		if (App->savescore->saveScore[i] < 1000 && App->savescore->saveScore[i] >= 100)
			App->fonts->BlitText(152, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);
		if (App->savescore->saveScore[i]< 10000 && App->savescore->saveScore[i] >= 1000)
			App->fonts->BlitText(144, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);
		if (App->savescore->saveScore[i] < 100000 && App->savescore->saveScore[i] >= 10000)
			App->fonts->BlitText(136, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);
		if (App->savescore->saveScore[i] < 1000000 && App->savescore->saveScore[i] >= 100000)
			App->fonts->BlitText(128, abs(App->render->camera.y / SCREEN_SIZE) + j, font_credit, str);

		if (App->savescore->saveCharacter[i] == YUAN_NANG) 
			App->render->Blit(portraits_graphics, 181, abs(App->render->camera.y / SCREEN_SIZE) + j - 2, &live[0], 1.0f);
		if (App->savescore->saveCharacter[i] == MARION) 
			App->render->Blit(portraits_graphics, 181, abs(App->render->camera.y / SCREEN_SIZE) + j - 2, &live[1], 1.0f);
		if (App->savescore->saveCharacter[i] == ASH) 
			App->render->Blit(portraits_graphics, 181, abs(App->render->camera.y / SCREEN_SIZE) + j - 2, &live[2], 1.0f);
		if (App->savescore->saveCharacter[i] == TETSU) 
			App->render->Blit(portraits_graphics, 181, abs(App->render->camera.y / SCREEN_SIZE) + j - 2, &live[3], 1.0f);
		if (App->savescore->saveCharacter[i] == VALNUS) 
			App->render->Blit(portraits_graphics, 181, abs(App->render->camera.y / SCREEN_SIZE) + j - 2, &live[4], 1.0f);

		j += 24;
	}

	return UPDATE_CONTINUE;
}