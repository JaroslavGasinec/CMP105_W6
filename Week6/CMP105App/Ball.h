#pragma once
#include "Framework/GameObject.h"
class Ball :
	public GameObject
{
	float* scaling;
	float gravity = 9.8f;
	sf::Vector2u* windowSize;

public:
	Ball(sf::Vector2u* ws);
	Ball(sf::Vector2u* ws, float* scaling);
	Ball(sf::Vector2u* ws, float* scaling, float gravity);
	~Ball();
	void handleInput(float dt) override;
	void update(float dt) override;
	void setWindowSize(sf::Vector2u* ws);
};

