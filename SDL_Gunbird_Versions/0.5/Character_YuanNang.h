#ifndef __CHARACTER_YUANNANG_H__
#define __CHARACTER_YUANNANG_H__

#include "Character.h"

class Character_YuanNang : public Character
{
private:
	Animation idle;
	Animation right;
	Animation mright;
	Animation left;
	Animation mleft;
	Animation death;
	Animation blit_idle;
	Animation blit_right;
	Animation blit_mright;
	Animation blit_left;
	Animation blit_mleft;

	iPoint original_pos;

public:
	Character_YuanNang(int x, int y);
	void Move();
	void Laser();
	void Dead();
	void OnCollision(Collider* collider);
	
};

#endif