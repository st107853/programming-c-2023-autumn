#pragma once
#include "Human.h"

class Citizen : public Human
{
private:
	std::vector<std::string> catch_phrases =
	{
		"������ �� ����� ���������...",
		"�٨ ���� �������",
		"���-������! �������� ��� �����",
		"������ �����?",
		"������ �������"
	};

	std::string speech() override;

	void die();
	void respond(int request)  override;
	void attack(int x, int y) override;
	void foo() override {}
	int ATK = 2;
};