#pragma once

#include "State.h"
#include "BackGroundEnd.h"
#include <string>
#include <sstream>


class EndState : public State {

public:

	EndState();
	void Update();
	void Render(sf::RenderWindow &window);
	bool GetClearToReStart();
	void SwitchEndState();
	std::string GetClassName();
	void SetEndScore(int points);

private:
	int endScore = 0;
	bool leaveEndState = false;
	BackGroundEnd backGroundEnd;
	std::string className = "EndState";

	//Font score variables
	sf::Font arial;
	std::ostringstream ssScore;
	sf::Text scoreBoard;
};