#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "CollisionObjects.h"
#include <string>

class Enemy : public CollisionObjects {

public:
	Enemy(std::string filename);

	void Move(sf::Vector2f distance);							
	virtual void Update(sf::Vector2f playerPosition) override;	
	void RaiseSpeed(float levelspeed);
	virtual void CollidedPlayer(int &health, int &score) override;
	virtual void CollidedShoot(int &score) override;
	virtual std::string GetType() override;

	float enemyMoveSpeed = 0.115f;

private:
	std::string className = "enemy";
	std::string enemyType = "";
	int counter = 400;
	bool counterUp = true;
};

