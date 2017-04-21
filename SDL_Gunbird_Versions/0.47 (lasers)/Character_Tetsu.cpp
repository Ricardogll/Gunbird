#include "Application.h"
#include "Character_Tetsu.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Character_Tetsu::Character_Tetsu(int x, int y) : Character(x, y)
{
	position.x = x;
	position.y = y;

	// idle animation
	idle.PushBack({ 572, 0, 30, 37 }); //1
	idle.PushBack({ 612, 0, 30, 37 }); //2
	idle.PushBack({ 652, 0, 30, 37 }); //3
	idle.PushBack({ 692, 0, 30, 37 }); //4
	idle.PushBack({ 732, 0, 30, 37 }); //5
	idle.PushBack({ 572, 47, 30, 37 }); //6
	idle.PushBack({ 612, 47, 30, 37 }); //7
	idle.PushBack({ 652, 47, 30, 37 }); //8
	idle.PushBack({ 692, 47, 30, 37 }); //9
	idle.PushBack({ 732, 47, 30, 37 }); //10
	idle.PushBack({ 572, 94, 30, 37 }); //11
	idle.PushBack({ 612, 94, 30, 37 }); //12
	idle.PushBack({ 652, 94, 30, 37 }); //13
	idle.PushBack({ 690, 94, 30, 37 }); //14
	idle.PushBack({ 732, 94, 30, 37 }); //15
	idle.PushBack({ 572, 141, 30, 37 }); //16
	idle.PushBack({ 612, 141, 30, 37 }); //17
	idle.PushBack({ 652, 141, 30, 37 }); //18
	idle.PushBack({ 692, 141, 30, 37 }); //19
	idle.PushBack({ 732, 141, 30, 37 }); //20
	idle.PushBack({ 572, 188, 30, 37 }); //21
	idle.PushBack({ 612, 188, 30, 37 }); //22
	idle.PushBack({ 652, 188, 30, 37 }); //23
	idle.PushBack({ 692, 188, 30, 37 }); //24
	idle.speed = 0.25f;

	// left animation
	left.PushBack({ 563, 282, 30, 37 }); //1
	left.PushBack({ 603, 282, 30, 37 }); //2
	left.PushBack({ 643, 282, 30, 37 }); //3
	left.PushBack({ 683, 282, 30, 37 }); //4
	left.PushBack({ 723, 282, 30, 37 }); //5
	left.PushBack({ 563, 329, 30, 37 }); //6
	left.PushBack({ 603, 329, 30, 37 }); //7
	left.PushBack({ 643, 329, 30, 37 }); //8
	left.loop = false;
	left.speed = 0.25f;

	//more left animation
	mleft.PushBack({ 683, 329, 30, 37 }); //9 ?
	mleft.PushBack({ 723, 329, 30, 37 }); //10 X (last fixed)
	mleft.PushBack({ 561, 374, 30, 37 }); //11
	mleft.PushBack({ 601, 374, 30, 37 }); //12
	mleft.PushBack({ 643, 374, 30, 37 }); //13
	mleft.PushBack({ 682, 374, 30, 37 }); //14
	mleft.PushBack({ 724, 374, 30, 37 }); //15
	mleft.PushBack({ 561, 421, 30, 37 }); //16
	mleft.PushBack({ 601, 421, 30, 37 }); //17
	mleft.PushBack({ 643, 421, 30, 37 }); //18
	mleft.PushBack({ 682, 421, 30, 37 }); //19
	mleft.PushBack({ 724, 421, 30, 37 }); //20
	mleft.PushBack({ 561, 469, 30, 37 }); //21
	mleft.PushBack({ 601, 469, 30, 37 }); //22
	mleft.PushBack({ 643, 469, 30, 37 }); //23
	mleft.PushBack({ 682, 469, 30, 37 }); //24
	mleft.PushBack({ 724, 469, 30, 37 }); //25
	mleft.PushBack({ 561, 515, 30, 37 }); //26
	mleft.PushBack({ 601, 515, 30, 37 }); //27
	mleft.PushBack({ 643, 515, 30, 37 }); //28 
	mleft.PushBack({ 682, 515, 30, 37 }); //29
	mleft.PushBack({ 724, 515, 30, 37 }); //30
	mleft.PushBack({ 561, 557, 30, 37 }); //31
	mleft.PushBack({ 601, 557, 30, 37 }); //32
	mleft.PushBack({ 643, 557, 30, 37 }); //33
	mleft.PushBack({ 682, 557, 30, 37 }); //34
	mleft.PushBack({ 724, 557, 30, 37 }); //35
	mleft.PushBack({ 561, 608, 30, 37 }); //36
	mleft.PushBack({ 601, 608, 30, 37 }); //37
	mleft.PushBack({ 643, 608, 30, 37 }); //38
	mleft.PushBack({ 682, 608, 30, 37 }); //39
	mleft.PushBack({ 724, 608, 30, 37 }); //40
	mleft.PushBack({ 561, 654, 30, 37 }); //41
	mleft.PushBack({ 601, 654, 30, 37 }); //42
	mleft.PushBack({ 643, 654, 30, 37 }); //43
	mleft.PushBack({ 682, 654, 30, 37 }); //44
	mleft.PushBack({ 724, 654, 30, 37 }); //45
	mleft.PushBack({ 561, 702, 30, 37 }); //46
	mleft.PushBack({ 601, 702, 30, 37 }); //47
	mleft.PushBack({ 643, 702, 30, 37 }); //48
	mleft.PushBack({ 682, 702, 30, 37 }); //49
	mleft.PushBack({ 724, 702, 30, 37 }); //50
	mleft.loop = true;
	mleft.speed = 0.25f;

	/*// left animation
	left.PushBack({ 561, 280, 30, 37 }); //1
	left.PushBack({ 601, 280, 30, 37 }); //2
	left.PushBack({ 643, 280, 30, 37 }); //3
	left.PushBack({ 682, 280, 30, 37 }); //4
	left.PushBack({ 724, 280, 30, 37 }); //5
	left.PushBack({ 561, 326, 30, 37 }); //6
	left.PushBack({ 601, 326, 30, 37 }); //7
	left.PushBack({ 643, 326, 30, 37 }); //8
	left.loop = false;
	left.speed = 0.25f;

	//more left animation
	mleft.PushBack({ 682, 326, 30, 37 }); //9
	mleft.PushBack({ 724, 326, 30, 37 }); //10
	mleft.PushBack({ 561, 374, 30, 37 }); //11
	mleft.PushBack({ 601, 374, 30, 37 }); //12
	mleft.PushBack({ 643, 374, 30, 37 }); //13
	mleft.PushBack({ 682, 374, 30, 37 }); //14
	mleft.PushBack({ 724, 374, 30, 37 }); //15
	mleft.PushBack({ 561, 421, 30, 37 }); //16
	mleft.PushBack({ 601, 421, 30, 37 }); //17
	mleft.PushBack({ 643, 421, 30, 37 }); //18
	mleft.PushBack({ 682, 421, 30, 37 }); //19
	mleft.PushBack({ 724, 421, 30, 37 }); //20
	mleft.PushBack({ 561, 469, 30, 37 }); //21
	mleft.PushBack({ 601, 469, 30, 37 }); //22
	mleft.PushBack({ 643, 469, 30, 37 }); //23
	mleft.PushBack({ 682, 469, 30, 37 }); //24
	mleft.PushBack({ 724, 469, 30, 37 }); //25
	mleft.PushBack({ 561, 515, 30, 37 }); //26
	mleft.PushBack({ 601, 515, 30, 37 }); //27
	mleft.PushBack({ 643, 515, 30, 37 }); //28
	mleft.PushBack({ 682, 515, 30, 37 }); //29
	mleft.PushBack({ 724, 515, 30, 37 }); //30
	mleft.PushBack({ 561, 557, 30, 37 }); //31
	mleft.PushBack({ 601, 557, 30, 37 }); //32
	mleft.PushBack({ 643, 557, 30, 37 }); //33
	mleft.PushBack({ 682, 557, 30, 37 }); //34
	mleft.PushBack({ 724, 557, 30, 37 }); //35
	mleft.PushBack({ 561, 608, 30, 37 }); //36
	mleft.PushBack({ 601, 608, 30, 37 }); //37
	mleft.PushBack({ 643, 608, 30, 37 }); //38
	mleft.PushBack({ 682, 608, 30, 37 }); //39
	mleft.PushBack({ 724, 608, 30, 37 }); //40
	mleft.PushBack({ 561, 654, 30, 37 }); //41
	mleft.PushBack({ 601, 654, 30, 37 }); //42
	mleft.PushBack({ 643, 654, 30, 37 }); //43
	mleft.PushBack({ 682, 654, 30, 37 }); //44
	mleft.PushBack({ 724, 654, 30, 37 }); //45
	mleft.PushBack({ 561, 702, 30, 37 }); //46
	mleft.PushBack({ 601, 702, 30, 37 }); //47
	mleft.PushBack({ 643, 702, 30, 37 }); //48
	mleft.PushBack({ 682, 702, 30, 37 }); //49
	mleft.PushBack({ 724, 702, 30, 37 }); //50
	mleft.loop = true;
	mleft.speed = 0.25f;*/

	// right animation
	right.PushBack({ 803, 284, 30, 37 }); //1
	right.PushBack({ 842, 284, 30, 37 }); //2
	right.PushBack({ 882, 284, 30, 37 }); //3
	right.PushBack({ 922, 284, 30, 37 }); //4
	right.PushBack({ 961, 284, 30, 37 }); //5
	right.PushBack({ 803, 331, 30, 37 }); //6
	right.PushBack({ 842, 331, 30, 37 }); //7
	right.PushBack({ 882, 331, 30, 37 }); //8
	right.loop = false;
	right.speed = 0.25f;

	//more right animation
	mright.PushBack({ 922, 331, 30, 37 }); //9
	mright.PushBack({ 961, 331, 30, 37 }); //10
	mright.PushBack({ 803, 378, 30, 37 }); //11
	mright.PushBack({ 842, 378, 30, 37 }); //12
	mright.PushBack({ 882, 378, 30, 37 }); //13
	mright.PushBack({ 922, 378, 30, 37 }); //14
	mright.PushBack({ 961, 378, 30, 37 }); //15
	mright.PushBack({ 803, 425, 30, 37 }); //16
	mright.PushBack({ 842, 425, 30, 37 }); //17
	mright.PushBack({ 882, 425, 30, 37 }); //18
	mright.PushBack({ 922, 425, 30, 37 }); //19
	mright.PushBack({ 961, 425, 30, 37 }); //20
	mright.PushBack({ 803, 472, 30, 37 }); //21
	mright.PushBack({ 842, 472, 30, 37 }); //22
	mright.PushBack({ 882, 472, 30, 37 }); //23
	mright.PushBack({ 922, 472, 30, 37 }); //24
	mright.PushBack({ 961, 472, 30, 37 }); //25
	mright.PushBack({ 803, 517, 30, 37 }); //26
	mright.PushBack({ 842, 517, 30, 37 }); //27
	mright.PushBack({ 882, 517, 30, 37 }); //28 
	mright.PushBack({ 922, 517, 30, 37 }); //29
	mright.PushBack({ 961, 517, 30, 37 }); //30
	mright.PushBack({ 803, 561, 30, 37 }); //31
	mright.PushBack({ 842, 561, 30, 37 }); //32
	mright.PushBack({ 882, 561, 30, 37 }); //33
	mright.PushBack({ 922, 561, 30, 37 }); //34
	mright.PushBack({ 961, 561, 30, 37 }); //35
	mright.PushBack({ 803, 612, 30, 37 }); //36
	mright.PushBack({ 842, 612, 30, 37 }); //37
	mright.PushBack({ 882, 612, 30, 37 }); //38
	mright.PushBack({ 922, 612, 30, 37 }); //39
	mright.PushBack({ 961, 612, 30, 37 }); //40
	mright.PushBack({ 803, 659, 30, 37 }); //41
	mright.PushBack({ 842, 659, 30, 37 }); //42
	mright.PushBack({ 882, 659, 30, 37 }); //43
	mright.PushBack({ 922, 659, 30, 37 }); //44
	mright.PushBack({ 961, 659, 30, 37 }); //45
	mright.PushBack({ 803, 706, 30, 37 }); //46
	mright.PushBack({ 842, 706, 30, 37 }); //47
	mright.PushBack({ 882, 706, 30, 37 }); //48
	mright.PushBack({ 922, 706, 30, 37 }); //49
	mright.PushBack({ 961, 706, 30, 37 }); //50
	mright.loop = true;
	mright.speed = 0.25f;

	collider = App->collision->AddCollider({ position.x, position.y, 30, 37 }, COLLIDER_PLAYER, (Module*)App->player);

	animation = &idle;

}

