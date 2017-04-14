#ifndef __ENEMY_BALLOON_H__
#define __ENEMY_BALLOON_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Balloon : public Enemy
{
private:
	Animation fly;
	iPoint original_pos;
	bool going_up = true;

public:
	Enemy_Balloon(int x, int y);
	void Move();
};


#endif