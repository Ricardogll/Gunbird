#ifndef __ENEMY_ROBOT_H__
#define __ENEMY_ROBOT_H__

#include "Enemy.h"

class Enemy_Robot : public Enemy
{
private:
	Animation robot;
	fPoint pos[2];

	Animation front;
	Animation l1;
	Animation l2;
	Animation l3;
	Animation l4;
	Animation l5;
	Animation l6;
	Animation l7;

	Animation back;

	Animation r1;
	Animation r2;
	Animation r3;
	Animation r4;
	Animation r5;
	Animation r6;
	Animation r7;
	
	Animation stand;

	Animation robot_white;
	Animation robot_red;
	iPoint original_pos;
	bool right;

public:
	Enemy_Robot(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	void Cannon();
	uint getHitPoints();
};


#endif