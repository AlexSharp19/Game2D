#ifndef IA2_H_INCLUDED
#define IA2_H_INCLUDED
#include "entidad.h"
#include "jugador.h"


class NPC2: public Entidad{
private:
    ///IDENTIFICACION DE FUNCIONES
    int caballero=0 , minotauro=0 , dragon=0, hechicero=0;
    ///VARIABLES GENERALES
    sf::Texture Texnpc;
    sf::Sprite spNpc;
    sf::Text textVidanpc;
    float vida , speed , speedtotal;
    int derecha , izquierda , chasing1 , chasing2;
    int distancia1 , distancia2 , activado=0;
    Jugador *player1;
    Jugador *player2;
    ///VARIABLES CABALLERO
    sf::Clock relojcaminarCaballero , relojataqueCaballero , relojtimingCaballero , relojmuerteCaballero;
    int muerteCaballero=0 ,  caballeromuerteanimacion=0;
    int Caballeroatk=0, Caballeroatkon=0 , timingCaballeroatk=0;
    int caminarCaballero=0;
    ///VARIABLES MINOTAURO
    sf::Clock relojcaminarMinotauro , relojataqueMinotauro , relojtimingMinotauro , relojmuerteMinotauro;
    int muerteMinotauro=0 , Minotauromuerteanimacion=0;
    int Minotauroatk=0, Minotauroatkon=0 , timingMinotauroatk=0;
    int caminarMinotauro=0;
    ///VARIABLES DRAGON
    sf::Texture texFuego2;
    sf::Sprite spFuego2;
    sf::Clock relojcaminarDragon ,relojataqueDragon ,relojanimacionDragon ,relojmuerteDragon ,relojanimacionFuego ,relojCooldownfuego;
    int animacionfuego=5;
    int muerteDragon=0 , Dragonmuerteanimacion=0;
    int Dragonatk=0, Dragonatkon=0 , Dragontimeatack;
    int caminarDragon=0;
    ///VARIABLES HECHICERO
   // sf::SoundBuffer bufferFuego, bufferMeteoro, bufferHielo;
   // sf::Sound soundFuego, soundMeteoro, soundHielo;
    sf::Texture texhpHechicero , texHechicero , texFuegoH1, texFuegoH2, texMeteorito, texHielo;
    sf::Sprite spHechicero , spFuegoH1 , spHpHechicero, spFuegoH2, spMeteorito, spHielo;
    sf::Clock relojcaminarHechicero , relojmuerteHechicero; // CAMINAR Y MUERTE
    sf::Clock relojFuegoH1, relojFuegoH2, relojMeteorito, relojHielo, relojAtacandoHechicero;
    sf::Clock relojCooldownFuegoH1, relojCooldownFuegoH2, relojCooldownMeteorito, relojCooldownHielo;
    sf::Clock relojTirarMeteorito, relojTirarHielo;
    int caminarHechicero=0, muerteHechicero=0 , Hechiceroanimacionmuerte=0, AtacarHechicero=0, AtacarHechicero2=0;
    int animacionFuegoH1=0, animacionFuegoH2=0, animacionMeteorito=0;
    int FuegoH1atkon=0, FuegoH2atkon=0, Meteoritoatkon=0, Hieloatkon=0;
    int timingFuegoH1=0, timingFuegoH2=0, timingMeteorito=0, timingHielo=0;
    float vidaHechicero  , porcentajevidaHechicero, vidainicialHechicero , speedHechicero , animacionvidaHechicero=0;
    float distancia1Hechicero=0 , distancia2Hechicero=0;
    int chasing1Hechicero=0 , chasing2Hechicero=0;
    int izquierdaHechicero=0 , derechaHechicero=0;
    int activadoHechicero=0;
    int reproducirMeteoro=1, reproducirHielo=1;
    sf::Font Fuente2;
    sf::Text Hechicerotext;
    ///SECCION BOSS FIGHT
    sf::Clock relojbossfightHechicero , relojbossfightHechicero2;
    int reiniciar = 1, fase2=0;

public:
    ///CONSTRUCTOR NPCS
    NPC2(Jugador *j1 , Jugador *j2){
        Fuente2.loadFromFile("Royal Inferno.ttf");
        spFuego2.setPosition(-9999,999);
        player1 = new Jugador();
        player1 = j1;
        player2 = new Jugador(1);
        player2 = j2;
    }
     ///CONSTRUCTOR BOSS
    NPC2(Jugador *j1 , Jugador *j2 , int){
      /*  bufferFuego.loadFromFile("sonidos/Fuego.wav");
        bufferMeteoro.loadFromFile("sonidos/Lluvia meteoros.wav");
        bufferHielo.loadFromFile("sonidos/Hielo.wav");
        soundFuego.setBuffer(bufferFuego);
        soundMeteoro.setBuffer(bufferMeteoro);
        soundHielo.setBuffer(bufferHielo);*/
        spFuegoH1.setPosition(-9999, 999);
        spFuegoH2.setPosition(-9999,999);
        spMeteorito.setPosition(-9999,999);
        spHielo.setPosition(-9999,999);
        spHpHechicero.setPosition(-9999, 999);
        Fuente2.loadFromFile("Royal Inferno.ttf");
        player1 = new Jugador();
        player1 = j1;
        player2 = new Jugador(1);
        player2 = j2;
    }
    void update() override;
    void ColisionesCaballero();
    void ColisionesMinotauro();
    void ColisionesDragon();
    void ColisionesHechicero();
    void dibujar(sf::RenderWindow &w) override;
    void update_movimiento();
    void deteccion_ataque_Caballero();
    void deteccion_ataque_Minotauro();
    void deteccion_ataque_Dragon();
    void deteccion_ataque_Hechicero();
    void add(Entidad *e);
    ///GET Y SETS NPCS Y BOSS-------------------------------
    sf::Sprite& Getspritenpc(){return spNpc;}
    sf::Sprite& GetspriteFuego2(){return spFuego2;}
    sf::Sprite& GetspriteHechicero(){return spHechicero;}
    sf::Sprite& GetspriteFuegoH1(){return spFuegoH1;}
    sf::Sprite& GetspriteFuegoH2(){return spFuegoH2;}
    sf::Sprite& GetspriteMeteorito(){return spMeteorito;}
    sf::Sprite& GetspriteHielo(){return spHielo;}
    sf::Sprite& GetspriteHpHechicero(){return spHpHechicero;}
    float& Setvidainicial(float v){vida=v;}
    float& SetvidainicialHechicero(float v){vidaHechicero=v;}
    float& SetvidainicialHechiceroTotal(float v){vidainicialHechicero=v;}
    float& SetvidaHechicero(float v){vidaHechicero-=v;}
    float& SetSpeedinicial(float s){speed = s;}
    float& SetSpeedtotal(float s){speedtotal = s;}
    float& SetSpeedinicialHechicero(float s){speedHechicero=s;}
    float& GetvidaBoss(){return vidaHechicero;}
    int& SetCaballero(int e){caballero=e;}
    int& SetMinotauro(int e){minotauro=e;}
    int& SetDragon(int e){dragon=e;}
    int& SetHechicero(int e){hechicero=e;}
    sf::Texture& GetTexturenpc() {return Texnpc;}
    sf::Texture& GetTextureFuego2(){return texFuego2;}
    sf::Texture& GetTextureHechicero(){return texHechicero;}
    sf::Texture& GetTextureFuegoH1(){return texFuegoH1;}
    sf::Texture& GetTextureFuegoH2(){return texFuegoH2;}
    sf::Texture& GetTextureMeteorito(){return texMeteorito;}
    sf::Texture& GetTextureHielo(){return texHielo;}
    sf::Texture& GetTextureHpHechicero(){return texhpHechicero;}
    ///------------------------------------------------------------

};

#endif // IA2_H_INCLUDED
