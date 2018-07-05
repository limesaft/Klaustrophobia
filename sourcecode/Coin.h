#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionObjects.h"

class Coin : public CollisionObjects {

public:
	Coin();

	virtual void CollidedPlayer(int &health, int &score) override;
	virtual std::string GetType() override;

private:
	std::string className = "coin";
};

