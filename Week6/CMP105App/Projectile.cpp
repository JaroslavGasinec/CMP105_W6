#include "Projectile.h"
#include "Physics.h"

Projectile::Projectile(sf::Vector2u* ws)
{
	windowSize = ws;
}

Projectile::Projectile(sf::Vector2u* ws, float* scaling)
{
	windowSize = ws;
	this->scaling = scaling;
}

Projectile::Projectile(sf::Vector2u* ws, float* scaling, float gravity)
{
	windowSize = ws;
	this->scaling = scaling;
	this->gravity = gravity;
}

Projectile::~Projectile()
{
}

void Projectile::handleInput(float dt)
{
	if (input->isMouseRDown() && drag == false) {
		startingDrag = sf::Vector2f(input->getMouseX(), input->getMouseY());
		setPosition(startingDrag - (getSize() * 0.5f));
		drag = true;
	}
	else if (input->isMouseRDown() && drag == true) {
		endDrag = sf::Vector2f(input->getMouseX(), input->getMouseY());
	}
	else if (!(input->isMouseRDown()) && drag == true) {
		velocity = (endDrag - startingDrag)/3.0f;
		drag = false;
	}

}

void Projectile::update(float dt)
{
	if (drag == false) {
		Physics::gravity(this, *scaling, gravity, dt);
		if (getPosition().x + velocity.x * dt > windowSize->x - getSize().x || getPosition().x + velocity.x * dt < 0) {
			velocity.x *= -1;
		}
		if (getPosition().y + velocity.y * dt > windowSize->y - getSize().y) {
			velocity = sf::Vector2f(0, 0);
		}
		setPosition(getPosition().x + velocity.x * dt * (*scaling), getPosition().y + ((velocity.y * dt + (gravity * dt * dt) / 2)) * (*scaling));
	}
}
