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
#include "ModuleSaveScore.h"
#include "ModuleFonts.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = titlescreen = new ModuleTitleScreen();
	modules[i++] = characterselection = new ModuleCharacterSelection();
	modules[i++] = background3 = new ModuleBackgroundCastle();
	modules[i++] = background = new ModuleBackgroundSea();
	modules[i++] = background2 = new ModuleBackgroundMine();
	modules[i++] = scorescreen = new ModuleScoreScreen();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = ui = new ModuleUI();
	modules[i++] = savescore = new ModuleSaveScore();
	modules[i++] = fade = new ModuleFadeToBlack();
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