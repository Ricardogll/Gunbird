#include "Application.h"
#include "Character_Valnus.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

Character_Valnus::Character_Valnus(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	idle.PushBack({ 218, 443, 31, 30 }); //1
	idle.PushBack({ 256, 443, 31, 30 }); //2
	idle.speed = 0.2f;

	// left animation
	left.PushBack({ 218, 519, 26, 30 });
	left.PushBack({ 256, 519, 26, 30 });
	left.loop = false;
	left.speed = 0.2f;

	// more left animation
	mleft.PushBack({ 294, 519, 21, 30 });
	mleft.PushBack({ 332, 519, 21, 30 });
	mleft.loop = true;
	mleft.speed = 0.2f;

	// right animation
	right.PushBack({ 218, 481, 26, 30 });
	right.PushBack({ 256, 481, 26, 30 });
	right.loop = false;
	right.speed = 0.2f;

	// more right animation
	mright.PushBack({ 294, 481, 21, 30 });
	mright.PushBack({ 332, 481, 21, 30 });
	mright.loop = true;
	mright.speed = 0.2f;

	// death sprite
	death.PushBack({ 294, 443, 32, 37 });

	collider = App->collision->AddCollider({ position.x, position.y, 31, 30 }, COLLIDER_PLAYER, VALNUS, (Module*)App->player);

	animation = &idle;

}

void Character_Valnus::Move()
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

	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
		{
			animation = &right;
			animation = &mright;
			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 30)) {
				position.x = (SCREEN_WIDTH - 30);
			}
		}

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
		{
			animation = &left;
			animation = &mleft;
			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT))
		{
			animation = &idle;
			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE)) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE);
			}
		}

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT))
		{
			animation = &idle;
			position.y += speed;
			if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 31) {
				position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 31;
			}
		}

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &right;

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &left;

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &right;

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &left;

		if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &idle;
	}
}

void Character_Valnus::Laser() {
	if ((App->player->characters[0]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time)) ||
		(App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
		//LEVEL 0
		if (level == 0) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 9, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 13, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 17, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 21, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				shot = false;
			}
			if (time == 5)/*7,25*/
			{
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 8, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 12, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 18, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 22, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 10, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 13, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 17, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 20, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 9, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 13, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 17, position.y - 14, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_0, position.x + 21, position.y - 11, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}
		//LEVEL 1
		if (level == 1) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 11, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 17, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 23, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				shot = false;
			}
			if (time == 7)/*7,5*/
			{
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 3, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 10, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 18, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 25, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 14)
			{
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 6, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 10, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 18, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 22, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 21)
			{
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 11, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 17, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_1, position.x + 23, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}
		//LEVEL 2
		if (level == 2) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 1, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 7, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 12, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 16, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 21, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 27, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				shot = false;
			}
			if (time == 7)/*6,9*/
			{
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 4, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 10, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 18, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 24, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 28, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 14)
			{
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 11, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 17, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 23, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 28, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 21)
			{
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 1, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 7, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 12, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 16, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 21, position.y - 16, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_2, position.x + 27, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}
		//LEVEL 3
		if (level == 3) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x - 5, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 2, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 10, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 16, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 24, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 31, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				shot = false;
			}
			if (time == 9)/*9,3*/
			{
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x - 6, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 8, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 18, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 26, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 32, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 18)
			{
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x - 7, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 1, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 9, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 17, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 25, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 33, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
			}
			if (time == 27)
			{
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x - 5, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 2, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 10, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 16, position.y - 28, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 24, position.y - 20, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_valnus_3, position.x + 31, position.y - 12, 0, SPEED_LASER_PLAYER, VALNUS, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_valnus_fx);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}
	}
}

void Character_Valnus::Dead() {
	if (this->playerDead == true) {
		animation = &death;
		this->desactivateInput = true;

		if (this->spawnPlayer == false && position.y <= 50 + ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
			position.y += 4;

		else {
			this->spawnPlayer = true;
			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				if (App->player->characters[0]->type == VALNUS)
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1] != nullptr) {
					if (App->player->characters[1]->type == VALNUS)
						position.x = App->render->camera.x + 150;
				}
			}

			animation = &idle;

			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 80)
				position.y -= 1;

			else {
				if (App->render->scroll == 0) {
					position.y = abs(App->render->camera.y / SCREEN_SIZE) + 240;
					this->spawnPlayer = false;
					this->playerDead = false;
					this->desactivateInput = false;
				}
			}
		}
	}
}

void Character_Valnus::OnCollision(Collider* collider) {

}