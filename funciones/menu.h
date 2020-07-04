#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 5

class Menu{
private:
    sf::Texture texmapa;
    sf::Sprite spmapa;
    int seleccionarindice;
    sf::Font fuente;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
     Menu(float ancho, float altura);
     ~ Menu();
     void dibujar(sf::RenderWindow &w);
     void moverarriba();
     void moverabajo();
     int presionaritem(){return seleccionarindice;}
};



#endif // MENU_H_INCLUDED
