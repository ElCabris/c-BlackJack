#include <string>
#include <vector>
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
	void hit(); //palabra utiliza para pedir carata
	void showCards();
	//virtual void Action() = 0;

protected:
	int _suma[2] = { 0, 0 }; //pongo dos opciones de suma por si aparece una As en la mano
	std::vector<Card> _playersCards;
	bool _BlackJack;
};

class Gambler : public Player {
public:
	using Player::Player;
};