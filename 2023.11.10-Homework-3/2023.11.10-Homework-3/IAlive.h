#pragma once
#include "IPhysicalObject.h"
#include "Write.h"

class IAlive : public IPhysicalObject
{
public:

	int health = 0;
	int attack_power = 0;

	virtual void die() = 0;
	virtual void attack(int x, int y) = 0;
	virtual void drop() = 0;
};