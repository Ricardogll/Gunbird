#include "Application.h"
#include "Enemy_Building2.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Building2::Enemy_Building2(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 801,444,72,83 });
	lastTime = 0;

	hitPoints = 25;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 72, 83 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}
uint Enemy_Building2::getHitPoints() {
	return hitPoints;
}