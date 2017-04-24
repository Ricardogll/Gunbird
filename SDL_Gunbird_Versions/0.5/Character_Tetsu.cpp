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
	idle.speed = 0.8f;

	// left animation
	left.PushBack({ 563, 282, 30, 37 }); //1
	left.PushBack({ 603, 282, 30, 37 }); //2
	left.PushBack({ 643, 282, 30, 37 }); //3
	left.PushBack({ 683, 282, 30, 37 }); //4
	left.PushBack({ 723, 282, 30, 37 }); //5
	left.PushBack({ 563, 329, 30, 37 }); //6
	left.loop = false;
	left.speed = 0.8f;

	//more left animation
	mleft.PushBack({ 604, 329, 27, 37 }); //7
	mleft.PushBack({ 642, 329, 27, 37 }); //8
	mleft.PushBack({ 683, 329, 27, 37 }); //9 
	mleft.PushBack({ 722, 329, 27, 37 }); //10 
	mleft.PushBack({ 564, 376, 27, 37 }); //11
	mleft.PushBack({ 602, 376, 27, 37 }); //12
	mleft.PushBack({ 644, 376, 27, 37 }); //13
	mleft.PushBack({ 682, 376, 27, 37 }); //14
	mleft.PushBack({ 724, 376, 27, 37 }); //15
	mleft.PushBack({ 562, 423, 27, 37 }); //16 
	mleft.PushBack({ 603, 423, 27, 37 }); //17 
	mleft.PushBack({ 642, 423, 27, 37 }); //18 
	mleft.PushBack({ 684, 423, 27, 37 }); //19
	mleft.PushBack({ 722, 423, 27, 37 }); //20
	mleft.PushBack({ 565, 470, 27, 37 }); //21 
	mleft.PushBack({ 602, 470, 27, 37 }); //22
	mleft.PushBack({ 644, 470, 27, 37 }); //23
	mleft.PushBack({ 682, 470, 27, 37 }); //24
	mleft.PushBack({ 723, 470, 27, 37 }); //25
	mleft.PushBack({ 562, 517, 27, 37 }); //26
	mleft.PushBack({ 604, 517, 27, 37 }); //27
	mleft.PushBack({ 639, 515, 27, 37 }); //28 
	mleft.PushBack({ 684, 517, 27, 37 }); //29
	mleft.PushBack({ 722, 515, 27, 37 }); //30
	mleft.PushBack({ 561, 559, 27, 37 }); //31
	mleft.PushBack({ 602, 559, 27, 37 }); //32
	mleft.PushBack({ 643, 559, 27, 37 }); //33
	mleft.PushBack({ 681, 559, 27, 37 }); //34
	mleft.PushBack({ 724, 559, 27, 37 }); //35
	mleft.PushBack({ 558, 610, 27, 37 }); //36
	mleft.PushBack({ 600, 610, 27, 37 }); //37
	mleft.PushBack({ 637, 610, 27, 37 }); //38
	mleft.PushBack({ 679, 610, 27, 37 }); //39
	mleft.PushBack({ 718, 610, 27, 37 }); //40
  /*mleft.PushBack({ 558, 656, 30, 37 }); //41
 mleft.PushBack({ 599, 656, 30, 37 }); //42
  mleft.PushBack({ 639, 656, 30, 37 }); //43
  mleft.PushBack({ 679, 656, 30, 37 }); //44
  mleft.PushBack({ 719, 656, 30, 37 }); //45
  mleft.PushBack({ 559, 703, 30, 37 }); //46
  mleft.PushBack({ 599, 703, 30, 37 }); //47
  mleft.PushBack({ 637, 703, 30, 37 }); //48
  mleft.PushBack({ 678, 703, 30, 37 }); //49
  mleft.PushBack({ 719, 703, 30, 37 }); //50*/
	mleft.loop = true;
	mleft.speed = 0.8f;

	// right animation
	right.PushBack({ 961, 284, 30, 37 }); //1
	right.PushBack({ 922, 284, 30, 37 }); //2
	right.PushBack({ 882, 284, 30, 37 }); //3
	right.PushBack({ 842, 284, 30, 37 }); //4
	right.PushBack({ 803, 284, 30, 37 }); //5
	right.PushBack({ 961, 331, 30, 37 }); //6
	right.loop = false;
	right.speed = 0.8f;

	//more right animation
	mright.PushBack({ 922, 331, 27, 37 }); //7
	mright.PushBack({ 884, 331, 27, 37 }); //8
	mright.PushBack({ 843, 331, 27, 37 }); //9
	mright.PushBack({ 804, 331, 27, 37 }); //10 
	mright.PushBack({ 962, 378, 27, 37 }); //11
	mright.PushBack({ 924, 378, 27, 37 }); //12
	mright.PushBack({ 882, 378, 27, 37 }); //13
	mright.PushBack({ 844, 378, 27, 37 }); //14
	mright.PushBack({ 802, 378, 27, 37 }); //15 
	mright.PushBack({ 964, 425, 27, 37 }); //16
	mright.PushBack({ 923, 425, 27, 37 }); //17
	mright.PushBack({ 884, 425, 27, 37 }); //18
	mright.PushBack({ 842, 425, 27, 37 }); //19
	mright.PushBack({ 804, 425, 27, 37 }); //20 
	mright.PushBack({ 961, 472, 27, 37 }); //21
	mright.PushBack({ 924, 472, 27, 37 }); //22
	mright.PushBack({ 882, 472, 27, 37 }); //23
	mright.PushBack({ 844, 472, 27, 37 }); //24
	mright.PushBack({ 803, 472, 27, 37 }); //25 
	mright.PushBack({ 964, 519, 27, 37 }); //26
	mright.PushBack({ 922, 519, 27, 37 }); //27
	mright.PushBack({ 887, 517, 27, 37 }); //28 
	mright.PushBack({ 842, 519, 27, 37 }); //29
	mright.PushBack({ 804, 517, 27, 37 }); //30 
	mright.PushBack({ 965, 561, 27, 37 }); //31
	mright.PushBack({ 924, 561, 27, 37 }); //32
	mright.PushBack({ 883, 561, 27, 37 }); //33
	mright.PushBack({ 845, 561, 27, 37 }); //34
	mright.PushBack({ 802, 561, 27, 37 }); //35
	mright.PushBack({ 963, 612, 27, 37 }); //36
	mright.PushBack({ 921, 612, 27, 37 }); //37
	mright.PushBack({ 884, 612, 27, 37 }); //38
	mright.PushBack({ 842, 612, 27, 37 }); //39
	mright.PushBack({ 803, 612, 27, 37 }); //40
 /*mright.PushBack({ 803, 659, 30, 37 }); //41
   mright.PushBack({ 842, 659, 30, 37 }); //42
   mright.PushBack({ 882, 659, 30, 37 }); //43
   mright.PushBack({ 922, 659, 30, 37 }); //44
   mright.PushBack({ 961, 659, 30, 37 }); //45
   mright.PushBack({ 803, 706, 30, 37 }); //46
   mright.PushBack({ 842, 706, 30, 37 }); //47
   mright.PushBack({ 882, 706, 30, 37 }); //48
   mright.PushBack({ 922, 706, 30, 37 }); //49
   mright.PushBack({ 961, 706, 30, 37 }); //50*/
	mright.loop = true;
	mright.speed = 0.8f;

	// blit idle animation
	blit_idle.PushBack({ 572, 0, 30, 37 }); //1
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 652, 0, 30, 37 }); //3
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 732, 0, 30, 37 }); //5
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 612, 47, 30, 37 }); //7
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 692, 47, 30, 37 }); //9
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 572, 94, 30, 37 }); //11
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 652, 94, 30, 37 }); //13
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 732, 94, 30, 37 }); //15
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 612, 141, 30, 37 }); //17
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 692, 141, 30, 37 }); //19
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 572, 188, 30, 37 }); //21
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.PushBack({ 652, 188, 30, 37 }); //23
	blit_idle.PushBack({ 0, 0, 0, 0 });
	blit_idle.speed = 0.8f;

	// left animation
	blit_left.PushBack({ 563, 282, 30, 37 }); //1
	blit_left.PushBack({ 0, 0, 0, 0 });
	blit_left.PushBack({ 643, 282, 30, 37 }); //3
	blit_left.PushBack({ 0, 0, 0, 0 });
	blit_left.PushBack({ 723, 282, 30, 37 }); //5
	blit_left.PushBack({ 0, 0, 0, 0 });
	blit_left.loop = false;
	blit_left.speed = 0.8f;

	//more left animation
	blit_mleft.PushBack({ 604, 329, 27, 37 }); //7
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 683, 329, 27, 37 }); //9 
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 564, 376, 27, 37 }); //11
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 644, 376, 27, 37 }); //13
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 724, 376, 27, 37 }); //15
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 603, 423, 27, 37 }); //17 
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 684, 423, 27, 37 }); //19
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 565, 470, 27, 37 }); //21 
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 644, 470, 27, 37 }); //23
	blit_mleft.PushBack({ 0, 0, 0, 0 }); 
	blit_mleft.PushBack({ 723, 470, 27, 37 }); //25
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 604, 517, 27, 37 }); //27
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 684, 517, 27, 37 }); //29
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 561, 559, 27, 37 }); //31
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 643, 559, 27, 37 }); //33
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 724, 559, 27, 37 }); //35
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 600, 610, 27, 37 }); //37
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.PushBack({ 679, 610, 27, 37 }); //39
	blit_mleft.PushBack({ 0, 0, 0, 0 });
	blit_mleft.loop = true;
	blit_mleft.speed = 0.8f;

	// right animation
	blit_right.PushBack({ 961, 284, 30, 37 }); //1
	blit_right.PushBack({ 0, 0, 0, 0 });
	blit_right.PushBack({ 882, 284, 30, 37 }); //3
	blit_right.PushBack({ 0, 0, 0, 0 });
	blit_right.PushBack({ 803, 284, 30, 37 }); //5
	blit_right.PushBack({ 0, 0, 0, 0 });
	blit_right.loop = false;
	blit_right.speed = 0.8f;

	//more right animation
	blit_mright.PushBack({ 922, 331, 27, 37 }); //7
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 843, 331, 27, 37 }); //9
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 962, 378, 27, 37 }); //11
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 882, 378, 27, 37 }); //13
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 802, 378, 27, 37 }); //15 
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 923, 425, 27, 37 }); //17
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 842, 425, 27, 37 }); //19
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 961, 472, 27, 37 }); //21
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 882, 472, 27, 37 }); //23
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 803, 472, 27, 37 }); //25 
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 922, 519, 27, 37 }); //27
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 842, 519, 27, 37 }); //29
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 965, 561, 27, 37 }); //31
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 883, 561, 27, 37 }); //33
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 802, 561, 27, 37 }); //35
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 921, 612, 27, 37 }); //37
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 842, 612, 27, 37 }); //39
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.PushBack({ 803, 612, 27, 37 }); //40
	blit_mright.PushBack({ 0, 0, 0, 0 });
	blit_mright.loop = true;
	blit_mright.speed = 0.8f;

	collider = App->collision->AddCollider({ position.x, position.y, 30, 37 }, COLLIDER_PLAYER, TETSU, (Module*)App->player);

	animation = &idle;

}

void Character_Tetsu::Move()
{
	if (inmortal == false)
		animation = &idle;
	else
		animation = &blit_idle;

	int speed = SPEED_TETSU;

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

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false) {
				animation = &right;
				animation = &mright;
			}

			else {
				animation = &blit_right;
				animation = &blit_mright;
			}

			position.x += speed;
			if (position.x > (SCREEN_WIDTH - 30)) {
				position.x = (SCREEN_WIDTH - 30);
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false) {
				animation = &left;
				animation = &mleft;
			}

			else {
				animation = &blit_left;
				animation = &blit_mleft;
			}

			position.x -= speed;
			if (position.x < 0) {
				position.x = 0;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false)
				animation = &idle;
			else
				animation = &blit_idle;

			position.y -= speed;
			if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE)) {
				position.y = (abs(App->render->camera.y) / SCREEN_SIZE) ;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT))
		{
			if (inmortal == false)
				animation = &idle;
			else
				animation = &blit_idle;

			position.y += speed;
			if (position.y > ((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE - 37) {
				position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE - 37;
			}
		}

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &mright;
			else
				animation = &blit_mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &mleft;
			else
				animation = &blit_mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &mright;
			else
				animation = &blit_mright;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &mleft;
			else
				animation = &blit_mleft;

		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT))
			if (inmortal == false)
				animation = &idle;
			else
				animation = &blit_idle;
	}
}

void Character_Tetsu::Laser() {
	if (this->desactivateInput == false) {
		if ((App->player->characters[0]->type == TETSU && App->input->keyboard[SDL_SCANCODE_LCTRL] == KEY_STATE::KEY_DOWN || (0 < time)) ||
			(App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU && App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN || (0 < time))) {
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

			if (inmortal == false)
				animation = &idle;
			else
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

void Character_Tetsu::OnCollision(Collider* collider) {

}