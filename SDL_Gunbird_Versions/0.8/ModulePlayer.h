#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Character_YuanNang.h"
#include "Character_Marion.h"
#include "Character_Ash.h"
#include "Character_Tetsu.h"
#include "Character_Valnus.h"
#include "Character_Kyoko.h"

#define MAX_CHARACTERS 2

enum CHARACTER_TYPES
{
	NO_CHARACTER,
	YUAN_NANG,
	MARION,
	ASH,
	TETSU,
	VALNUS,
	KYOKO
};

class Character;

struct CharacterInfo
{
	CHARACTER_TYPES type = CHARACTER_TYPES::NO_CHARACTER;
	int x, y;
};

class ModulePlayer : public Module
{
public:

	ModulePlayer();
	~ModulePlayer();

	bool Start();

	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddCharacter(CHARACTER_TYPES type, int x, int y, int player);

	Character* characters[MAX_CHARACTERS];

	bool activatePlayer2;
	int coins;

	uint insertcoin_fx;
	uint score_coin;

	uint marion_powerup;
	uint yuan_nang_powerup;
	uint ash_powerup;
	uint valnus_powerup;
	uint tetsu_powerup;
	uint kyoko_powerup;

	uint marion_powerup_limit;
	uint yuan_nang_powerup_limit;
	uint ash_powerup_limit;
	uint valnus_powerup_limit;
	uint tetsu_powerup_limit;
	uint kyoko_powerup_limit;

	uint marion_dead;
	uint yuan_nang_dead;
	uint ash_dead;
	uint valnus_dead;
	uint tetsu_dead;
	uint kyoko_dead;

public:
	bool gateF4;
	bool deathwin;

private:

	void SpawnCharacter(const CharacterInfo& info);

private:

	CharacterInfo queue[MAX_CHARACTERS];
	SDL_Texture* graphics;
};

#endif // __ModulePlayer_H__