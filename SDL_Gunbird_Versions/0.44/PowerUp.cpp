#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"
#include "Path.h"

PowerUp::PowerUp(int x, int y) : Enemy(x, y)
{
	//Row 1 of the spritesheet
	anim.PushBack({ 11, 949, 22, 13 });
	anim.PushBack({ 36, 949, 22, 13 });
	anim.PushBack({ 61, 949, 22, 13 });
	anim.PushBack({ 86, 949, 22, 13 });
	anim.PushBack({ 111, 949, 22, 13 });
	//Row 2 of the spritesheet
	anim.PushBack({ 11, 965, 22, 13 });
	anim.PushBack({ 36, 965, 22, 13 });
	anim.PushBack({ 61, 965, 22, 13 });
	anim.PushBack({ 86, 965, 22, 13 });
	anim.PushBack({ 111, 965, 22, 13 });
	//Row 3 of the spritesheet
	anim.PushBack({ 11, 982, 22, 13 });
	anim.PushBack({ 36, 982, 22, 13 });
	anim.PushBack({ 61, 982, 22, 13 });
	anim.PushBack({ 86, 982, 22, 13 });
	anim.PushBack({ 111, 982, 22, 13 });
	//Row 4 of the spritesheet
	anim.PushBack({ 11, 1001, 22, 13 });
	anim.PushBack({ 36, 1001, 22, 13 });
	anim.PushBack({ 61, 1001, 22, 13 });
	anim.PushBack({ 86, 1001, 22, 13 });
	
	animation = &anim;
	anim.speed = 0.4f;


	position.x = x;
	position.y = y;

	collider = App->collision->AddCollider({ 0, 0, 22, 13 }, COLLIDER_TYPE::COLLIDER_POWER_UP, (Module*)App->enemies);

	up = true;
	left = true;
}

void PowerUp::Move()
{
	//Move up and right
	if (up == true)
		position.y -= 1;
	else
		position.y += 1;

	if (left == true)
		position.x -= 1;
	else
		position.x += 1;

	//When it hits the borders turn arround
	if (position.x < 0)
		left = false;

	if (position.x > SCREEN_WIDTH - 22)
		left = true;

	if (position.y < 0)
		up = false;

	if (position.y > SCREEN_HEIGHT - 13)
		up = true;
}
