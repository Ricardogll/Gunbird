#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleBackgroundCastle.h"
#include "ModuleBackgroundSea.h"
#include "ModuleBackgroundMine.h"
#include "ModuleScoreScreen.h"
#include "ModuleTitleScreen.h"
#include "ModuleCharacterSelection.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleUI.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = audio = new ModuleAudio();
	modules[5] = titlescreen = new ModuleTitleScreen();
	modules[6] = characterselection = new ModuleCharacterSelection();
	modules[7] = background3 = new ModuleBackgroundCastle();
	modules[8] = background = new ModuleBackgroundSea();
	modules[9] = background2 = new ModuleBackgroundMine();
	modules[10] = scorescreen = new ModuleScoreScreen();
	modules[11] = enemies = new ModuleEnemies();
	modules[12] = particles = new ModuleParticles();
	modules[13] = player = new ModulePlayer();
	modules[14] = collision = new ModuleCollision();
	modules[15] = ui = new ModuleUI();
	modules[16] = fade = new ModuleFadeToBlack();
}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	collision->Disable();
	enemies->Disable();
	player->Disable();
	// Disable the map that you do not start with
	characterselection->Disable();
	background3->Disable();
	background->Disable();
	background2->Disable();
	scorescreen->Disable();
	particles->Disable();
	ui->Disable();

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

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}