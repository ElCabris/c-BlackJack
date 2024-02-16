#include "OOP.hpp"
#include <iostream>

int main()
{
	Gambler player1("Emanuel", 100);

	std::cout << "se reparten dos cartas" << std::endl;

	player1.showCards();

	std::string hacer;
	do
	{
		getline(std::cin, hacer);
		player1.Action(hacer);
		player1.showCards();
	} while (hacer != "exit");
	

	
	return 0;
}