#include "Application.h"
#include "Enemy_drone.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Drone::Enemy_Drone(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 224,148,28,29 });
	fly.PushBack({ 272,144,26,35 });
	fly.PushBack({ 320,147,26,33 });
	fly.PushBack({ 375,151,30,28 });
	fly.PushBack({ 266,204,32,26 });
	fly.PushBack({ 321,197,26,34 });
	fly.PushBack({ 377,197,26,35 });
	fly.speed = 0.25f;

	lastTime = 0;

	hitPoints = 25;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 30, 35 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Drone::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &fly;
		lastTime = 0;
	}

}

void Enemy_Drone::OnCollision(Collider* collider) {
	hitPoints -= 1;
}

uint Enemy_Drone::getHitPoints() {
	return hitPoints;
}