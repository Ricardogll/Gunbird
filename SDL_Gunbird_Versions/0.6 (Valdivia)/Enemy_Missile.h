#ifndef __ENEMY_MISSILE_H__
#define __ENEMY_MISSILE_H__

#include "Enemy.h"

class Enemy_Missile : public Enemy
{
private:
	Animation missile;
	Animation missile_white;
	iPoint original_pos;

public:
	Enemy_Missile(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif