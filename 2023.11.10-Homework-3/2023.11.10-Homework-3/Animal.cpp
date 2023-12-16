#include "Animal.h"

void Animal::drop()
{
	this->x = this->inventory->x;
	this->y = this->inventory->y;
};

void Animal::die()
{
	write("ÆÈÂÎÒÍÎÅ ÏÎÂÅÐÆÅÍÎ");
	this->drop();
}