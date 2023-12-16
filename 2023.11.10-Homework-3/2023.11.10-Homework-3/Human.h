#pragma once

#include "Animal.h"
#include "ISpeakable.h"

class Human : public ISpeakable, public IAlive
{
	std::string name = "";

public:
	ItemObject* inventory[5]{};

	void drop();
};