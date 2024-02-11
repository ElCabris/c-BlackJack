# Documentation (Spanish)

## Class Card
Cada instancia de esta clase representa una carta del las 52 presentes en un mazo.
### Atributos
Esta clase cuenta con dos atributos, de pinta y número. Se utilizan para representar cada una de las diferentes cartas
### Metodos
Cuenta con los getters para cada respectivo metodo
### Constructores
Card cuenta con una sobrecarga del constructor.
La primera se utiliza para construir una carta personalizada y necesitas los parametros de la pinta ye el palo o pinta.
El segundo crea una carta aleatoria y la va a guardar en el vector CARDS.


## Class Player
(clase incompleta)
La idea de esta clase es poder tener los jugadores que se desee en una partida
### Atributos
(consiero que se le deben agregar otros metodos como si el jugador ha terminado la ronda)
como atributos tiene:
|Atributo |Descripción|
|-|-|
|type: int[2]. suma |es la suma toria total de las cartas, es un arreglo de dos debido a que el haz proboca una variación (de 1 o 11) |
|type: bool. BlackJack| Agrego este atributo porque la mano del blackjack le gana a cualquier otra mano, y solo empata contra ella misma|
|player_cards|un arreglo de tipo vector<Card> que almacena las cartas que el jugador tiene en la mano|
### Metodos
