#ifndef MENU3_H
#define MENU3_H
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 4

class Menu3{
private:
    sf::Texture texmapa;
    sf::Sprite spmapa;
    int seleccionarindice;
    sf::Font fuente;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
     Menu3(float ancho, float altura);
     ~ Menu3();
     void dibujar(sf::RenderWindow &w);
     void moverarriba();
     void moverabajo();
     int presionaritem(){return seleccionarindice;}
};

#endif // MENU3_H
