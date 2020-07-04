#include "menu.h"

Menu::Menu(float ancho, float altura){
     texmapa.loadFromFile("mapas/Infiernomenu.png");
     spmapa.setTexture(texmapa);
    if(!fuente.loadFromFile("Royal Inferno.ttf")){

    }
    menu[0].setFont(fuente);
    menu[0].setScale(1.5,1.5);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("1 Jugador");
    menu[0].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*1.5));

    menu[1].setFont(fuente);
    menu[1].setScale(1.5,1.5);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("2 Jugadores");
    menu[1].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*2.5));

    menu[2].setFont(fuente);
    menu[2].setScale(1.5,1.5);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Dificultad");
    menu[2].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*3.5));

    menu[3].setFont(fuente);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Salir");
    menu[3].setScale(1.5,1.5);
    menu[3].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*4.5));

    menu[4].setFont(fuente);
    menu[4].setColor(sf::Color::Red);
    menu[4].setString("RETURN FROM HELL");
    menu[4].setScale(2,2);
    menu[4].setPosition(sf::Vector2f(ancho/2.7, altura/(MAX_NUMBER_OF_ITEMS+1)*0.2));

    seleccionarindice = 0;
}

Menu::~Menu(){
}

void Menu::dibujar(sf::RenderWindow &window){
    window.draw(spmapa);
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }

}
 void Menu::moverarriba(){

    if(seleccionarindice -1 >= 0 & seleccionarindice <4){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice--;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }

 }

 void Menu::moverabajo(){
    if(seleccionarindice +1 < MAX_NUMBER_OF_ITEMS-1){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice++;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }
 }
