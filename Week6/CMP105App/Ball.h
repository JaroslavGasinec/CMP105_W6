#pragma once
#include "Framework/GameObject.h"
class Ball :
	public GameObject
{
	float* scaling;
	float gravity = 9.8f;
	sf::Vector2u* windowSize;

public:
	Ball();
	Ball(float* scaling);
	Ball(float* scaling, float gravity);
	~Ball();
	void handleInput(float dt) override;
	void update(float dt) override;
};

