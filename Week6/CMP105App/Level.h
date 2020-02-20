#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Ball.h"
#include "Shroom.h"
#include "Projectile.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	sf::Texture ball_T;
	sf::Texture shroom_T;
	sf::Texture projectile_T;
	GameObject* ball;
	GameObject* shroom;
	GameObject* projectile;
	float scaling;
	sf::Vector2u windowSize;

	// More level variables
};