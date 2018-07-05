#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionObjects.h"
#include <string>
#include "Player.h"
class Wall : public CollisionObjects {

public:
	Wall(std::string filename);
	virtual std::string GetType() override;
private:
	std::string className = "wall";
};

