#include "Application.h"
#include "Character_Tetsu.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

Character_Tetsu::Character_Tetsu(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	blit_idle.PushBack({ 572, 0, 30, 37 }); //1
	blit_idle.PushBack({ 0, 0,0,0 }); //2
	blit_idle.PushBack({ 652, 0, 30, 37 }); //3
	blit_idle.PushBack({ 0, 0,0,0 }); //4
	blit_idle.PushBack({ 732, 0, 30, 37 }); //5
	blit_idle.PushBack({ 0, 0,0,0 }); //6
	blit_idle.PushBack({ 612, 47, 30, 37 }); //7
	blit_idle.PushBack({ 0, 0,0,0 }); //8
	blit_idle.PushBack({ 692, 47, 30, 37 }); //9
	blit_idle.PushBack({ 0, 0,0,0 }); //10
	blit_idle.PushBack({ 572, 94, 30, 37 }); //11
	blit_idle.PushBack({ 0, 0,0,0 }); //12
	blit_idle.PushBack({ 652, 94, 30, 37 }); //13
	blit_idle.PushBack({  0, 0,0,0 }); //14
	blit_idle.PushBack({ 732, 94, 30, 37 }); //15
	blit_idle.PushBack({ 0, 0,0,0 }); //16
	blit_idle.PushBack({ 612, 141, 30, 37 }); //17
	blit_idle.PushBack({ 0, 0,0,0 }); //18
	blit_idle.PushBack({ 692, 141, 30, 37 }); //19
	blit_idle.PushBack({ 0, 0,0,0 }); //20
	blit_idle.PushBack({ 572, 188, 30, 37 }); //21
	blit_idle.PushBack({ 0, 0,0,0 }); //22
	blit_idle.PushBack({ 652, 188, 30, 37 }); //23
	blit_idle.PushBack({ 0, 0,0,0 }); //24
	blit_idle.speed = 0.25f;

	// left animation
	blit_left.PushBack({ 563, 282, 30, 37 }); //1
	blit_left.PushBack({ 0, 0,0,0 }); //2
	blit_left.PushBack({ 643, 282, 30, 37 }); //3
	blit_left.PushBack({ 0, 0,0,0 }); //4
	blit_left.PushBack({ 723, 282, 30, 37 }); //5
	blit_left.PushBack({ 0, 0,0,0 }); //6
	blit_left.PushBack({ 603, 329, 30, 37 }); //7
	blit_left.PushBack({ 0, 0,0,0 }); //8
	blit_left.loop = false;
	blit_left.speed = 0.25f;

	//more left animation
	blit_mleft.PushBack({ 683, 329, 30, 37 }); //9 ?
	blit_mleft.PushBack({ 0, 0,0,0 }); //10 X (last fixed)
	blit_mleft.PushBack({ 561, 374, 30, 37 }); //11
	blit_mleft.PushBack({ 0, 0,0,0 }); //12
	blit_mleft.PushBack({ 643, 374, 30, 37 }); //13
	blit_mleft.PushBack({ 0, 0,0,0 }); //14
	blit_mleft.PushBack({ 724, 374, 30, 37 }); //15
	blit_mleft.PushBack({ 0, 0,0,0 }); //16
	blit_mleft.PushBack({ 601, 421, 30, 37 }); //17
	blit_mleft.PushBack({ 0, 0,0,0 }); //18
	blit_mleft.PushBack({ 682, 421, 30, 37 }); //19
	blit_mleft.PushBack({ 0, 0,0,0 }); //20
	blit_mleft.PushBack({ 561, 469, 30, 37 }); //21
	blit_mleft.PushBack({ 0, 0,0,0 }); //22
	blit_mleft.PushBack({ 643, 469, 30, 37 }); //23
	blit_mleft.PushBack({ 0, 0,0,0 }); //24
	blit_mleft.PushBack({ 724, 469, 30, 37 }); //25
	blit_mleft.PushBack({ 0, 0,0,0 }); //26
	blit_mleft.PushBack({ 601, 515, 30, 37 }); //27
	blit_mleft.PushBack({ 0, 0,0,0 }); //28 
	blit_mleft.PushBack({ 682, 515, 30, 37 }); //29
	blit_mleft.PushBack({ 0, 0,0,0 }); //30
	blit_mleft.PushBack({ 561, 557, 30, 37 }); //31
	blit_mleft.PushBack({ 0, 0,0,0 }); //32
	blit_mleft.PushBack({ 643, 557, 30, 37 }); //33
	blit_mleft.PushBack({ 0, 0,0,0 }); //34
	blit_mleft.PushBack({ 724, 557, 30, 37 }); //35
	blit_mleft.PushBack({ 0, 0,0,0 }); //36
	blit_mleft.PushBack({ 601, 608, 30, 37 }); //37
	blit_mleft.PushBack({ 0, 0,0,0 }); //38
	blit_mleft.PushBack({ 682, 608, 30, 37 }); //39
	blit_mleft.PushBack({ 0, 0,0,0 }); //40
	blit_mleft.PushBack({ 561, 654, 30, 37 }); //41
	blit_mleft.PushBack({ 0, 0,0,0 }); //42
	blit_mleft.PushBack({ 643, 654, 30, 37 }); //43
	blit_mleft.PushBack({ 0, 0,0,0 }); //44
	blit_mleft.PushBack({ 724, 654, 30, 37 }); //45
	blit_mleft.PushBack({ 0, 0,0,0 }); //46
	blit_mleft.PushBack({ 601, 702, 30, 37 }); //47
	blit_mleft.PushBack({ 0, 0,0,0 }); //48
	blit_mleft.PushBack({ 682, 702, 30, 37 }); //49
	blit_mleft.PushBack({ 0, 0,0,0 }); //50
	blit_mleft.loop = true;
	blit_mleft.speed = 0.25f;

	/*// left animation
	blit_left.PushBack({ 561, 280, 30, 37 }); //1
	blit_left.PushBack({  0, 0,0,0  }); //2
	blit_left.PushBack({ 643, 280, 30, 37 }); //3
	blit_left.PushBack({  0, 0,0,0  }); //4
	blit_left.PushBack({ 724, 280, 30, 37 }); //5
	blit_left.PushBack({  0, 0,0,0  }); //6
	blit_left.PushBack({ 601, 326, 30, 37 }); //7
	blit_left.PushBack({  0, 0,0,0  }); //8
	blit_left.loop = false;
	blit_left.speed = 0.25f;

	//more left animation
	blit_mleft.PushBack({ 682, 326, 30, 37 }); //9
	blit_mleft.PushBack({  0, 0,0,0  }); //10
	blit_mleft.PushBack({ 561, 374, 30, 37 }); //11
	blit_mleft.PushBack({  0, 0,0,0  }); //12
	blit_mleft.PushBack({ 643, 374, 30, 37 }); //13
	blit_mleft.PushBack({  0, 0,0,0  }); //14
	blit_mleft.PushBack({ 724, 374, 30, 37 }); //15
	blit_mleft.PushBack({ 0, 0,0,0 }); //16
	blit_mleft.PushBack({ 601, 421, 30, 37 }); //17
	blit_mleft.PushBack({  0, 0,0,0  }); //18
	blit_mleft.PushBack({ 682, 421, 30, 37 }); //19
	blit_mleft.PushBack({  0, 0,0,0 }); //20
	blit_mleft.PushBack({ 561, 469, 30, 37 }); //21
	blit_mleft.PushBack({  0, 0,0,0  }); //22
	blit_mleft.PushBack({ 643, 469, 30, 37 }); //23
	blit_mleft.PushBack({ 0, 0,0,0  }); //24
	blit_mleft.PushBack({ 724, 469, 30, 37 }); //25
	blit_mleft.PushBack({  0, 0,0,0  }); //26
	blit_mleft.PushBack({ 601, 515, 30, 37 }); //27
	blit_mleft.PushBack({  0, 0,0,0  }); //28
	blit_mleft.PushBack({ 682, 515, 30, 37 }); //29
	blit_mleft.PushBack({  0, 0,0,0  }); //30
	blit_mleft.PushBack({ 561, 557, 30, 37 }); //31
	blit_mleft.PushBack({  0, 0,0,0  }); //32
	blit_mleft.PushBack({ 643, 557, 30, 37 }); //33
	blit_mleft.PushBack({  0, 0,0,0  }); //34
	blit_mleft.PushBack({ 724, 557, 30, 37 }); //35
	blit_mleft.PushBack({ 0, 0,0,0  }); //36
	blit_mleft.PushBack({ 601, 608, 30, 37 }); //37
	blit_mleft.PushBack({  0, 0,0,0  }); //38
	blit_mleft.PushBack({ 682, 608, 30, 37 }); //39
	blit_mleft.PushBack({ 0, 0,0,0 }); //40
	blit_mleft.PushBack({ 561, 654, 30, 37 }); //41
	blit_mleft.PushBack({  0, 0,0,0  }); //42
	blit_mleft.PushBack({ 643, 654, 30, 37 }); //43
	blit_mleft.PushBack({  0, 0,0,0  }); //44
	blit_mleft.PushBack({ 724, 654, 30, 37 }); //45
	blit_mleft.PushBack({ 0, 0,0,0  }); //46
	blit_mleft.PushBack({ 601, 702, 30, 37 }); //47
	blit_mleft.PushBack({  0, 0,0,0 }); //48
	blit_mleft.PushBack({ 682, 702, 30, 37 }); //49
	blit_mleft.PushBack({  0, 0,0,0  }); //50
	blit_mleft.loop = true;
	blit_mleft.speed = 0.25f;*/

	// right animation
	blit_right.PushBack({ 803, 284, 30, 37 }); //1
	blit_right.PushBack({ 0, 0,0,0 }); //2
	blit_right.PushBack({ 882, 284, 30, 37 }); //3
	blit_right.PushBack({ 0, 0,0,0 }); //4
	blit_right.PushBack({ 961, 284, 30, 37 }); //5
	blit_right.PushBack({ 0, 0,0,0 }); //6
	blit_right.PushBack({ 842, 331, 30, 37 }); //7
	blit_right.PushBack({ 0, 0,0,0 }); //8
	blit_right.loop = false;
	blit_right.speed = 0.25f;

	//more right animation
	blit_mright.PushBack({ 922, 331, 30, 37 }); //9
	blit_mright.PushBack({ 0, 0,0,0 }); //10
	blit_mright.PushBack({ 803, 378, 30, 37 }); //11
	blit_mright.PushBack({ 0, 0,0,0 }); //12
	blit_mright.PushBack({ 882, 378, 30, 37 }); //13
	blit_mright.PushBack({ 0, 0,0,0 }); //14
	blit_mright.PushBack({ 961, 378, 30, 37 }); //15
	blit_mright.PushBack({ 0, 0,0,0 }); //16
	blit_mright.PushBack({ 842, 425, 30, 37 }); //17
	blit_mright.PushBack({ 0, 0,0,0 }); //18
	blit_mright.PushBack({ 922, 425, 30, 37 }); //19
	blit_mright.PushBack({ 0, 0,0,0 }); //20
	blit_mright.PushBack({ 803, 472, 30, 37 }); //21
	blit_mright.PushBack({ 0, 0,0,0 }); //22
	blit_mright.PushBack({ 882, 472, 30, 37 }); //23
	blit_mright.PushBack({ 0, 0,0,0 }); //24
	blit_mright.PushBack({ 961, 472, 30, 37 }); //25
	blit_mright.PushBack({ 0, 0,0,0 }); //26
	blit_mright.PushBack({ 842, 517, 30, 37 }); //27
	blit_mright.PushBack({ 0, 0,0,0 }); //28 
	blit_mright.PushBack({ 922, 517, 30, 37 }); //29
	blit_mright.PushBack({ 0, 0,0,0 }); //30
	blit_mright.PushBack({ 803, 561, 30, 37 }); //31
	blit_mright.PushBack({ 0, 0,0,0 }); //32
	blit_mright.PushBack({ 882, 561, 30, 37 }); //33
	blit_mright.PushBack({ 0, 0,0,0 }); //34
	blit_mright.PushBack({ 961, 561, 30, 37 }); //35
	blit_mright.PushBack({ 0, 0,0,0 }); //36
	blit_mright.PushBack({ 842, 612, 30, 37 }); //37
	blit_mright.PushBack({ 0, 0,0,0 }); //38
	blit_mright.PushBack({ 922, 612, 30, 37 }); //39
	blit_mright.PushBack({ 0, 0,0,0 }); //40
	blit_mright.PushBack({ 803, 659, 30, 37 }); //41
	blit_mright.PushBack({ 0, 0,0,0 }); //42
	blit_mright.PushBack({ 882, 659, 30, 37 }); //43
	blit_mright.PushBack({ 0, 0,0,0 }); //44
	blit_mright.PushBack({ 961, 659, 30, 37 }); //45
	blit_mright.PushBack({ 0, 0,0,0 }); //46
	blit_mright.PushBack({ 842, 706, 30, 37 }); //47
	blit_mright.PushBack({ 0, 0,0,0 }); //48
	blit_mright.PushBack({ 922, 706, 30, 37 }); //49
	blit_mright.PushBack({ 0, 0,0,0 }); //50
	blit_mright.loop = true;
	blit_mright.speed = 0.25f;

	collider = App->collision->AddCollider({ position.x, position.y, 30, 37 }, COLLIDER_PLAYER, TETSU, (Module*)App->player);

	animation = &blit_idle;

}

