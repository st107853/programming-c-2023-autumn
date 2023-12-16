#include "Human.h"
#include "ItemObject.h"
#include "Wizard.h"
#include "Knight.h"
#include "Citizen.h"
#include "Tradesman.h"
#include "Predator.h"

class Player : public Human
{
	Human* being;

	Player()
	{
		write("ÅÑËÈ È ÁÛÒÜ, ÒÎ ÊÅÌ?");
		write("0 ÂÎËØÅÁÍÈÊÎÌ 1 ĞÛÖÀĞÅÌ 2 ÌÈĞÍÛÌ ÃĞÀÆÄÀÍÈÍÎÌ 3 ÒÎĞÃÎÂÖÅÌ");
		
		int type = 2;
		std::cin >> type;

		switch (type)
		{
		case 0: being = new Wizard(); break;
		case 1: being = new Knight(); break;
		case 2: being = new Citizen(); break;
		default: being = new Tradesman(); break;
		}
	}
	void attack(int x, int y) override
	{
		being->attack(x, y);
	}
	void die() override
	{
		being->die();
		std::cout << "Game over" << std::endl;
		delete being;
	}
};

int main()
{
	std::cout << "It doesn't work" << std::endl;

	return EXIT_SUCCESS;
}