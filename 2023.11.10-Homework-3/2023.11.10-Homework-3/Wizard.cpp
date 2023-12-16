#include "Wizard.h"

std::string Wizard::speech()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	return catch_phrases[gen() % 5];
}

void Wizard::die()
{
	write("Волшебник: Я нассал в штаны");
	this->drop();
}

void Wizard::respond(int request)
{
	int ans = request;

	switch (ans)
	{
	case 0:	write("Волшебник: Чего надобно?");
		write("1 'Ты кота не видел? жирного такого' 2 'Как сделать приворотное заклинание?'");
		std::cin >> ans;
		respond(ans);
	case 1: write("Волшебник: Ты дурной?!");
	case 2: write("Волшебник: Боюсь, даже оно тебе не поможет");
	default: write("Волшебник: Плюшку изо рта вынь, потом говори");
		break;
	}
}

void Wizard::attack(int x, int y)
{
	write("Волшебник: АВОКАДО КИДАЮ");
	IPhysicalObject* point = map[x][y];

	if (std::pow(x - this->x, 2) + std::pow(y - this->y, 2) > 2)
		return;

	if (auto victim = dynamic_cast<Human*>(point))
	{
		victim->health -= attack_power;
		if (victim->health <= 0) victim->die();
		else victim->attack(this->x, this->y);
	}

	if (auto victim = dynamic_cast<Animal*>(point))
	{
		victim->health -= attack_power;
		if (victim->health <= 0) victim->die();
		else victim->attack(this->x, this->y);
	}
}