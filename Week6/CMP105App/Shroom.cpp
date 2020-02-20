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

void Shroom::handleInput(float dt)
{
	setGoal(sf::Vector2f(input->getMouseX(),input->getMouseY()));
}

void Shroom::update(float dt)
{
	if (Vector::magnitude(getPosition()-goal) < 0.2) {
		speed = 150;
	}
	else {
		velocity = goal - getPosition();
		velocity = sf::Vector2f(velocity.x * speed / Vector::magnitude(velocity), velocity.y * speed / Vector::magnitude(velocity));
		setPosition(getPosition() + velocity * dt);
		speed += acceleration;
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
