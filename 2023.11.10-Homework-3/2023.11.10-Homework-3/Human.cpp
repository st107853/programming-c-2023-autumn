#include "Human.h"

void Human::drop()
{
	for (int i = 0; i < 5; ++i)
	{
		this->inventory[i]->x = this->x;
		this->inventory[i]->y = this->y;
	}
}