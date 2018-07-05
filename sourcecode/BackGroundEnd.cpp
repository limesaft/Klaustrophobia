#include "BackGroundEnd.h"

BackGroundEnd::BackGroundEnd() {
	sprite_texture.loadFromFile("EndState.png");
	sprite_object.setTexture(sprite_texture);
	sprite_object.setPosition({ 0, 0 });
}
