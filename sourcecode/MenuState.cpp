#include "MenuState.h"
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <iostream>

MenuState::MenuState() {}

void MenuState::Update() {
  // flyttar selectbaren upp och ner, men kollar även positionen den har innan
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && selectBar.GetPosition() == false) {
    selectBar.Move({ 0, -72 });
    selectBar.SwitchPosition();
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && selectBar.GetPosition() == true) {
    selectBar.Move({ 0, 72 });
    selectBar.SwitchPosition();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    if (!selectBar.GetPosition()) {
		  exit(0);
    }
    SwitchMenuState();
  }	
}

void MenuState::Render(sf::RenderWindow &window) {
  backGround.drawTo(window);
  selectBar.drawTo(window);
}

bool MenuState::GetClearToStart() {
  return leaveMenuState;
}

std::string MenuState::GetClassName() {
  return className;
}

void MenuState::SwitchMenuState() {
  leaveMenuState = !leaveMenuState;

}
