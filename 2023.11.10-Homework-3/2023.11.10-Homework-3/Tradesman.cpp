#include "Tradesman.h"

std::string Tradesman::speech()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	return catch_phrases[gen() % 5];
}

void Tradesman::die()
{
	write("Торговец: Всё нажитое отдайте моим детям. Надеюсь этого хватит для закрытия долга по алиментам.");
	this->drop();
}

void Tradesman::respond(int request)
{
	int ans = request;

	switch (ans)
	{
	case 0:	write("Торговец: Брать что-то будешь? Время - деньги.");
		write("1 'Ты кота не видел? жирного такого.' 2 'А что есть?'");
		std::cin >> ans;
		respond(ans);
	case 1: write("Торговец: Жирного, говоришь. А в шаурмичных на вокзале спрашивал?");
		write("3 'Нет...' 4 'Да, он самый!'");
		std::cin >> ans;
		respond(ans);
	case 2: write("Торговец: Это нарушение устава.");
	case 3: write("Торговец: Такого здесь нет, я бы заметил. Спроси у торговцев на пирсе.");
	case 4: write("Торговец: Кажетя я замечал похожего на севере страны.");
	default: write("Торговец: Сударь, я вас не понимаюю");
		break;
	}
}

void Tradesman::attack(int x, int y)
{
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