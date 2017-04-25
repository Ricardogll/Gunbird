#include "Application.h"
#include "Enemy_vase.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Vase::Enemy_Vase(int x, int y) : Enemy(x, y)
{
	vase.PushBack({ 23,163,32,49 });

	vase_white.PushBack({ 61,162,33,49 });

	vase_red.PushBack({ 23,163,32,49 });
	vase_red.PushBack({ 101,162,33,49 }); //RED
	vase_red.speed = 0.25f;

	lastTime = 0;

	hitPoints = 12;

	animation = &vase;

	collider = App->collision->AddCollider({ 0, 0, 32, 49 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Vase::Move() {
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &vase;

	if (hit_animation == true) {
		animation = &vase_white;
		hit_animation = false;
	}

	if (hitPoints <= 5 && animation != &vase_white)
	{
		animation = &vase_red;
	}
}

void Enemy_Vase::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
}

uint Enemy_Vase::getHitPoints() {
	return hitPoints;
}