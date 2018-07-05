#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "Object.h"
#include <algorithm>

GameState::GameState(){}

void GameState::Init() {
	level = 1;
	health = 3;
	levelspeed = 0.001f;
	score = 0;

	// Load font
	arial.loadFromFile("arial.ttf");

	// Load stringstream
	ssScore << "Score: " << score;
	ssLevel << "Level: " << level;
	ssHealth << "Health: " << health;

	//Add values to scoreBoard;
	scoreBoard.setCharacterSize(30);
	scoreBoard.setPosition({ 120,40 });
	scoreBoard.setFont(arial);
	scoreBoard.setString(ssScore.str());

	//Add values to levelBoard;
	levelBoard.setCharacterSize(30);
	levelBoard.setPosition({ 320,40 });
	levelBoard.setFont(arial);
	levelBoard.setString(ssLevel.str());

	//Add values to healthBoard;
	healthBoard.setCharacterSize(30);
	healthBoard.setPosition({ 1300,40 });
	healthBoard.setFont(arial);
	healthBoard.setColor(sf::Color::Red);
	healthBoard.setString(ssHealth.str());

	// Player object
	player = new Player();
	player->SetPos({ 50,400 });

	//Coin added
	CreateCoins();

	//Enemy added
	CreateEnemies(0);

	//Create walls
	Createwalls();
}

void GameState::Update() {

	// Uppdate the player
	player->Update();

	// Shoot logic, max 1 shoot each time
	if (player->getShootStatus()) {
		player->changeStatusIfShoot(true);

		if (shootVec.size() < 1) {
			CreateShoot();
		}
	}

	// Uppdate the shoots
	for (std::vector<Shoot*>::iterator it = shootVec.begin(); it != shootVec.end(); ++it)
	{
		(*it)->Update();
	}

	// Kollar om player träffar antingen vägg, coin eller enemy skickar in variabler för att eventuellt ändra dem
	for (std::vector<CollisionObjects*>::iterator it = collVec.begin(); it != collVec.end(); ++it) {

		if (player->IsCollidingWithObject(*it)) {
			(*it)->CollidedPlayer(health, score);
			if ((*it)->GetType() != "wall") {
				objectToDelete.push_back(*it);
			}
			if ((*it)->GetType() == "wall") {
				player->setPlayerPos();
			}
		}

		// kollar om skotten träffar fienden och wall, fienden och wall flyttar den till annan position
		for (std::vector<Shoot*>::iterator itShoot = shootVec.begin(); itShoot != shootVec.end(); ++itShoot) {
			if ((*itShoot)->IsCollidingWithObject(*it)) {

				// om träff med fiende så ger den poäng oavsett så försvinner skottet om det ej är coin
				if ((*it)->GetType() != "coin") {
					(*it)->CollidedShoot(score);
					(*itShoot)->SetPos({ 24000,24600 });
					objectToDelete.push_back(*itShoot);
				}
				// om träff men ej wall, döda objektet som den träffar
				if ((*it)->GetType() != "wall") {
					objectToDelete.push_back(*it);
				}
			}
		}
	}

	// Uppdaterar enemy med spelarens position.
	for (std::vector<CollisionObjects*>::iterator it = collVec.begin(); it != collVec.end(); ++it) {
		if ((*it)->GetType() == "enemy") {
			(*it)->Update(player->getPlayerPos());
		}
	}
	// itererar över objecten för att se vilka som ska tas bort och tar bort dem ifrån vectorerna
	for (std::vector<Object*>::iterator it = objectToDelete.begin(); it != objectToDelete.end(); ++it) {

		std::vector<CollisionObjects*>::iterator foundObj = std::find(collVec.begin(), collVec.end(), (*it));
		if (foundObj != collVec.end()) {
			delete (*foundObj);
			collVec.erase(foundObj);
		}

		std::vector<Shoot*>::iterator foundShoot = std::find(shootVec.begin(), shootVec.end(), (*it));
		if (foundShoot != shootVec.end()) {
			delete (*foundShoot);
			shootVec.erase(foundShoot);
		}
	}

	// Uppdaterar score och health
	ssScore.str("");
	ssScore << "Score: " << score;
	scoreBoard.setString(ssScore.str());

	ssHealth.str("");
	ssHealth << "Health: " << health;
	healthBoard.setString(ssHealth.str());
	objectToDelete.clear();

	// If all enemies is dead, start new level 
	if (collVec.size() < 5) {
		levelspeed = levelspeed + 0.01f;
		CreateEnemies(level);

		level++;
		CreateBoss(level);
	
		if ((level % 3) == 0)
		{
			CreateUberBoss(level);
		}

		if ((level % 5) == 0)
		{
			player->giveBoost();
		}

		ssLevel.str("");
		ssLevel << "Level: " << level;
		levelBoard.setString(ssLevel.str());
	}
		if (health < 1) {
		GameOver();
	}
}