void Character_Tetsu::Move()
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

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
		{
			animation = &right;
			animation = &mright;
			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 30)) {
				position.x = (SCREEN_WIDTH - 30);
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
		{
			animation = &left;
			animation = &mleft;
			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT))
		{
			animation = &idle;
			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 37) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 37;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT))
		{
			animation = &idle;
			position.y += speed;
			if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 37) {
				position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 37;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT))
			animation = &mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT))
			animation = &idle;
	}
}

void Character_Tetsu::Laser() {
	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
			//LEVEL 0
			if (level == 0) {
				if (time == 0)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 8, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 20, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x , position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 3, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 2, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 26, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 31, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 4, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 8, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 20, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 32, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 9, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 5, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 33, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 37, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 3, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 2, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 9, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 19, position.y - 19, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 26, position.y - 15, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 31, position.y - 11, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 7, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
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
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 17, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 13, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 41, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 45, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					shot = false;
				}
				if (time == 5)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 15, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 11, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 6, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 7, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 21, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 27, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 34, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 39, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 43, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 10)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 15, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 12, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 7, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 28, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 35, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 40, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 44, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
				}
				if (time == 15)
				{
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 17, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 13, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 8, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x - 1, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 6, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 22, position.y - 21, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 29, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 36, position.y - 17, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 41, position.y - 13, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					App->particles->AddParticle(App->particles->laser_tetsu, position.x + 45, position.y - 9, 0, SPEED_LASER_PLAYER, COLLIDER_PLAYER_SHOT);
					time = 0;
					shot = true;
				}
				if (shot == false)
					time++;
			}
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
				if (App->player->characters[0])
					position.x = App->render->camera.x + 50;
				if (App->player->characters[1])
					position.x = App->render->camera.x + 150;
			}

			animation = &idle;

			if (position.y >= ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 80)
				position.y -= 1;

			else {
				if (this->scroll == 0) {
					if (App->player->characters[0])
						position.y = abs(App->render->camera.y / SCREEN_SIZE) + 240;
					if (App->player->characters[1])
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