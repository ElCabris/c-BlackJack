#include "OOP.hpp"
#include <iostream>

int main()
{
	Gambler player1("Emanuel", 100);

	std::cout << "se reparten dos cartas" << std::endl;

	player1.showCards();

	std::cout << "coges una carta" << std::endl;

	player1.Action("hit");
	player1.showCards();
	std::cout << player1.getChips() << std::endl;
	return 0;
}