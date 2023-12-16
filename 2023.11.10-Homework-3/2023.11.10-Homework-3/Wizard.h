#pragma once
#include "Human.h"

class Wizard : public Human
{
private:
	std::vector<std::string> catch_phrases =
	{
		"������ ��� ���ר���...",
		"��� ��� ��� ������",
		"���-�� ���� �������",
		"����������� ����",
		"���������� �����"
	};

	std::string speech() override;

	void die();
	void respond(int request)  override;
	void attack(int x, int y) override;
	void foo() override {}
};