#include "Application.h"
#include "Enemy_turret2.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Turret2::Enemy_Turret2(int x, int y) : Enemy(x, y)
{
	turret2.PushBack({ 10,256,28,41 });
	turret2.PushBack({ 46,255,28,41 });
	turret2.PushBack({ 84,253,28,41 });
	turret2.PushBack({ 124,253,28,41 });
	turret2.PushBack({ 11,307,28,41 });
	turret2.PushBack({ 49,307,28,41 });
	turret2.PushBack({ 91,308,28,41 });
	turret2.PushBack({ 130,307,28,41 });
	turret2.PushBack({ 12,369,28,41 });
	turret2.PushBack({ 53,369,28,41 });

	turret2.speed = 0.25f;

	lastTime = 0;

	hitPoints = 3;

	score = 500;

	animation = &turret2;

	collider = App->collision->AddCollider({ 0, 0, 28, 41 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret2::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	currentTime = SDL_GetTicks();

	if (currentTime > (lastTime + 70)) {
		animation = &turret2;
		lastTime = 0;
	}

}

void Enemy_Turret2::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
		hitPoints -= 1;
}

uint Enemy_Turret2::getHitPoints() {
	return hitPoints;
}