#include "Application.h"
#include "Character_Tetsu.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"

Character_Tetsu::Character_Tetsu(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	idle.PushBack({ 216, 71, 20, 32 }); //1
	idle.PushBack({ 248, 71, 20, 32 }); //2
	idle.PushBack({ 280, 71, 20, 32 }); //3
	idle.PushBack({ 312, 71, 20, 32 }); //4

	idle.speed = 0.25f;

	// left animation
	right.PushBack({ 216, 104, 23, 32 });
	right.PushBack({ 249, 104, 23, 32 });
	right.PushBack({ 280, 104, 23, 32 });
	right.PushBack({ 313, 104, 23, 32 });
	right.speed = 0.25f;

	// right animation
	left.PushBack({ 212, 7, 23, 32 });
	left.PushBack({ 244, 7, 23, 32 });
	left.PushBack({ 277, 7, 23, 32 });
	left.PushBack({ 308, 7, 23, 32 });
	left.speed = 0.25f;

	collider = App->collision->AddCollider({ position.x, position.y, 23, 32 }, COLLIDER_PLAYER, (Module*)App->player);

	animation = &idle;

}

void Character_Tetsu::Move()
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

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		animation = &right;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 23)) {
			position.x = (SCREEN_WIDTH - 23);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		animation = &left;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 32) {
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 32;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		animation = &left;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		animation = &left;


	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &idle;

}

void Character_Tetsu::Move2()
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
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 23)) {
			position.x = (SCREEN_WIDTH - 23);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		animation = &left;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 32) {
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 32;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE;
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

void Character_Tetsu::Laser() {

}

void Character_Tetsu::OnCollision(Collider* collider) {

}