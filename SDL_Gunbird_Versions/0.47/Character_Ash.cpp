#include "Application.h"
#include "Character_Ash.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"

Character_Ash::Character_Ash(int x, int y) : Character(x, y)
{
	// idle animation
	idle.PushBack({ 217, 223, 19, 32 }); //1
	idle.PushBack({ 246, 223, 19, 32 }); //2

	idle.speed = 0.2f;

	// left animation
	left.PushBack({ 219, 265, 17, 32 });
	left.PushBack({ 246, 265, 17, 32 });
	left.loop = false;
	left.speed = 0.2f;

	// more left animation
	mleft.PushBack({ 273, 265, 14, 32 });
	mleft.PushBack({ 297, 265, 14, 32 });
	mleft.loop = true;
	mleft.speed = 0.2f;

	// right animation
	right.PushBack({ 266, 307, 17, 32 });
	right.PushBack({ 293, 307, 17, 32 });
	right.loop = false;
	right.speed = 0.2f;

	// more right animation
	mright.PushBack({ 218, 307, 14, 32 });
	mright.PushBack({ 242, 307, 14, 32 });
	mright.loop = true;
	mright.speed = 0.2f;

	// death sprite
	death.PushBack({ 289, 395, 31, 26 });

	collider = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, (Module*)App->player);

	animation = &idle;

}

void Character_Ash::Move()
{
	animation = &idle;

	int speed = 8;

	if ((position.y < (abs(App->render->camera.y) / SCREEN_SIZE)))
		position.y = (abs(App->render->camera.y) / SCREEN_SIZE);

	else {
		if (movement == false) {
			position.y -= 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		animation = &right;
		animation = &mright;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 19)) {
			position.x = (SCREEN_WIDTH - 19);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		animation = &left;
		animation = &mleft;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE)) {
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 32) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 32;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		animation = &left;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		animation = &left;


	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &idle;
}

void Character_Ash::Laser() {

}

void Character_Ash::OnCollision(Collider* collider) {

}