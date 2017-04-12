#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22 });
	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 21, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_Balloon::Move()
{
	path.PushBack({ -0.3f, 0.0f }, 150);
	path.PushBack({ 1.2f, 0.0f }, 150);

	position = original_pos + path.GetCurrentPosition();
	position.x -= 4;
}

