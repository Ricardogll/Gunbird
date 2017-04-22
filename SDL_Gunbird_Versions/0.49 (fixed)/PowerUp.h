#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "Enemy.h"

class PowerUp : public Enemy
{
private:
	Animation anim;
	bool up;
	bool left;

public:

	PowerUp(int x, int y);
	void Move();

};

#endif