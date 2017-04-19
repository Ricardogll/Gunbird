 #include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_Balloon.h"
#include "Enemy_Turret.h"
#include "Enemy_building.h"
#include "Enemy_building2.h"
#include "Enemy_flag.h"
#include "Enemy_vase.h"
#include "Enemy_drone.h"
#include "Enemy_Missile.h"

#include "PowerUp.h"

#define SPAWN_MARGIN 250 //50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	//Path Balloon Castle
	balloonCastle.PushBack({ 0.0f, 1.5f }, 50); 
	balloonCastle.PushBack({ 0.0f, 0.0f }, 100); 
	balloonCastle.PushBack({ 0.0f, -1.5f }, 150); 
	balloonCastle.PushBack({ 0.0f, 0.0f }, 100); 
	balloonCastle.PushBack({ 0.0f, 1.5f }, 142);
	balloonCastle.loop = false;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/enemies/enemies.png");
	

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, ENEMY_MOVE move, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].move = move;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::BALLOON:
			enemies[i] = new Enemy_Balloon(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BALLOON;
			switch (info.move)
			{
			case ENEMY_MOVE::BALLOON_CASTLE:
				enemies[i]->path = balloonCastle;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::TURRET:
			enemies[i] = new Enemy_Turret(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TURRET;
			break;
		case ENEMY_TYPES::MISSILE:
			enemies[i] = new Enemy_Missile(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::MISSILE;
			break;
		case ENEMY_TYPES::POWERUP:
			enemies[i] = new PowerUp(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::POWERUP;
			/*switch (info.move)
			{
			case ENEMY_MOVE::POWERUP_MOV:
				enemies[i]->path = powerUp_Path;
				break;
			}*/
			break;
		case ENEMY_TYPES::BUILDING:
			enemies[i] = new Enemy_Building(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BUILDING;
			break;
			case ENEMY_TYPES::BUILDING2:
				enemies[i] = new Enemy_Building2(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BUILDING2;
				break;
			case ENEMY_TYPES::FLAG:
				enemies[i] = new Enemy_Flag(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::FLAG;
				break;
			case ENEMY_TYPES::VASE:
				enemies[i] = new Enemy_Vase(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::VASE;
				break;
			case ENEMY_TYPES::DRONE:
				enemies[i] = new Enemy_Drone(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::DRONE;
				break;



		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			if (enemies[i]/*->type == ENEMY_TYPES::BALLOON*/ ) {
				if (enemies[i]->getHitPoints() == 0) {
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL);
					//Spawn Power Up when an enemy dies
					//this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
					App->particles->AddParticle(App->particles->power_up, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, COLLIDER_POWER_UP);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}	
			}
			//Erase Power Up when the player grabs it
			else if (enemies[i]->type == ENEMY_TYPES::POWERUP && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER) {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
		}
	}
}