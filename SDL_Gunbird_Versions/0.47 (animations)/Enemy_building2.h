#ifndef __ENEMY_BUILDING2_H__
#define __ENEMY_BUILDING2_H__

#include "Enemy.h"

class Enemy_Building2 : public Enemy
{
private:
	Animation fly;
	iPoint original_pos;

public:
	Enemy_Building2(int x, int y);
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif