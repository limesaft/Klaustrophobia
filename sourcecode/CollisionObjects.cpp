#include "CollisionObjects.h"

CollisionObjects::CollisionObjects(){}

sf::FloatRect CollisionObjects::GetGlobalBounds()
{
	return sprite_object.getGlobalBounds();
}

std::string CollisionObjects::GetType() { return ""; };
void CollisionObjects::CollidedPlayer(int &health, int &score) {}
void CollisionObjects::CollidedShoot(int &score) {}
void CollisionObjects::Update(sf::Vector2f playerPosition) {}
