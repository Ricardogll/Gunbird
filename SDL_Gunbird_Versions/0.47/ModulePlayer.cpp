#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Character.h"
#include "Character_YuanNang.h"
#include "Character_Marion.h"
#include "Character_Ash.h"
#include "Character_Tetsu.h"
#include "Character_Valnus.h"

ModulePlayer::ModulePlayer()
{
	for (uint i = 0; i < MAX_CHARACTERS; ++i)
		characters[i] = nullptr;
}

// Destructor
ModulePlayer::~ModulePlayer()
{
}

bool ModulePlayer::Start()
{
	coins = 2;
	bool ret = true;
	activatePlayer2 = false;

	// Create a prototype for each enemy available so we can copy them around
	graphics = App->textures->Load("assets/characters/Characters.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in yuan nang");
		ret = false;
	}

	insertcoin_fx = App->audio->LoadWAV("assets/audio/sound/InsertCoin.wav");

	return ret;
}

// Called before render is available
update_status ModulePlayer::Update()
{
	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		if (queue[i].type != CHARACTER_TYPES::NO_CHARACTER)
		{
			SpawnCharacter(queue[i]);
			queue[i].type = CHARACTER_TYPES::NO_CHARACTER;
			LOG("Spawning character at %d", queue[i].x * SCREEN_SIZE);
		}
	}

	for (uint i = 0; i < MAX_CHARACTERS; ++i) 
		if (characters[i] != nullptr) characters[i]->Move(); 		

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
		if (characters[i] != nullptr) characters[i]->Laser();

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
		if (characters[i] != nullptr) characters[i]->Draw(graphics);

	//Activate Player 2
	if (App->input->keyboard[SDL_SCANCODE_Z] == KEY_STATE::KEY_DOWN)
		if (coins > 0) {
			activatePlayer2 = true;
			if (coins != 0)
				coins--;
		}

	//COIN
	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN) {
		if (coins < 9)
			coins++;
		App->audio->PlayWAV(insertcoin_fx);
	}
	

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	LOG("Freeing all characters");
	App->textures->Unload(graphics);

	App->audio->UnloadWAV(insertcoin_fx);

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		if (characters[i] != nullptr)
		{
			delete characters[i];
			characters[i] = nullptr;
		}
	}
	delete characters[0];
	characters[0] = nullptr;
	if (characters[1] != nullptr) {
		delete characters[1];
		characters[1] = nullptr;
	}

	return true;
}

bool ModulePlayer::AddCharacter(CHARACTER_TYPES type, int x, int y, int player)
{
	bool ret = false;
	
	queue[player].type = type;
	queue[player].x = x;
	queue[player].y = y;
	ret = true;

	return ret;
}

void ModulePlayer::SpawnCharacter(const CharacterInfo& info)
{
	uint i = 0;
	for (; characters[i] != nullptr && i < MAX_CHARACTERS; ++i);

	if (i != MAX_CHARACTERS)
	{
		switch (info.type)
		{
		case CHARACTER_TYPES::YUAN_NANG:
			characters[i] = new Character_YuanNang(info.x, info.y);
			characters[i]->type = CHARACTER_TYPES::YUAN_NANG;
			break;
		case CHARACTER_TYPES::MARION:
			characters[i] = new Character_Marion(info.x, info.y);
			characters[i]->type = CHARACTER_TYPES::MARION;
			break;
		case CHARACTER_TYPES::ASH:
			characters[i] = new Character_Ash(info.x, info.y);
			characters[i]->type = CHARACTER_TYPES::ASH;
			break;
		case CHARACTER_TYPES::TETSU:
			characters[i] = new Character_Tetsu(info.x, info.y);
			characters[i]->type = CHARACTER_TYPES::TETSU;
			break;
		case CHARACTER_TYPES::VALNUS:
			characters[i] = new Character_Valnus(info.x, info.y);
			characters[i]->type = CHARACTER_TYPES::VALNUS;
			break;
		}
	}
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		if (characters[i] != nullptr && characters[i]->GetCollider() == c1)
		{
			characters[i]->OnCollision(c2);
			if (c2->type == COLLIDER_POWER_UP)
			{
				if (characters[i]->level < 3)
					characters[i]->level++;
			}
		}
	}
}