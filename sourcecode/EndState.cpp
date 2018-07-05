#include "EndState.h"
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <sstream>

EndState::EndState() {

	// Load font
	arial.loadFromFile("arial.ttf");

	// Load stringstream
	ssScore.str("");
	ssScore << endScore;
	scoreBoard.setString(ssScore.str());

	//Add values to scoreBoard;
	scoreBoard.setCharacterSize(25);
	scoreBoard.setPosition({ 680,338 });
	scoreBoard.setFont(arial);
	scoreBoard.setString(ssScore.str());

}

void EndState::Update() {

	ssScore.str("");
	ssScore << endScore;
	scoreBoard.setString(ssScore.str());

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) ) {
		SwitchEndState();
	}
}

void EndState::Render(sf::RenderWindow &window) {
	backGroundEnd.drawTo(window);
	window.draw(scoreBoard);

}

bool EndState::GetClearToReStart() {
	return leaveEndState;
}

std::string EndState::GetClassName() {
	return className;
}
void EndState::SwitchEndState() {
	leaveEndState = !leaveEndState;
}


void EndState::SetEndScore(int points) {
	endScore = points;
}
