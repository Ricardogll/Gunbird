#include "Application.h"
#include "Enemy_Balloon.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleParticles.h"

Enemy_Balloon::Enemy_Balloon(int x, int y) : Enemy(x, y)
{
	balloon.PushBack({ 212,6,43,53 });
	balloon.PushBack({ 265,6,42,53 });
	balloon.PushBack({ 317,6,42,53 });
	balloon.PushBack({ 369,6,43,53 });
	balloon.PushBack({ 420,6,42,53 });
	balloon.speed = 0.25f;

	balloon_red.PushBack({ 212,6,43,53 });
	balloon_red.PushBack({ 521,6,42,53 }); //RED
	balloon_red.PushBack({ 265,6,42,53 });
	balloon_red.PushBack({ 317,6,42,53 });
	balloon_red.PushBack({ 369,6,43,53 });
	balloon_red.PushBack({ 420,6,42,53 });
	balloon_red.PushBack({ 212,6,43,53 });
	balloon_red.PushBack({ 265,6,42,53 });
	balloon_red.PushBack({ 317,6,42,53 });
	balloon_red.PushBack({ 369,6,43,53 });
	balloon_red.PushBack({ 420,6,42,53 });
	balloon_red.PushBack({ 212,6,43,53 });
	balloon_red.PushBack({ 521,6,42,53 });
	balloon_red.PushBack({ 265,6,42,53 });
	balloon_red.PushBack({ 317,6,42,53 });
	balloon_red.PushBack({ 369,6,43,53 });
	balloon_red.PushBack({ 420,6,42,53 });
	balloon_red.speed = 0.25f;

	//balloon.PushBack({ 470,6,42,53 });

//	balloon.PushBack({ 521,6,42,53 });

	balloon_white.PushBack({ 470,6,42,53 });
	balloon_white.speed = 0.25f;
	balloon_white.loop = true;

	lastTime = 0;

	hitPoints = 80;

	score = 500;

	animation = &balloon;

	collider = App->collision->AddCollider({ 0, 0, 43, 53 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Balloon::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &balloon;

	if (hit_animation == true) {
		animation = &balloon_white;
		hit_animation = false;
	}

	if (hitPoints <= 15 && animation != &balloon_white)
	{
		animation = &balloon_red;
	}

	if (time == 100) {
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 8, position.y + 48, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 35, position.y + 48, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	}

	if (time == 400)
		time = 0;

	time++;

}

void Enemy_Balloon::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
	
}

uint Enemy_Balloon::getHitPoints() {
	return hitPoints;
}

