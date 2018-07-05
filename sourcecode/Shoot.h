#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include <string>
#include "Enemy.h"
#include "Wall.h"

class Shoot : public Object{
public:
	Shoot(std::string direction);

	void Update();
	void Move(sf::Vector2f distance);
	bool IsCollidingWithObject(CollisionObjects*);
	bool IsCollidingWithWall(Wall*);
private:
	std::string pointing_direction = "right";
	float shootMoveSpeed = 1.8f;
};


