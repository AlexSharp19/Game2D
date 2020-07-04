#ifndef ENTIDAD_H_INCLUDED
#define ENTIDAD_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Entidad{
public:
    virtual void update() = 0;
    virtual void dibujar(sf::RenderWindow &w) = 0;
};

#endif // ENTIDAD_H_INCLUDED
