#pragma once
#include "IPhysicalObject.h"

class ItemObject : public IPhysicalObject
{
	int attackImprove = 0;
	int healthImprove = 0;

public:
	int get_attack() { return attackImprove; }
	int get_health() { return healthImprove; }
};