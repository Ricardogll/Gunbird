#ifndef __CHARACTER_ASH_H__
#define __CHARACTER_ASH_H__

#include "Character.h"

class Character_Ash : public Character
{
private:
	Animation idle;
	Animation left;
	Animation mleft;
	Animation right;
	Animation mright;
	Animation death;
	Animation blit_idle;
	Animation blit_left;
	Animation blit_mleft;
	Animation blit_right;
	Animation blit_mright;
	Animation blit_death;

	iPoint original_pos;

public:
	Character_Ash(int x, int y);
	void Move();
	void Laser();
	void Dead();
	void OnCollision(Collider* collider);

};

#endif