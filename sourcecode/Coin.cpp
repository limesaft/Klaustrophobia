#pragma once
#include <SFML/Graphics.hpp>
#include "Coin.h"
#include <iostream>

Coin::Coin() {

	sprite_texture.loadFromFile("Coin.png");
	sprite_object.setTexture(sprite_texture);
}

void Coin::CollidedPlayer(int &health, int &score) {
	score++;
	health++;
	sprite_object.setPosition(26000, 26000);
}

std::string Coin::GetType() {
	return className;
}
