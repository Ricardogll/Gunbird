#ifndef __CHARACTER_TETSU_H__
#define __CHARACTER_TETSU_H__

#include "Character.h"

class Character_Tetsu : public Character
{
private:
	Animation idle;
	Animation right;
	Animation mright;
	Animation left;
	Animation mleft;

	iPoint original_pos;

public:
	Character_Tetsu(int x, int y);
	void Move();
	void Move2();
	void Laser();
	void OnCollision(Collider* collider);

};

#endif