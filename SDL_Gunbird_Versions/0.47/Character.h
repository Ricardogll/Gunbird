#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "p2Point.h"
#include "Animation.h"
#include "Path.h"

struct SDL_Texture;
struct Collider;

class Character
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	bool shot;
	int time = 0;

public:
	iPoint position;
	int type;
	int level = 0;
	int live = 2;
	int bombs = 2;
	bool movement = false;

public:
	Character(int x, int y);
	virtual ~Character();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Move2() {};
	virtual void Laser() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	virtual uint getHitPoints() { return 0; }
};

#endif // __CHARACTER_H__