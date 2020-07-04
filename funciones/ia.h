#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED
#include "entidad.h"
#include "jugador.h"
#include <iostream>
using namespace std;


class NPC: public Entidad {
private:
    ///IDENTIFICACION DE FUNCIONES
     int esqueleto=0 , helldog=0 , troll=0 , demonking=0;
   ///VARIABLES GENERALES
    sf::Texture Texnpc;
    sf::Sprite spNpc;
    sf::Texture texPortal;
    sf::Texture texCorazon;
    sf::Sprite spCorazon;
    sf::Sprite spPortal;
    sf::Text textVidanpc;
    float vida , speed , speedtotal;
    int derecha , izquierda , chasing1 , chasing2;
    int distancia1 , distancia2 , activado=0;
    ///VARIABLES ESQUELETO
    sf::Clock relojcaminarEsqueleto , relojataqueEsqueleto , relojtimingEsqueleto , relojmuerteEsqueleto;
    int muerteEsqueleto=0 ,  Esqueletomuerteanimacion=0;
    int Esqueletatk=0, Esqueletoatkon=0 , timingEsqueletoatk=0;
    int caminarEsqueleto=0;
    ///VARIABLES HELLDOG
    sf::Clock relojcaminarHelldog , relojfuegoHelldo , relojAnimacionfuego , relojmuerteHelldog;
    int muerteHelldog=0 , Helldogmuerteanimacion=0;
    int Helldogatk=0, Helldogatkon=0 , timingFuego=0;
    int caminarHelldog=0;
    ///VARIABLES TROLL
    sf::Clock relojcaminarTroll , relojataqueTroll , relojanimacionTroll , relojmuerteTroll;
    int muerteTroll=0 , Trollmuerteanimacion=0;
    int Trollatk=0, Trollatkon=0 , Trolltimeatack;
    int caminarTroll=0;
    ///VARIABLES DEMON KING
    //sf::SoundBuffer bufferEspadazo, bufferDashDemon, bufferEpadas;
   // sf::Sound soundEspadazo ,  soundDashDemon, soundEspadas;
    sf::Texture texhpDemonking , texDemonking , texEspadas;
    sf::Sprite spDemonking , spEspadas , spHpDemonking;
    sf::Clock relojcaminarDemonking , relojmuerteDemonking; // CAMINAR Y MUERTE
    int caminarDemonking=0;
    int muerteDemonking=0 , Demonkinganimacionmuerte=0;
    float vidaDemonking  , porcentajevidaDemonking, vidainicialDemonking , speedDemonking , animacionvidaDemonking=0;
    float distancia1Demonking=0 , distancia2Demonking=0;
    int chasing1Demonking=0 , chasing2Demonking=0;
    int izquierdaDemonking=0 , derechaDemonking=0;
    int activadoDemonking=0;
   // int reproducirEspadas=1;
    ///SECCION BOSS FIGHT
    sf::Clock relojbossfightDemonking , relojbossfightDemonking2;
    int reiniciar = 1;
    ///CAMBIO DE NIVEL
    int Portalanimacion=0 , activarPortal=0;
    sf::Clock relojPortalanimacion;
    ///SECCION ATAQUES
    ///RELOJES
    sf::Clock relojtiminataque1Demonking , relojanimacionataque1Demonking; //ATAQUE 1
    sf::Clock relojtiminataque2Demonking , relojanimacionataque2Demonking , relojfreezeEstocada; //ATAQUE 2
    sf::Clock relojtiminataque3Demonking , relojanimacionataque3Demonking; //ATAQUE 3
    sf::Clock relojtiminataque4Demonking , relojanimacionataque4Demonking;//ATAQUE 4
    sf::Clock relojtiminataque5Demonking , relojanimacionataque5Demonking ,relojanimacionEspadas , relojfreezeEspadas , relojTirarEspadas; //ATAQUE 5
    ///VARIABLES
    int animacionEspadas=0 , lanzarEspadas=0; // ATAQUE 5
    int Demonkingatack1=0 , Demonkingatackndo1=0 ,timingataque1Demonking=0; //ATAQUE 1
    int Demonkingatack2=0 , Demonkingatackndo2=0 ,timingataque2Demonking=0; //ATAQUE 2
    int Demonkingatack3=0 , Demonkingatackndo3=0 ,timingataque3Demonking=0; //ATAQUE 3
    int Demonkingatack4=0 , Demonkingatackndo4=0 ,timingataque4Demonking=0; //ATAQUE 4
    int Demonkingatack5=0 , Demonkingatackndo5=0 ,timingataque5Demonking=0; //ATAQUE 5
    int fase2=0;
    sf::Font Fuente;
    sf::Text Demonkingtext;
    int corazon=0;
    ///VARIABLES Y FUNCIONES GLOBALES
    float distancia3=0;
    Jugador *player1;
    Jugador *player2;
public:
    ///CONSTRUCTOR NPCS
    NPC(Jugador *j1 , Jugador *j2){
        if(!Fuente.loadFromFile("Royal Inferno.ttf")){
        }
        player1 = new Jugador();
        player1 = j1;
        player2 = new Jugador(1);
        player2 = j2;
    }
    ///CONSTRUCTOR BOSS
    NPC(Jugador *j1 , Jugador *j2 , int){
        /*bufferEspadazo.loadFromFile("sonidos/Espadazo.wav");
        bufferDashDemon.loadFromFile("sonidos/Dash.wav");
        bufferEpadas.loadFromFile("sonidos/Lanzar Espadas.wav");
        soundDashDemon.setBuffer(bufferDashDemon);
        soundEspadas.setBuffer(bufferEpadas);
        soundEspadazo.setBuffer(bufferEspadazo);*/
        spEspadas.setPosition(-9999,-10);
        spEspadas.setScale(0.8 , 0.8);
        spPortal.setPosition(-9999,-10);
        spHpDemonking.setPosition(-9999,-10);
        if(!Fuente.loadFromFile("Royal Inferno.ttf")){
        }
        player1 = new Jugador();
        player1 = j1;
        player2 = new Jugador(1);
        player2 = j2;
    }
    void update() override;
    void ColisionesEsqueleto();
    void ColisionesHelldog();
    void ColisionesTroll();
    void ColisionesDemonking();
    void ColisionesCorazon();
    void dibujar(sf::RenderWindow &w) override;
    void update_movimiento();
    void deteccion_ataque_Esqueleto();
    void deteccion_ataque_Helldog();
    void deteccion_ataque_Troll();
    void deteccion_ataque_Demonking();
    void add(Entidad *e);
    ///GET Y SETS NPCS Y BOSS-------------------------------
    sf::Sprite& GetSpritenpc() {return spNpc;}
    sf::Sprite& GetspriteDemonking(){return spDemonking;}
    sf::Sprite& GetspriteEspadas(){return spEspadas;}
    sf::Sprite& GetspriteHpDemonking(){return spHpDemonking;}
    sf::Sprite& GetspritePortal(){return spPortal;}
    float& Setvidanpc(float v){vida -= v;}
    float& SetvidaDemonking(float v){vidaDemonking-=v;}
    float& Setvidainicial(float v){vida = v;}
    float& SetvidainicialDemonking(float v){vidaDemonking=v;}
    float& SetvidainicialDemonkingtotal(float v){vidainicialDemonking = v;}
    float& SetSpeedinicial(float s){speed = s;}
    float& Setspeedtotal(float s){speedtotal=s;}
    float& SetspeedinicialDemonking(float s){speedDemonking = s;}
    int& SetEsqueleto(int e){esqueleto=e;}
    int& SetHelldog(int e){helldog=e;}
    int& SetTroll(int e){troll=e;}
    int& SetDemonking(int e){demonking=e;}
    sf::Texture& GettextureNpc(){return Texnpc;}
    sf::Texture& GetTextureDemonking(){return texDemonking;}
    sf::Texture& GetTextureEspada(){return texEspadas;}
    sf::Texture& GetTextureHpDemonking(){return texhpDemonking;}
    sf::Texture& GetTexturePortal(){return texPortal;}
    ///------------------------------------------------------------
    ///GET Y SET CORAZON
    sf::Texture& GetTexturecorazon(){return texCorazon;}
    sf::Sprite&  GetSpritecorazon(){return spCorazon;}
    int& SetCorazon(int c){corazon=c;}

};

#endif // IA_H_INCLUDED
