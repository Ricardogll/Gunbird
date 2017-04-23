#ifndef __ENEMY_TURRET_H__
#define __ENEMY_TURRET_H__

#include "Enemy.h"

class Enemy_Turret	: public Enemy
{
private:
	Animation turret;
	iPoint original_pos;

public:
	Enemy_Turret(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif