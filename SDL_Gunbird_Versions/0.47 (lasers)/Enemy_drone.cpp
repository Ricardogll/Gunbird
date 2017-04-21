#include "Application.h"
#include "Enemy_drone.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Drone::Enemy_Drone(int x, int y) : Enemy(x, y)
{
	drone.PushBack({ 224,148,28,29 });
	drone.PushBack({ 272,144,26,35 });
	drone.PushBack({ 320,147,26,33 });
	drone.PushBack({ 375,151,30,28 });
	drone.PushBack({ 266,204,32,26 });
	drone.PushBack({ 321,197,26,34 });
	drone.PushBack({ 377,197,26,35 });
	drone.speed = 0.25f;

	lastTime = 0;

	hitPoints = 25;

	animation = &drone;

	collider = App->collision->AddCollider({ 0, 0, 30, 35 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Drone::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &drone;
		lastTime = 0;
	}

}

void Enemy_Drone::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
	hitPoints -= 1;
}

uint Enemy_Drone::getHitPoints() {
	return hitPoints;
}