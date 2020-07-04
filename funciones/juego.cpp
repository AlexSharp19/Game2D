#include <iostream>
using namespace std;
#include "juego.h"
#include "Continuar.h"

 Juego::Juego(){
 iniciar();
}

void Juego::iniciar(){
///sonidos y musica menu y juego
musicMenu.openFromFile("musica/menu.wav");
musicInfierno.openFromFile("musica/Infierno.ogg");
musicDemon.openFromFile("musica/Soundtrack demonking.ogg");
musicTierra.openFromFile("musica/Tierra.ogg");
musicBoss.openFromFile("musica/Soundtrack Boss.ogg");
Buffermenu.loadFromFile("sonidos/Bola de fuego.wav");
Soundmenu.setBuffer(Buffermenu);
///crear ventana del juego
w.create(sf::VideoMode(1130,600),"Return from hell");
musicMenu.setLoop(true);
musicMenu.play();
///limitar fps
w.setFramerateLimit(60);
///crear el mapa
mapas=new Mapas();
add(mapas);
///CREAR PLAYER 1
jugador = new Jugador();
add(jugador);
jugador->SetPlayer1(1);
///CREAR PLAYER 2
jugador2 = new Jugador(1);
add(jugador2);
jugador2->SetPlayer2(1);

}
///NIVELES EM DIFICULTAD FACIL---------------------------------------------

void Juego::GenerarNiveles1jugadorFacil(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1300, 300 , 70 , 0 ,1 );
  CreatenpcEsqueleto(1500, 300 , 70 , 0 ,1 );
  CreatenpcEsqueleto(1800, 300 , 70 , 0 ,1 );
  CreatenpcEsqueleto(2000, 300 , 70 , 0 ,1 );
  CreatenpcHelldog(2500, 300 , 130 , 0.70 ,1 );
  CreatenpcHelldog(2800, 300 , 130 , 0.72 ,1 );
  CreatenpcHelldog(3100, 300 , 130 , 0.68 ,1 );
  CreatenpcHelldog(3400, 300 , 130 , 0.74 ,1 );
  CreatenpcTroll(4000 , 300 , 170 , 0.63 , 1);
  CreatenpcTroll(4200 , 300 , 170 , 0.65 , 1);
  CreatenpcTroll(4500 , 300 , 170 , 0.62 , 1);
  CreatenpcTroll(4700 , 300 , 170 , 0.60 , 1);
  CreatenpcTroll(5000 , 300 , 170 , 0.60 , 1);
  CreatenpcHelldog(5200, 300 , 130 , 0.74 ,1 );
  CreatenpcEsqueleto(5400, 300 , 70 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 170 , 0.60 , 1);
  CreatenpcHelldog(6000, 300 , 130 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 70 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 170 , 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 130 , 0.74 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 650 , 0.30 , 1);
  ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 100 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 100 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 100 , 0.65 ,1 );
  CreatenpcCaballero(2000, 2550 , 100 , 0.68 ,1 );
  CreatenpcMinotauro(2500, 2550 , 150 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 150 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 150 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 150 , 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,100 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 150 , 0.74 ,1 );
  CreatenpcDragon(3700, 2550, 130 , 0.68 ,1 );
  CreatenpcDragon(3900, 2550, 130 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 150 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,100 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 150 , 0.70 ,1 );
  CreatenpcDragon(5400, 2550, 130 , 0.67 ,1 );
  CreatenpcDragon(5600, 2550, 130 , 0.72 ,1 );
  CreatenpcMinotauro(6100, 2550, 150 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,100 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 150 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS HECHICERO
   CreatebossHechicero(9200, 2550, 500, 0.40, 1);
   ///VIDAS EN EL MAPA
   CreateCorazon( 4500, 400 ,1);
   CreateCorazon( 7600, 400 ,1);
   CreateCorazon( 7700, 400 ,1);
   if(corazon==1){
   CreateCorazon( 400, 2620 ,1);
   CreateCorazon( 600, 2620 ,1);}
   CreateCorazon( 3000, 2620 ,1);
   CreateCorazon( 7500, 2620 ,1);
   CreateCorazon( 7300, 2620 ,1);

}

void Juego::GenerarNiveles2jugadoresFacil(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1200, 300 , 150 , 0.68 ,1 );
  CreatenpcEsqueleto(1500, 300 , 150 , 0.66 ,1 );
  CreatenpcEsqueleto(1800, 300 , 150 , 0.64 ,1 );
  CreatenpcEsqueleto(2000, 300 , 150 , 0.70 ,1 );
  CreatenpcHelldog(2500, 300 , 200 , 0.73 ,1 );
  CreatenpcHelldog(2800, 300 , 200 , 0.75 ,1 );
  CreatenpcHelldog(3100, 300 , 200 , 0.71 ,1 );
  CreatenpcHelldog(3400, 300 , 200 , 0.77 ,1 );
  CreatenpcTroll(4000 , 300 , 250 , 0.66 , 1);
  CreatenpcTroll(4200 , 300 , 250 , 0.60 , 1);
  CreatenpcTroll(4500 , 300 , 250 , 0.65 , 1);
  CreatenpcTroll(4700 , 300 , 250 , 0.63 , 1);
  CreatenpcTroll(5000 , 300 , 250 , 0.66 , 1);
  CreatenpcHelldog(5200, 300 , 190 , 0.77 ,1 );
  CreatenpcEsqueleto(5400, 300 , 150 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 250, 0.58 , 1);
  CreatenpcHelldog(6000, 300 , 200 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 150 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 250, 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 200 , 0.74 ,1 );
  CreatenpcEsqueleto(7000, 300 , 150 , 0.67 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 1100 , 0.30 , 1);
   ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 180 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 180 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 180 , 0.67 ,1 );
  CreatenpcCaballero(2000, 2550 , 180 , 0.69 ,1 );
  CreatenpcMinotauro(2500, 2550 , 180 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 220 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 220 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 220, 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 220 , 0.70 ,1 );
  CreatenpcDragon(3700, 2550, 230 , 0.70 ,1 );
  CreatenpcDragon(3900, 2550, 230 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 220 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 220 , 0.69 ,1 );
  CreatenpcDragon(5400, 2550, 230 , 0.70 ,1 );
  CreatenpcDragon(5600, 2550, 230 , 0.74 ,1 );
  CreatenpcMinotauro(6100, 2550, 220 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 250 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS VOID
 CreatebossHechicero(9200, 2550, 950, 0.40, 1);
  ///VIDAS EN EL MAPA
  CreateCorazon( 3600, 400 ,1);
  CreateCorazon( 5500, 400 ,1);
  CreateCorazon( 7500, 400 ,1);
  CreateCorazon( 7600, 400 ,1);
  CreateCorazon( 7700, 400 ,1);
   if(corazon==1){
  CreateCorazon( 400, 2620 ,1);
  CreateCorazon( 600, 2620 ,1);}
  CreateCorazon( 1800, 2620 ,1);
  CreateCorazon( 2000, 2620 ,1);
  CreateCorazon( 7200, 2620 ,1);
  CreateCorazon( 7500, 2620 ,1);
  CreateCorazon( 7800, 2620 ,1);
}
///--------------------------------------------------------------------

