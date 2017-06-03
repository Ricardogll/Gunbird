#include "Application.h"
#include "ModulePlayer.h"
#include "Enemy_Turret3.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleBackgroundCastle.h"
#include "SDL\include\SDL_timer.h"

#define PI 3.14159265 
#define REACH_ANGLE 12.0f
#define CONVERT_ANGLE (180.0 / PI)

Enemy_Turret3::Enemy_Turret3(int x, int y) : Enemy(x, y)
{
	front.PushBack({ 1028,27,33,40 });
	front.speed = 0.25f;

	r1.PushBack({ 1066,27,37,40 });
	r1.speed = 0.25f;
	r2.PushBack({ 1104,27,37,40 });
	r2.speed = 0.25f;
	r3.PushBack({ 1142,27,39,40 });
	r3.speed = 0.25f;
	r4.PushBack({ 1181,27,39,40 });
	r4.speed = 0.25f;
	r5.PushBack({ 1223,27,39,40 });
	r5.speed = 0.25f;
	r6.PushBack({ 1266,27,39,40 });
	r6.speed = 0.25f;
	r7.PushBack({ 1309,27,39,40 });
	r7.speed = 0.25f;
	r8.PushBack({ 1351,27,39,40 });
	r8.speed = 0.25f;
	r9.PushBack({ 1392,27,39,40 });
	r9.speed = 0.25f;
	r10.PushBack({ 1435,27,39,40 });
	r10.speed = 0.25f;
	r11.PushBack({ 1478,27,39,40 });
	r11.speed = 0.25f;
	r12.PushBack({ 1522,27,39,40 });
	r12.speed = 0.25f;
	r13.PushBack({ 1027,73,39,40 });
	r13.speed = 0.25f;
	r14.PushBack({ 1068,73,39,40 });
	r14.speed = 0.25f;
	r15.PushBack({ 1107,73,37,40 });
	r15.speed = 0.25f;

	back.PushBack({ 1145,73,37,40 });
	back.speed = 0.25f;
	//
	l1.PushBack({ 1232,119,39,40 });
	l1.speed = 0.25f;
	l2.PushBack({ 1193,119,39,40 });
	l2.speed = 0.25f;
	l3.PushBack({ 1153,119,39,40 });
	l3.speed = 0.25f;
	l4.PushBack({ 1111,119,39,40 });
	l4.speed = 0.25f;
	l5.PushBack({ 1068,119,39,40 });
	l5.speed = 0.25f;
	l6.PushBack({ 1024,119,39,40 });
	l6.speed = 0.25f;
	l7.PushBack({ 1514,73,39,40 });
	l7.speed = 0.25f;
	l8.PushBack({ 1473,73,39,40 });
	l8.speed = 0.25f;
	l9.PushBack({ 1430,73,39,40 });
	l9.speed = 0.25f;
	l10.PushBack({ 1386,73,39,40 });
	l10.speed = 0.25f;
	l11.PushBack({ 1343,73,39,40 });
	l11.speed = 0.25f;
	l12.PushBack({ 1301,73,39,40 });
	l12.speed = 0.25f;
	l13.PushBack({ 1259,73,39,40 });
	l13.speed = 0.25f;
	l14.PushBack({ 1220,73,39,40 });
	l14.speed = 0.25f;
	l15.PushBack({ 1183,73,37,40 });
	l15.speed = 0.25f;

	lastTime = 0;

	hitPoints = 45;

	score = 500;

	animation = &front;

	collider = App->collision->AddCollider({ 0, 0, 37, 37 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret3::Move()
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
			if (angle >= 0 && angle < REACH_ANGLE  / 2)
				animation = &front;
			else if (angle >= REACH_ANGLE  / 2 && angle < REACH_ANGLE  * (3 / 2))
				animation = &r1;
			else if (angle >= REACH_ANGLE *(3 / 2) && angle < REACH_ANGLE  * (5 / 2))
				animation = &r2;
			else if (angle >= REACH_ANGLE *(5 / 2) && angle < REACH_ANGLE  * (7 / 2))
				animation = &r3;
			else if (angle >= REACH_ANGLE *(7 / 2) && angle < REACH_ANGLE  * (9 / 2))
				animation = &r4;
			else if (angle >= REACH_ANGLE *(9 / 2) && angle < REACH_ANGLE  * (11 / 2))
				animation = &r5;
			else if (angle >= REACH_ANGLE *(11 / 2) && angle < REACH_ANGLE  * (13 / 2))
				animation = &r6;
			else if (angle >= REACH_ANGLE *(13 / 2) && angle < REACH_ANGLE  * (15 / 2))
				animation = &r7;
			else if (angle >= REACH_ANGLE *(15 / 2) && angle < REACH_ANGLE  * (17 / 2))
				animation = &r8;
			else if (angle >= REACH_ANGLE *(17 / 2) && angle < REACH_ANGLE  * (19 / 2))
				animation = &r9;
			else if (angle >= REACH_ANGLE *(19 / 2) && angle < REACH_ANGLE  * (21 / 2))
				animation = &r10;
			else if (angle >= REACH_ANGLE *(21 / 2) && angle < REACH_ANGLE  * (23 / 2))
				animation = &r11;
			else if (angle >= REACH_ANGLE *(23 / 2) && angle < REACH_ANGLE  * (25 / 2))
				animation = &r12;
			else if (angle >= REACH_ANGLE *(25 / 2) && angle < REACH_ANGLE  * (27 / 2))
				animation = &r13;
			else if (angle >= REACH_ANGLE *(27 / 2) && angle < REACH_ANGLE  * (29 / 2))
				animation = &r14;
			else if (angle >= REACH_ANGLE *(29 / 2) && angle < REACH_ANGLE  * 15)
				animation = &r15;
			else if (angle >= REACH_ANGLE * 15 && angle < REACH_ANGLE  * 16)
				animation = &back;
			}
		
			else
			{
			right = false;

			if (angle >= 0 && angle < REACH_ANGLE  / 2)
				animation = &front;
			else if (angle >= REACH_ANGLE  / 2 && angle < REACH_ANGLE  * (3 / 2))
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
			else if (angle >= REACH_ANGLE *(29 / 2) && angle < REACH_ANGLE  * 15)
				animation = &l15;
			else if (angle >= REACH_ANGLE  * 15 && angle < REACH_ANGLE  * 16)
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

void Enemy_Turret3::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}

}

uint Enemy_Turret3::getHitPoints() {
	return hitPoints;
}
