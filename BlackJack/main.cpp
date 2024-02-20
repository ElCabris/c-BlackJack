#include "OOP.hpp"
#include <iostream>

int main()
{
	int nplayers;
	std::cout << "ingrese la cantidad de jugadores: ";
	std::cin >> nplayers;
	std::cin.ignore();
	
	Gambler jugadores[nplayers];
	std::string name;

	for(int i = 0; i < nplayers; i++)
	{
		std::cout << "introduce el nombre del jugador " << i + 1 << ": ";
		getline(std::cin, name);
		jugadores[i].setName(name);
	}

	Dealer crupier; //el iniciador del Dealer imprime únicamente la primera carta

	return 0;
}