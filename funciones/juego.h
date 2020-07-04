#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;
#include <vector>
#include "ia.h"
#include "ia2.h"
#include "jugador.h"
#include "mapas.h"
#include "menu.h"
#include "menu2.h"
#include "menu3.h"

class Juego{
private:
    sf::Music musicMenu, musicInfierno, musicDemon, musicTierra, musicBoss;
    sf::SoundBuffer Buffermenu;
    sf::Sound Soundmenu;
    sf::RenderWindow w;
    Jugador *jugador;
    Jugador *jugador2;
    Mapas *mapas;
    NPC *npce;
    NPC2 *npc2;
    int reproducir=1, reproducir2=1, reproducir3=1;
    vector<NPC *> enemies;
    vector<NPC2 *> enemies2;
    vector<Entidad *> entidades;
    vector<Entidad *> to_delete;
    void iniciar();
    void update();
    void dibujar();
    int dosplayer=0; //PARA FUNCIONALIDAD 1 O 2 JUGADORES
    sf::Clock Relojcrearnpc , Relojgameover , Relojgameoverdef , Relojgamewin , Relojgamewindef;
    sf::Vector2f ultimaposp1 , ultimaposp2;
    int guardado=0 , gameover=0 , gamewin=0 , corazon=1;
public:
    Juego();
    ~Juego(){
    borrar(npc2);
    borrar(npce);
    borrar(jugador);  //LIBERAR MEMORIA DINAMICA POR DESCONTRUCTOR
    borrar(mapas);
    cout << "GAME OVER";

    }
    void Colisiones();
    void run();
    void add(Entidad *e);
    void borrar(Entidad *e);
    void CreatenpcEsqueleto(int , int , int , float , int);
    void CreatenpcHelldog(int , int , int , float , int);
    void CreatenpcTroll(int , int , int , float , int);
    void CreatebossDemonking(int , int , int , float , int);
    void CreatebossHechicero(int , int , int , float , int);
    void CreatenpcCaballero(int , int , int , float , int);
    void CreatenpcMinotauro(int , int , int , float , int);
    void CreatenpcDragon(int , int , int , float , int);
    void CreateCorazon(int , int , int );
    void MenuPrincipal();
    void MenuInicio();
    void Menudificultad();
    void Endgame();
    void GenerarNiveles1jugadorFacil();
    void GenerarNiveles2jugadoresFacil();
    void GenerarNiveles1jugadorNormal();
    void GenerarNiveles2jugadoresNormal();
    void GenerarNiveles1jugadorDificil();
    void GenerarNiveles2jugadoresDificil();
    int& Getplayermod(){return dosplayer;}
    void SoundsPrimerNivel();
    void SoundsSegundoNivel();
};
#endif // JUEGO_H_INCLUDED
