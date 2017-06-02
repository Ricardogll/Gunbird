#ifndef __ENEMY_ROBOT_H__
#define __ENEMY_ROBOT_H__

#include "Enemy.h"

class Enemy_Robot : public Enemy
{
private:
	Animation robot;
	Animation turret_white;
	Animation turret_red;
	iPoint original_pos;

public:
	Enemy_Robot(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif