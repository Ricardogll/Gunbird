#include "Application.h"
#include "Enemy_Turret.h"
#include "ModuleCollision.h"

Enemy_Turret::Enemy_Turret(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 20,8,32,32 });
	fly.PushBack({ 54,8,32,32 });
	fly.PushBack({ 88,8,32,32 });
	fly.PushBack({ 122,8,32,32 });
	fly.speed = 0.25f;

	hitPoints = 4;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret::Move()
{
	position = original_pos;
}

void Enemy_Turret::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
	hitPoints -= 1;
}

uint Enemy_Turret::getHitPoints() {
	return hitPoints;
}
