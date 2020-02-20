#pragma once
#include "Framework/GameObject.h"
class Projectile :
	public GameObject
{
	float* scaling;
	float gravity = 9.8f;
	sf::Vector2u* windowSize;
	sf::Vector2f startingDrag;
	sf::Vector2f endDrag;
	bool drag = false;
public:
	Projectile(sf::Vector2u* ws);
	Projectile(sf::Vector2u* ws, float* scaling);
	Projectile(sf::Vector2u* ws, float* scaling, float gravity);
	~Projectile();
	void handleInput(float dt) override;
	void update(float dt) override;
};

