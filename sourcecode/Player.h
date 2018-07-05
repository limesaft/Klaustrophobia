#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Object.h"
#include "CollisionObjects.h"

class Player : public Object{

public:
	Player();  
	void move(sf::Vector2f distance);
	void Update();			

	sf::Vector2f getPlayerPos();             
	void setPlayerPos();             
	std::string getPlayerDirection();

	bool IsCollidingWithObject(CollisionObjects* collObject);

	void changeStatusIfShoot(bool shoot);
	void giveBoost();
	bool getShootStatus();

private:
	float playerMoveSpeed = 1.2f;

	// For shoots and sprite
	std::string pointing_direction = "right";
	bool shooted = false;

};
