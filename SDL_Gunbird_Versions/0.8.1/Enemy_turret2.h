#ifndef __ENEMY_TURRET2_H__
#define __ENEMY_TURRET2_H__

#include "Enemy.h"

class Enemy_Turret2 : public Enemy
{
private:
	Animation front;
	Animation l1;
	Animation l2;
	Animation l3;
	Animation l4;
	Animation l5;
	Animation l6;
	Animation l7;
	Animation l8;
	Animation l9;
	Animation l10;
	Animation l11;
	Animation l12;
	Animation l13;
	Animation l14;

	Animation back;

	Animation r1;
	Animation r2;
	Animation r3;
	Animation r4;
	Animation r5;
	Animation r6;
	Animation r7;
	Animation r8;
	Animation r9;
	Animation r10;
	Animation r11;
	Animation r12;
	Animation r13;
	Animation r14;
	Animation r15;







	Animation turret2;
	Animation turret2_white;
	iPoint original_pos;
	bool right;

public:
	Enemy_Turret2(int x, int y);
	void Move();
	void OnCollision(Collider* collider);
	uint getHitPoints();
};

#endif
