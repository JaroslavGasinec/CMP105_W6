#pragma once
#include "Framework/GameObject.h"
class Ball :
	public GameObject
{
	float scaling = 10.0f;
	float gravity = 9.8f;

public:
	Ball();
	Ball(float scaling);
	Ball(float scaling, float gravity);
	~Ball();
	void handleInput(float dt) override;
	void update(float dt) override;
	float getScaling() { return scaling; };
};

