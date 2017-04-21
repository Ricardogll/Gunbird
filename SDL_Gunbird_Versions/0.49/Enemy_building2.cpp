#include "Application.h"
#include "Enemy_Building2.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Building2::Enemy_Building2(int x, int y) : Enemy(x, y)
{
	building.PushBack({ 801,444,72,83 });
	lastTime = 0;

	hitPoints = 25;

	score = 3000;

	animation = &building;

	collider = App->collision->AddCollider({ 0, 0, 72, 83 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Building2::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
		hitPoints -= 1;
}

uint Enemy_Building2::getHitPoints() {
	return hitPoints;
}