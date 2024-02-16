#include "OOP.hpp"
#include <random>
#include <iostream>


std::vector<Card> CARDS;


int OOP::valor_real(int valor_neto)
{
	if (valor_neto >= 11) {
		return 10;
	}
	else if (valor_neto == 1)
	{
		return 11;
	}
	else
	{
		return valor_neto;
	}
}

Card::Card() {
 //pasos necesarios para generar un n�mero aleatorio con <random>
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
			_suma += 10;
		}
		else if (valor_neto == 1) {
			_suma += 11;
			_AsActivate++;
		}
		else {
			_suma += valor_neto;
		}
	}

	if (_suma == 21) {
		_BlackJack = true;
		_playing = false;
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

void Player::hit()
{
	if (_playing) {
		_playersCards.push_back(Card());
		int neto_valor = _playersCards[_playersCards.size() - 1].getNumber();
		neto_valor = OOP::valor_real(neto_valor);
		
		if (neto_valor == 11) {
			_AsActivate++;
		}
		_suma += neto_valor;

		if (_suma > 21) {
			if (_AsActivate++)
			{
				_suma -= 10;
				_AsActivate--;
			}
			else
			{
				_playing = false;
			}
		}
		else if (_suma == 21)
		{
			_playing = false;
		}

	}
	else {
		std::cout << "error, el jugador ya ha terminado la ronda" << std::endl;
	}
	
}

void Player::to_stand()
{
	_playing = false;
}

void Gambler::Action(std::string action) 
/*en esta funci�n van a ir incluido
todos las "acciones que puede hacer el jugador seg�n sus condiciones" tambi�n una consulta para ver los
comados*/
{
	if (action == "help")
	{
		std::cout << "hit para pedir" << std::endl << "stand para plantarse" << std::endl; 
	}
	else if (action == "hit") { this->hit(); }
	else if (action == "stand") { this->to_stand(); }
	
}

unsigned int Gambler::getChips()
{
	return _chips;
}
