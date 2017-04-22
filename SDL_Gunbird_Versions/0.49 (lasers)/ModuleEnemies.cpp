 #include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "Enemy.h"
#include "Enemy_Balloon.h"
#include "Enemy_Turret.h"
#include "Enemy_building.h"
#include "Enemy_building2.h"
#include "Enemy_vase.h"
#include "Enemy_drone.h"
#include "coin.h"
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

	//FLAG
	flag.PushBack({ 745,539,64,21 });
	flag.PushBack({ 821,541,64,21 });
	flag.PushBack({ 745,565,64,21 });
	flag.PushBack({ 821,570,64,21 });
	flag.PushBack({ 745,590,64,21 });
	flag.PushBack({ 821,597,64,21 });
	flag.PushBack({ 745,615,64,21 });
	flag.speed = 0.08f;

	

}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/enemies/enemies.png");
	building_destroyed == false;

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

	if (building_destroyed == false)
		App->render->Blit(sprites, 177, 1049, &(flag.GetCurrentFrame()));

	if (building2_destroyed == false)
		App->render->Blit(sprites, 110, 785, &(flag.GetCurrentFrame()));


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
			break;
		case ENEMY_TYPES::COIN:
			enemies[i] = new Coin (info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::COIN;
			break;
		case ENEMY_TYPES::BUILDING:
			enemies[i] = new Enemy_Building(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BUILDING;
			break;
			case ENEMY_TYPES::BUILDING2:
				enemies[i] = new Enemy_Building2(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::BUILDING2;
				break;
			case ENEMY_TYPES::VASE:
				enemies[i] = new Enemy_Vase(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::VASE;
				break;
			case ENEMY_TYPES::DRONE:
				enemies[i] = new Enemy_Drone(info.x, info.y);
				enemies[i]->type = ENEMY_TYPES::DRONE;
				switch (info.move)
				{

				case ENEMY_MOVE::DRONE_CASTLE:
					enemies[i]->path = drone;
					break;
				default:
					break;
				}
			

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
			if (enemies[i]->type == ENEMY_TYPES::BALLOON ) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					//Spawn Power Up when an enemy dies
					this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}	
			}
			if (enemies[i]->type == ENEMY_TYPES::TURRET) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::MISSILE) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BUILDING) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					building_destroyed = true;
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BUILDING2) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					building2_destroyed = true;
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::VASE){
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					//Spawn Power Up when an enemy dies
					this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
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
			else if (enemies[i]->type == ENEMY_TYPES::COIN&& c2->type == COLLIDER_TYPE::COLLIDER_PLAYER) {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
		}
	}
}

void ModuleEnemies::scoreEnemy(Enemy* enemy, Collider* c2) {
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		//PLAYER 1
		if (c2->type==COLLIDER_PLAYER_SHOT && c2->character == YUAN_NANG) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == YUAN_NANG)
					scoreP1 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == MARION) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == MARION)
				scoreP1 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == ASH) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == ASH)
				scoreP1 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == TETSU) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == TETSU)
				scoreP1 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == VALNUS) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == VALNUS)
				scoreP1 = enemy->score;
		}
		//PLAYER 2
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == YUAN_NANG) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == YUAN_NANG)
				scoreP2 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == MARION) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == MARION)
				scoreP2 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == ASH) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == ASH)
				scoreP2 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == TETSU) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == TETSU)
				scoreP2 = enemy->score;
		}
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == VALNUS) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == VALNUS)
				scoreP2 = enemy->score;
		}

	}

	if (App->player->characters[0] != nullptr) {
		App->player->characters[0]->score += scoreP1;
	}
	if (App->player->characters[1] != nullptr) {
		App->player->characters[1]->score += scoreP2;
	}

}