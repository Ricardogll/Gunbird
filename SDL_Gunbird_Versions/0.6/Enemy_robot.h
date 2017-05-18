#ifndef __ENEMY_ROBOT_H__
#define __ENEMY_ROBOT_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Robot : public Enemy
{
private:
	Animation robot;
	Animation balloon_white;
	Animation balloon_red;
	iPoint original_pos;

public:
	Enemy_Robot(int x, int y);
	void Move();
};


#endif