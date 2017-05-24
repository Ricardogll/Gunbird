#include "Application.h"
#include "Enemy_Robot.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "SDL\include\SDL_timer.h"
#include "ModuleBackgroundCastle.h"

#define PI 3.14159265

Enemy_Robot::Enemy_Robot(int x, int y) : Enemy(x, y)
{
	robot.PushBack({ 685,123,85,74 });
	robot.PushBack({ 583,23,85,74 });
	robot.PushBack({ 689,21,85,74 });
	robot.PushBack({ 794,23,76,74 });
	robot.PushBack({ 895,24,76,74 });
	robot.PushBack({ 795,124,76,74 });
	
	

	robot.speed = 0.5f;

	lastTime = 0;

	hitPoints = 3;

	score = 500;

	animation = &robot;

	collider = App->collision->AddCollider({ 0, 0, 76, 74 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
}

void Enemy_Robot::Move()
{
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &robot;

	

	

}

void Enemy_Robot::OnCollision(Collider* collider) {
	if (collider->type == COLLIDER_TYPE::COLLIDER_PLAYER_SHOT) {
		hit_animation = true;
		hitPoints -= 1;
	}
}

uint Enemy_Robot::getHitPoints() {
	return hitPoints;
}