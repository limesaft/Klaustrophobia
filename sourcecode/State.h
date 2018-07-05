#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class State {

public:
	virtual void Init();	
	virtual void Update();  
	virtual void Render(sf::RenderWindow&); 
	virtual std::string GetClassName();
};
