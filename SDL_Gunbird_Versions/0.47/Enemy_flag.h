#ifndef __ENEMY_FLAG_H__
#define __ENEMY_FLAG_H__
	
#include "Enemy.h"

class Enemy_Flag : public Enemy
{
private:
	Animation fly;
	iPoint original_pos;

public:
	Enemy_Flag(int x, int y);

	uint getHitPoints();
};


#endif