///NIVELES EM DIFICULTAD NORMAL---------------------------------------------
void Juego::GenerarNiveles1jugadorNormal(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1300, 300 , 120 , 0.65 ,1 );
  CreatenpcEsqueleto(1500, 300 , 100 , 0.63 ,1 );
  CreatenpcEsqueleto(1800, 300 , 120 , 0.61 ,1 );
  CreatenpcEsqueleto(2000, 300 , 150 , 0.67 ,1 );
  CreatenpcHelldog(2500, 300 , 220 , 0.70 ,1 );
  CreatenpcHelldog(2800, 300 , 230 , 0.72 ,1 );
  CreatenpcHelldog(3100, 300 , 200 , 0.68 ,1 );
  CreatenpcHelldog(3400, 300 , 200 , 0.74 ,1 );
  CreatenpcTroll(4000 , 300 , 250 , 0.63 , 1);
  CreatenpcTroll(4200 , 300 , 250 , 0.65 , 1);
  CreatenpcTroll(4500 , 300 , 250 , 0.62 , 1);
  CreatenpcTroll(4700 , 300 , 250 , 0.60 , 1);
  CreatenpcTroll(5000 , 300 , 250 , 0.60 , 1);
  CreatenpcHelldog(5200, 300 , 220 , 0.74 ,1 );
  CreatenpcEsqueleto(5400, 300 , 150 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 250 , 0.60 , 1);
  CreatenpcHelldog(6000, 300 , 200 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 150 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 250 , 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 200 , 0.74 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 1250 , 0.30 , 1);
  ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 180 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 180 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 180 , 0.65 ,1 );
  CreatenpcCaballero(2000, 2550 , 180 , 0.68 ,1 );
  CreatenpcMinotauro(2500, 2550 , 220 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 220 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 220 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 220 , 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 220 , 0.74 ,1 );
  CreatenpcDragon(3700, 2550, 200 , 0.68 ,1 );
  CreatenpcDragon(3900, 2550, 200 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 220 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 220 , 0.70 ,1 );
  CreatenpcDragon(5400, 2550, 200 , 0.67 ,1 );
  CreatenpcDragon(5600, 2550, 200 , 0.72 ,1 );
  CreatenpcMinotauro(6100, 2550, 220 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,180 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 220 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS HECHICERO
   CreatebossHechicero(9200, 2550, 1000, 0.40, 1);
   ///VIDAS EN EL MAPA
   CreateCorazon( 4500, 400 ,1);
   CreateCorazon( 7600, 400 ,1);
   CreateCorazon( 7700, 400 ,1);
   if(corazon==1){
   CreateCorazon( 400, 2620 ,1);
   CreateCorazon( 600, 2620 ,1);}
   CreateCorazon( 3000, 2620 ,1);
   CreateCorazon( 7500, 2620 ,1);
   CreateCorazon( 7300, 2620 ,1);

}

