#include <string>
#include <vector>
#include <iostream>

namespace OOP
{
	int valor_real(int);
}


class Card
{
public:
	Card();
	Card(int, char); //constructor para crear una carta personalizada
	char getPinta();
	int getNumber();

private:
	char _pinta;
	int _number;
};

class Player
{
public:
	Player();
	virtual void showCards();
	virtual void hit(); //metodo para pedir una carta (se hace virtual debido a la implementación en dealer)
	void to_stand(); //metodo para "plantarse" en una partida

protected:
	int _suma = 0; //pongo dos opciones de suma por si aparece una As en la mano
	int _AsActivate = 0;
	std::vector<Card> _playersCards;
	bool _BlackJack = false;
	bool _playing = true;

};

class Gambler : public Player {
public:
	Gambler(std::string nombre, unsigned int fichas); //constructor personalizado
	Gambler(); //constructor sin nombre ni cantidad de fichas
	void Action(std::string action);
	unsigned int getChips();
	void setName(std::string);
	void showCards() override{
		std::cout << this->_name << "'s cards" << std::endl;
		Player::showCards();
	}
	
private:
	std::string _name;
	unsigned int _chips;
};

class Dealer : public Player
{
public:
	Dealer();
	void hit() override;
	void play();
};