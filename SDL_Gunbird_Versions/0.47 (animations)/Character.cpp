#include "Application.h"
#include "Character.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"

Character::Character(int x, int y) : position(x, y)
{}

Character::~Character()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Character::GetCollider() const
{
	return collider;
}

void Character::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Character::OnCollision(Collider* collider)
{

}