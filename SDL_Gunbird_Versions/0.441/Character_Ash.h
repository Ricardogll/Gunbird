#ifndef __CHARACTER_ASH_H__
#define __CHARACTER_ASH_H__

#include "Character.h"

class Character_Ash : public Character
{
private:
	Animation idle;
	Animation right;
	Animation left;

	iPoint original_pos;

public:
	Character_Ash(int x, int y);
	void Move();
	void Laser();
	void OnCollision(Collider* collider);

};

#endif