#include "Level.h"
#include "Physics.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	scaling = 20;

	// initialise game objects
	ball = new Ball(&scaling);
	ball_T.loadFromFile("gfx/Beach_Ball.png");
	ball->setTexture(&ball_T);
	ball->setInput(in);
	ball->setPosition(window->getSize().x/2, window->getSize().y/2);
	ball->setSize(sf::Vector2f(100,100));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	Physics::gravity(ball,scaling,dt);
	ball->update(dt);
	if (ball->getPosition().y > window->getSize().y - ball->getSize().y) {
		ball->setPosition(ball->getPosition().x, window->getSize().y - ball->getSize().y);
		ball->setVelocity(0,0);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(*ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}