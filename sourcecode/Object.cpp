#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "Object.h"

void Object::Init() {}
void Object::Update() {}

void Object::drawTo(sf::RenderWindow &window) {
	
	// kan ha en check här vilket håll den pekar på sen så man vet om gubben ska titta uppåt eller sidan
	window.draw(sprite_object);
}

void Object::Move(sf::Vector2f distance){
		sprite_object.move(distance);
}

void Object::SetPos(const sf::Vector2f &newPos) {
	sprite_object.setPosition(newPos);
}
