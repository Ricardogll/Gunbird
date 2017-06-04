#ifndef __ENEMY_BOSS_H__
#define __ENEMY_BOSS_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Boss : public Enemy
{
private:
	Animation boss;
	Animation boss_white;
	Animation boss_red;
	Animation boss_red2;
	Animation boss_nomove;
	iPoint original_pos;
	bool gate = false;

public:
	Enemy_Boss(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};

#endif