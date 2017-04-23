#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	balloon.PushBack({ 212,6,43,53 });
	balloon.PushBack({ 265,6,42,53 });
	balloon.PushBack({ 317,6,42,53 });
	balloon.PushBack({ 369,6,43,53 });
	balloon.PushBack({ 420,6,42,53 });
	balloon.speed = 0.25f;

	lastTime = 0;

	hitPoints = 25;

	score = 500;

	animation = &balloon;

	collider = App->collision->AddCollider({ 0, 0, 43, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Balloon::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &balloon;
		lastTime = 0;
	}

}

void Enemy_Balloon::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
	hitPoints -= 1;
}

uint Enemy_Balloon::getHitPoints() {
	return hitPoints;
}

