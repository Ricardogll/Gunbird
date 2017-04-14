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

	//Explosion
	explosion_balloon.anim.PushBack({ 23,37,92,85 });
	explosion_balloon.anim.PushBack({ 122,33,101,93 });
	explosion_balloon.anim.PushBack({ 230,28,105,102 });
	explosion_balloon.anim.PushBack({ 336,116,99,101 });
	explosion_balloon.anim.PushBack({ 18,141,111,131 });
	explosion_balloon.anim.PushBack({ 127,140,99,104 });
	explosion_balloon.anim.PushBack({ 234,138,100,106 });
	explosion_balloon.anim.PushBack({ 349,145,98,105 });
	explosion_balloon.anim.PushBack({ 29,282,82,82 });
	explosion_balloon.anim.PushBack({ 129,264,83,107 });
	explosion_balloon.anim.PushBack({ 245,281,65,81 });
	explosion_balloon.anim.PushBack({ 357,301,71,51 });
	explosion_balloon.anim.loop = false;
	explosion_balloon.anim.speed = 0.5f;

	// Yuan Nang laser
	laser.anim.PushBack({ 512, 40, 16, 30 });
	laser.speed.y = -20;
	laser.life = 1500;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/particles.png");
	if(laser.life != NULL)
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
		collider->to_delete = true;
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