void Character_Tetsu::Move()
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

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_right;
			animation = &blit_mright;
			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 30)) {
				position.x = (SCREEN_WIDTH - 30);
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_left;
			animation = &blit_mleft;
			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_idle;
			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) - 37) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE) - 37;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT))
		{
			animation = &blit_idle;
			position.y += speed;
			if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &blit_mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &blit_idle;
	}
}

void Character_Tetsu::Laser() {
	if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time)) ||
		(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
		//LEVEL 0
		if (level == 0) {
			if (time == 0)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 8, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 20, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
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
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
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
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 3, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 2, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 26, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 31, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 4, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 8, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 20, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 32, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 9, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 5, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 33, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 37, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);

			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 3, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 2, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 19, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 26, position.y - 15, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 31, position.y - 11, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 7, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
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
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 17, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 13, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 41, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 45, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
				shot = false;
			}
			if (time == 5)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 15, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 11, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 6, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 34, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 39, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 43, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 10)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 15, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 12, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 40, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 44, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
			}
			if (time == 15)
			{
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 17, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 13, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 17, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 41, position.y - 13, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_tetsu, position.x + 45, position.y - 9, 0, SPEED_LASER_PLAYER, TETSU, COLLIDER_PLAYER_SHOT);
				App->audio->PlayWAV(App->particles->laser_tetsu_fx);
				time = 0;
				shot = true;
			}
			if (shot == false)
				time++;
		}
	}
}

void Character_Tetsu::Dead() {
	if (this->playerDead == true) {
		//animation = &death;
		this->desactivateInput = true;

		if (this->spawnPlayer == false && position.y <= 50 + ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE)
			position.y += 4;

		else {
			this->spawnPlayer = true;
			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
				if (App->player->characters[0]->type == TETSU)
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1] != nullptr) {
					if (App->player->characters[1]->type == TETSU)
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

void Character_Tetsu::OnCollision(Collider* collider) {

}