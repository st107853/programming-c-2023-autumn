#pragma once
#include "IAlive.h"
#include "ItemObject.h"
#include "Human.h"

class Animal : public IAlive
{
public:
	ItemObject* inventory = 0;

	void drop();
	void die();
};