#include "OOP.hpp"
#include <random>
#include <iostream>


std::vector<Card> CARDS;

Card::Card() {
 //pasos necesarios para generar un número aleatorio con <random>
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> pintas(1, 4);
	std::uniform_int_distribution<> numeros(1, 13);
	bool same;
	do {
		same = false;
		_pinta = pintas(gen) + 2;
		_number = numeros(gen);
		for (auto& it : CARDS) {
			if (it._number == _number && it._pinta == _pinta) {
				same = true;
				break;
			}
		}
	} while (same);

	CARDS.push_back(Card(_number, _pinta));

}

Card::Card(int numero, char pinta) : _number(numero), _pinta(pinta) {}

int Card::getNumber() {
	return _number;
}

char Card::getPinta() {
	return _pinta;
}

Player::Player(){
 // para iniciar cada jugador debe tener dos cartas
	int number_cards = 2;
	while (number_cards--) {
		_playersCards.push_back(Card());
		int valor_neto = _playersCards[_playersCards.size() - 1].getNumber();
		if (valor_neto >= 11) {
			_suma[0] += 10;
			_suma[1] += 10;
		}
		else if (valor_neto == 1) {
			_suma[0] += 11;
			_suma[1] += 1;
		}
		else {
			_suma[0] += valor_neto;
			_suma[1] += valor_neto;
		}
	}

	if (_suma[0] == 21) {
		_BlackJack = true;
	}
}

void Player::showCards() {
	for (auto it : _playersCards) {
		switch (it.getNumber())
		{
		case 11: std::cout << 'J';
			break;
		case 12: std::cout << 'Q';
			break;
		case 13: std::cout << 'K';
			break;
		case 1: std::cout << 'A';
			break;
		default:
			std::cout << it.getNumber();
			break;
		}
		std::cout << ' ';
		switch (it.getPinta())
		{
		case 3: std::cout << "Hearts";
			break;
		case 4: std::cout << "Diams";
			break;
		case 5: std::cout << "Clubs";
			break;
		case 6: std::cout << "Spades";
			break;
		}
		std::cout << std::endl;
	}
}

void Player::hit() {
	_playersCards.push_back(Card());

	
}