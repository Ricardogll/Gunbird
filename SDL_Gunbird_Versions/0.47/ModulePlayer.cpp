#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModuleUI.h"
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
	bool ret = true;
	activatePlayer2 = false;

	// Create a prototype for each enemy available so we can copy them around
	graphics = App->textures->Load("assets/characters/Characters.png");
	if (graphics == nullptr) {
		LOG("Cannot load the texture in yuan nang");
		ret = false;
	}

	insertcoin_fx = App->audio->LoadWAV("assets/audio/sound/InsertCoin.wav");

	marion_powerup = App->audio->LoadWAV("assets/audio/sound/gunbird-024_Marion_PowerUp.wav");
	yuan_nang_powerup = App->audio->LoadWAV("assets/audio/sound/gunbird-025_YungNang_PowerUp.wav");
	tetsu_powerup = App->audio->LoadWAV("assets/audio/sound/gunbird-027_Tetsu_PowerUp.wav");
	ash_powerup = App->audio->LoadWAV("assets/audio/sound/gunbird-028_Ash_PowerUp.wav");
	valnus_powerup = App->audio->LoadWAV("assets/audio/sound/gunbird-026_Valnus_PowerUp.wav");

	marion_powerup_limit = App->audio->LoadWAV("assets/audio/sound/gunbird-029_Marion_LimitPowerUp.wav");
	yuan_nang_powerup_limit = App->audio->LoadWAV("assets/audio/sound/gunbird-030_YungNang_LimitPowerUp.wav");
	tetsu_powerup_limit = App->audio->LoadWAV("assets/audio/sound/gunbird-032_Tetsu_LimitPowerUp.wav");
	ash_powerup_limit = App->audio->LoadWAV("assets/audio/sound/gunbird-033_Ash_LimitPowerUp.wav");
	valnus_powerup_limit = App->audio->LoadWAV("assets/audio/sound/gunbird-031_Valnus_LimitPowerUp.wav");

	marion_dead = App->audio->LoadWAV("assets/audio/sound/gunbird-039_Marion_Dead.wav");
	yuan_nang_dead = App->audio->LoadWAV("assets/audio/sound/gunbird-040_YungNang_Dead.wav");
	tetsu_dead = App->audio->LoadWAV("assets/audio/sound/gunbird-042_Tetsu_Dead.wav");
	ash_dead = App->audio->LoadWAV("assets/audio/sound/gunbird-043_Ash_Dead.wav");
	valnus_dead = App->audio->LoadWAV("assets/audio/sound/gunbird-041_Valnus_Dead.wav");

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

	//for (uint i = 0; i < MAX_CHARACTERS; ++i) 
	//	if (characters[i] != nullptr) characters[i]->Move(); 		
	if (characters[0] != nullptr)
		characters[0]->Move();
	if (characters[1] != nullptr)
		characters[1]->Move2();

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
		if (characters[i] != nullptr) characters[i]->Laser();

	for (uint i = 0; i < MAX_CHARACTERS; ++i)
		if (characters[i] != nullptr) characters[i]->Draw(graphics);

	//Activate Player 2
	if (App->ui->titlescreen_ui != true) {
		if (App->input->keyboard[SDL_SCANCODE_BACKSPACE] == KEY_STATE::KEY_DOWN)
			if (coins > 0) {
				activatePlayer2 = true;
				if (coins != 0)
					coins--;
			}
	}

	//COIN
	if (App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_DOWN) {
		App->audio->PlayWAV(insertcoin_fx);
		if (coins < 9) {
			coins++;
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	LOG("Freeing all characters");
	App->textures->Unload(graphics);

	App->audio->UnloadWAV(insertcoin_fx);
	App->audio->UnloadWAV(marion_powerup);
	App->audio->UnloadWAV(yuan_nang_powerup);
	App->audio->UnloadWAV(valnus_powerup);
	App->audio->UnloadWAV(tetsu_powerup);
	App->audio->UnloadWAV(ash_powerup);
	App->audio->UnloadWAV(marion_powerup_limit);
	App->audio->UnloadWAV(yuan_nang_powerup_limit);
	App->audio->UnloadWAV(valnus_powerup_limit);
	App->audio->UnloadWAV(tetsu_powerup_limit);
	App->audio->UnloadWAV(ash_powerup_limit);
	App->audio->UnloadWAV(marion_dead);
	App->audio->UnloadWAV(yuan_nang_dead);
	App->audio->UnloadWAV(valnus_dead);
	App->audio->UnloadWAV(tetsu_dead);
	App->audio->UnloadWAV(ash_dead);

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

				if (characters[i]->type == CHARACTER_TYPES::YUAN_NANG && characters[i]->level < 3)
					App->audio->PlayWAV(yuan_nang_powerup);
				if (characters[i]->type == CHARACTER_TYPES::MARION && characters[i]->level < 3)
					App->audio->PlayWAV(marion_powerup);
				if (characters[i]->type == CHARACTER_TYPES::TETSU && characters[i]->level < 3)
					App->audio->PlayWAV(tetsu_powerup);
				if (characters[i]->type == CHARACTER_TYPES::ASH && characters[i]->level < 3)
					App->audio->PlayWAV(ash_powerup);
				if (characters[i]->type == CHARACTER_TYPES::VALNUS && characters[i]->level < 3)
					App->audio->PlayWAV(valnus_powerup);

				if (characters[i]->type == CHARACTER_TYPES::YUAN_NANG && characters[i]->level == 3)
					App->audio->PlayWAV(yuan_nang_powerup_limit);
				if (characters[i]->type == CHARACTER_TYPES::MARION && characters[i]->level == 3)
				App->audio->PlayWAV(marion_powerup_limit);
				if (characters[i]->type == CHARACTER_TYPES::TETSU && characters[i]->level == 3)
				App->audio->PlayWAV(tetsu_powerup_limit);
				if (characters[i]->type == CHARACTER_TYPES::ASH && characters[i]->level == 3)
				App->audio->PlayWAV(ash_powerup_limit);
				if (characters[i]->type == CHARACTER_TYPES::VALNUS && characters[i]->level == 3)
				App->audio->PlayWAV(valnus_powerup_limit);
			}

			characters[i]->OnCollision(c2);
			if (c2->type == COLLIDER_ENEMY_SHOT)
			{
				if (characters[i]->live > 0)
					characters[i]->live--;

				if (characters[i]->type == CHARACTER_TYPES::YUAN_NANG)
					App->audio->PlayWAV(yuan_nang_dead);
				if (characters[i]->type == CHARACTER_TYPES::MARION)
					App->audio->PlayWAV(marion_dead);
				if (characters[i]->type == CHARACTER_TYPES::TETSU)
					App->audio->PlayWAV(tetsu_dead);
				if (characters[i]->type == CHARACTER_TYPES::ASH)
					App->audio->PlayWAV(ash_dead);
				if (characters[i]->type == CHARACTER_TYPES::VALNUS)
					App->audio->PlayWAV(valnus_dead);
			}
		}
	}
}