void Juego::GenerarNiveles2jugadoresNormal(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1200, 300 , 220 , 0.68 ,1 );
  CreatenpcEsqueleto(1500, 300 , 220 , 0.66 ,1 );
  CreatenpcEsqueleto(1800, 300 , 220 , 0.64 ,1 );
  CreatenpcEsqueleto(2000, 300 , 220 , 0.70 ,1 );
  CreatenpcHelldog(2500, 300 , 270 , 0.73 ,1 );
  CreatenpcHelldog(2800, 300 , 270 , 0.75 ,1 );
  CreatenpcHelldog(3100, 300 , 270 , 0.71 ,1 );
  CreatenpcHelldog(3400, 300 , 270 , 0.77 ,1 );
  CreatenpcTroll(4000 , 300 , 350 , 0.66 , 1);
  CreatenpcTroll(4200 , 300 , 350 , 0.60 , 1);
  CreatenpcTroll(4500 , 300 , 350 , 0.65 , 1);
  CreatenpcTroll(4700 , 300 , 350 , 0.63 , 1);
  CreatenpcTroll(5000 , 300 , 350 , 0.66 , 1);
  CreatenpcHelldog(5200, 300 , 270 , 0.77 ,1 );
  CreatenpcEsqueleto(5400, 300 , 220 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 350, 0.58 , 1);
  CreatenpcHelldog(6000, 300 , 370 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 220 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 350, 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 270 , 0.74 ,1 );
  CreatenpcEsqueleto(7000, 300 , 200 , 0.67 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 2800 , 0.30 , 1);
   ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 250 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 250 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 250 , 0.67 ,1 );
  CreatenpcCaballero(2000, 2550 , 250 , 0.69 ,1 );
  CreatenpcMinotauro(2500, 2550 , 250 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 300 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 300 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 300 , 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,250 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 300 , 0.70 ,1 );
  CreatenpcDragon(3700, 2550, 270 , 0.70 ,1 );
  CreatenpcDragon(3900, 2550, 270 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 300 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,250 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 300 , 0.69 ,1 );
  CreatenpcDragon(5400, 2550, 270 , 0.70 ,1 );
  CreatenpcDragon(5600, 2550, 270 , 0.74 ,1 );
  CreatenpcMinotauro(6100, 2550, 300 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,250 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 350 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS VOID
 CreatebossHechicero(9200, 2550, 2600, 0.40, 1);
  ///VIDAS EN EL MAPA
  CreateCorazon( 3600, 400 ,1);
  CreateCorazon( 5500, 400 ,1);
  CreateCorazon( 7500, 400 ,1);
  CreateCorazon( 7600, 400 ,1);
  CreateCorazon( 7700, 400 ,1);
  if(corazon==1){
  CreateCorazon( 400, 2620 ,1);
  CreateCorazon( 600, 2620 ,1);}
  CreateCorazon( 1800, 2620 ,1);
  CreateCorazon( 2000, 2620 ,1);
  CreateCorazon( 7200, 2620 ,1);
  CreateCorazon( 7500, 2620 ,1);
  CreateCorazon( 7800, 2620 ,1);
}
///--------------------------------------------------------------------
///NIVELES EM DIFICULTAD DIFICIL---------------------------------------
void Juego::GenerarNiveles1jugadorDificil(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1300, 300 , 170 , 0.65 ,1 );
  CreatenpcEsqueleto(1500, 300 , 180 , 0.63 ,1 );
  CreatenpcEsqueleto(1800, 300 , 170 , 0.61 ,1 );
  CreatenpcEsqueleto(2000, 300 , 200 , 0.67 ,1 );
  CreatenpcHelldog(2500, 300 , 270 , 0.70 ,1 );
  CreatenpcHelldog(2800, 300 , 280 , 0.72 ,1 );
  CreatenpcHelldog(3100, 300 , 250 , 0.68 ,1 );
  CreatenpcHelldog(3400, 300 , 250 , 0.74 ,1 );
  CreatenpcTroll(4000 , 300 , 320, 0.63 , 1);
  CreatenpcTroll(4200 , 300 , 320 , 0.65 , 1);
  CreatenpcTroll(4500 , 300 , 320 , 0.62 , 1);
  CreatenpcTroll(4700 , 300 , 320 , 0.60 , 1);
  CreatenpcTroll(5000 , 300 , 320 , 0.60 , 1);
  CreatenpcHelldog(5200, 300 , 300 , 0.74 ,1 );
  CreatenpcEsqueleto(5400, 300 , 220 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 320 , 0.60 , 1);
  CreatenpcHelldog(6000, 300 , 260 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 200 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 310 , 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 250 , 0.74 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 2000 , 0.30 , 1);
  ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 240 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 240 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 240 , 0.65 ,1 );
  CreatenpcCaballero(2000, 2550 , 240 , 0.68 ,1 );
  CreatenpcMinotauro(2500, 2550 , 300 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 300 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 300 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 300, 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,240 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 300 , 0.74 ,1 );
  CreatenpcDragon(3700, 2550, 260 , 0.68 ,1 );
  CreatenpcDragon(3900, 2550, 260 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 300 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,250 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 320 , 0.70 ,1 );
  CreatenpcDragon(5400, 2550, 260 , 0.67 ,1 );
  CreatenpcDragon(5600, 2550, 260 , 0.72 ,1 );
  CreatenpcMinotauro(6100, 2550, 300 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,250 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 320 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS HECHICERO
   CreatebossHechicero(9200, 2550, 1850, 0.40, 1);
   ///VIDAS EN EL MAPA
   CreateCorazon( 4500, 400 ,1);
   CreateCorazon( 7600, 400 ,1);
   CreateCorazon( 7700, 400 ,1);
   if(corazon==1){
   CreateCorazon( 400, 2620 ,1);
   CreateCorazon( 600, 2620 ,1);}
   CreateCorazon( 3000, 2620 ,1);
   CreateCorazon( 7500, 2620 ,1);
   CreateCorazon( 7300, 2620 ,1);

}

