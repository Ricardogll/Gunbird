#include "Application.h"
#include "Enemy_Building.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Building::Enemy_Building(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 732,444,64,86 });
	
	lastTime = 0;

	hitPoints = 25;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 64, 86 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Building::OnCollision(Collider* collider) {
	hitPoints -= 1;
}

uint Enemy_Building::getHitPoints() {
	return hitPoints;
}