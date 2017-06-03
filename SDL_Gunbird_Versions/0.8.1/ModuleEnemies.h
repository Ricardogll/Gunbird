#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy.h"
#include "Path.h"

#define MAX_ENEMIES 50

enum ENEMY_TYPES
{
	NO_TYPE,
	BALLOON,
	TURRET,
	MISSILE,
	BUILDING,
	BUILDING2,
	VASE,
	TURRET2,
	DRONE,
	ROBOT,
	TURRET3,
	
	
	COIN,
	POWERUP
};

enum ENEMY_MOVE
{
	NO_MOVE,
	BALLOON_CASTLE,
	BUILDING_CASTLE,
	TURRET_1,
	TURRET_2,
	MISSILE_1,
	MISSILE_2,
	MISSILE_3,
	MISSILE_4,
	DRONE1,
	DRONE2,
	_ROBOT
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	ENEMY_MOVE move = ENEMY_MOVE::NO_MOVE;
	int x, y;
	int id;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, ENEMY_MOVE move, int x, int y);

public:
	bool building_destroyed = false;
	bool building2_destroyed = false;

	Enemy* enemies[MAX_ENEMIES];

	uint explosion1;

private:

	void SpawnEnemy(const EnemyInfo& info);
	void scoreEnemy(Enemy* enemy, Collider* c2);

private:

	//Paths
	Path balloonCastle;

	Path turret1;
	Path turret2;

	Path missile1;
	Path missile2;
	Path missile3;
	Path missile4;

	Path drone1;
	Path drone2;

	Path robot;

	Animation flag;

	EnemyInfo queue[MAX_ENEMIES];
	SDL_Texture* sprites;

	int scoreP1;
	int scoreP2;
};

#endif // __ModuleEnemies_H__