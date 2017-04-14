#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer2.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 150;
	position.y = 2610;

	// idle animation
	idle.PushBack({ 4, 64, 20, 32 }); //1
	idle.PushBack({ 36, 64, 20, 32 }); //2
	idle.PushBack({ 67, 64, 20, 32 }); //3
	idle.PushBack({ 100, 64, 20, 32 }); //4

	idle.speed = 0.08f;

	// left animation
	right.PushBack({ 5, 96, 23, 32 });
	right.PushBack({ 37, 96, 23, 32 });
	right.PushBack({ 68, 96, 23, 32 });
	right.PushBack({ 101, 96, 23, 32 });
	right.speed = 0.08f;

	// right animation
	left.PushBack({ 0, 0, 23, 32 });
	left.PushBack({ 31, 0, 23, 32 });
	left.PushBack({ 64, 0, 23, 32 });
	left.PushBack({ 96, 0, 23, 32 });
	left.speed = 0.08f;

}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("assets/Marion.png");
	collider = App->collision->AddCollider({ position.x, position.y, 23, -32 }, COLLIDER_PLAYER, this);
	return ret;
}

bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player 2");
	App->textures->Unload(graphics);
	App->collision->EraseCollider(collider);

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	if ((position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 32))
		position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 32;

	else {
		if (movement == false) {
			position.y -= 1;
		}
	}

	int speed = 8;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &right;
		position.x += speed;
		if (position.x > (SCREEN_WIDTH - 23)) {
			position.x = (SCREEN_WIDTH - 23);
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &left;
		position.x -= speed;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y -= speed;
		if (position.y < (abs(App->render->camera.y) / SCREEN_SIZE) + 32) {
			position.y = (abs(App->render->camera.y) / SCREEN_SIZE) + 32;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &idle;
		position.y += speed;
		if (position.y >((abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE))) / SCREEN_SIZE) {
			position.y = (abs(App->render->camera.y) + (SCREEN_HEIGHT*SCREEN_SIZE)) / SCREEN_SIZE;
		}
	}

	if(App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		current_animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		current_animation = &left;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		current_animation = &right;

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		current_animation = &left;


	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT
		&& App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		current_animation = &idle;

	collider->SetPos(position.x, position.y);
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (graphics != nullptr && collider == c1)
	{
		//App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE);
	}
}