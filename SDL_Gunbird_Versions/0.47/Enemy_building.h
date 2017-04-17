#ifndef __ENEMY_BUILDING_H__
#define __ENEMY_BUILDING_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Building : public Enemy
{
private:
	Animation fly;
	iPoint original_pos;

public:
	Enemy_Building(int x, int y);
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif