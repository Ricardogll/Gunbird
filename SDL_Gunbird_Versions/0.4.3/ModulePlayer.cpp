#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "ModuleParticles.h"

ModulePlayer::ModulePlayer()
{
	position.x = 0;
	position.y = 0;

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
	left.speed = 0.25f;

	// more left animation
	mleft.PushBack({ 18, 350, 26, 48 });
	mleft.PushBack({ 73, 351, 27, 48 });
	mleft.PushBack({ 120, 351, 27, 48 });
	mleft.PushBack({ 170, 351, 27, 48 });
	mleft.loop = true;
	mleft.speed = 0.25f;

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

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	levelPlayer1 = 0;

	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("assets/Yuan_Nang.png");

	collider = App->collision->AddCollider({ position.x, position.y, 27, -48 }, COLLIDER_PLAYER, this);
	return ret;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player 1");
	App->textures->Unload(graphics);
	App->collision->EraseCollider(collider);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 8;

	if ((position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 48))
		position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 48;

	else {
		if (movement == false) {
			position.y -= 1;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &right;
		current_animation = &mright;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 27)) {
			position.x = (SCREEN_WIDTH - 27);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &left;
		current_animation = &mleft;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 48) {
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 48;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)))/SCREEN_SIZE) {
		position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))/SCREEN_SIZE;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || (0 < time))
	{ 
		if (levelPlayer1 == 0) {
			if (time == 0) 
			{
				App->particles->AddParticle(App->particles->laser, position.x + 9, position.y - 30, COLLIDER_PLAYER_SHOT);
				shot = false;
			}
			if (time == 3)
			{
				App->particles->AddParticle(App->particles->laser, position.x + 9, position.y - 30, COLLIDER_PLAYER_SHOT);
			}
			if (time == 6) 
			{
				App->particles->AddParticle(App->particles->laser, position.x + 9, position.y - 30, COLLIDER_PLAYER_SHOT);
			}
			if (time == 9)
			{
				App->particles->AddParticle(App->particles->laser, position.x + 9, position.y - 30, COLLIDER_PLAYER_SHOT);
				time = 0;
				shot = true;
			} 
			if (shot == false)
				time++;
		}
		
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		current_animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		current_animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		current_animation = &mright;

	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		current_animation = &mleft;

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		current_animation = &idle;


	collider->SetPos(position.x, position.y);
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (graphics != nullptr && collider == c1)
	{
		//App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE);
		
	}
}