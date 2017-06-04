#include "Application.h"
#include "Enemy_Boss.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"

Enemy_Boss::Enemy_Boss(int x, int y) : Enemy(x, y)
{
	boss_nomove.PushBack({ 0,0,0,0 });

	boss.PushBack({ 1133,321,154,231 });
	boss.PushBack({ 1343,325,154,231 });
	boss.PushBack({ 1534,328,154,231 });
	boss.speed = 0.25f;

	boss_red.PushBack({ 1359,641,154,231 });//RED
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });//RED
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });//RED
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });//RED
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.PushBack({ 1535,328,154,231 });
	boss_red.PushBack({ 1359,641,154,231 });//RED
	boss_red.PushBack({ 1133,321,154,231 });
	boss_red.PushBack({ 1342,325,154,231 });
	boss_red.speed = 0.25f;

	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1133,321,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1342,325,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1535,328,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1133,321,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1342,325,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1535,328,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1133,321,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1342,325,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1342,325,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1535,328,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1133,321,154,231 });
	boss_red2.PushBack({ 1359,641,154,231 });//RED
	boss_red2.PushBack({ 1342,325,154,231 });
	boss_red2.speed = 0.25f;

	boss_white.PushBack({ 1134,631,154,231 });
	boss_white.speed = 0.25f;
	boss_white.loop = true;

	lastTime = 0;

	hitPoints = 600;

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

	if (App->render->camera.y <= -21 * SCREEN_SIZE) {
		animation = &boss_nomove;
	}
		

	if (hit_animation == true) {
		animation = &boss_white;
		hit_animation = false;
	}

	if (hitPoints <= 40 && animation != &boss_white)
	{
		animation = &boss_red2;
	}

	if (hitPoints >= 40 && hitPoints <= 150 && animation != &boss_white)
	{
		animation = &boss_red;
	}


	if (time == 450) {
		App->particles->AddParticle(App->particles->shot_turret, position.x + 34, position.y + 105, -1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 62, position.y + 121, 0, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 82, position.y + 121, 0, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 117, position.y + 105, 1, 1, NULL, COLLIDER_ENEMY_SHOT);
	}


	if (time == 550) {
		App->particles->AddParticle(App->particles->shot_turret, position.x + 34, position.y + 105, -1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 62, position.y + 121, 0, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 82, position.y + 121, 0, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 117, position.y + 105, 1, 1, NULL, COLLIDER_ENEMY_SHOT);
	}

	if (time == 600) 
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 77, position.y, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 610)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 93, position.y + 2, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 620)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 107, position.y + 7, -1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 630)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 119, position.y + 14, -1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 640)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 131, position.y + 25, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 650)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 141, position.y + 37, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 660)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 146, position.y + 49, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 670)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 149, position.y + 63, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 680)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 149, position.y + 79, -2, 2, NULL, COLLIDER_ENEMY_SHOT);


	if (time == 710)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 147, position.y + 95, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 720)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 143, position.y + 102, -2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 730)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 138, position.y + 113, -1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 740)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 133, position.y + 120, -1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 750)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 128, position.y + 131, 0, 2, NULL, COLLIDER_ENEMY_SHOT);

	if (time == 780)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 73, position.y + 151, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 790)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 57, position.y + 148, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 800)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 42, position.y + 143, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 810)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 30, position.y + 137, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 820)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 129, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 830)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 12, position.y + 116, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 840)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 5, position.y + 104, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 850)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 2, position.y + 87, -1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 860)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 1, position.y + 76, -1, 2, NULL, COLLIDER_ENEMY_SHOT);


	if (time == 890)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 1, position.y + 88, 2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 900)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 0, position.y + 71, 2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 910)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 3, position.y + 59, 2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 920)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 5, position.y + 46, 2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 930)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 15, position.y + 32, 2, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 940)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 24, position.y + 20, 1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 950)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 36, position.y + 12, 1, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 960)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 50, position.y + 4, 0, 2, NULL, COLLIDER_ENEMY_SHOT);
	if (time == 970)
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 63, position.y + 1, 0, 2, NULL, COLLIDER_ENEMY_SHOT); 

	if (time == 1000)
		time = 400;

	time++;

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