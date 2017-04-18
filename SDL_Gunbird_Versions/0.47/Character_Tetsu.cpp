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
	idle.PushBack({ 574, 0, 26, 37 }); //1
	idle.PushBack({ 614, 0, 26, 37 }); //2
	idle.PushBack({ 652, 0, 30, 37 }); //3
	idle.PushBack({ 694, 0, 26, 37 }); //4
	idle.PushBack({ 732, 0, 30, 37 }); //5
	idle.PushBack({ 574, 47, 26, 37 }); //6
	idle.PushBack({ 612, 47, 30, 37 }); //7
	idle.PushBack({ 654, 47, 26, 37 }); //8
	idle.PushBack({ 694, 47, 26, 37 }); //9
	idle.PushBack({ 734, 47, 26, 37 }); //10
	idle.PushBack({ 572, 94, 30, 37 }); //11
	idle.PushBack({ 614, 94, 30, 37 }); //12
	idle.PushBack({ 652, 94, 30, 37 }); //13
	idle.PushBack({ 692, 94, 26, 37 }); //14
	idle.PushBack({ 732, 94, 30, 37 }); //15
	idle.PushBack({ 574, 141, 26, 37 }); //16
	idle.PushBack({ 614, 141, 26, 37 }); //17
	idle.PushBack({ 654, 141, 26, 37 }); //18
	idle.PushBack({ 692, 141, 30, 37 }); //19
	idle.PushBack({ 734, 141, 26, 37 }); //20
	idle.PushBack({ 572, 188, 30, 37 }); //21
	idle.PushBack({ 614, 188, 26, 37 }); //22
	idle.PushBack({ 652, 188, 30, 37 }); //23
	idle.PushBack({ 694, 188, 26, 37 }); //24

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