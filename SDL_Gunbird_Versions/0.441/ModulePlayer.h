#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Character_YuanNang.h"
#include "Character_Marion.h"
#include "Character_Ash.h"
#include "Character_Tetsu.h"
#include "Character_Valnus.h"

#define MAX_CHARACTERS 2

enum CHARACTER_TYPES
{
	NO_CHARACTER,
	YUAN_NANG,
	MARION,
	ASH,
	TETSU,
	VALNUS
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
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddCharacter(CHARACTER_TYPES type, int x, int y, int player);

	Character* characters[MAX_CHARACTERS];

	bool activatePlayer2;
	int coins;
	uint insertcoin_fx;

private:

	void SpawnCharacter(const CharacterInfo& info);

private:

	CharacterInfo queue[MAX_CHARACTERS];
	SDL_Texture* graphics;
};

#endif // __ModulePlayer_H__