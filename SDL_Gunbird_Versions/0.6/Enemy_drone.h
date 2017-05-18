#ifndef __ENEMY_DRONE_H__
#define __ENEMY_DRONE_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Drone : public Enemy
{
private:
	Animation drone;
	iPoint original_pos;

public:
	Enemy_Drone(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};

#endif