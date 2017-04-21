#ifndef __ENEMY_TURRET2_H__
#define __ENEMY_TURRET2_H__

#include "Enemy.h"

class Enemy_Turret2 : public Enemy
{
private:
	Animation turret2;
	iPoint original_pos;

public:
	Enemy_Turret2(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif