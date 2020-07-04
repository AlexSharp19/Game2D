#ifndef MAPAS_H_INCLUDED
#define MAPAS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "entidad.h"

class Mapas: public Entidad{
private:
    ///INFIERNO
    sf::Texture texmapita;
    sf::Sprite spmapita;
    ///TIERRA
    sf::Texture texmapita2;
    sf::Sprite spmapita2;
public:
    Mapas(){
        ///INFIERNO
    texmapita.loadFromFile("mapas/Infierno.png");
    spmapita.setTexture(texmapita);
    spmapita.setPosition(0,-10);
    spmapita.setScale(1,0.6);

       ///TIERRA
    texmapita2.loadFromFile("mapas/Tierra.png");
    spmapita2.setTexture(texmapita2);
    spmapita2.setPosition(0,1990);
    spmapita2.setScale(1,0.6);
}
    void update() override;
    void dibujar(sf::RenderWindow &w) override;
};


#endif // MAPAS_H_INCLUDED
