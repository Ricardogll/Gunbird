#include "Application.h"
#include "ModuleRender.h"
#include "Enemy_Missile.h"
#include "ModuleCollision.h"

Enemy_Missile::Enemy_Missile(int x, int y) : Enemy(x, y)
{
	missile.PushBack({ 20,45,18,32 });
	missile.PushBack({ 43,46,16,32 });
	missile.PushBack({ 62,46,22,32 });
	missile.PushBack({ 85,46,26,32 });
	missile.PushBack({ 20,82,28,32 });
	missile.PushBack({ 50,82,26,32 });
	missile.PushBack({ 80,82,22,32 });
	missile.PushBack({ 104,82,16,32 });
	missile.speed = 0.1f;

	missile_white.PushBack({ 118,46,19,33 });

	hitPoints = 5;

	score = 200;

	animation = &missile;

	collider = App->collision->AddCollider({ 0, 0, 18, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Missile::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &missile;

	if (hit_animation == true) {
		animation = &missile_white;
		hit_animation = false;
	}
	
}

void Enemy_Missile::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
}

uint Enemy_Missile::getHitPoints() {
	return hitPoints;
}
