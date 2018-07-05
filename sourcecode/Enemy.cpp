#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <string>


Enemy::Enemy(std::string filename) {

	sprite_texture.loadFromFile(filename);
	sprite_object.setTexture(sprite_texture);
	enemyType = filename;
}

void Enemy::Move(sf::Vector2f distance) {
	sprite_object.move(distance);
}

void Enemy::Update(sf::Vector2f playerPosition) {
	if (enemyType != "Boss.png") {
		if (sprite_object.getPosition().x <= playerPosition.x) {
			sprite_object.move({ enemyMoveSpeed, 0 });
		}
		if (sprite_object.getPosition().x > playerPosition.x) {
			sprite_object.move({ -enemyMoveSpeed, 0 });
		}
		if (sprite_object.getPosition().y <= playerPosition.y) {
			sprite_object.move({ 0, enemyMoveSpeed });
		}
		if (sprite_object.getPosition().y > playerPosition.y) {
			sprite_object.move({ 0, -enemyMoveSpeed });
		}
	}
	if (enemyType == "Boss.png") {
		if (counterUp) {
			counter++;
			sprite_object.move({-1.0f,0  });
		} else  {
			counter--;
			sprite_object.move({ 1.0f,0 });
		}
		
		if (counter <= 0) {
			counterUp = true;
		}

		if (counter >= 800) {
			counterUp = false;
		}
	}
}

void Enemy::RaiseSpeed(float levelspeed) {
	enemyMoveSpeed = enemyMoveSpeed + levelspeed;
}

void Enemy::CollidedPlayer(int &health, int &score) {
	health--;
	sprite_object.setPosition(26000, 26000);
}

void Enemy::CollidedShoot(int &score) {
	score++;
	sprite_object.setPosition(26000, 26000);
}

std::string Enemy::GetType() {
	return className;
}
