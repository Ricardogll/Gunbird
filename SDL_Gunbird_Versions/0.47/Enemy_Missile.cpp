#include "Application.h"
#include "Enemy_Missile.h"
#include "ModuleCollision.h"

Enemy_Missile::Enemy_Missile(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 20,45,18,32 });
	fly.PushBack({ 43,46,16,32 });
	fly.PushBack({ 62,46,22,32 });
	fly.PushBack({ 85,46,26,32 });
	fly.PushBack({ 20,82,28,32 });
	fly.PushBack({ 50,82,26,32 });
	fly.PushBack({ 80,82,22,32 });
	fly.PushBack({ 104,82,16,32 });
	fly.speed = 0.25f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 18, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Missile::Move()
{
	position.y += 1;
	position.x += 1;


	//position = original_pos + path.GetCurrentPosition();
}

