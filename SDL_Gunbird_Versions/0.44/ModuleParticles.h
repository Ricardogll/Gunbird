#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

#include "SDL_mixer\include\SDL_mixer.h"
#include "SDL/include/SDL.h"

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];
	//uint last_particle = 0;

	bool up;
	bool left;

public:
	Particle laser_yang_v0_0;
	Particle laser_yang_v0_1;
	Particle laser_yang_v0_2;

	Particle laser_yang_v1_0;
	Particle laser_yang_v1_1;
	Particle laser_yang_v1_2;

	Particle laser_yang_v2_0;
	Particle laser_yang_v2_1;
	Particle laser_yang_v2_2;

	Particle laser_yang_v3_0;
	Particle laser_yang_v3_1;

	Particle yang_sword;

	Particle explosion_balloon;
	Particle power_up;
	Mix_Chunk* lasersound = nullptr;
};

#endif // __MODULEPARTICLES_H__