#ifndef MENU2_H
#define MENU2_H
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu2
{
private:
    sf::Texture texmapa;
    sf::Sprite spmapa;
    int seleccionarindice;
    sf::Font fuente;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
     Menu2(float ancho, float altura);
     ~ Menu2();
     void dibujar(sf::RenderWindow &w);
     void moverarriba();
     void moverabajo();
     int presionaritem(){return seleccionarindice;}
};

#endif // MENU2_H
