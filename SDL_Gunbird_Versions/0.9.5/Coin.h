#ifndef __ENEMY_COIN_H__
#define __ENEMY_COIN_H__

#include "Enemy.h"

class Coin : public Enemy
{
private:
	Animation coin;


public:
	Coin(int x, int y);
};


#endif