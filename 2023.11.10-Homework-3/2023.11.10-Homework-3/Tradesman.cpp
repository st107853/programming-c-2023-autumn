#include "Tradesman.h"

std::string Tradesman::speech()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	return catch_phrases[gen() % 5];
}

void Tradesman::die()
{
	write("��������: �� ������� ������� ���� �����. ������� ����� ������ ��� �������� ����� �� ���������.");
	this->drop();
}

void Tradesman::respond(int request)
{
	int ans = request;

	switch (ans)
	{
	case 0:	write("��������: ����� ���-�� ������? ����� - ������.");
		write("1 '�� ���� �� �����? ������� ������.' 2 '� ��� ����?'");
		std::cin >> ans;
		respond(ans);
	case 1: write("��������: �������, ��������. � � ���������� �� ������� ���������?");
		write("3 '���...' 4 '��, �� �����!'");
		std::cin >> ans;
		respond(ans);
	case 2: write("��������: ��� ��������� ������.");
	case 3: write("��������: ������ ����� ���, � �� �������. ������ � ��������� �� �����.");
	case 4: write("��������: ������ � ������� �������� �� ������ ������.");
	default: write("��������: ������, � ��� �� ��������");
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