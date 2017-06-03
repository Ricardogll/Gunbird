#include "Application.h"
#include "ModulePlayer.h"
#include "Enemy_Turret2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleBackgroundCastle.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define REACH_ANGLE 12.0f
#define CONVERT_ANGLE (180.0 / PI)

Enemy_Turret2::Enemy_Turret2(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 13,223,28,42 });
	front.PushBack({ 52,223,28,42 });
	front.PushBack({ 92,222,28,42 });
	front.PushBack({ 130,223,28,42 });
	front.PushBack({ 168,223,28,42 });
	front.PushBack({ 205,223,28,42 });
	front.speed = 0.25f;

	l1.PushBack({ 13,272,28,41 });
	l1.PushBack({ 52,272,28,41 });
	l1.PushBack({ 92,272,28,41 });
	l1.PushBack({ 130,273,28,41 });
	l1.PushBack({ 168,272,28,41 });
	l1.PushBack({ 205,273,28,41 });
	l1.speed = 0.25f;

	l2.PushBack({ 13,324,28,42 });
	l2.PushBack({ 52,325,28,42 });
	l2.PushBack({ 92,324,28,42 });
	l2.PushBack({ 130,325,28,42 });
	l2.PushBack({ 168,324,28,42 });
	l2.PushBack({ 205,325,28,42 });
	l2.speed = 0.25f;

	l3.PushBack({ 259,564,28,42});
	l3.PushBack({ 298,565,28,42 });
	l3.PushBack({ 338,564,28,42 });
	l3.PushBack({ 376,565,28,42 });
	l3.PushBack({ 414,564,28,42 });
	l3.PushBack({ 451,565,28,42 });
	l3.speed = 0.25f;


	l4.PushBack({ 259,515,28,42 });
	l4.PushBack({ 298,516,28,42 });
	l4.PushBack({ 338,515,28,42 });
	l4.PushBack({ 376,516,28,42 });
	l4.PushBack({ 414,516,28,42 });
	l4.PushBack({ 451,516,28,42 });
	l4.speed = 0.25f;

	l5.PushBack({ 259,468,28,42 });
	l5.PushBack({ 298,468,28,42 });
	l5.PushBack({ 338,468,28,42 });
	l5.PushBack({ 376,468,28,42 });
	l5.PushBack({ 414,468,28,42 });
	l5.PushBack({ 451,469,28,42 });
	l5.speed = 0.25f;

	l6.PushBack({ 259,419,28,42 });
	l6.PushBack({ 298,420,28,42 });
	l6.PushBack({ 338,419,28,42 });
	l6.PushBack({ 376,420,28,42 });
	l6.PushBack({ 414,419,28,42 });
	l6.PushBack({ 451,420,28,42 });
	l6.speed = 0.25f;

	l7.PushBack({ 259,373,28,42 });
	l7.PushBack({ 298,374,28,42 });
	l7.PushBack({ 338,373,28,42 });
	l7.PushBack({ 376,375,28,42 });
	l7.PushBack({ 414,373,28,42 });
	l7.PushBack({ 451,374,28,42 });
	l7.speed = 0.25f;

	l8.PushBack({ 258,329,28,42 });
	l8.PushBack({ 297,330,28,42 });
	l8.PushBack({ 337,329,28,42 });
	l8.PushBack({ 375,330,28,42 });
	l8.PushBack({ 413,329,28,42 });
	l8.PushBack({ 450,330,28,42 });
	l8.speed = 0.25f;

	l9.PushBack({ 524,955,28,42 });
	l9.PushBack({ 563,955,28,42 });
	l9.PushBack({ 603,955,28,42 });
	l9.PushBack({ 641,955,28,42 });
	l9.PushBack({ 679,955,28,42 });
	l9.PushBack({ 716,956,28,42 });
	l9.speed = 0.25f;

	l10.PushBack({ 524,906,28,42 });
	l10.PushBack({ 563,906,28,42 });
	l10.PushBack({ 603,906,28,42 });
	l10.PushBack({ 641,906,28,42 });
	l10.PushBack({ 679,906,28,42 });
	l10.PushBack({ 716,906,28,42 });
	l10.speed = 0.25f;

	l11.PushBack({ 524,859,28,42 });
	l11.PushBack({ 563,860,28,42 });
	l11.PushBack({ 603,859,28,42 });
	l11.PushBack({ 641,860,28,42 });
	l11.PushBack({ 679,859,28,42 });
	l11.PushBack({ 716,860,28,42 });
	l11.speed = 0.25f;

	l12.PushBack({ 524,808,28,42 });
	l12.PushBack({ 563,808,28,42 });
	l12.PushBack({ 603,808,28,42 });
	l12.PushBack({ 641,809,28,42 });
	l12.PushBack({ 679,808,28,42 });
	l12.PushBack({ 716,809,28,42 });
	l12.speed = 0.25f;

	l13.PushBack({ 524,763,28,42 });
	l13.PushBack({ 563,764,28,42 });
	l13.PushBack({ 603,763,28,42 });
	l13.PushBack({ 641,764,28,42 });
	l13.PushBack({ 679,763,28,42 });
	l13.PushBack({ 716,764,28,42 });
	l13.speed = 0.25f;

	l14.PushBack({ 524,717,28,42 });
	l14.PushBack({ 563,718,28,42 });
	l14.PushBack({ 603,717,28,42 });
	l14.PushBack({ 641,718,28,42 });
	l14.PushBack({ 678,717,28,42 });
	l14.PushBack({ 716,718,28,42 });
	l14.speed = 0.25f;

	back.PushBack({ 261,887,28,42 });
	back.PushBack({ 300,887,28,42 });
	back.PushBack({ 340,887,28,42 });
	back.PushBack({ 378,887,28,42 });
	back.PushBack({ 416,887,28,42 });
	back.PushBack({ 453,887,28,42 });
	back.speed = 0.25f;

	r1.PushBack({ 261,839,28,42 });
	r1.PushBack({ 300,839,28,42 });
	r1.PushBack({ 340,839,28,42 });
	r1.PushBack({ 378,839,28,42 });
	r1.PushBack({ 416,839,28,42 });
	r1.PushBack({ 453,839,28,42 });
	r1.speed = 0.25f;

	r2.PushBack({ 261,795,28,42 });
	r2.PushBack({ 300,795,28,42 });
	r2.PushBack({ 340,795,28,42 });
	r2.PushBack({ 378,795,28,42 });
	r2.PushBack({ 416,795,28,42 });
	r2.PushBack({ 453,795,28,42 });
	r2.speed = 0.25f;

	r3.PushBack({ 260,744,28,42 });
	r3.PushBack({ 299,744,28,42 });
	r3.PushBack({ 339,744,28,42 });
	r3.PushBack({ 377,744,28,42 });
	r3.PushBack({ 415,744,28,42 });
	r3.PushBack({ 452,744,28,42 });
	r3.speed = 0.25f;

	r4.PushBack({ 261,698,28,42 });
	r4.PushBack({ 300,698,28,42 });
	r4.PushBack({ 340,698,28,42 });
	r4.PushBack({ 378,698,28,42 });
	r4.PushBack({ 416,698,28,42 });
	r4.PushBack({ 453,698,28,42 });
	r4.speed = 0.25f;

	r5.PushBack({ 261,656,28,42 });
	r5.PushBack({ 300,656,28,42 });
	r5.PushBack({ 340,656,28,42 });
	r5.PushBack({ 378,656,28,42 });
	r5.PushBack({ 416,656,28,42 });
	r5.PushBack({ 453,656,28,42 });
	r5.speed = 0.25f;

	r6.PushBack({ 14,479,28,42 });
	r6.PushBack({ 53,479,28,42 });
	r6.PushBack({ 93,479,28,42 });
	r6.PushBack({ 131,479,28,42 });
	r6.PushBack({ 169,479,28,42 });
	r6.PushBack({ 206,479,28,42 });
	r6.speed = 0.25f;

	r7.PushBack({ 14,522,28,42 });
	r7.PushBack({ 53,522,28,42 });
	r7.PushBack({ 93,522,28,42 });
	r7.PushBack({ 131,522,28,42 });
	r7.PushBack({ 169,522,28,42 });
	r7.PushBack({ 206,522,28,42 });
	r7.speed = 0.25f;

	r8.PushBack({ 14,565,28,42 });
	r8.PushBack({ 53,565,28,42 });
	r8.PushBack({ 93,565,28,42 });
	r8.PushBack({ 131,565,28,42 });
	r8.PushBack({ 169,565,28,42 });
	r8.PushBack({ 206,565,28,42 });
	r8.speed = 0.25f;

	r9.PushBack({ 14,608,28,42 });
	r9.PushBack({ 53,608,28,42 });
	r9.PushBack({ 93,608,28,42 });
	r9.PushBack({ 131,608,28,42 });
	r9.PushBack({ 169,608,28,42 });
	r9.PushBack({ 206,608,28,42 });
	r9.speed = 0.25f;

	r10.PushBack({ 14,650,28,42 });
	r10.PushBack({ 53,650,28,42 });
	r10.PushBack({ 93,650,28,42 });
	r10.PushBack({ 131,650,28,42 });
	r10.PushBack({ 169,650,28,42 });
	r10.PushBack({ 206,650,28,42 });
	r10.speed = 0.25f;

	r11.PushBack({ 14,693,28,42 });
	r11.PushBack({ 53,693,28,42 });
	r11.PushBack({ 93,693,28,42 });
	r11.PushBack({ 131,693,28,42 });
	r11.PushBack({ 169,693,28,42 });
	r11.PushBack({ 206,693,28,42 });
	r11.speed = 0.25f;

	r12.PushBack({ 14,736,28,42 });
	r12.PushBack({ 53,736,28,42 });
	r12.PushBack({ 93,736,28,42 });
	r12.PushBack({ 131,736,28,42 });
	r12.PushBack({ 169,736,28,42 });
	r12.PushBack({ 206,736,28,42 });
	r12.speed = 0.25f;

	r13.PushBack({ 14,793,28,42 });
	r13.PushBack({ 53,793,28,42 });
	r13.PushBack({ 93,793,28,42 });
	r13.PushBack({ 131,793,28,42 });
	r13.PushBack({ 169,793,28,42 });
	r13.PushBack({ 206,793,28,42 });
	r13.speed = 0.25f;

	r14.PushBack({ 14,844,28,42 });
	r14.PushBack({ 53,844,28,42 });
	r14.PushBack({ 93,844,28,42 });
	r14.PushBack({ 131,844,28,42 });
	r14.PushBack({ 169,844,28,42 });
	r14.PushBack({ 206,844,28,42 });
	r14.speed = 0.25f;

	r15.PushBack({ 14,889,28,42 });
	r15.PushBack({ 53,889,28,42 });
	r15.PushBack({ 93,889,28,42 });
	r15.PushBack({ 131,889,28,42 });
	r15.PushBack({ 169,889,28,42 });
	r15.PushBack({ 206,889,28,42 });
	r15.speed = 0.25f;




	turret2_white.PushBack({ 148,965,29,41 });

	lastTime = 0;

	hitPoints = 12;

	score = 500;

	animation = &front;

	collider = App->collision->AddCollider({ 0, 0, 28, 41 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret2::Move()
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
				animation = &r15;
			else if (angle >= REACH_ANGLE *(3 / 2) && angle < REACH_ANGLE  * (5 / 2))
				animation = &r14;
			else if (angle >= REACH_ANGLE *(5 / 2) && angle < REACH_ANGLE  * (7 / 2))
				animation = &r13;
			else if (angle >= REACH_ANGLE *(7 / 2) && angle < REACH_ANGLE  * (9 / 2))
				animation = &r12;
			else if (angle >= REACH_ANGLE *(9 / 2) && angle < REACH_ANGLE  * (11 / 2))
				animation = &r11;
			else if (angle >= REACH_ANGLE *(11 / 2) && angle < REACH_ANGLE  * (13 / 2))
				animation = &r10;
			else if (angle >= REACH_ANGLE *(13 / 2) && angle < REACH_ANGLE  * (15 / 2))
				animation = &r9;
			else if (angle >= REACH_ANGLE *(15 / 2) && angle < REACH_ANGLE  * (17 / 2))
				animation = &r8;
			else if (angle >= REACH_ANGLE *(17 / 2) && angle < REACH_ANGLE  * (19 / 2))
				animation = &r7;
			else if (angle >= REACH_ANGLE *(19 / 2) && angle < REACH_ANGLE  * (21 / 2))
				animation = &r6;
			else if (angle >= REACH_ANGLE *(21 / 2) && angle < REACH_ANGLE  * (23 / 2))
				animation = &r5;
			else if (angle >= REACH_ANGLE *(23 / 2) && angle < REACH_ANGLE  * (25 / 2))
				animation = &r4;
			else if (angle >= REACH_ANGLE *(25 / 2) && angle < REACH_ANGLE  * (27 / 2))
				animation = &r3;
			else if (angle >= REACH_ANGLE *(27 / 2) && angle < REACH_ANGLE  * (29 / 2))
				animation = &r2;
			else if (angle >= REACH_ANGLE *(29 / 2) && angle < REACH_ANGLE * 15)
				animation = &r1;
			else if (angle >= REACH_ANGLE * 15 && angle < REACH_ANGLE * 16)
				animation = &back;
			else 
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
				animation = &l2;
			else if (angle >= REACH_ANGLE *(5 / 2) && angle < REACH_ANGLE  * (7 / 2))
				animation = &l3;
			else if (angle >= REACH_ANGLE *(7 / 2) && angle < REACH_ANGLE  * (9 / 2))
				animation = &l4;
			else if (angle >= REACH_ANGLE *(9 / 2) && angle < REACH_ANGLE  * (11 / 2))
				animation = &l5;
			else if (angle >= REACH_ANGLE *(11 / 2) && angle < REACH_ANGLE  * (13 / 2))
				animation = &l6;
			else if (angle >= REACH_ANGLE *(13 / 2) && angle < REACH_ANGLE  * (15 / 2))
				animation = &l7;
			else if (angle >= REACH_ANGLE *(15 / 2) && angle < REACH_ANGLE  * (17 / 2))
				animation = &l8;
			else if (angle >= REACH_ANGLE *(17 / 2) && angle < REACH_ANGLE  * (19 / 2))
				animation = &l9;
			else if (angle >= REACH_ANGLE *(19 / 2) && angle < REACH_ANGLE  * (21 / 2))
				animation = &l10;
			else if (angle >= REACH_ANGLE *(21 / 2) && angle < REACH_ANGLE  * (23 / 2))
				animation = &l11;
			else if (angle >= REACH_ANGLE *(23 / 2) && angle < REACH_ANGLE  * (25 / 2))
				animation = &l12;
			else if (angle >= REACH_ANGLE *(25 / 2) && angle < REACH_ANGLE  * (27 / 2))
				animation = &l13;
			else if (angle >= REACH_ANGLE *(27 / 2) && angle < REACH_ANGLE  * (29 / 2))
				animation = &l14;
			else if (angle >= REACH_ANGLE * 15 && angle < REACH_ANGLE * 16)
				animation = &back;
			else
				animation = &back;
		}
	}

	if (hit_animation == true) {
		animation = &turret2_white;
		hit_animation = false;
	}

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
	if (time ==1200)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, App->background3->res_x[i], App->background3->res_y[i], NULL, COLLIDER_ENEMY_SHOT);

		time = 0;
	}
	time++;

}

void Enemy_Turret2::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
}

uint Enemy_Turret2::getHitPoints() {
	return hitPoints;
}