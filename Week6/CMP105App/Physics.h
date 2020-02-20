#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"

class Physics
{
public:
	static void gravity(GameObject* object,float scaling, float gravity,float dt);
	static void gravity(GameObject* object,float scaling, float dt);
	static void friction(GameObject* object, float friction);
};

