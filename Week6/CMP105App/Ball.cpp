#include "Ball.h"

Ball::Ball(sf::Vector2u* ws)
{
	windowSize = ws;
}

Ball::Ball(sf::Vector2u* ws, float* scaling)
{
	this->scaling = scaling;
	windowSize = ws;
}

Ball::Ball(sf::Vector2u* ws, float* scaling, float gravity)
{
	this->scaling = scaling;
	this->gravity = gravity;
	windowSize = ws;
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
		velocity = sf::Vector2f(0, 0);
		setPosition(input->getMouseX() - getSize().x / 2, input->getMouseY() - getSize().y / 2);
	}
}

void Ball::update(float dt)
{
	setPosition(getPosition().x, getPosition().y + ((getVelocity().y*dt+(gravity*dt*dt)/2))*(*scaling));
	if (getPosition().y > windowSize->y - getSize().y) {
		setPosition(getPosition().x, windowSize->y - getSize().y);
		setVelocity(0, velocity.y*-0.75);
	}
}

void Ball::setWindowSize(sf::Vector2u* ws)
{
	windowSize = ws;
}
