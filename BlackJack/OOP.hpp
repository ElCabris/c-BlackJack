#include <string>
#include <vector>

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
	Player(); //number cards la implementé por si se quieren jugar más adelante variantes del blackjack
	void showCards();
	virtual void Action(std::string) = 0;
	void hit(); //palabra utiliza para pedir 
protected:
	int _suma = 0; //pongo dos opciones de suma por si aparece una As en la mano
	int _AsActivate = 0;
	std::vector<Card> _playersCards;
	bool _BlackJack = false;
	bool _playing = true;

};

class Gambler : public Player {
public:
	Gambler(std::string nombre, unsigned fichas) : _name(nombre), _chips(fichas), Player::Player() {}
	void Action(std::string action) override;
	unsigned int getChips();
private:
	std::string _name;
	unsigned int _chips;
};