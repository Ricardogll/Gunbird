#ifndef __CHARACTER_KYOKO_H__
#define __CHARACTER_KYOKO_H__

#include "Character.h"

class Character_Kyoko : public Character
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
	Character_Kyoko(int x, int y);
	void Move();
	void Laser();
	void Dead();
	void OnCollision(Collider* collider);

};

#endif