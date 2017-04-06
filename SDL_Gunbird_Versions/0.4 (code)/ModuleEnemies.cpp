#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "ModuleParticles.h"

ModuleEnemies::ModuleEnemies()
{
	position.x = 50;
	position.y = 2410;

	// idle animation
	balloon.PushBack({ 11, 6, 44, 55 }); //1
	balloon.speed = 0.08f;

	// Explosion Balloon
	explosion_balloon.PushBack({ 11,124,97,88 });;
}

ModuleEnemies::~ModuleEnemies()
{}

// Load assets
bool ModuleEnemies::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("assets/Balloon.png");
	collider = App->collision->AddCollider({position.x, position.y, 44, 55 }, COLLIDER_ENEMY, this);
	return ret;
}

bool ModuleEnemies::CleanUp()
{
	LOG("Unloading enemies");
	App->textures->Unload(graphics);
	App->collision->EraseCollider(collider);

	return true;
}

// Update: draw background
update_status ModuleEnemies::Update()
{
	Animation* current_animation_balloon = &balloon;
	int speed = 3;

	collider->SetPos(position.x, position.y-55);
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation_balloon->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	if (graphics != nullptr && collider == c1)
	{
		//current_animation_balloon = &explosion_balloon;
		graphics = nullptr;
		//App->particles->AddParticle(App->particles->explosion_balloon, position.x, position.y, COLLIDER_NONE);
	}
}