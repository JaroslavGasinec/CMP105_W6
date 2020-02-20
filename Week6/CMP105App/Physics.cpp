#include "Physics.h"

void Physics::gravity(GameObject* object, float scaling, float gravity, float dt)
{
	object->setVelocity(object->getVelocity().x, object->getVelocity().y + gravity*dt*scaling);
}

void Physics::gravity(GameObject* object,float scaling, float dt)
{
	gravity(object, scaling, 9.8, dt);
}
 