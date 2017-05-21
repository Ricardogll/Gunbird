#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 200
#define SPEED_LASER_PLAYER -10
#define SPEED_SWORD_YUAN_NANG -5

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
	uint type;
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

	void AddParticle(const Particle& particle, int x, int y, int speed_x, int speed_y, uint type, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
	//uint last_particle = 0;

	bool up;
	bool left;

public:
	Particle* active[MAX_ACTIVE_PARTICLES];

	Particle laser_nang_0;
	Particle laser_nang_1;
	Particle laser_nang_2;
	Particle laser_nang_3;
	Particle laser_nang_4;
	Particle laser_nang_5;
	Particle laser_nang_6;
	Particle laser_nang_7;
	Particle laser_nang_8;
	Particle laser_nang_9;
	Particle laser_nang_10;
	Particle laser_nang_11;
	Particle laser_nang_12;
	Particle laser_nang_13;
	Particle laser_nang_14;

	Particle nang_sword;	

	Particle laser_marion_0;
	Particle laser_marion_1;
	Particle laser_marion_2;

	Particle laser_marion_left_0;
	Particle laser_marion_left_1;
	Particle laser_marion_left_2;

	Particle laser_marion_right_0;
	Particle laser_marion_right_1;
	Particle laser_marion_right_2;

	Particle laser_ash;

	Particle laser_tetsu;

	Particle laser_valnus_0;
	Particle laser_valnus_1;
	Particle laser_valnus_2;
	Particle laser_valnus_3;

	Particle shot_enemy;
	Particle shot_turret;
	Particle explosion_turret;
	Particle explosion_balloon;
	Particle power_up;

	uint laser_nang_fx;
	uint laser_marion_fx;
	uint laser_ash_fx;
	uint laser_tetsu_fx;
	uint laser_valnus_fx;

};

#endif // __MODULEPARTICLES_H__