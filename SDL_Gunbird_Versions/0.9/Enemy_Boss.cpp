#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	boss_nomove.PushBack({ 0,0,0,0 });

	boss.PushBack({ 1133,321,154,231 });
	boss.PushBack({ 1343,325,154,231 });
	boss.PushBack({ 1534,328,154,231 });
	boss.speed = 0.25f;

	boss_red.PushBack({ 1359,641,154,231 }); //RED
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.speed = 0.25f;

	boss_white.PushBack({ 1134,631,154,231 });
	boss_white.speed = 0.25f;
	boss_white.loop = true;

	lastTime = 0;

	hitPoints = 400;

	score = 2500;

	animation = &boss;

	collider = App->collision->AddCollider({ 0, 0, 153, 161 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Boss::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &boss;

	if (App->render->camera.y * SCREEN_SIZE >= -21) {
		animation = &boss_nomove;
	}
		

	if (hit_animation == true) {
		animation = &boss_white;
		hit_animation = false;
	}

	if (hitPoints <= 15 && animation != &boss_white)
	{
		animation = &boss_red;
	}

}

void Enemy_Boss::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}

}

uint Enemy_Boss::getHitPoints() {
	return hitPoints;
}