void Juego::GenerarNiveles2jugadoresDificil(){
 ///NIVEL 1 INFIERNO NPCS
  CreatenpcEsqueleto(1200, 300 , 320 , 0.68 ,1 );
  CreatenpcEsqueleto(1500, 300 , 320 , 0.66 ,1 );
  CreatenpcEsqueleto(1800, 300 , 320 , 0.64 ,1 );
  CreatenpcEsqueleto(2000, 300 , 320 , 0.70 ,1 );
  CreatenpcHelldog(2500, 300 , 370 , 0.73 ,1 );
  CreatenpcHelldog(2800, 300 , 370 , 0.75 ,1 );
  CreatenpcHelldog(3100, 300 , 370 , 0.71 ,1 );
  CreatenpcHelldog(3400, 300 , 370 , 0.77 ,1 );
  CreatenpcTroll(4000 , 300 , 500 , 0.66 , 1);
  CreatenpcTroll(4200 , 300 , 500 , 0.60 , 1);
  CreatenpcTroll(4500 , 300 , 500 , 0.65 , 1);
  CreatenpcTroll(4700 , 300 , 500 , 0.63 , 1);
  CreatenpcTroll(5000 , 300 , 500 , 0.66 , 1);
  CreatenpcHelldog(5200, 300 , 370 , 0.77 ,1 );
  CreatenpcEsqueleto(5400, 300 , 320 , 0.67 ,1 );
  CreatenpcTroll(5800 , 300 , 500, 0.58 , 1);
  CreatenpcHelldog(6000, 300 , 380 , 0.74 ,1 );
  CreatenpcEsqueleto(6200, 300 , 320 , 0.67 ,1 );
  CreatenpcTroll(6500 , 300 , 500, 0.60 , 1);
  CreatenpcHelldog(6700, 300 , 370 , 0.74 ,1 );
  CreatenpcEsqueleto(7000, 300 , 300 , 0.67 ,1 );
  ///NIVEL 1 INFIERNO BOSS DEMON KING
  CreatebossDemonking(9200, 300 , 3850 , 0.30 , 1);
   ///NIVEL 2 TIERRA NPCS
  CreatenpcCaballero(1300, 2550 , 370 , 0.75 ,1 );
  CreatenpcCaballero(1500, 2550 , 370 , 0.70 ,1 );
  CreatenpcCaballero(1800, 2550 , 370 , 0.67 ,1 );
  CreatenpcCaballero(2000, 2550 , 370 , 0.69 ,1 );
  CreatenpcMinotauro(2500, 2550 , 370 , 0.70 ,1 );
  CreatenpcMinotauro(2800, 2550 , 450 , 0.75 ,1 );
  CreatenpcMinotauro(3100, 2550 , 450 , 0.79 ,1 );
  CreatenpcMinotauro(3400, 2550, 450 , 0.74 ,1 );
  CreatenpcCaballero(3100, 2550 ,370 , 0.68 ,1 );
  CreatenpcMinotauro(3400, 2550, 450 , 0.70 ,1 );
  CreatenpcDragon(3700, 2550, 400 , 0.70 ,1 );
  CreatenpcDragon(3900, 2550, 400 , 0.75 ,1 );
  CreatenpcMinotauro(4300, 2550, 450 , 0.74 ,1 );
  CreatenpcCaballero(4700, 2550 ,370 , 0.68 ,1 );
  CreatenpcMinotauro(5100, 2550, 450 , 0.69 ,1 );
  CreatenpcDragon(5400, 2550, 400 , 0.70 ,1 );
  CreatenpcDragon(5600, 2550, 400 , 0.74 ,1 );
  CreatenpcMinotauro(6100, 2550, 450 , 0.74 ,1 );
  CreatenpcCaballero(6400, 2550 ,370 , 0.68 ,1 );
  CreatenpcMinotauro(6800, 2550, 480 , 0.70 ,1 );
  ///NIVEL 2 TIERRA BOSS VOID
 CreatebossHechicero(9200, 2550, 3650, 0.40, 1);
  ///VIDAS EN EL MAPA
  CreateCorazon( 3600, 400 ,1);
  CreateCorazon( 5500, 400 ,1);
  CreateCorazon( 7500, 400 ,1);
  CreateCorazon( 7600, 400 ,1);
  CreateCorazon( 7700, 400 ,1);
   if(corazon==1){
  CreateCorazon( 400, 2620 ,1);
  CreateCorazon( 600, 2620 ,1);}
  CreateCorazon( 1800, 2620 ,1);
  CreateCorazon( 2000, 2620 ,1);
  CreateCorazon( 7200, 2620 ,1);
  CreateCorazon( 7500, 2620 ,1);
  CreateCorazon( 7800, 2620 ,1);
}
///--------------------------------------------------------------------

///MENU PRINCIPAL -------------------------------------------------
void Juego::MenuPrincipal(){
Menu menu(w.getSize().x, w.getSize().y);
while(w.isOpen()){
///Quitar todos los  eventos en cola de la ventana
sf::Event event;
while(w.pollEvent(event)){
switch (event.type){
    case sf::Event::JoystickMoved:
    if(event.joystickMove.axis == sf::Joystick::Y){
        if(event.joystickMove.position > 95.f ){
            menu.moverabajo();
            Soundmenu.play();
        }
        if(event.joystickMove.position < -95.f){
            menu.moverarriba();
            Soundmenu.play();
        }
    }
    break;
    case sf::Event::JoystickButtonPressed:
switch(menu.presionaritem()){
case 0:
Soundmenu.play();
dosplayer=0;
MenuInicio();
break;
case 1:
Soundmenu.play();
dosplayer=1;
MenuInicio();
break;
case 2:
Soundmenu.play();
Menudificultad();
break;
case 3:
Soundmenu.play();
w.close();
break;
}
    break;
    /*
case sf::Event::KeyReleased:
switch(event.key.code){
case sf::Keyboard::Up:
menu.moverarriba();
Soundmenu.play();
break;
case sf::Keyboard::Down:
menu.moverabajo();
Soundmenu.play();
break;
case sf::Keyboard::Return:
switch(menu.presionaritem()){
case 0:
Soundmenu.play();
dosplayer=0;
MenuInicio();
break;
case 1:
Soundmenu.play();
dosplayer=1;
MenuInicio();
break;
case 2:
Soundmenu.play();
Menudificultad();
break;
case 3:
Soundmenu.play();
w.close();
break;
}
break;
}
break;*/
case sf::Event::Closed:
Soundmenu.play();
w.close();
break;
}
    }
menu.dibujar(w);
w.display();
}
   }
///--------------------------------------------------------

