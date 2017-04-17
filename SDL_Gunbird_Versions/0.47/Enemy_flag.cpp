#include "Application.h"
#include "Enemy_Flag.h"
#include "ModuleCollision.h"
#include "SDL\include\SDL_timer.h"

Enemy_Flag::Enemy_Flag(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 745,539,64,21});
	fly.PushBack({ 821,541,64,21 });
	fly.PushBack({ 745,565,64,21 });
	fly.PushBack({ 821,570,64,21 });
	fly.PushBack({ 745,590,64,21 });
	fly.PushBack({ 821,597,64,21 });
	fly.PushBack({ 745,615,64,21 });
	fly.speed = 0.2f;
	lastTime = 0;

	hitPoints = 25;

	animation = &fly;


	original_pos.y = y;
	original_pos.x = x;
}
uint Enemy_Flag::getHitPoints() {
	return hitPoints;
}