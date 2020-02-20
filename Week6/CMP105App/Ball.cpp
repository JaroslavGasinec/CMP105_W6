#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(float* scaling)
{
	this->scaling = scaling;
}

Ball::Ball(float* scaling, float gravity)
{
	this->scaling = scaling;
	this->gravity = gravity;
}

Ball::~Ball()
{
}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {
		velocity += sf::Vector2f(0,-20*dt*(*scaling));
	}
	if (input->isMouseLDown()) {
		setPosition(input->getMouseX() - getSize().x / 2, input->getMouseY() - getSize().y / 2);
	}
}

void Ball::update(float dt)
{
	
	setPosition(getPosition().x, getPosition().y + ((getVelocity().y*dt+(gravity*dt*dt)/2))*(*scaling));
}
