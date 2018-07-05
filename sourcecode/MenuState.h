#pragma once

#include "State.h"
#include "SelectBar.h"
#include "BackGround.h"
#include <string>

class MenuState : public State {

public:

	MenuState();
	void Update();
	void Render(sf::RenderWindow &window);
	bool GetClearToStart();
	void SwitchMenuState();
	std::string GetClassName();

private:
	bool leaveMenuState = false;
	BackGround backGround;	
	SelectBar selectBar;
	std::string className = "MenuState";
};
