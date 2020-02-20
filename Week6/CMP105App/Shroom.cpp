#include "Shroom.h"
#include "Framework/Vector.h"

Shroom::Shroom()
{
	goal = sf::Vector2f(500,500);
}

Shroom::Shroom(sf::Vector2f goal)
{
	this->goal = goal;
}

Shroom::~Shroom()
{
}

void Shroom::update(float dt)
{
	if (getPosition() == goal) {}
	else {
		velocity = goal - getPosition();
		velocity = sf::Vector2f(velocity.x * speed / Vector::magnitude(velocity), velocity.y * speed / Vector::magnitude(velocity));
		setPosition(getPosition() + velocity * dt);
	}

}

void Shroom::setGoal(sf::Vector2f goal)
{
	this->goal = goal;
}

void Shroom::setSpeed(float speed)
{
	this->speed = speed;
}
