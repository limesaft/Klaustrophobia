#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "State.h"
#include "MenuState.h"
#include "GameState.h"
#include "EndState.h"
#include <vector>

class StateManager {

public:
	StateManager(); 
	void Init();
	void ChangeState(const std::string &stateName); 
	void Update();
	void Render(sf::RenderWindow&);
	void CheckIfSwitchState(); 
private:
	bool shallChangeState = false;
	State* currentState;

	MenuState* menuState;
	GameState* gameState;
	EndState* endState;

	std::vector<State*> stateList;
};