///MENU-INICIO-DEL-JUEGO-----------------------------------
void Juego::MenuInicio(){
Menu2 menu(w.getSize().x, w.getSize().y);
while(w.isOpen()){
///Quitar todos los  eventos en cola de la ventana
sf::Event event;
while(w.pollEvent(event)){
switch (event.type){
    case sf::Event::JoystickMoved:
    if(event.joystickMove.axis == sf::Joystick::Y){
        if(event.joystickMove.position > 95.f ){
            menu.moverabajo();
            Soundmenu.play();
        }
        if(event.joystickMove.position < -95.f){
            menu.moverarriba();
            Soundmenu.play();
        }
    }
    break;
    case sf::Event::JoystickButtonPressed:
        switch(menu.presionaritem()){
case 0:
Soundmenu.play();
Guardar2();
musicMenu.stop();
musicInfierno.setLoop(true);
musicInfierno.play();
if(dosplayer==0){
if(ComprobarFacil()==1)GenerarNiveles1jugadorFacil();
else if(ComprobarNormal()==1)GenerarNiveles1jugadorNormal();
else if(ComprobarDificil()==1)GenerarNiveles1jugadorDificil();
else GenerarNiveles2jugadoresNormal();
}
else if (dosplayer==1){
if(ComprobarFacil()==1)GenerarNiveles2jugadoresFacil();
else if(ComprobarNormal()==1)GenerarNiveles2jugadoresNormal();
else if(ComprobarDificil()==1)GenerarNiveles2jugadoresDificil();
else GenerarNiveles2jugadoresNormal();
}
w.create(sf::VideoMode(1130, 600), "Return from hell");
while (w.isOpen()){
while (w.pollEvent(event)){
if (event.type ==  sf::Event::Closed){
w.close();}
}
update();
dibujar();
}
break;
case 1:
Soundmenu.play();
if(Comprobar()==1){
corazon=0;
if(dosplayer==0){
if(ComprobarFacil()==1)GenerarNiveles1jugadorFacil();
else if(ComprobarNormal()==1)GenerarNiveles1jugadorNormal();
else if(ComprobarDificil()==1)GenerarNiveles1jugadorDificil();
else GenerarNiveles2jugadoresNormal();
jugador2->Setnivel2(1);
}
else if (dosplayer==1){
if(ComprobarFacil()==1)GenerarNiveles2jugadoresFacil();
else if(ComprobarNormal()==1)GenerarNiveles2jugadoresNormal();
else if(ComprobarDificil()==1)GenerarNiveles2jugadoresDificil();
else GenerarNiveles2jugadoresNormal();
jugador2->Setnivel2(1);
jugador->Setnivel2(1);
}
w.create(sf::VideoMode(1130, 600), "Return from hell");
while (w.isOpen()){
while (w.pollEvent(event)){
if (event.type ==  sf::Event::Closed){
w.close();}
}
update();
dibujar();
}
}
break;
case 2:
Soundmenu.play();
MenuPrincipal();
break;
}
        break;
/*case sf::Event::KeyReleased:
switch(event.key.code){
case sf::Keyboard::Up:
menu.moverarriba();
Soundmenu.play();
break;
case sf::Keyboard::Down:
menu.moverabajo();
Soundmenu.play();
break;
case sf::Keyboard::Return:
switch(menu.presionaritem()){
case 0:
Soundmenu.play();
Guardar2();
musicMenu.stop();
musicInfierno.setLoop(true);
musicInfierno.play();
if(dosplayer==0){
if(ComprobarFacil()==1)GenerarNiveles1jugadorFacil();
else if(ComprobarNormal()==1)GenerarNiveles1jugadorNormal();
else if(ComprobarDificil()==1)GenerarNiveles1jugadorDificil();
else GenerarNiveles2jugadoresNormal();
}
else if (dosplayer==1){
if(ComprobarFacil()==1)GenerarNiveles2jugadoresFacil();
else if(ComprobarNormal()==1)GenerarNiveles2jugadoresNormal();
else if(ComprobarDificil()==1)GenerarNiveles2jugadoresDificil();
else GenerarNiveles2jugadoresNormal();
}
w.create(sf::VideoMode(1130, 600), "Return from hell");
while (w.isOpen()){
while (w.pollEvent(event)){
if (event.type ==  sf::Event::Closed){
w.close();}
}
update();
dibujar();
}
break;
case 1:
Soundmenu.play();
if(Comprobar()==1){
corazon=0;
if(dosplayer==0){
if(ComprobarFacil()==1)GenerarNiveles1jugadorFacil();
else if(ComprobarNormal()==1)GenerarNiveles1jugadorNormal();
else if(ComprobarDificil()==1)GenerarNiveles1jugadorDificil();
else GenerarNiveles2jugadoresNormal();
jugador2->Setnivel2(1);
}
else if (dosplayer==1){
if(ComprobarFacil()==1)GenerarNiveles2jugadoresFacil();
else if(ComprobarNormal()==1)GenerarNiveles2jugadoresNormal();
else if(ComprobarDificil()==1)GenerarNiveles2jugadoresDificil();
else GenerarNiveles2jugadoresNormal();
jugador2->Setnivel2(1);
jugador->Setnivel2(1);
}
w.create(sf::VideoMode(1130, 600), "Return from hell");
while (w.isOpen()){
while (w.pollEvent(event)){
if (event.type ==  sf::Event::Closed){
w.close();}
}
update();
dibujar();
}
}
break;
case 2:
Soundmenu.play();
MenuPrincipal();
break;
}
break;
}
break;*/
case sf::Event::Closed:
Soundmenu.play();
w.close();
break;
}
}
menu.dibujar(w);
w.display();
}

}
///----------------------------------------------------------------

