#include "Application.h"
#include "ModulePlayer.h"
#include "Enemy_Rcannon.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleBackgroundCastle.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define REACH_ANGLE 12.0f
#define CONVERT_ANGLE (180.0 / PI)

Enemy_Rcannon::Enemy_Rcannon(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 588,233,16,18 });
	front.speed = 0.25f;

	r1.PushBack({ 608,233,16,18 });
	r1.speed = 0.25f;
	r2.PushBack({ 628,233,16,18 });
	r2.speed = 0.25f;
	r3.PushBack({ 650,233,16,18 });
	r3.speed = 0.25f;
	r4.PushBack({ 671,233,16,18 });
	r4.speed = 0.25f;
	r5.PushBack({ 694,233,16,18 });
	r5.speed = 0.25f;
	r6.PushBack({ 716,233,16,18 });
	r6.speed = 0.25f;
	r7.PushBack({ 740,233,16,18 });
	r7.speed = 0.25f;

	back.PushBack({ 763,233,16,18 });
	back.speed = 0.25f;
	//
	l1.PushBack({ 923,233,16,18 });
	l1.speed = 0.25f;
	l2.PushBack({ 899,233,16,18 });
	l2.speed = 0.25f;
	l3.PushBack({ 875,233,16,18 });
	l3.speed = 0.25f;
	l4.PushBack({ 851,233,16,18 });
	l4.speed = 0.25f;
	l5.PushBack({ 828,233,16,18 });
	l5.speed = 0.25f;
	l6.PushBack({ 806,233,16,18 });
	l6.speed = 0.25f;
	l7.PushBack({ 784,233,16,18 });
	l7.speed = 0.25f;

	lastTime = 0;

	hitPoints = 45;

	score = 500;

	animation = &front;

	collider = App->collision->AddCollider({ 0, 0, 16, 18 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Rcannon::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	float deltaX = (App->player->characters[0]->position.x - (position.x + 15));
	float deltaY = (App->player->characters[0]->position.y - (position.y + 21));
	float angle;

	if (deltaY != 0)
	{
		angle = atan2(deltaX, deltaY);
		angle *= CONVERT_ANGLE;

		if (angle < 0) {
			angle = angle * -1;
			right = true;
		}

		if (!right)
		{
			if (angle >= 0 && angle < REACH_ANGLE / 2)
				animation = &front;
			else if (angle >= REACH_ANGLE / 2 && angle < REACH_ANGLE  * (3 / 2))
				animation = &r1;
			else if (angle >= REACH_ANGLE *(3 / 2) && angle < REACH_ANGLE  * (5 / 2))
				animation = &r1;
			else if (angle >= REACH_ANGLE *(5 / 2) && angle < REACH_ANGLE  * (7 / 2))
				animation = &r2;
			else if (angle >= REACH_ANGLE *(7 / 2) && angle < REACH_ANGLE  * (9 / 2))
				animation = &r2;
			else if (angle >= REACH_ANGLE *(9 / 2) && angle < REACH_ANGLE  * (11 / 2))
				animation = &r3;
			else if (angle >= REACH_ANGLE *(11 / 2) && angle < REACH_ANGLE  * (13 / 2))
				animation = &r3;
			else if (angle >= REACH_ANGLE *(13 / 2) && angle < REACH_ANGLE  * (15 / 2))
				animation = &r4;
			else if (angle >= REACH_ANGLE *(15 / 2) && angle < REACH_ANGLE  * (17 / 2))
				animation = &r4;
			else if (angle >= REACH_ANGLE *(17 / 2) && angle < REACH_ANGLE  * (19 / 2))
				animation = &r5;
			else if (angle >= REACH_ANGLE *(19 / 2) && angle < REACH_ANGLE  * (21 / 2))
				animation = &r5;
			else if (angle >= REACH_ANGLE *(21 / 2) && angle < REACH_ANGLE  * (23 / 2))
				animation = &r6;
			else if (angle >= REACH_ANGLE *(23 / 2) && angle < REACH_ANGLE  * (25 / 2))
				animation = &r6;
			else if (angle >= REACH_ANGLE *(25 / 2) && angle < REACH_ANGLE  * (27 / 2))
				animation = &r7;
			else if (angle >= REACH_ANGLE *(27 / 2) && angle < REACH_ANGLE  * (29 / 2))
				animation = &r7;
			else if (angle >= REACH_ANGLE *(29 / 2) && angle < REACH_ANGLE * 15)
				animation = &back;
			else if (angle >= REACH_ANGLE * 15 && angle < REACH_ANGLE * 16)
				animation = &back;
		}

		else
		{
			right = false;

			if (angle >= 0 && angle < REACH_ANGLE / 2)
				animation = &front;
			else if (angle >= REACH_ANGLE / 2 && angle < REACH_ANGLE  * (3 / 2))
				animation = &l1;
			else if (angle >= REACH_ANGLE *(3 / 2) && angle < REACH_ANGLE  * (5 / 2))
				animation = &l1;
			else if (angle >= REACH_ANGLE *(5 / 2) && angle < REACH_ANGLE  * (7 / 2))
				animation = &l2;
			else if (angle >= REACH_ANGLE *(7 / 2) && angle < REACH_ANGLE  * (9 / 2))
				animation = &l2;
			else if (angle >= REACH_ANGLE *(9 / 2) && angle < REACH_ANGLE  * (11 / 2))
				animation = &l3;
			else if (angle >= REACH_ANGLE *(11 / 2) && angle < REACH_ANGLE  * (13 / 2))
				animation = &l3;
			else if (angle >= REACH_ANGLE *(13 / 2) && angle < REACH_ANGLE  * (15 / 2))
				animation = &l4;
			else if (angle >= REACH_ANGLE *(15 / 2) && angle < REACH_ANGLE  * (17 / 2))
				animation = &l4;
			else if (angle >= REACH_ANGLE *(17 / 2) && angle < REACH_ANGLE  * (19 / 2))
				animation = &l5;
			else if (angle >= REACH_ANGLE *(19 / 2) && angle < REACH_ANGLE  * (21 / 2))
				animation = &l5;
			else if (angle >= REACH_ANGLE *(21 / 2) && angle < REACH_ANGLE  * (23 / 2))
				animation = &l6;
			else if (angle >= REACH_ANGLE *(23 / 2) && angle < REACH_ANGLE  * (25 / 2))
				animation = &l6;
			else if (angle >= REACH_ANGLE *(25 / 2) && angle < REACH_ANGLE  * (27 / 2))
				animation = &l7;
			else if (angle >= REACH_ANGLE *(27 / 2) && angle < REACH_ANGLE  * (29 / 2))
				animation = &l7;
			else if (angle >= REACH_ANGLE *(29 / 2) && angle < REACH_ANGLE * 15)
				animation = &back;
			else if (angle >= REACH_ANGLE * 15 && angle < REACH_ANGLE * 16)
				animation = &back;
		}
	}

	/*if (hit_animation == true) {
	animation = &balloon_white;
	hit_animation = false;
	}*/

	/*if (hitPoints <= 15 && animation != &balloon_white)
	{
	animation = &balloon_red;
	}*/
	int i = id;

	if (time == 400)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, App->background3->res_x[i], App->background3->res_y[i], NULL, COLLIDER_ENEMY_SHOT);

	}
	if (time == 800)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, App->background3->res_x[i], App->background3->res_y[i], NULL, COLLIDER_ENEMY_SHOT);

	}
	if (time == 1200)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, App->background3->res_x[i], App->background3->res_y[i], NULL, COLLIDER_ENEMY_SHOT);

		time = 0;
	}
	time++;
}

void Enemy_Rcannon::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}

}

uint Enemy_Rcannon::getHitPoints() {
	return hitPoints;
}