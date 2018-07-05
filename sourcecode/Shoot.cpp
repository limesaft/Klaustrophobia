#include "Shoot.h"
#include <string>

Shoot::Shoot(std::string direction)
{
	sprite_texture.loadFromFile("Shoot.png");
	sprite_object.setTexture(sprite_texture);
	pointing_direction = direction;
}

void Shoot::Move(sf::Vector2f distance) {
	sprite_object.move(distance);
}


void Shoot::Update() {
	if (pointing_direction == "up") {
		sprite_object.move({ 0, -shootMoveSpeed });
	}

	if (pointing_direction == "down") {
		sprite_object.move({ 0, shootMoveSpeed });
	}

	if (pointing_direction == "right") {
		sprite_object.move({ shootMoveSpeed, 0 });
	}

	if (pointing_direction == "left") {
		sprite_object.move({ -shootMoveSpeed, 0 });
	}

}

bool Shoot::IsCollidingWithObject(CollisionObjects* object) {
	if (sprite_object.getGlobalBounds().intersects(object->GetGlobalBounds())) {
		// kolla vägg + enemy

		return true;
	}
	return false;
}

bool Shoot::IsCollidingWithWall(Wall* wall) {

	if (sprite_object.getGlobalBounds().intersects(wall->GetGlobalBounds())) {
		return true;
	}
	return false; 
}
