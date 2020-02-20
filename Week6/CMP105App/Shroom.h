#pragma once
#include "Framework/GameObject.h"
class Shroom :
	public GameObject
{
	sf::Vector2f goal;
	float speed = 150.0;
public:
	Shroom();
	Shroom(sf::Vector2f goal);
	~Shroom();
	void update(float dt) override;
	void setGoal(sf::Vector2f goal);
	void setSpeed(float speed);
};

