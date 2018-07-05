#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "State.h"
#include "Player.h"
#include "Object.h"
#include "Enemy.h"
#include "Shoot.h"
#include "Coin.h"
#include "Wall.h"
#include "CollisionObjects.h"

class GameState : public State {

public:
	GameState();

	void Init();	
	void Update();  
	void Render(sf::RenderWindow&); 

	void CreateCoins(); 
	void CreateEnemies(int level);
	void CreateBoss(int level);
	void CreateUberBoss(int level);
	void CreateShoot();
	void Createwalls();

	int GetTotalPoints();
	bool IsGameOver();

	void SwitchGameOver();
	std::string GetClassName();
	void GameOver();

private:
	//Interact objects
	Player* player;

	int level;
	int health;
	float levelspeed;
	int score;
	std::string className = "GameState";

	bool isEndOfGame = false;

	//Font score variables
	sf::Font arial;
	std::ostringstream ssScore;
	sf::Text scoreBoard;

	//Font level variables
	std::ostringstream ssLevel;
	sf::Text levelBoard;

	//Font level variables
	std::ostringstream ssHealth;
	sf::Text healthBoard;

	// Shoot storage
	std::vector<Shoot*> shootVec;

	// Collision storage
	std::vector<CollisionObjects*> collVec;

	// To delete
	std::vector<Object*> objectToDelete;
};
