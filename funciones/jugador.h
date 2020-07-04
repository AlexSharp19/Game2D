#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entidad.h"


class Jugador: public Entidad{
private:
   ///VARIABLES GENERALES
    int nivel2=0;
    int Bossfight=0 , Bossfight2=0; //ACTIVAR LIMITACIONES BOSSFIGHT
    float vida = 100 , animacionvida;//HUD JUGADORES
    int quieto=1,parado=0;//ANIMACION ESTATICA
    int player1=0 , player2=0; //IDENTIFICAR FUNCIONES DEL OBJETO
    sf::SoundBuffer bufferDash;
    sf::Sound soundDash;
    sf::Text Gameover;
    sf::Text Gamewin;
    ///PLAYER 1
    sf::SoundBuffer bufferGolpe, bufferDisparo, bufferRecarga;
    sf::Sound soundGolpe, soundDisparo, soundRecarga;
    sf::Texture texVida1;
    sf::Sprite  spVida1;
    sf::Texture texPlayer;
    sf::Sprite player;
    sf::Texture texBala;
    sf::Sprite spBala;
    sf::Texture texBala2;
    sf::Sprite spBala2;
    sf::Texture texRecarga;
    sf::Sprite spRecarga;
    sf::Font Fuente;
    sf::Text VidaPlayer1;
    sf::Vector2f speed2 = sf::Vector2f(0.f,0.f);
    float speedpj1 = 0.15;
    int disparar=0,disparando=0,timingdisparo=0,cargando=0,cargador=6 , reproducircargador=0;//ATAQUE DISTANCIA
    float walk=0;//ANIMACION MOVIMIENTO
    int frame=0;//FRAME FILA
    float row=0;//FRAME COLUMNA
    int girar=0 , girando=0 , timinggiro=0;//ATAQUE GIRATORIO
    int derecha=1 , izquierda=0 , arriba=0 , abajo=0; //POSICIONAMIENTO DE ESTATICA Y ATAQUES
    int pegar=0 , pegando=0 , timingpinia=0 ;//ATAQUE PIÑA
    int patar=0 , pateando=0 , timingpatada=0; //ATAQUE PATADA
    int dash=0 , dashing=0 , timingdash=0; //DASH MOVE
    sf::Clock relojcaminar; //ANIMACION CAMINAR PJ1 Y 2
    sf::Clock relojquieto;  //ANIMACION QUIETO PJ1 Y 2
    sf::Clock relojdisparo , relojpinia , relojgiro , relojpatada, relojRecargando;// ANIMACION ATAQUES PJ1
    sf::Clock relojrecorridobala , relojtimingdisparo , relojtimingpinia , relojtiminggiro , relojtimingpatada;//COOLDOWN ATAQUES PJ1
    sf::Clock relojdash , relojduraciondash; //DASH PJ1 Y PJ2
    sf::Time TimePerFrame2 = sf::seconds(1.f / 300.f);
    sf::Time TiempoNulo2;
    sf::Time TiempoDevuelto2 = sf::seconds(1.f / 300.f);
    ///PLAYER 2
    sf::SoundBuffer bufferGetsuga, bufferEspadaso, bufferFuegoNegro, bufferDash2, bufferAirEspadas;
    sf::Sound soundGetsuga, soundEspadaso, soundFuegoNegro, soundDash2, soundAirEspadas;
    sf::Texture texVida2;
    sf::Sprite  spVida2;
    sf::Texture texPJ2;
    sf::Sprite spPJ2;
    sf::Texture texGetsuga;
    sf::Sprite spGetsuga;
    sf::Texture texGetsuga2;
    sf::Sprite spGetsuga2;
    sf::Texture texDark;
    sf::Sprite spDark;
    sf::Texture texDark2;
    sf::Sprite spDark2;
    sf::Text VidaPlayer2;
    sf::Vector2f speed = sf::Vector2f(0.f,0.f);
    float speedpj2 = 0.15;
    int disparar2=0,disparando2=0,timingdisparop2=0,animaciongetsuga=0; //ATAQUE DISTANCIA
    int girar2=0 , girando2=0 , timinggirop2=0;//ATAQUE GIRATORIO
    int pegar2=0 , pegando2=0 , timingpiniap2=0 , animaciondark=0 ;//ATAQUE OSCURO
    int pisar=0 , pisando=0 , timingpiso=0 , animaciondarkK=0 ;//ATAQUE PISO
    int dash2=0 ,  dashing2=0 , timingdash2=0;//DASH MOVE
    sf::Clock relojgetsuga ,relojdark , relojpiso , relojespada; //ANIMACION ATAQUES PJ2
    sf::Clock  relojtiminggetsu , relojtimingespada , relojtimingdark , relojtimingpiso;//COOLDOW ATAQUES PJ2
    sf::Clock relojanimaciongetsu , relojanimaciondark , relojanimacionpiso; //ANIMACION PROYECTILES PJ2
    sf::Clock relojrecorridogetsu , relojduraciondark , relojduracionpiso; //RECORRIDO Y DURACION PROYECTILES PJ2
    sf::Time TimePerFrame = sf::seconds(1.f / 300.f);
    sf::Time TiempoNulo;
    sf::Time TiempoDevuelto = sf::seconds(1.f / 300.f);
public:
    Jugador();
    Jugador(int dato);
    ///GENERALES
    void update() override;
    void dibujar(sf::RenderWindow &w) override;
    void posicionar_camara();
    int& Setnivel2(int n){nivel2=n;}
    int& Getnivel2(){return nivel2;}
    float& Getvida(){return vida;}
    float& Setvida(float v){vida-=v;}
    float& Darlevida(float v){vida=v;}
    float& SetaumentoVida(float v){vida += v;}
    int& SetBossfight(float b){Bossfight=b;}
    int& GetBossfight(){return Bossfight;}
    int& SetBossfight2(float b){Bossfight2=b;}
    int& GetBossfight2(){return Bossfight2;}
    int& SetPlayer1(int p){player1=p;}
    int& SetPlayer2(int p){player2=p;}
    int& GetPlayer1(){return player1;}
    int& GetPlayer2(){return player2;}
    sf::Text& Getgameover(){return Gameover;}
    sf::Text& Getgamewin(){return Gamewin;}
    ///JUGADOR 1
    void updateMoveSet1();
    sf::Time setTiempo2(sf::Time tiempoj2){TimePerFrame2=tiempoj2;}
    sf::Sprite& getSprite(){return player;}
    int& getGiro(){return girando;}
    sf::Sprite& getTiro() {return spBala;}
    sf::Sprite& getTiro2() {return spBala2;}
    int& Getpinia(){return pegando;}
    int& Getpatada(){return pateando;}
    int& Getderecha(){return derecha;}
    int& Getizquierda(){return izquierda;}
    int& Getdash(){return dash;}
    ///JUGADOR 2
    void updateMoveSet2();
    sf::Time setTiempo(sf::Time tiempoj){TimePerFrame=tiempoj;}
    sf::Sprite& getSprite2(){return spPJ2;}
    sf::Sprite& getSpritegetsuga1(){return spGetsuga;}
    sf::Sprite& getSpritegetsuga2(){return spGetsuga2;}
    sf::Sprite& getSpritedark(){return spDark;}
    sf::Sprite& getSpritedarkpiso(){return spDark2;}
    int& Getespada(){return girando2;}
    int& Getpiso(){return pisando;}
    int& Getgetsuga(){return disparando2;}
    int& Getdark (){return pegando2;}
    int& Getdash2(){return dash2;}

};



#endif // JUGADOR_H_INCLUDED
