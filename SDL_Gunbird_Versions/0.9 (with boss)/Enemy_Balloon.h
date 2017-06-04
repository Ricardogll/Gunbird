#ifndef __ENEMY_BALLOON_H__
#define __ENEMY_BALLOON_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Balloon : public Enemy
{
private:
	Animation balloon;
	Animation balloon_white;
	Animation balloon_red;
	iPoint original_pos;

public:
	Enemy_Balloon(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};


#endif