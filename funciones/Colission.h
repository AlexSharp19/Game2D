
#ifndef COLSSION_H
#define COLISSION_H

#include <SFML/Graphics.hpp>

namespace Collision {

	bool PixelPerfectTest(const sf::Sprite& Object1 ,const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);
}

#endif	/* COLLISION_H */
