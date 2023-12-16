#pragma once

class IPhysicalObject 
{
private:
	int * id = nullptr;
public:
	int x = -1;
	int y = -1;

	int * get_id();
	virtual void foo() = 0;
};

static IPhysicalObject *** map = new IPhysicalObject ** [9];