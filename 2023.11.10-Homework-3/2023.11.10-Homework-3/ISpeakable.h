#pragma once
#include "Write.h"
#include<random>

class ISpeakable
{
	virtual std::string speech() = 0;
public:
	virtual void speak() { std::cout << speech() << std::endl; }
	virtual void respond(int request) = 0;
};