#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleBackgroundSea.h"
#include "ModuleBackgroundMine.h"
#include "ModuleScoreScreen.h"
#include "ModuleTitleScreen.h"
#include "ModulePlayer.h"
#include "ModuleAudioTitle.h"
#include "ModuleAudioSea.h"
#include "ModuleAudioMine.h"
#include "ModuleAudioScore.h"
#include "ModuleFadeToBlack.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = titlescreen = new ModuleTitleScreen();
	modules[5] = background = new ModuleBackgroundSea();
	modules[6] = background2 = new ModuleBackgroundMine();
	modules[7] = scorescreen = new ModuleScoreScreen();
	modules[8] = player = new ModulePlayer();
	modules[9] = audiotitle = new ModuleAudioTitle();
	modules[10] = audiosea = new ModuleAudioSea();
	modules[11] = audiomine = new ModuleAudioMine();
	modules[12] = audioscore = new ModuleAudioScore();
	modules[13] = fade = new ModuleFadeToBlack();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	// Disable the map that you do not start with
	background->Disable();
	background2->Disable();
	scorescreen->Disable();
	audiosea->Disable();
	audiomine->Disable();
	audioscore->Disable();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}