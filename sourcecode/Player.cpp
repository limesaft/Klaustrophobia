#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "Player.h"
#include <string>
#include <iostream>

Player::Player() {
	sprite_texture.loadFromFile("Purpleball.png");
	sprite_object.setTexture(sprite_texture);
}

void Player::move(sf::Vector2f distance) {
	sprite_object.move(distance);
}

void Player::changeStatusIfShoot(bool shoot) {

	if (shoot) {
		shooted = false;
	}

	else {
		shooted = true;
	}
}

bool Player::getShootStatus() {
	return shooted;
}

void Player::Update() {
		
	// Check keyboard could maybe do case
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		pointing_direction = "up";
		sprite_object.move({ 0, -playerMoveSpeed });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		pointing_direction = "down";
		sprite_object.move({ 0, playerMoveSpeed });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		pointing_direction = "right";
		sprite_object.move({ playerMoveSpeed, 0 });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		pointing_direction = "left";
		sprite_object.move({ -playerMoveSpeed, 0 });
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		changeStatusIfShoot(false);
	}
}

sf::Vector2f Player::getPlayerPos() {
	return sprite_object.getPosition();
}

void Player::setPlayerPos() {
	 sprite_object.setPosition(200,200);
}


std::string Player::getPlayerDirection() {
	return pointing_direction;
}

void Player::giveBoost() {
	playerMoveSpeed = playerMoveSpeed + 0.1f;
}

bool Player::IsCollidingWithObject(CollisionObjects* collObjec) {

	if (sprite_object.getGlobalBounds().intersects(collObjec->GetGlobalBounds())) {
		return true;
	}
	return false;
}
