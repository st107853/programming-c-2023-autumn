#pragma once
#include "Animal.h"

class Predator :public Animal
{
	void attack(int x, int y) override;
};