///-------MENU-SELECCION-DE-DIFICULTAD-----------------------------
void Juego::Menudificultad(){
 Menu3 menu(w.getSize().x, w.getSize().y);
while(w.isOpen()){
///Quitar todos los  eventos en cola de la ventana
sf::Event event;
while(w.pollEvent(event)){
switch (event.type){
     case sf::Event::JoystickMoved:
    if(event.joystickMove.axis == sf::Joystick::Y){
        if(event.joystickMove.position > 95.f ){
            menu.moverabajo();
            Soundmenu.play();
        }
        if(event.joystickMove.position < -95.f){
            menu.moverarriba();
            Soundmenu.play();
        }
    }
    break;
    case sf::Event::JoystickButtonPressed:
        switch(menu.presionaritem()){
case 0:
Soundmenu.play();
GuardarFacil();
MenuPrincipal();
break;
case 1:
Soundmenu.play();
GuardarNormal();
MenuPrincipal();
break;
case 2:
Soundmenu.play();
GuardarDificil();
MenuPrincipal();
break;
case 3:
Soundmenu.play();
MenuPrincipal();
break;
}
        break;
        /*
case sf::Event::KeyReleased:
switch(event.key.code){
case sf::Keyboard::Up:
menu.moverarriba();
Soundmenu.play();
break;
case sf::Keyboard::Down:
menu.moverabajo();
Soundmenu.play();
break;
case sf::Keyboard::Return:
switch(menu.presionaritem()){
case 0:
Soundmenu.play();
GuardarFacil();
MenuPrincipal();
break;
case 1:
Soundmenu.play();
GuardarNormal();
MenuPrincipal();
break;
case 2:
Soundmenu.play();
GuardarDificil();
MenuPrincipal();
break;
case 3:
Soundmenu.play();
MenuPrincipal();
break;
}
break;
}
break;*/
case sf::Event::Closed:
Soundmenu.play();
w.close();
break;
}
    }
menu.dibujar(w);
w.display();
}
   }
///----------------------------------------------------------------------

void Juego::add(Entidad *e){ //AGREGAR OBJETOS AL JUEGO
    entidades.push_back(e);
}
void Juego::borrar(Entidad *e){ //FUNCION LIBERAR MEMORIA DINAMICA AL FINALIZAR JUEGO
    delete e;
    to_delete.push_back(e);

}
///--------------------------------NPC PRIMER NIVEL-----------------------------
void Juego::CreatenpcEsqueleto(int x , int y , int vida , float speed , int colision){
    npce = new NPC(jugador , jugador2);
    enemies.push_back(npce);
    add(npce);
    npce->SetSpeedinicial(speed);
    npce->Setspeedtotal(speed);
    npce->Setvidainicial(vida);
    npce->GettextureNpc().loadFromFile("npc/infierno/Esqueleto.png");
    ///crear sprites
     npce->GetSpritenpc().setTexture(npce->GettextureNpc());
    ///posicionar y recortar sprite
     npce->GetSpritenpc().setTextureRect(sf::IntRect(0, 0, 100, 75));
     npce->GetSpritenpc().setScale(1.2,1.2);
     npce->GetSpritenpc().setPosition(x , y);
     npce->SetEsqueleto(colision);
     ///sonidos


}

void Juego::CreatenpcHelldog(int x , int y , int vida , float speed , int colision){
  npce = new NPC(jugador , jugador2);
    enemies.push_back(npce);
    add(npce);
    npce->SetSpeedinicial(speed);
    npce->Setspeedtotal(speed);
    npce->Setvidainicial(vida);
    npce->GettextureNpc().loadFromFile("npc/infierno/Helldog.png");
    ///crear sprites
     npce->GetSpritenpc().setTexture(npce->GettextureNpc());
    ///posicionar y recortar sprite
     npce->GetSpritenpc().setTextureRect(sf::IntRect(0, 0, 150, 60));
     npce->GetSpritenpc().setScale(1,1);
     npce->GetSpritenpc().setPosition(x , y);
     npce->SetHelldog(colision);

}

void Juego::CreatenpcTroll(int x , int y , int vida , float speed , int colision){
    npce = new NPC(jugador , jugador2);
    enemies.push_back(npce);
    add(npce);
    npce->SetSpeedinicial(speed);
    npce->Setspeedtotal(speed);
    npce->Setvidainicial(vida);
    npce->GettextureNpc().loadFromFile("npc/infierno/3.png");
    ///crear sprites
     npce->GetSpritenpc().setTexture(npce->GettextureNpc());
    ///posicionar y recortar sprite
     npce->GetSpritenpc().setTextureRect(sf::IntRect(0, 0, 150, 60));
     npce->GetSpritenpc().setScale(1,1);
     npce->GetSpritenpc().setPosition(x , y);
     npce->SetTroll(colision);

}
void Juego::CreatebossDemonking(int x , int y , int vida , float speed , int colision){
    npce = new NPC(jugador , jugador2 , 1);
    enemies.push_back(npce);
    add(npce);
    npce->SetspeedinicialDemonking(speed);
    npce->SetvidainicialDemonking(vida);
    npce->SetvidainicialDemonkingtotal(vida);
    npce->GetTextureDemonking().loadFromFile("boss/infierno/DemonKing.png");
    npce->GetTextureEspada().loadFromFile("boss/infierno/Espada.png");
    npce->GetTextureHpDemonking().loadFromFile("boss/infierno/HP.png");
    npce->GetTexturePortal().loadFromFile("boss/infierno/Portal.png");
    ///crear sprites
     npce->GetspriteDemonking().setTexture(npce->GetTextureDemonking());
     npce->GetspriteEspadas().setTexture(npce->GetTextureEspada());
     npce->GetspriteHpDemonking().setTexture(npce->GetTextureHpDemonking());
     npce->GetspritePortal().setTexture(npce->GetTexturePortal());
    ///posicionar y recortar sprite
     npce->GetspriteDemonking().setTextureRect(sf::IntRect(0, 200, 200,200 ));
     npce->GetspriteDemonking().setScale(1,1);
     npce->GetspriteDemonking().setPosition(x , y);
     npce->SetDemonking(colision);
}

