#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 11,6,43,53 });
	fly.PushBack({ 64,6,42,53});
	fly.PushBack({ 116,6,42,53 });
	fly.PushBack({ 168,6,43,53 });
	fly.PushBack({ 219,6,42,53 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 43, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Balloon::Move()
{
	position = original_pos + path.GetCurrentPosition();
	path.PushBack({ 0.0f,0.2f }, 11500, nullptr);


	//position = original_pos + path.GetCurrentPosition();
	//position.x -= 4;
}

