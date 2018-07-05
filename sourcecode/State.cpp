#include "State.h"
#include "SFML/Graphics.hpp"
#include <string>
void State::Init(){}
void State::Update(){}
void State::Render(sf::RenderWindow &window) {}

std::string State::GetClassName() { return "";}
