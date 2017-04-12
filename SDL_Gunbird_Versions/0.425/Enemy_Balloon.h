#ifndef __ENEMY_BALLOON_H__
#define __ENEMY_BALLOON_H__

#include "Enemy.h"

class Enemy_Balloon : public Enemy
{
private:
	Animation fly;
	Path path;
	iPoint original_pos;

public:

	Enemy_Balloon(int x, int y);
	void Move();
};


#endif