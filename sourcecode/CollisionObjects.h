#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include <string>

class CollisionObjects : public Object
{

public:
	CollisionObjects();
	
	sf::FloatRect GetGlobalBounds();
	virtual void CollidedPlayer(int &health, int &score);
	virtual void CollidedShoot(int &score);
	virtual void Update(sf::Vector2f playerPosition);
	virtual std::string GetType(); 
};

