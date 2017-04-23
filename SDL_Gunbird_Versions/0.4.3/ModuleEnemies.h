#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_Balloon.h"
#include "Enemy_Turret.h"
#include "Enemy_Missile.h"
#include "Path.h"

#define MAX_ENEMIES 100

enum ENEMY_TYPES
{
	NO_TYPE,
	BALLOON,
	TURRET,
	MISSILE
};

enum ENEMY_MOVE
{
	NO_MOVE,
	BALLOON_CASTLE,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	ENEMY_MOVE move = ENEMY_MOVE::NO_MOVE;
	int x, y;
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

private:

	void SpawnEnemy(const EnemyInfo& info);

private:
	Path balloonCastle;

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
};

#endif // __ModuleEnemies_H__