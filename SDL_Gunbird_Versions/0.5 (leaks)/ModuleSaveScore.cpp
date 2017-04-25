#include "Globals.h"
#include "Application.h"
#include "ModuleSaveScore.h"
#include "ModulePlayer.h"

ModuleSaveScore::ModuleSaveScore() : Module() 
{}

ModuleSaveScore::~ModuleSaveScore()
{}

bool ModuleSaveScore::Init()
{
	LOG("Init Save Score");
	bool ret = true;

	for (uint i = 0; i < 10; ++i) {
		saveScore[i] = 0;
		saveCharacter[i] = 0;
	}

	return ret;
}

update_status ModuleSaveScore::Update()
{
	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		if (App->player->characters[i] != nullptr) {
			saveScore[i] = App->player->characters[i]->score;
			saveCharacter[i] = App->player->characters[i]->type;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleSaveScore::CleanUp()
{
	for (uint i = 0; i < 10; ++i) {
		saveScore[i] = 0;
		saveCharacter[i] = 0;
	}

	return true;
}