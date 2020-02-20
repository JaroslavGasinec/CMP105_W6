#include "Level.h"
#include "Physics.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	scaling = 20;
	windowSize = window->getSize();
	// initialise game objects
	ball = new Ball(&windowSize, &scaling);
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
	windowSize = window->getSize();
	ball->update(dt);
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