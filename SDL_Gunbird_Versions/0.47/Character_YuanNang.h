#ifndef __CHARACTER_YUNGYANG_H__
#define __CHARACTER_YUNGYANG_H__

#include "Character.h"

class Character_YuanNang : public Character
{
private:
	Animation idle;
	Animation right;
	Animation mright;
	Animation left;
	Animation mleft;

	iPoint original_pos;

public:
	Character_YuanNang(int x, int y);
	void Move();
	void Laser();
	void OnCollision(Collider* collider);
	
};

#endif