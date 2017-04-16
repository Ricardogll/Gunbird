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
	laser_yang_v0_0.anim.PushBack({ 511, 40, 17, 30 });
	laser_yang_v0_0.speed.y = -20;
	laser_yang_v0_0.life = 1500;
	laser_yang_v0_1.anim.PushBack({ 560, 39, 17, 30 });
	laser_yang_v0_1.speed.y = -20;
	laser_yang_v0_1.life = 1500;
	laser_yang_v0_2.anim.PushBack({ 604, 39, 17, 30 });
	laser_yang_v0_2.speed.y = -20;
	laser_yang_v0_2.life = 1500;

	laser_yang_v1_0.anim.PushBack({ 512, 83, 17, 42 });
	laser_yang_v1_0.speed.y = -20;
	laser_yang_v1_0.life = 1500;
	laser_yang_v1_1.anim.PushBack({ 561, 81, 17, 42 });
	laser_yang_v1_1.speed.y = -20;
	laser_yang_v1_1.life = 1500;
	laser_yang_v1_2.anim.PushBack({ 602, 80, 17, 42 });
	laser_yang_v1_2.speed.y = -20;
	laser_yang_v1_2.life = 1500;

	laser_yang_v2_0.anim.PushBack({ 510, 139, 23, 38 });
	laser_yang_v2_0.speed.y = -20;
	laser_yang_v2_0.life = 1500;
	laser_yang_v2_1.anim.PushBack({ 557, 139, 23, 38 });
	laser_yang_v2_1.speed.y = -20;
	laser_yang_v2_1.life = 1500;
	laser_yang_v2_2.anim.PushBack({ 600, 138, 23, 38 });
	laser_yang_v2_2.speed.y = -20;
	laser_yang_v2_2.life = 1500;

	laser_yang_v3_0.anim.PushBack({ 513, 188, 45, 38 });
	laser_yang_v3_0.speed.y = -20;
	laser_yang_v3_0.life = 1500;
	laser_yang_v3_1.anim.PushBack({ 584, 186, 45, 38 });
	laser_yang_v3_1.speed.y = -20;
	laser_yang_v3_1.life = 1500;

	yang_sword.anim.PushBack({ 513, 233, 13, 32 });
	yang_sword.anim.PushBack({ 537, 233, 13, 32 });
	yang_sword.anim.PushBack({ 565, 233, 13, 32 });
	yang_sword.anim.PushBack({ 592, 233, 13, 32 });
	yang_sword.anim.PushBack({ 618, 233, 13, 32 });
	yang_sword.speed.y = -15;
	yang_sword.life = 1500;

	//Power Up SI NO VA PUES SE BORRA
	power_up.anim.PushBack({ 685, 147, 22, 13 });
	power_up.anim.PushBack({ 710, 147, 22, 13 });
	power_up.anim.PushBack({ 735, 147, 22, 13 });
	power_up.anim.PushBack({ 760, 147, 22, 13 });
	power_up.anim.PushBack({ 785, 147, 22, 13 });
	power_up.anim.PushBack({ 685, 163, 22, 13 });
	power_up.anim.PushBack({ 710, 163, 22, 13 });
	power_up.anim.PushBack({ 735, 163, 22, 13 });
	power_up.anim.PushBack({ 760, 163, 22, 13 });
	power_up.anim.PushBack({ 785, 163, 22, 13 });
	power_up.anim.PushBack({ 685, 180, 22, 13 });
	power_up.anim.PushBack({ 710, 180, 22, 13 });
	power_up.anim.PushBack({ 735, 180, 22, 13 });
	power_up.anim.PushBack({ 760, 180, 22, 13 });
	power_up.anim.PushBack({ 785, 180, 22, 13 });
	power_up.anim.PushBack({ 685, 199, 22, 13 });
	power_up.anim.PushBack({ 710, 199, 22, 13 });
	power_up.anim.PushBack({ 735, 199, 22, 13 });
	power_up.anim.PushBack({ 760, 199, 22, 13 });
	power_up.anim.speed = 0.8f;
	power_up.life = 150000;

	//Move up and right
	if (up == true)
		power_up.speed.y += 1;
	else
		power_up.speed.y -= 1;

	if (left == true)
		power_up.speed.x += 1;
	else
		power_up.speed.x -= 1;

	//When it hits the borders turn arround
	if (power_up.position.x < 0)
		left = false;

	if (power_up.position.x > SCREEN_WIDTH - 22)
		left = true;

	if (power_up.position.y < 0)
		up = false;

	if (power_up.position.y > SCREEN_HEIGHT - 13)
		up = true;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("assets/particles/particles.png");
	if(laser_yang_v0_0.life != NULL)
	lasersound = Mix_LoadWAV("assets/audio/sound/gunbird-056_Shoot_YungNang.wav");
	up = true;
	left = true;
	
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