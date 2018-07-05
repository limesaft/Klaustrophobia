#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class SelectBar : public Object {

public:
	SelectBar();
	void SwitchPosition();
	bool GetPosition();
private:
	bool isUp = true;
};
