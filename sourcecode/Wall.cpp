#pragma once
#include <SFML/Graphics.hpp>
#include "Wall.h"


Wall::Wall(std::string filename) {
	sprite_texture.loadFromFile(filename + ".png");
	sprite_object.setTexture(sprite_texture);
}

std::string Wall::GetType() {
	return className;
}
