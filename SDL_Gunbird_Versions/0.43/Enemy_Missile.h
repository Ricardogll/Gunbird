#ifndef __ENEMY_MISSILE_H__
#define __ENEMY_MISSILE_H__

#include "Enemy.h"

class Enemy_Missile : public Enemy
{
private:
	Animation fly;
	Path path;
	iPoint original_pos;

public:

	Enemy_Missile(int x, int y);
	void Move();
};


#endif