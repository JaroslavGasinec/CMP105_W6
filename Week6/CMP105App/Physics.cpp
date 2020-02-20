#include "Physics.h"

void Physics::gravity(GameObject* object, float gravity, float dt)
{
	object->setVelocity(object->getVelocity().x, object->getVelocity().y + gravity*dt*10);
}

void Physics::gravity(GameObject* object, float dt)
{
	gravity(object,9.8,dt);
}
 