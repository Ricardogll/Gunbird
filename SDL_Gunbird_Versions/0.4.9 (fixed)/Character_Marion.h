#ifndef __CHARACTER_MARION_H__
#define __CHARACTER_MARION_H__

#include "Character.h"

class Character_Marion : public Character
{
private:
	Animation idle;
	Animation left;
	Animation mleft;
	Animation right;
	Animation mright;
	Animation death;

	iPoint original_pos;

public:
	Character_Marion(int x, int y);
	void Move();
	void Laser();
	void Dead();
	void OnCollision(Collider* collider);

};

#endif