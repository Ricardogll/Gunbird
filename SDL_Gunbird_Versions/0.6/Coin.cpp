#include "Application.h"
#include "Coin.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "SDL\include\SDL_timer.h"

Coin::Coin(int x, int y) : Enemy(x, y)
{
	coin.PushBack({ 424,262,12,16 });
	coin.PushBack({ 447,262,12,16 });
	coin.PushBack({ 472,263,12,16 });
	coin.PushBack({ 501,264,12,16 });
	coin.PushBack({ 427,289,12,16 });
	coin.PushBack({ 453,291,12,16 });
	coin.PushBack({ 477,291,12,16 });
	coin.PushBack({ 500,292,12,16 });
	coin.speed = 0.09f;

	animation = &coin;

	score = 200;
	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 12, 16 }, COLLIDER_TYPE::COLLIDER_COIN, NULL, (Module*)App->enemies);
}
