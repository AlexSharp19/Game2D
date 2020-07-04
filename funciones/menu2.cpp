#include "menu2.h"

Menu2::Menu2(float ancho, float altura){
     texmapa.loadFromFile("mapas/Infiernomenu.png");
     spmapa.setTexture(texmapa);
    if(!fuente.loadFromFile("Royal Inferno.ttf")){

    }
    menu[0].setFont(fuente);
    menu[0].setScale(1.5,1.5);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Nueva partida");
    menu[0].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(fuente);
    menu[1].setScale(1.5,1.5);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Continuar");
    menu[1].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(fuente);
    menu[2].setScale(1.5,1.5);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Volver");
    menu[2].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*3));


    seleccionarindice = 0;
}

Menu2::~Menu2(){
}

void Menu2::dibujar(sf::RenderWindow &window){
    window.draw(spmapa);
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }

}
 void Menu2::moverarriba(){

    if(seleccionarindice -1 >= 0 & seleccionarindice <3){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice--;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }

 }

 void Menu2::moverabajo(){
      if(seleccionarindice==3){
        seleccionarindice=0;
    }

    if(seleccionarindice +1 < MAX_NUMBER_OF_ITEMS){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice++;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }
 }

