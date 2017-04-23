#include "Application.h"
#include "Character_YuanNang.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

Character_YuanNang::Character_YuanNang(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	blit_idle.PushBack({ 9, 6, 27, 48 }); //1
	blit_idle.PushBack({ 0,0,0,0 }); //2
	blit_idle.PushBack({ 61, 96, 27, 48 }); //3
	blit_idle.PushBack({ 0,0,0,0 }); //4
	blit_idle.PushBack({ 159, 5, 27, 48 }); //5
	blit_idle.PushBack({ 0,0,0,0 }); //6
	blit_idle.PushBack({ 14, 95, 27, 48 }); //7
	blit_idle.PushBack({ 0,0,0,0 }); //8
	blit_idle.speed = 0.25f;

	// left animation
	blit_left.PushBack({ 18, 417, 24, 47 });
	blit_left.PushBack({ 0,0,0,0 });
	blit_left.PushBack({ 122, 419, 24, 47 });
	blit_left.PushBack({ 0,0,0,0 });
	blit_left.loop = false;
	blit_left.speed = 0.05f;

	// more left animation
	blit_mleft.PushBack({ 18, 350, 26, 48 });
	blit_mleft.PushBack({ 0,0,0,0 });
	blit_mleft.PushBack({ 120, 351, 27, 48 });
	blit_mleft.PushBack({ 0,0,0,0 });
	blit_mleft.loop = true;
	blit_mleft.speed = 0.05f;

	// right animation
	blit_right.PushBack({ 70, 171, 26, 48 });
	blit_right.PushBack({ 0,0,0,0 });
	blit_right.PushBack({ 168, 172, 27, 48 });
	blit_right.PushBack({ 0,0,0,0 });
	blit_right.loop = false;
	blit_right.speed = 0.25f;

	// more right animation
	blit_mright.PushBack({ 20, 246, 27, 47 });
	blit_mright.PushBack({ 0,0,0,0 });
	blit_mright.PushBack({ 121, 247, 27, 46 });
	blit_mright.PushBack({ 0,0,0,0 });
	blit_mright.loop = true;
	blit_mright.speed = 0.25f;

	// death sprite
	blit_death.PushBack({ 23, 965, 30, 30 });

	collider = App->collision->AddCollider({ position.x, position.y, 27, 48 }, COLLIDER_PLAYER, YUAN_NANG,(Module*)App->player);

	animation = &blit_idle;

}

void Character_YuanNang::Move()
{
	animation = &blit_idle;

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

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_right;
			animation = &blit_mright;
			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 27)) {
				position.x = (SCREEN_WIDTH - 27);
			}
		}

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_left;
			animation = &blit_mleft;
			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_idle;
			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE)) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE);
			}
		}

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_idle;
			position.y += speed;
			if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 48) {
				position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 48;
			}
		}

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mright;

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mleft;

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mright;

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mleft;

		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_idle;
	}
}

void Character_YuanNang::Laser() {

	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
			//LEVEL 0
			if (level == 0) {
				if (time == 0)
				{
					App->particles->AddParticle(App->particles->laser_nang_0, position.x + 9, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_0, position.x + 17, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 8, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 20, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_nang_2, position.x + 10, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_2, position.x + 16, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_nang_0, position.x + 9, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_0, position.x + 17, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
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
					App->particles->AddParticle(App->particles->laser_nang_3, position.x + 7, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_4, position.x + 11, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_3, position.x + 15, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_nang_5, position.x + 6, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_5, position.x + 11, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_5, position.x + 16, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_nang_6, position.x + 6, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_7, position.x + 12, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_6, position.x + 18, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_nang_3, position.x + 7, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_4, position.x + 11, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_3, position.x + 15, position.y - 5, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
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
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 5, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 10, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 18, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 23, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_nang_10, position.x + 6, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_10, position.x + 11, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_10, position.x + 15, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_10, position.x + 20, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 10, position.y - 24, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 16, position.y - 24, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 21, position.y - 16, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 5, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 10, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_1, position.x + 18, position.y - 12, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 23, position.y - 4, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
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
					App->particles->AddParticle(App->particles->laser_nang_13, position.x - 5, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 1, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_12, position.x + 9, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_12, position.x + 15, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 25, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 31, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_nang_8, position.x - 6, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 2, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_14, position.x + 8, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_14, position.x + 16, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 24, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_8, position.x + 32, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_nang_9, position.x - 6, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 4, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_11, position.x + 8, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_11, position.x + 18, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 24, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_9, position.x + 34, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_nang_13, position.x - 5, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 1, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_12, position.x + 9, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_12, position.x + 15, position.y - 10, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 25, position.y - 6, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_nang_13, position.x + 31, position.y - 2, 0, SPEED_LASER_PLAYER, YUAN_NANG, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_nang_fx);
					time = 0;
					shot = true;
				}
				if (shot == false)
					time++;
			}
		}
	}
}

void Character_YuanNang::Dead() {
	if (this->playerDead == true && this->live != -1) {
		animation = &blit_death;
		this->desactivateInput = true;

		if (this->spawnPlayer == false && position.y <= 50 + ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
			position.y += 4;

		else {
			this->spawnPlayer = true;
			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				if (App->player->characters[0]->type == YUAN_NANG)
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1] != nullptr) {
					if (App->player->characters[1]->type == YUAN_NANG)
						position.x = App->render->camera.x + 150;
				}
			}

			animation = &blit_idle;

			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 80)
				position.y -= 1;

			else {
				if (this->scroll == 0) {
					position.y = abs(App->render->camera.y / SCREEN_SIZE) + 240;
					this->spawnPlayer = false;
					this->playerDead = false;
					this->desactivateInput = false;
				}
			}
		}
	}
}

void Character_YuanNang::OnCollision(Collider* collider) {
	
}
