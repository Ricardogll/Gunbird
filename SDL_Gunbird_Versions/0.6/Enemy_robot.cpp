#include "Application.h"
#include "Enemy_Robot.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"

Enemy_Robot::Enemy_Robot(int x, int y) : Enemy(x, y)
{
	robot.PushBack({ 690,124,76,73 });
	robot.PushBack({ 583,23,76,73 });
	robot.PushBack({ 689,21,76,73 });
	robot.PushBack({ 583,124,76,73 });
	robot.speed = 0.25f;

	lastTime = 0;
	animation = &robot;

	collider = App->collision->AddCollider({ 0, 0, 76, 73 }, COLLIDER_TYPE::COLLIDER_ENEMY, NULL, (Module*)App->enemies);

	original_pos.y = y;
	original_pos.x = x;
	
}

void Enemy_Robot::Move() {
	position = original_pos + path.GetCurrentPosition(&animation);

	animation = &robot;

	

}