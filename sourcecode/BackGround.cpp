#include "BackGround.h"

BackGround::BackGround() {
	sprite_texture.loadFromFile("StartMenu.png");
	sprite_object.setTexture(sprite_texture);
	sprite_object.setPosition({ 0, 0});
}
