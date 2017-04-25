#ifndef __ENEMY_VASE_H__
#define __ENEMY_VASE_H__

#include "Enemy.h"
#include"Path.h"

class Enemy_Vase : public Enemy
{
private:
	Animation vase;
	Animation vase_white;
	Animation vase_red;
	iPoint original_pos;

public:
	Enemy_Vase(int x, int y);
	void OnCollision(Collider* collider);
	void Move();
	uint getHitPoints();
};


#endif