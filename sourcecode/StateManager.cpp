#include "StateManager.h"
#include <typeinfo>
#include "State.h"
#include <string>

StateManager::StateManager() {}

void StateManager::Init() {
	menuState = new MenuState();
	gameState = new GameState();
	endState = new EndState();

	stateList.push_back(menuState);
	stateList.push_back(gameState);
	stateList.push_back(endState);

	currentState = menuState;
}

void StateManager::CheckIfSwitchState() {

	if (menuState->GetClearToStart()) {
		menuState->SwitchMenuState();
		gameState->Init();
		ChangeState("GameState");
	}
	
	if (gameState->IsGameOver()) {
		// uppdate the gamestate to false again
		gameState->SwitchGameOver();
		int temp = gameState->GetTotalPoints();
		endState->SetEndScore(temp);
		ChangeState("EndState");
	}

	if (endState->GetClearToReStart()) {
		// uppdate the gamestate to false again
		endState->SwitchEndState();
		ChangeState("MenuState");
	}
}

void StateManager::ChangeState(const std::string &stateName) {
	for (std::vector<State*>::iterator it = stateList.begin(); it != stateList.end(); ++it)
	{
		std::string temp = (*it)->GetClassName();
		if (stateName == temp) {
			currentState = (*it);
		}
	}
}
void StateManager::Update() {
	CheckIfSwitchState();

	for (std::vector<State*>::iterator it = stateList.begin(); it != stateList.end(); ++it)
	{
		if (currentState == (*it)) {
			(*it)->Update();
		}
	}
}
void StateManager::Render(sf::RenderWindow &window) {
	for (std::vector<State*>::iterator it = stateList.begin(); it != stateList.end(); ++it)
	{
		if (currentState == (*it)) {
			(*it)->Render(window);
		}
	}
}

