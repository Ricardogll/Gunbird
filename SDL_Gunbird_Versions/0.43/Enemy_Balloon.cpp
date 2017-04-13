#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 212,6,43,53 });
	fly.PushBack({ 265,6,42,53});
	fly.PushBack({ 317,6,42,53 });
	fly.PushBack({ 369,6,43,53 });
	fly.PushBack({ 420,6,42,53 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 43, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Balloon::Move()
{
	//path.PushBack({ 0.0f,7.0f }, 100, nullptr);
	path.PushBack({ 0.0f,-1.0f }, 1150000, nullptr);


	position = original_pos + path.GetCurrentPosition();
}

