#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "Enemy.h"
#include "Enemy_Balloon.h"
#include "Enemy_Turret.h"
#include "Enemy_turret2.h"
#include "Enemy_building.h"
#include "Enemy_building2.h"
#include "Enemy_vase.h"
#include "Enemy_Drone.h"
#include "Enemy_Robot.h"
#include "Enemy_Missile.h"
#include "Enemy_Turret3.h"
#include "Enemy_Rcannon.h"
#include "Enemy_Boss.h"
#include "PowerUp.h"
#include "Coin.h"
#include "ModuleBackgroundCastle.h"

#define SPAWN_MARGIN 70

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	//Path Balloon Castle
	balloonCastle.PushBack({ 0.0f, 0.0f }, 420);
	balloonCastle.PushBack({ 0.0f, 0.5f }, 100);
	balloonCastle.PushBack({ 0.0f, 0.0f }, 120);
	balloonCastle.PushBack({ 0.0f, -1.5f }, 60);
	balloonCastle.PushBack({ 0.0f, 0.0f }, 300);
	balloonCastle.PushBack({ 0.0f, 1.5f }, 300);
	balloonCastle.loop = false;

	//Path Turret1
	turret1.PushBack({ 0.0f, 0.0f }, 150);
	turret1.PushBack({ 0.5f, 0.0f }, 150);
	turret1.loop = false;

	//Path Turret2
	turret2.PushBack({ 0.0f, 0.0f }, 150);
	turret2.PushBack({ -0.5f, 0.0f }, 150);
	turret2.loop = false;

	//Path Missile1
	missile1.PushBack({ 1.5f, 1.5f }, 15000);
	missile1.loop = true;

	// Path Robot
	robot.PushBack({ 0.0f,-0.0f }, 400);
	robot.PushBack({ 0.0f,-0.5f }, 300);
	robot.loop = false;

	//Path Rcannon
	rcannon.PushBack({ 0.0f,1.5f }, 33);
	rcannon.PushBack({ 0.0f,0.0f }, 265);
	rcannon.PushBack({ 0.0f,-0.5f }, 300);
	rcannon.loop = false;

	//Path Missile2
	missile2.PushBack({ 0.0f, 0.0f }, 250);
	missile2.PushBack({ -5.0f, -0.3f }, 50);
	missile2.PushBack({ 0.0f, -0.3f }, 70);
	missile2.PushBack({ 0.0f, 3.0f }, 150);
	missile2.loop = false;

	//Path Missile3
	missile3.PushBack({ 0.0f, 0.0f }, 0);
	missile3.PushBack({ 0.0f, 1.5f }, 1500);
	missile3.loop = false;

	//Path Missile 4
	missile4.PushBack({ 0.0f, 0.0f }, 0);
	missile4.PushBack({ 1.0f,1.0f }, 1500);
	missile4.loop = false;

	//Path Drone
	//drone1.PushBack({ 0.0f, 0.5f }, 0);
	drone1.PushBack({ 0.5f,0.5f }, 2000);
	drone1.loop = false;

	//Path Drone 2
	drone2.PushBack({ 0.0f, 0.5f }, 200);
	drone2.PushBack({ -0.3f,0.3f }, 2000);
	drone2.loop = false;

	//FLAG
	flag.PushBack({ 745,539,64,21 });
	flag.PushBack({ 821,541,64,21 });
	flag.PushBack({ 745,565,64,21 });
	flag.PushBack({ 821,570,64,21 });
	flag.PushBack({ 745,590,64,21 });
	flag.PushBack({ 821,597,64,21 });
	flag.PushBack({ 745,615,64,21 });
	flag.speed = 0.1f;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("assets/enemies/enemies.png");
	explosion1 = App->audio->LoadWAV("assets/audio/sound/gunbird-069_Explosion01.wav");
	building_destroyed = false;
	building2_destroyed = false;
	robot_destroyed = false;

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].y > (abs(App->render->camera.y) / SCREEN_SIZE) - SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].y);
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

	//if (App->input->keyboard[SDL_SCANCODE_ESCAPE]) {
	//	for (uint i = 0; i < MAX_ENEMIES; ++i) {
	//		if (enemies[i] != nullptr) {
	//			enemies[i]->position.y = 5000;
	//			enemies[i]->position.x = 0;
	//			App->collision->EraseCollider(enemies[i]->collider);
	//		}
	//	}
	//	App->input->gate_enemies = true;
	//}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.y >((abs(App->render->camera.y) + SCREEN_WIDTH) / SCREEN_SIZE) + 240)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.y);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	if (robot_destroyed == true) {
		for (uint i = 0; i < MAX_ENEMIES; ++i) {
			if (enemies[i] != nullptr) {
				if (enemies[i]->type == ENEMY_TYPES::RCANNON) {
					delete enemies[i];
					enemies[i] = nullptr;
				}
			}
		}
		robot_destroyed = false;
	}

	if (App->render->camera.y == -20 * SCREEN_SIZE) {
		for (uint i = 0; i < MAX_ENEMIES; ++i) {
			if (enemies[i] != nullptr) {
				if (enemies[i]->type == ENEMY_TYPES::TURRET2) {
					delete enemies[i];
					enemies[i] = nullptr;
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	App->audio->UnloadWAV(explosion1);

	LOG("Freeing all enemies");

	App->textures->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			//App->collision->EraseCollider(enemies[i]->collider);
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
			queue[i].id = i;
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
			enemies[i]->id = info.id;
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
			enemies[i]->id = info.id;
			break;


		case ENEMY_TYPES::MISSILE:
			enemies[i] = new Enemy_Missile(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::MISSILE;
			enemies[i]->id = info.id;
			switch (info.move)
			{
			case ENEMY_MOVE::MISSILE_1:
				enemies[i]->path = missile1;
				break;
			case ENEMY_MOVE::MISSILE_2:
				enemies[i]->path = missile2;
				break;
			case ENEMY_MOVE::MISSILE_3:
				enemies[i]->path = missile3;
				break;
			case ENEMY_MOVE::MISSILE_4:
				enemies[i]->path = missile3;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::POWERUP:
			enemies[i] = new PowerUp(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::POWERUP;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::BUILDING:
			enemies[i] = new Enemy_Building(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BUILDING;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::BUILDING2:
			enemies[i] = new Enemy_Building2(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BUILDING2;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::VASE:
			enemies[i] = new Enemy_Vase(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::VASE;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::DRONE:
			enemies[i] = new Enemy_Drone(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::DRONE;
			enemies[i]->id = info.id;
			switch (info.move) {
			case ENEMY_MOVE::DRONE1:
				enemies[i]->path = drone1;
				break;
			case ENEMY_MOVE::DRONE2:
				enemies[i]->path = drone2;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::ROBOT:
			enemies[i] = new Enemy_Robot(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::ROBOT;
			enemies[i]->id = info.id;
			switch (info.move)
			{
			case ENEMY_MOVE::_ROBOT:
				enemies[i]->path = robot;
				break;
			default:
				break;
			}
			break;

		case ENEMY_TYPES::RCANNON:
			enemies[i] = new Enemy_Rcannon(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::RCANNON;
			enemies[i]->id = info.id;
			switch (info.move)
			{
			case ENEMY_MOVE::_CANNON:
				enemies[i]->path = rcannon;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::TURRET2:
			enemies[i] = new Enemy_Turret2(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TURRET2;
			enemies[i]->id = info.id;
			switch (info.move)
			{
			case ENEMY_MOVE::TURRET_1:
				enemies[i]->path = turret1;
				break;
			case ENEMY_MOVE::TURRET_2:
				enemies[i]->path = turret2;
				break;
			default:
				break;
			}
			break;
		case ENEMY_TYPES::TURRET3:
			enemies[i] = new Enemy_Turret3(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::TURRET3;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::BOSS:
			enemies[i] = new Enemy_Boss(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::BOSS;
			enemies[i]->id = info.id;
			break;
		case ENEMY_TYPES::COIN:
			enemies[i] = new Coin(info.x, info.y);
			enemies[i]->type = ENEMY_TYPES::COIN;
			enemies[i]->id = info.id;
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
			if (enemies[i]->type == ENEMY_TYPES::ROBOT) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 4), (c1->rect.y - ((c1->rect.h)) / 4), NULL, NULL, NULL);
					App->audio->PlayWAV(explosion1);
					delete enemies[i];
					enemies[i] = nullptr;
					robot_destroyed = true;
					break;
				}
			}
			/*if (enemies[i]->type == ENEMY_TYPES::RCANNON) {
				if (robot_destroyed == true) {
					delete enemies[i];
					enemies[i] = nullptr;
				}
				break;
			}*/

			if (enemies[i]->type == ENEMY_TYPES::BALLOON) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
					App->audio->PlayWAV(explosion1);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::TURRET) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->audio->PlayWAV(explosion1);
					App->particles->AddParticle(App->particles->explosion_turret, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::MISSILE) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_drone, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BUILDING) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
					building_destroyed = true;
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					App->audio->PlayWAV(explosion1);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BUILDING2) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					this->AddEnemy(ENEMY_TYPES::POWERUP, ENEMY_MOVE::NO_MOVE, c1->rect.x, c1->rect.y);
					App->audio->PlayWAV(explosion1);
					building2_destroyed = true;
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::VASE) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_turret, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					//Spawn Power Up when an enemy dies
					this->AddEnemy(ENEMY_TYPES::COIN, ENEMY_MOVE::NO_MOVE, c1->rect.x + 9, c1->rect.y + 13);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::TURRET2) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_turret, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					App->audio->PlayWAV(explosion1);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::DRONE) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->particles->AddParticle(App->particles->explosion_drone, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					App->audio->PlayWAV(explosion1);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::TURRET3) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->audio->PlayWAV(explosion1);
					App->particles->AddParticle(App->particles->explosion_turret, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}
			if (enemies[i]->type == ENEMY_TYPES::BOSS) {
				if (enemies[i]->getHitPoints() == 0) {
					scoreEnemy(enemies[i], c2);
					App->audio->PlayWAV(explosion1);
					App->background3->boss_dead = true;
					App->particles->AddParticle(App->particles->explosion_turret, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 4), (c1->rect.y - ((c1->rect.h))), NULL, NULL, NULL);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w))), (c1->rect.y - ((c1->rect.h)) / 2), NULL, NULL, NULL);
					App->particles->AddParticle(App->particles->explosion_balloon, (c1->rect.x - ((c1->rect.w)) / 2), (c1->rect.y - ((c1->rect.h)) / 4), NULL, NULL, NULL);
					delete enemies[i];
					enemies[i] = nullptr;
					break;
				}
			}

			//Erase Coin when the player grabs it
			if (enemies[i]->type == ENEMY_TYPES::COIN && c2->type == COLLIDER_TYPE::COLLIDER_PLAYER) {
				delete enemies[i];
				enemies[i] = nullptr;
				break;
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

void ModuleEnemies::scoreEnemy(Enemy* enemy, Collider* c2) {
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		scoreP1 = 0;
		scoreP2 = 0;
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
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == KYOKO) {
			if (App->player->characters[0] != nullptr && App->player->characters[0]->type == KYOKO)
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
		if (c2->type == COLLIDER_PLAYER_SHOT && c2->character == KYOKO) {
			if (App->player->characters[1] != nullptr && App->player->characters[1]->type == KYOKO)
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