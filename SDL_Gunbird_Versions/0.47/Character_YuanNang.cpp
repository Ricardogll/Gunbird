#include "Application.h"
#include "Character_YuanNang.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"

Character_YuanNang::Character_YuanNang(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	idle.PushBack({ 9, 6, 27, 48 }); //1
	idle.PushBack({ 107, 7, 27, 48 }); //2
	idle.PushBack({ 61, 96, 27, 48 }); //3
	idle.PushBack({ 112, 97, 27, 48 }); //4
	idle.PushBack({ 159, 5, 27, 48 }); //5
	idle.PushBack({ 53, 6, 27, 48 }); //6
	idle.PushBack({ 14, 95, 27, 48 }); //7
	idle.PushBack({ 163, 99, 27, 48 }); //8
	idle.speed = 0.25f;

	// left animation
	left.PushBack({ 18, 417, 24, 47 });
	left.PushBack({ 73, 418, 24, 47 });
	left.PushBack({ 122, 419, 24, 47 });
	left.PushBack({ 170, 420, 24, 46 });
	left.loop = false;
	left.speed = 0.05f;

	// more left animation
	mleft.PushBack({ 18, 350, 26, 48 });
	mleft.PushBack({ 73, 351, 27, 48 });
	mleft.PushBack({ 120, 351, 27, 48 });
	mleft.PushBack({ 170, 351, 27, 48 });
	mleft.loop = true;
	mleft.speed = 0.05f;

	// right animation
	right.PushBack({ 70, 171, 26, 48 });
	right.PushBack({ 119, 171, 27, 48 });
	right.PushBack({ 168, 172, 27, 48 });
	right.PushBack({ 15, 174, 27, 48 });
	right.loop = false;
	right.speed = 0.25f;

	// more right animation
	mright.PushBack({ 20, 246, 27, 47 });
	mright.PushBack({ 79, 248, 27, 47 });
	mright.PushBack({ 121, 247, 27, 46 });
	mright.PushBack({ 171, 248, 27, 46 });
	mright.loop = true;
	mright.speed = 0.25f;

	// death sprite
	death.PushBack({ 23, 965, 30, 30 });

	collider = App->collision->AddCollider({ position.x, position.y, 27, 48 }, COLLIDER_PLAYER, (Module*)App->player);

	animation = &idle;

}

void Character_YuanNang::Move()
{
	animation = &idle;

	int speed = SPEED_CHARACTER;

	if ((position.y < (abs(App->render->camera.y) / SCREEN_SIZE)))
		position.y = (abs(App->render->camera.y) / SCREEN_SIZE);

	else {
		if (movement == false) {
			scroll += 0.5;
			if (scroll == 1.5) {
				position.y -= 1;
				scroll = 0;
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		animation = &right;
		animation = &mright;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 27)) {
			position.x = (SCREEN_WIDTH - 27);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		animation = &left;
		animation = &mleft;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE)) { 
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 48) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 48;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		animation = &idle;

}

//IF PLAYER 2
void Character_YuanNang::Move2()
{
	animation = &idle;

	int speed = SPEED_CHARACTER;

	if ((position.y < (abs(App->render->camera.y) / SCREEN_SIZE)))
		position.y = (abs(App->render->camera.y) / SCREEN_SIZE);

	else {
		if (movement == false) {
			scroll += 0.5;
			if (scroll == 1.5) {
				position.y -= 1;
				scroll = 0;
			}
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		animation = &right;
		animation = &mright;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 27)) {
			position.x = (SCREEN_WIDTH - 27);
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
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 48) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 48;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		animation = &idle;

}

void Character_YuanNang::Laser() {
	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time))
	{
		if (level == 0) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_nang_v0_0, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_nang_v0_1, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_nang_v0_2, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_nang_v0_0, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}

		if (level == 1) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_nang_v1_0, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_nang_v1_1, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_nang_v1_2, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_nang_v1_0, position.x + 8, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}

		if (level == 2) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_nang_v2_0, position.x + 5, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->nang_sword, position.x - 20, position.y, 0, SPEED_SWORD_YUAN_NANG, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->nang_sword, position.x + 40, position.y, 0, SPEED_SWORD_YUAN_NANG, COLLIDER_PLAYER_SHOT);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_nang_v2_1, position.x + 5, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_nang_v2_2, position.x + 5, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_nang_v2_0, position.x + 5, position.y, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}

		if (level == 3) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_nang_v3_0, position.x - 7, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				shot = false; //FALTA PONER LAS ESPADAS
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_nang_v3_1, position.x - 7, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_nang_v3_0, position.x - 7, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_nang_v3_1, position.x - 7, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}

	}
}

void Character_YuanNang::OnCollision(Collider* collider) {
	
}
