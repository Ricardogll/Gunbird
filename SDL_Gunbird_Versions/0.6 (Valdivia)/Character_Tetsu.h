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
	Animation blit_idle;
	Animation blit_left;
	Animation blit_mleft;
	Animation blit_right;
	Animation blit_mright;

	iPoint original_pos;

public:
	Character_Tetsu(int x, int y);
	void Move();
	void Laser();
	void Dead();
	void OnCollision(Collider* collider);

};

#endif