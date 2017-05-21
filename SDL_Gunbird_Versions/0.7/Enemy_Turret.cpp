#include "Application.h"
#include "Enemy_Turret.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

Enemy_Turret::Enemy_Turret(int x, int y) : Enemy(x, y)
{
	turret.PushBack({ 20,8,32,32 });
	turret.PushBack({ 54,8,32,32 });
	turret.PushBack({ 88,8,32,32 });
	turret.PushBack({ 122,8,32,32 });
	turret.speed = 0.25f;

	turret_white.PushBack({ 161,8,33,33 });

	turret_red.PushBack({ 20,8,32,32 });
	turret_red.PushBack({ 160,47,33,33 }); //RED
	turret_red.PushBack({ 54,8,32,32 });
	turret_red.PushBack({ 88,8,32,32 });
	turret_red.PushBack({ 122,8,32,32 });
	turret_red.speed = 0.25f;

	hitPoints = 25;

	score = 500;

	animation = &turret;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret::Move()
{
	position = original_pos;

	animation = &turret;

	if (hit_animation == true) {
		animation = &turret_white;
		hit_animation = false;
	}

	if (hitPoints <= 10 && animation != &turret_white)
	{
		animation = &turret_red;
	}

	if (time == 250)
	{
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 6, -1, -1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 20, -1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 20, position.y + 20, 1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 20, position.y + 6, 1, -1, NULL, COLLIDER_ENEMY_SHOT);
	}
	
	if (time == 260)
	{
	App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, -1, 0.5, NULL, COLLIDER_ENEMY_SHOT);
	App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, 1, 0.5, NULL, COLLIDER_ENEMY_SHOT);
	App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 20, 0, -1, NULL, COLLIDER_ENEMY_SHOT);
	App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, 0, 1, NULL, COLLIDER_ENEMY_SHOT);
	}
	
	if (time == 350)
	{
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 6, -1, -1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 20, -1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 20, position.y + 20, 1, 1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 20, position.y + 6, 1, -1, NULL, COLLIDER_ENEMY_SHOT);
	
	}
	if (time == 360)
	{
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, -1, 0.75, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, 1, 0.75, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 20, -0.5, -1, NULL, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_turret, position.x + 6, position.y + 14, 0.5, 1, NULL, COLLIDER_ENEMY_SHOT);
		time = 0;
	}

	time++;


}

void Enemy_Turret::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
}

uint Enemy_Turret::getHitPoints() {
	return hitPoints;
}
