#include "Predator.h"

void Predator::attack(int x, int y)
{
	IPhysicalObject* point = map[x][y];

	if (auto victim = dynamic_cast<Human*>(point))
	{
		victim->health -= attack_power;
		if (victim->health == 0) victim->die();
		else victim->attack(this->x, this->y);
	}
}
