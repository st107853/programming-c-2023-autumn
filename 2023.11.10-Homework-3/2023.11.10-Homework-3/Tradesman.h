#pragma once
#include "Human.h"

class Tradesman : public Human
{
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
	void sell() {};
	void buy() {};
	void foo() override {}
};