#include "Citizen.h"

std::string Citizen::speech()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	return catch_phrases[gen() % 5];
}

void Citizen::die()
{
	write("Рыцарь: Я пал во имя короля");
	this->drop();
}

void Citizen::respond(int request)
{
	int ans = request;

	switch (ans)
	{
	case 0:	write("Рыцарь: Чем могу помочь?");
		write("1 'Ты кота не видел? жирного такого.' 2 'Дай мечь подержать.'");
		std::cin >> ans;
		respond(ans);
	case 1: write("Рыцарь: Это его фото на стенде пропаж?");
		write("3 'Нет, мой красивый, пушистый.' 4 'Да, он самый!'");
		std::cin >> ans;
		respond(ans);
	case 2: write("Рыцарь: Это нарушение устава.");
	case 3: write("Рыцарь: Такого здесь нет, я бы заметил. Спроси у торговцев на пирсе.");
	case 4: write("Рыцарь: Кажетя я замечал похожего на севере страны.");
	default: write("Рыцарь: Сударь, я вас не понимаюю");
		break;
	}
}

void Citizen::attack(int x, int y)
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