///-----------------------NPC SEGUNDO NIVEL-------------------------------------
void Juego::CreatenpcCaballero(int x , int y , int vida , float speed , int colision){
  npc2 = new NPC2(jugador , jugador2);
    enemies2.push_back(npc2);
    add(npc2);
    npc2->SetSpeedinicial(speed);
    npc2->SetSpeedtotal(speed);
    npc2->Setvidainicial(vida);
    npc2->GetTexturenpc().loadFromFile("npc/tierra/caballero.png");
    ///crear sprites
     npc2->Getspritenpc().setTexture(npc2->GetTexturenpc());
    ///posicionar y recortar sprite
     npc2->Getspritenpc().setTextureRect(sf::IntRect(0, 0, 100, 100));
     npc2->Getspritenpc().setScale(1.3,1.3);
     npc2->Getspritenpc().setPosition(x , y);
     npc2->SetCaballero(colision);

}

void Juego::CreatenpcMinotauro(int x , int y , int vida , float speed , int colision){
  npc2 = new NPC2(jugador , jugador2);
    enemies2.push_back(npc2);
    add(npc2);
     npc2->SetSpeedinicial(speed);
     npc2->SetSpeedtotal(speed);
     npc2->Setvidainicial(vida);
     npc2->GetTexturenpc().loadFromFile("npc/tierra/minotauro.png");
    ///crear sprites
     npc2->Getspritenpc().setTexture(npc2->GetTexturenpc());
    ///posicionar y recortar sprite
     npc2->Getspritenpc().setTextureRect(sf::IntRect(0, 0, 150, 120));
     npc2->Getspritenpc().setScale(1.6,1.6);
     npc2->Getspritenpc().setPosition(x , y);
     npc2->SetMinotauro(colision);

}

void Juego::CreatenpcDragon(int x , int y , int vida , float speed , int colision){
  npc2 = new NPC2(jugador , jugador2);
    enemies2.push_back(npc2);
    add(npc2);
    npc2->SetSpeedinicial(speed);
    npc2->SetSpeedtotal(speed);
    npc2->Setvidainicial(vida);
    npc2->GetTexturenpc().loadFromFile("npc/tierra/dragon.png");
    npc2->GetTextureFuego2().loadFromFile("npc/tierra/Fuego.png");
    ///crear sprites
     npc2->Getspritenpc().setTexture(npc2->GetTexturenpc());
     npc2->GetspriteFuego2().setTexture(npc2->GetTextureFuego2());
    ///posicionar y recortar sprite
     npc2->Getspritenpc().setTextureRect(sf::IntRect(0, 0, 200, 170));
     npc2->Getspritenpc().setScale(0.9,0.9);
     npc2->Getspritenpc().setPosition(x , y);
     npc2->SetDragon(colision);

}

void Juego::CreatebossHechicero(int x , int y , int vida , float speed , int colision){
    npc2 = new NPC2(jugador , jugador2 , 1 );
    enemies2.push_back(npc2);
    add(npc2);
    npc2->SetSpeedinicialHechicero(speed);
    npc2->SetvidainicialHechicero(vida);
    npc2->SetvidainicialHechiceroTotal(vida);
    npc2->GetTextureHechicero().loadFromFile("boss/tierra/mago.png");
    npc2->GetTextureFuegoH1().loadFromFile("boss/tierra/mago atk 1 f1.png");
    npc2->GetTextureFuegoH2().loadFromFile("boss/tierra/mago atk 2 f1.png");
    npc2->GetTextureMeteorito().loadFromFile("boss/tierra/final 1.png");
    npc2->GetTextureHielo().loadFromFile("boss/tierra/final 2.png");
    npc2->GetTextureHpHechicero().loadFromFile("boss/infierno/HP.png");
    ///crear sprites
     npc2->GetspriteHechicero().setTexture(npc2->GetTextureHechicero());
     npc2->GetspriteFuegoH1().setTexture(npc2->GetTextureFuegoH1());
     npc2->GetspriteFuegoH2().setTexture(npc2->GetTextureFuegoH2());
     npc2->GetspriteMeteorito().setTexture(npc2->GetTextureMeteorito());
     npc2->GetspriteHielo().setTexture(npc2->GetTextureHielo());
     npc2->GetspriteHpHechicero().setTexture(npc2->GetTextureHpHechicero());
    ///posicionar y recortar sprite
     npc2->GetspriteHechicero().setTextureRect(sf::IntRect(0, 120, 150, 120));
     npc2->GetspriteHechicero().setScale(1.5,1.5);
     npc2->GetspriteMeteorito().setScale(2.5,2.5);
     npc2->GetspriteHechicero().setPosition(x , y);
     npc2->SetHechicero(colision);
}

void Juego::CreateCorazon(int x , int y , int estad){
npce = new NPC(jugador , jugador2);
enemies.push_back(npce);
add(npce);
npce->GetTexturecorazon().loadFromFile("imagenes player 1/Vida.png");
npce->GetSpritecorazon().setTexture(npce->GetTexturecorazon());
npce->GetSpritecorazon().setPosition( x , y);
npce->SetCorazon(estad);
npce->GetSpritecorazon().setTextureRect(sf::IntRect (200 ,  0 , 100 , 100));

}

