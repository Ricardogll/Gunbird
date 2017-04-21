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

	hitPoints = 25;

	animation = &turret;

	collider = App->collision->AddCollider({ 0, 0, 32, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Turret::Move()
{
	position = original_pos;

	if (time == 100)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, -1, -1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 20, -1, 1, COLLIDER_ENEMY_SHOT); 
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 20, 1, 1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 6, 1, -1, COLLIDER_ENEMY_SHOT);
	}
	if (time == 200)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, -1, -1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 20, -1, 1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 20, 1, 1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 6, 1, -1, COLLIDER_ENEMY_SHOT);
	}
	if (time == 300)
	{
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 6, -1, -1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 6, position.y + 20, -1, 1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 20, 1, 1, COLLIDER_ENEMY_SHOT);
		App->particles->AddParticle(App->particles->shot_enemy, position.x + 20, position.y + 6, 1, -1, COLLIDER_ENEMY_SHOT);
		time = 0;
	}
	time++;


}

void Enemy_Turret::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT)
	hitPoints -= 1;
}

uint Enemy_Turret::getHitPoints() {
	return hitPoints;
}
