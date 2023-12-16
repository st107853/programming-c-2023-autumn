#pragma once
#include "Human.h"

class Wizard : public Human
{
private:
	std::vector<std::string> catch_phrases =
	{
		"якнбмн уси дпнв╗мши...",
		"лнч уеп йюй охнмеп",
		"врн-рн фною веьеряъ",
		"юапюйюдюапю ╗орю",
		"нярнкаемеи охднп"
	};

	std::string speech() override;

	void die();
	void respond(int request)  override;
	void attack(int x, int y) override;
	void foo() override {}
};