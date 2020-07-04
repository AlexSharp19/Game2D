#include "menu3.h"

Menu3::Menu3(float ancho, float altura){
     texmapa.loadFromFile("mapas/Infiernomenu.png");
     spmapa.setTexture(texmapa);
    if(!fuente.loadFromFile("Royal Inferno.ttf")){

    }
    menu[0].setFont(fuente);
    menu[0].setScale(1.5,1.5);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Facil");
    menu[0].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*0.8));

    menu[1].setFont(fuente);
    menu[1].setScale(1.5,1.5);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Normal");
    menu[1].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*1.8));

    menu[2].setFont(fuente);
    menu[2].setScale(1.5,1.5);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Dificil");
    menu[2].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*2.8));

    menu[3].setFont(fuente);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Volver");
    menu[3].setScale(1.5,1.5);
    menu[3].setPosition(sf::Vector2f(ancho/2.2, altura/(MAX_NUMBER_OF_ITEMS+1)*3.8));



    seleccionarindice = 0;
}

Menu3::~Menu3(){
}

void Menu3::dibujar(sf::RenderWindow &window){
    window.draw(spmapa);
    for(int i=0;i<MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }

}
 void Menu3::moverarriba(){

    if(seleccionarindice -1 >= 0 & seleccionarindice <4){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice--;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }

 }

 void Menu3::moverabajo(){
    if(seleccionarindice +1 < MAX_NUMBER_OF_ITEMS){
        menu[seleccionarindice].setColor(sf::Color::White);
        seleccionarindice++;
        menu[seleccionarindice].setColor(sf::Color::Red);
    }
 }
