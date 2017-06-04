#include "Application.h"
#include "Character_Ash.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

Character_Ash::Character_Ash(int x, int y) : Character(x, y)
{
	// idle animation
	idle.PushBack({ 217, 223, 19, 32 }); //1
	idle.PushBack({ 246, 223, 19, 32 }); //2
	idle.speed = 0.2f;

	// left animation
	left.PushBack({ 219, 265, 17, 32 });
	left.PushBack({ 246, 265, 17, 32 });
	left.speed = 0.2f;

	// more left animation
	mleft.PushBack({ 273, 265, 14, 32 });
	mleft.PushBack({ 297, 265, 14, 32 });
	mleft.loop = true;
	mleft.speed = 0.2f;

	// right animation
	right.PushBack({ 266, 307, 17, 32 });
	right.PushBack({ 293, 307, 17, 32 });
	right.speed = 0.2f;

	// more right animation
	mright.PushBack({ 218, 307, 14, 32 });
	mright.PushBack({ 242, 307, 14, 32 });
	mright.loop = true;
	mright.speed = 0.2f;

	// death sprite
	death.PushBack({ 289, 395, 31, 26 });

	//blit
	blit_idle.PushBack({ 217, 223, 19, 32 }); 
	blit_idle.PushBack({ 0,0,0,0 });
	blit_idle.speed = 0.2f;

	blit_left.PushBack({ 219, 265, 17, 32 });
	blit_left.PushBack({ 0, 0, 0,0 });
	blit_left.speed = 0.2f;

	blit_mleft.PushBack({ 273, 265, 14, 32 });
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.speed = 0.2f;

	blit_right.PushBack({ 266, 307, 17, 32 });
	blit_right.PushBack({ 0,0,0,0 });
	blit_right.speed = 0.2f;

	blit_mright.PushBack({ 218, 307, 14, 32 });
	blit_mright.PushBack({ 0, 0, 0,0 });
	blit_mright.speed = 0.2f;

	collider = App->collision->AddCollider({ position.x, position.y, 19, 32 }, COLLIDER_PLAYER, ASH, (Module*)App->player);

	animation = &idle;

}

void Character_Ash::Move()
{
	if (inmortal == false)
		animation = &idle;
	else
		animation = &blit_idle;

	int speed = SPEED_ASH;

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
		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false)
				animation = &mright;
			else
				animation = &blit_mright;

			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 19)) {
				position.x = (SCREEN_WIDTH - 19);
			}
		}

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false)
				animation = &mleft;
			else
				animation = &blit_mleft;

			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false)
				animation = &idle;
			else
				animation = &blit_idle;

			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 32) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 32;
			}
		}

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT))
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

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up) &&
			(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &right;
			else
				animation = &blit_right;

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_UP == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_up) &&
			(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &left;
			else
				animation = &blit_left;

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down) &&
			(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &right;
			else
				animation = &blit_right;

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_DOWN == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_down) &&
			(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &left;
			else
				animation = &blit_left;

		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_LEFT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_left) &&
			(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || App->input->gamepad.DPAD_RIGHT == CONTROLLER_STATE::BUTTON_REPEAT || App->input->joystick_right)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &idle;
			else
				animation = &blit_idle;
	}

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

}

void Character_Ash::Laser() {
	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == ASH && (App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || App->input->gamepad.A == CONTROLLER_STATE::BUTTON_DOWN) || (0 < time)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH && App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
			//LEVEL 0
			if (level == 0) {
				if (time == 0)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x + 4, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 12, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x + 2, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 14, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x + 5, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 11, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x + 4, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 12, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 8, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 1, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 8, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 17, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 3, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 8, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 19, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 8, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 6, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 10, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 1, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 5, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 11, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 17, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 3, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 4, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 19, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 6, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 10, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_ash, position.x - 5, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 4, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 21, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 2, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 2, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 6, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 10, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 14, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 18, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 3, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 1, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 5, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 11, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 15, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 19, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->audio->PlayWAV(App->particles->laser_ash_fx);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_ash, position.x - 5, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 4, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 12, position.y - 24, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 16, position.y - 20, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_ash, position.x + 21, position.y - 16, 0, SPEED_LASER_PLAYER, ASH, COLLIDER_PLAYER_SHOT);
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

void Character_Ash::Dead() {
	if (this->playerDead == true) {
		animation = &death;
		this->desactivateInput = true;

		if (this->spawnPlayer == false && position.y <= 50 + ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
			position.y += 4;

		else {
			this->spawnPlayer = true;
			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				if (App->player->characters[0]->type == ASH)
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1] != nullptr) {
					if (App->player->characters[1]->type == ASH)
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

void Character_Ash::OnCollision(Collider* collider) {

}