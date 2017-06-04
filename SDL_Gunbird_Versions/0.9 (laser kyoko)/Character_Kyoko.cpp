#include "Application.h"
#include "Character_Kyoko.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

Character_Kyoko::Character_Kyoko(int x, int y) : Character(x, y)
{
	// idle animation
	idle.PushBack({ 607, 804, 34, 37 }); //1
	idle.PushBack({ 649, 804, 34, 37 }); //2
	idle.PushBack({ 692, 804, 34, 37 }); //3
	idle.PushBack({ 735, 804, 34, 37 }); //4
	idle.speed = 0.2f;

	// left animation
	left.PushBack({ 609, 897, 33, 30 });
	left.PushBack({ 649, 897, 33, 30 });
	left.PushBack({ 689, 897, 33, 30 });
	left.PushBack({ 729, 897, 33, 30 });
	left.speed = 0.2f;

	// right animation
	right.PushBack({ 608, 853, 32, 28  });
	right.PushBack({ 644, 853, 32, 28 });
	right.PushBack({ 680, 853, 32, 28 });
	right.PushBack({ 716, 853, 32, 28 });
	right.speed = 0.2f;

	// death sprite
	death.PushBack({ 611, 943, 27, 22 });

	//blit
	blit_idle.PushBack({ 607, 804, 34, 37 });
	blit_idle.PushBack({ 0,0,0,0 });
	blit_idle.PushBack({ 692, 804, 34, 37 });
	blit_idle.PushBack({ 0,0,0,0 });
	blit_idle.speed = 0.2f;

	blit_left.PushBack({ 609, 897, 33, 30 });
	blit_left.PushBack({ 0, 0, 0,0 });
	blit_left.PushBack({ 689, 897, 33, 30 });
	blit_left.PushBack({ 0, 0, 0,0 });
	blit_left.speed = 0.2f;

	blit_right.PushBack({ 608, 853, 32, 28 });
	blit_right.PushBack({ 0,0,0,0 });
	blit_right.PushBack({ 680, 853, 32, 28 });
	blit_right.PushBack({ 0,0,0,0 });
	blit_right.speed = 0.2f;

	collider = App->collision->AddCollider({ position.x, position.y, 14, 23 }, COLLIDER_PLAYER, KYOKO, (Module*)App->player);

	animation = &idle;

}

void Character_Kyoko::Move()
{
	if (inmortal == false)
		animation = &idle;
	else
		animation = &blit_idle;

	int speed = SPEED_KYOKO;

	if (desactivateLimit == false)
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
			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			{
				if (inmortal == false)
					animation = &right;
				else
					animation = &blit_right;

				position.x += speed;
				if (position.x > (SCREEN_WIDTH - 32)) {
					position.x = (SCREEN_WIDTH - 32);
				}
			}

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
			{
				if (inmortal == false)
					animation = &left;
				else
					animation = &blit_left;

				position.x -= speed;
				if (position.x < 0) {
					position.x = 0;
				}
			}

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT))
			{
				if (inmortal == false)
					animation = &idle;
				else
					animation = &blit_idle;

				position.y -= speed;
				if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 37) {
					position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 37;
				}
			}

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT))
			{
				if (inmortal == false)
					animation = &idle;
				else
					animation = &blit_idle;

				position.y += speed;
				if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 32) {
					position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 32;
				}
			}

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up) &&
				(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
				if (inmortal == false)
					animation = &right;
				else
					animation = &blit_right;

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up) &&
				(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
				if (inmortal == false)
					animation = &left;
				else
					animation = &blit_left;

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down) &&
				(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
				if (inmortal == false)
					animation = &right;
				else
					animation = &blit_right;

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down) &&
				(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
				if (inmortal == false)
					animation = &left;
				else
					animation = &blit_left;

			if ((App->player->characters[0]->type == KYOKO && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left) &&
				(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
				(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
				if (inmortal == false)
					animation = &idle;
				else
					animation = &blit_idle;
		}

	if (collider != nullptr)
		collider->SetPos(position.x + 10, position.y + 2);
}

void Character_Kyoko::Laser() {
	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || App->input->gamepad.A == CONTROLLER_STATE::BUTTON_DOWN || (0 < time)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO && App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
			//LEVEL 0
			if (level == 0) {
				if (time == 0)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 12, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 20, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 10, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 22, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 13, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 19, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 12, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 20, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
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
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 16, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 7, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 16, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 25, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 16, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 27, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 16, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
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
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 14, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 18, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 7, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 13, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 19, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 25, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 20, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 27, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 14, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 18, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
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
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 3, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 20, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 29, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 6, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 10, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 14, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 18, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 22, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 26, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 9, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 13, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 19, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 23, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 27, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 3, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 8, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 20, position.y - 24, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 24, position.y - 20, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_kyoko, position.x + 29, position.y - 16, 0, SPEED_LASER_PLAYER, KYOKO, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					time = 0;
					shot = true;
				}
				if (shot == false)
					time++;
			}
		}
	}
}

void Character_Kyoko::Dead() {
	if (this->playerDead == true) {
		animation = &death;
		this->desactivateInput = true;

		if (this->spawnPlayer == false && position.y <= 50 + ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
			position.y += 4;

		else {
			this->spawnPlayer = true;
			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				if (App->player->characters[0]->type == KYOKO)
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1] != nullptr) {
					if (App->player->characters[1]->type == KYOKO)
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
					this->inmortal = false;
				}
			}
		}
	}
}

void Character_Kyoko::OnCollision(Collider* collider) {

}