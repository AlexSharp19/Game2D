#include "mapas.h"

void Mapas::update(){
}

void Mapas::dibujar(sf::RenderWindow &w){
    ///dibujar mapa en ventana
    w.draw(spmapita);
    w.draw(spmapita2);
}
