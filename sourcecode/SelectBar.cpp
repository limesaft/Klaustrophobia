#include "SelectBar.h"
#include <SFML/Graphics.hpp>


SelectBar::SelectBar(){
	sprite_texture.loadFromFile("SelectBar.png");
	sprite_object.setTexture(sprite_texture);
	sprite_object.setPosition({ 666,368});
}

void SelectBar::SwitchPosition(){
	isUp = !isUp;
}
bool SelectBar::GetPosition() {
	return isUp;
}
