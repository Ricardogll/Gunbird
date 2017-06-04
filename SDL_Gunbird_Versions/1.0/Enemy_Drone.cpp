#include "Application.h"
#include "Enemy_Drone.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"

Enemy_Drone::Enemy_Drone(int x, int y) : Enemy(x, y)
{
	drone.PushBack({ 272,144,32,35 });
	drone.PushBack({ 320,147,32,35 });
	drone.PushBack({ 375,151,32,35 });
	drone.PushBack({ 266,204,32,35 });
	drone.PushBack({ 224,148,32,35 });
	drone.PushBack({ 321,197,32,35 });
	drone.PushBack({ 377,197,32,35 });
	drone.speed = 0.25f;

	lastTime = 0;

	hitPoints = 2;

	score = 200;

	animation = &drone;

	collider = App->collision->AddCollider({ 0, 0, 32, 35 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Drone::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &drone;
	//currentTime = SDL_GetTicks();

	if (time == 100)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 10, position.y + 25, 0, 2, NULL, COLLIDER_ENEMY_SHOT);

	if (time == 800)
		time = 0;

	time++;

}

void Enemy_Drone::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
		hitPoints -= 1;
}

uint Enemy_Drone::getHitPoints() {
	return hitPoints;
}