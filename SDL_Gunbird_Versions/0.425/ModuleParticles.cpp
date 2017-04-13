#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
	explosion_balloon.anim.PushBack({ 14,123,92,86 });
	explosion_balloon.anim.PushBack({ 113,120,101,93 });
	explosion_balloon.anim.PushBack({ 221,115,105,102 });
	explosion_balloon.anim.PushBack({ 336,116,99,101 });
	explosion_balloon.anim.PushBack({ 9,228,111,131 });
	explosion_balloon.anim.PushBack({ 117,226,99,104 });
	explosion_balloon.anim.PushBack({ 226,225,100,106 });
	explosion_balloon.anim.PushBack({ 345,232,95,105 });
	explosion_balloon.anim.PushBack({ 20,370,82,82 });
	explosion_balloon.anim.PushBack({ 120,350,83,107 });
	explosion_balloon.anim.PushBack({ 236,367,65,81 });
	explosion_balloon.anim.PushBack({ 345,386,71,51 });
	explosion_balloon.anim.speed = 0.2f;
	// Yuan Nang laser
	laser.anim.PushBack({ 732, 31, 13, 29 });
	laser.speed.y = -4;
	laser.life = 1500;

	// Explosion Balloon
	//explosion_balloon.anim.PushBack({ 11,124,97,88 });;
	//explosion_balloon.life = 500;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/Yuan_Nang.png");

	//graphics2 = App->textures->Load("assets/Balloon.png");

	lasersound = Mix_LoadWAV("assets/gunbird-056_Shoot_YungNang.wav");
	
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);
	Mix_FreeChunk(lasersound);
	Mix_CloseAudio();
	lasersound = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				Mix_PlayChannel(-1, lasersound, 0);
			}
			App->render->Blit(graphics2, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			//	AddParticle(explosion, active[i]->position.x, active[i]->position.y, COLLIDER_NONE);
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		App->collision->EraseCollider(collider);
}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}