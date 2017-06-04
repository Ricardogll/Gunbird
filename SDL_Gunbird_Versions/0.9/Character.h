#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"

struct SDL_Texture;
struct Collider;

#define SPEED_ASH 3
#define SPEED_MARION 3
#define SPEED_VALNUS 2
#define SPEED_YUAN_NANG 2
#define SPEED_TETSU 2
#define SPEED_KYOKO 2

class Character
{
protected:
	Animation* animation = nullptr;
	bool shot;
	int time = 0;
	float scroll = 0;
	bool spawnPlayer = false;

public:
	Collider* collider = nullptr;
	iPoint position;
	int type;
	int level = 0;
	int live = 2;
	int bombs = 2;
	int score = 0;
	bool movement = false;
	bool playerDead = false;
	bool desactivateInput = false;
	bool inmortal = false;
	bool desactivateLimit = false;

public:
	Character(int x, int y);
	virtual ~Character();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Laser() {};
	virtual void Dead() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	virtual uint getHitPoints() { return 0; }
};

#endif // __CHARACTER_H__