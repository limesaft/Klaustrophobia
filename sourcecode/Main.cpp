#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "GameState.h"
#include "StateManager.h"
#include "MenuState.h"

int main()
{
	sf::RenderWindow window;
	int windowWidth = 1600;
	int windowHeight  = 800;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - windowWidth /2, (sf::VideoMode::getDesktopMode().height / 2) - windowHeight /2-40);

	window.create(sf::VideoMode(windowWidth, windowHeight), "Playwindow", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);
	window.setKeyRepeatEnabled(true);
	
	//Skapa StateManager;
	StateManager stateManager;
	stateManager.Init(); 

	// main loop
	while (window.isOpen())
	{
		sf::Event event;
		//Event Loop:
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
			}
		}

		//mainGame.Update();
		stateManager.Update();
		window.clear();

		//mainGame.Render(window);
		stateManager.Render(window);
		window.display();
	}
	return 0;
}
