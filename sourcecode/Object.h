#pragma once
#include "SFML/Graphics.hpp"

class Object{

public:
	virtual void Init();
	virtual void Update();				
	void drawTo(sf::RenderWindow &window);	

	virtual void Move(sf::Vector2f move);   
	void SetPos(const sf::Vector2f &newPos);

protected:
	sf::Texture sprite_texture;
	sf::Sprite sprite_object;
	sf::Vector2f position;
};