void Juego::Endgame(){
sf::Time gameoverclock = Relojgameover.getElapsedTime();
sf::Time gameoverclockdef = Relojgameoverdef.getElapsedTime();
sf::Time gamewinclock = Relojgamewin.getElapsedTime();
sf::Time gamewinclockdef = Relojgamewindef.getElapsedTime();
if(jugador2->Getvida() >= 1) ultimaposp2 = jugador2->getSprite2().getPosition();
if(jugador->Getvida() >= 1) ultimaposp1 = jugador->getSprite().getPosition();
if(gameover==0){
Relojgameover.restart();
Relojgameoverdef.restart();
}
if(gamewin==0){
Relojgamewin.restart();
Relojgamewindef.restart();
}
///QUITAR AL OTRO JUGADOR DE LA PANTALLA EN MODO 1 PLAYER
 if(dosplayer==0){
    jugador->Darlevida(-1);
    jugador->getSprite().setPosition(-99999,999);
    dosplayer=2;
    }
///QUITAR DE LA PANTALLA AL JUGADOR QUE MUERA
   if(jugador2->Getvida()<=0){
    jugador2->getSprite2().setPosition(-999999,999);
    jugador2->Darlevida(-10);
   }
   if(jugador->Getvida()<=0){
    jugador->getSprite().setPosition(-999999,999);
    jugador->Darlevida(-10);
   }
 ///INICIAR EL GAMEOVER AL MORIR LOS 2 JUGADORES
   if(jugador->Getvida()<=0 & jugador2->Getvida()<=0){
    gameover=1;
 }
 if(npc2->GetvidaBoss()<=0){
    gamewin=1;
 }
 ///TERMINA EL JUEGO AL MORIR LOS 2 JUGADORES
   if(gameover==1){
    if(gameoverclock.asSeconds() >= 0.5 & gameoverclock.asSeconds() <1){
    jugador2->Getgameover().setPosition(ultimaposp2.x-200 , ultimaposp2.y-200);
    }
    if(gameoverclock.asSeconds() >= 1 & gameoverclock.asSeconds() <1.5){
    jugador2->Getgameover().setPosition(ultimaposp1.x-200 , ultimaposp1.y-200);
    Relojgameover.restart();
    }
    if(gameoverclockdef.asSeconds()>=10){
        w.close();
    }
   }
   ///TERMINA EL JUEGO AL DERROTAR AL JEFE DINAL
   if(gamewin==1){
    if(gamewinclock.asSeconds() >= 0.5 & gamewinclock.asSeconds() <1){
    jugador->Getgamewin().setPosition(ultimaposp2.x-380 , ultimaposp2.y-200);
    }
    if(gamewinclock.asSeconds() >= 1 & gamewinclock.asSeconds() <1.5){
    jugador->Getgamewin().setPosition(ultimaposp1.x-380 , ultimaposp1.y-200);
    Relojgamewin.restart();
    }
    if(gamewinclockdef.asSeconds()>=20 & gamewinclockdef.asSeconds()<=20.1){
        w.close();
    }
   }
}
void Juego::run(){
   MenuPrincipal();

     }

void Juego::SoundsPrimerNivel(){
     if(jugador2->GetBossfight()==1 || jugador->GetBossfight()==1){
         if(reproducir==1){
        musicInfierno.stop();
        musicDemon.setLoop(true);
        musicDemon.play();
         }
         reproducir=0;
        }
    if(jugador2->GetBossfight()==0 || jugador->GetBossfight()==0){
        musicDemon.stop();
    }
}

void Juego::SoundsSegundoNivel(){
    if(jugador->Getnivel2()==1 || jugador2->Getnivel2()==1){
            if(reproducir2==1){
            musicMenu.stop();
        musicTierra.setLoop(true);
        musicTierra.play();
            }
            reproducir2=0;
    }
    if(jugador2->GetBossfight2()==1 || jugador->GetBossfight2()==1){
         if(reproducir3==1){
        musicTierra.stop();
        musicBoss.setLoop(true);
        musicBoss.play();
         }
         reproducir3=0;
        }
}

void Juego::update(){
    for(auto e: entidades){
    e->update();

    }
    Endgame();
   SoundsPrimerNivel();///MUSICA NIVEL Y BOSS NIVEL 1
   SoundsSegundoNivel();///MUSICA NIVEL Y BOSS NIVEL 2
   if(jugador2->Getnivel2()==1 || jugador->Getnivel2()==1){
       if(guardado==0) {
            Guardar();
       }
       guardado=1;
        }
 }

void Juego::dibujar(){
    ///limpiar la pantalla
     w.clear(sf::Color::Black);
    ///dibujar los elementos del juego
    for(auto e: entidades){
    e->dibujar(w);
    }
    ///refrescar pantalla
    w.display();
      ///seguimiento de camara al pj-------------------------------
   if(jugador->Getvida() >= 1 & jugador->GetBossfight()==0 & jugador->GetBossfight2()==0){ sf::Vector2f position;
    sf::View view, view2;
    position.x = jugador->getSprite().getPosition().x+10 -(1130/2);
    position.y = jugador->getSprite().getPosition().y+10 -(600/2);
    if(position.x < 0)position.x=0;
    if(position.y < 0)position.y=0;
    view.reset(sf::FloatRect(position.x, position.y, 1200, 600));
    w.setView(view);}
    ///---------------------------------------------------------

    ///SEGUIMIENTO PJ2-------------------------------------------
   else if(jugador->Getvida()<=0 & jugador2->GetBossfight()==0 & jugador2->GetBossfight2()==0 & jugador2->Getvida()>=1){
    sf::Vector2f position;
    sf::View view, view2;
    position.x = jugador2->getSprite2().getPosition().x+10 -(1130/2);
    position.y = jugador2->getSprite2().getPosition().y+10 -(600/2);
    if(position.x < 0)position.x=0;
    if(position.y < 0)position.y=0;
    view.reset(sf::FloatRect(position.x, position.y, 1200, 600));
    w.setView(view);
   }
    ///----------------------------------------------------------
}