void GameState::Render(sf::RenderWindow &window) {

	// Ritar ut player
	player->drawTo(window);

	// Ritar ut alla coins
	for (std::vector<CollisionObjects*>::iterator it = collVec.begin(); it != collVec.end(); ++it)
	{
		(*it)->drawTo(window);
	}
	for (std::vector<Shoot*>::iterator it = shootVec.begin(); it != shootVec.end(); ++it)
	{
		(*it)->drawTo(window);
	}

	// Draw the fonts
  	window.draw(scoreBoard);
	window.draw(healthBoard);
	window.draw(levelBoard);
}
	
void GameState::CreateCoins() {
	for (int i = 0; i < 5; i++)
	{
		Coin* coin = new Coin();
		coin->SetPos({ float(rand() % 1450), float(rand() % 700) });
		collVec.push_back(coin);
	}
}

void GameState::CreateEnemies(int level) {
	for (int i = 0; i < 5 + level; i++)
	{
		Enemy* enemy = new Enemy("Enemy.png");
		enemy->SetPos({ float(rand() % 1450), float(rand() % 700) });
		enemy->RaiseSpeed(levelspeed );
		collVec.push_back(enemy);
	}
}

void GameState::CreateBoss(int level) {
	for (int i = 0; i < 1; i++)
	{
		Enemy* enemy = new Enemy("Boss.png");
		enemy->RaiseSpeed(levelspeed*3);
		enemy->SetPos({ float(700), float(350) });
		collVec.push_back(enemy);
	}
}

void GameState::CreateUberBoss(int level) {
	for (int i = 0; i < level; i++)
	{
		Enemy* enemy = new Enemy("Uberboss.png");
		enemy->RaiseSpeed(levelspeed*5);
		enemy->SetPos({ float(rand() % 1450), float(rand() % 700) });
		collVec.push_back(enemy);
	}
}

void GameState::CreateShoot() {
	Shoot* shoot = new Shoot(player->getPlayerDirection());
	float x = player->getPlayerPos().x + 10;	       // put bullet from mid
	float y = player->getPlayerPos().y + 10;
	shoot->SetPos({ x,y });
	shootVec.push_back(shoot);    
}

void GameState::Createwalls() {

	// Top
	Wall* wall = new Wall("Walltop");
	wall->SetPos({ 0, 0 });
	collVec.push_back(wall);

	// Bottom
	wall = new Wall("Walltop");
	wall->SetPos({ 0, 790  });
	collVec.push_back(wall);

	// Left side
	wall = new Wall("Wallside");
	wall->SetPos({ 0, 0 });
	collVec.push_back(wall);

	// Right side
	wall = new Wall("Wallside");
	wall->SetPos({ 1580, 0 });
	collVec.push_back(wall);

}
int GameState::GetTotalPoints() {
	return score;
}

bool GameState::IsGameOver() {
	return isEndOfGame;
}
void GameState::SwitchGameOver() {
	isEndOfGame = !isEndOfGame;
}

std::string GameState::GetClassName() {
	return className;
}

void GameState::GameOver() {

	// Reset the text
	ssHealth.str("");
	healthBoard.setString(ssHealth.str());

	ssLevel.str("");
	levelBoard.setString(ssLevel.str());

	ssScore.str("");
	scoreBoard.setString(ssScore.str());

	SwitchGameOver();
	// rensa alla pekare
	for (std::vector<CollisionObjects*>::iterator it = collVec.begin(); it != collVec.end(); ++it) {
		objectToDelete.push_back(*it);
	}
	for (std::vector<Shoot*>::iterator it = shootVec.begin(); it != shootVec.end(); ++it) {
		objectToDelete.push_back(*it);
	}

	for (std::vector<Object*>::iterator it = objectToDelete.begin(); it != objectToDelete.end(); ++it) {

		std::vector<CollisionObjects*>::iterator found = std::find(collVec.begin(), collVec.end(), (*it));
		if (found != collVec.end()) {
			delete (*found);
			collVec.erase(found);
		}

		std::vector<Shoot*>::iterator foundShoot = std::find(shootVec.begin(), shootVec.end(), (*it));
		if (foundShoot != shootVec.end()) {
			delete (*foundShoot);
			shootVec.erase(foundShoot);
		}
	}

	objectToDelete.clear();
}
