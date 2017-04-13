#include "Application.h"
#include "Enemy_Missile.h"
#include "ModuleCollision.h"

Enemy_Missile::Enemy_Missile(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 20,82,28,32 });
	fly.PushBack({ 50,82,28,32 });
	fly.PushBack({ 84,82,28,32 });
	fly.PushBack({ 89,82,28,32 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 28, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Missile::Move()
{
	position.y += 2;


	//position = original_pos + path.GetCurrentPosition();
}

