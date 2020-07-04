#include "ia2.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "Colission.h"
#include "juego.h"
using namespace std;

void NPC2::ColisionesHechicero(){
    ///----------------------------------CON PJ1 HECHICERO--------------------------------------------------------
if(Collision::PixelPerfectTest(player1->getSprite() , spHechicero) ){ // ATAQUE GIRATORIO

   if(player1->getGiro()==1)        vidaHechicero-=0.1 ;
   else if (player1->Getpinia()==1) vidaHechicero-=0.2;
   else if (player1->Getpatada()==1)vidaHechicero-=0.15;

}
if(Collision::PixelPerfectTest(player1->getTiro() , spHechicero) & player1->GetBossfight2()==1){ // TIRO DESDE DERECHA
    player1->getTiro().setPosition(9999,9999);
    vidaHechicero-=40;

}
if(Collision::PixelPerfectTest(player1->getTiro2() , spHechicero)& player1->GetBossfight2()==1){ // TIRO DESDE IZQUIERDA
    player1->getTiro2().setPosition(9999,9999);
    vidaHechicero-=40;
}
if(Collision::PixelPerfectTest(player1->getSprite() , spFuegoH1)){ // TIRO DESDE IZQUIERDA
   if (player1->Getdash()==0){
    spFuegoH1.setPosition(9999,9999);
    player1->Setvida(10);
   }
}

if(Collision::PixelPerfectTest(player1->getSprite() , spFuegoH2)){ // TIRO DESDE IZQUIERDA
   if (player1->Getdash()==0){
    spFuegoH2.setPosition(9999,9999);
    player1->Setvida(10);
   }
}

if(Collision::PixelPerfectTest(player1->getSprite() , spMeteorito)){ // TIRO DESDE IZQUIERDA
   if (player1->Getdash()==0){
    spMeteorito.setPosition(9999,9999);
    player1->Setvida(12);
   }
}

if(Collision::PixelPerfectTest(player1->getSprite() , spHielo)){ // TIRO DESDE IZQUIERDA
   if (player1->Getdash()==0){
    spHielo.setPosition(9999,9999);
    player1->Setvida(15);
   }
}
///----------------------------------------------------------------------------------------

///----------------------------------------------------------------------------------------
///--------------------------------CON-PJ2 HECHICERO---------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spHechicero) ){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
    vidaHechicero-=0.2;
}
}

if(Collision::PixelPerfectTest(player2->getSpritegetsuga1() , spHechicero)& player2->GetBossfight2()==1 ){ // ATAQUE GETSUGA DERECHA
    vidaHechicero-=40;
    player2->getSpritegetsuga1().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga2() , spHechicero)& player2->GetBossfight2()==1){ // ATAQUE GETSUGA IZQUIERDA
    vidaHechicero-=40;
    player2->getSpritegetsuga2().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritedarkpiso() , spHechicero) ){ // ATAQUE OSCURO PISO
    vidaHechicero-=0.06;
}

if(Collision::PixelPerfectTest(player2->getSpritedark() , spHechicero)& player2->GetBossfight2()==1 ){ // ATAQUE OSCURO
    vidaHechicero-=0.06;
}

if(Collision::PixelPerfectTest(player2->getSprite2() , spFuegoH1)){ // TIRO DESDE IZQUIERDA
   if (player2->Getdash2()==0){
    spFuegoH1.setPosition(9999,9999);
    player2->Setvida(10);
   }
}

if(Collision::PixelPerfectTest(player2->getSprite2() , spFuegoH2)){ // TIRO DESDE IZQUIERDA
   if (player2->Getdash2()==0){
    spFuegoH2.setPosition(9999,9999);
    player2->Setvida(10);
   }
}

if(Collision::PixelPerfectTest(player2->getSprite2() , spMeteorito)){ // TIRO DESDE IZQUIERDA
   if (player2->Getdash2()==0){
    spMeteorito.setPosition(9999,9999);
    player2->Setvida(12);
   }
}

if(Collision::PixelPerfectTest(player2->getSprite2() , spHielo)){ // TIRO DESDE IZQUIERDA
   if (player2->Getdash2()==0){
    spHielo.setPosition(9999,9999);
    player2->Setvida(15);
   }

}
}

void NPC2::ColisionesCaballero(){
    ///----------------------------------CON PJ1 CABALLERO--------------------------------------------------------
if(Collision::PixelPerfectTest(player1->getSprite() , spNpc) ){ // ATAQUE GIRATORIO
   if(player1->Getizquierda()== 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)) {
        spNpc.move(-3,0);
   }
   if(player1->Getderecha() == 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)){
        spNpc.move(3,0);
        }

   if(player1->getGiro()==1)        vida-=1;
   else if (player1->Getpinia()==1) vida-=1.6;
   else if (player1->Getpatada()==1)vida-=1;
   if(Caballeroatk >=1 &  Caballeroatk<= 3 & player1->Getdash()==0){
    player1->Setvida(0.06);
   }

}
if(Collision::PixelPerfectTest(player1->getTiro() , spNpc)){ // TIRO DESDE DERECHA
    player1->getTiro().setPosition(9999,9999);
    spNpc.move(20,0);
    vida-=40;
}
if(Collision::PixelPerfectTest(player1->getTiro2() , spNpc)){ // TIRO DESDE IZQUIERDA
    player1->getTiro2().setPosition(9999,9999);
    spNpc.move(-20,0);
    vida-=40;
}
///----------------------------------------------------------------------------------------

///----------------------------------------------------------------------------------------
///--------------------------------CON-PJ2 CABALLERO-------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc) ){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
    vida-=1;}
    if(Caballeroatk >=1 &  Caballeroatk<= 3 & player2->Getdash2()==0){
    player2->Setvida(0.06);
   }


}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga1() , spNpc) ){ // ATAQUE GETSUGA DERECHA
    spNpc.move(20,0);
    vida-=40;
    player2->getSpritegetsuga1().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga2() , spNpc) ){ // ATAQUE GETSUGA IZQUIERDA
    spNpc.move(-20,0);
    vida-=40;
    player2->getSpritegetsuga2().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritedarkpiso() , spNpc) ){ // ATAQUE OSCURO PISO
    vida-=0.06;
}
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
    vida-=0.06;
    speed=0.4;
}
else speed=speedtotal;
   }

void NPC2::ColisionesMinotauro(){

///----------------------------------CON PJ1 MINOTAURO--------------------------------------------------------
   if(Collision::PixelPerfectTest(player1->getSprite() , spNpc) ){ // ATAQUE GIRATORIO
   if(player1->Getizquierda()== 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)) {
        spNpc.move(-3,0);
   }
   if(player1->Getderecha() == 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)){
        spNpc.move(3,0);
        }

   if(player1->getGiro()==1)        vida-=1;
   else if (player1->Getpinia()==1) vida-=1.6;
   else if (player1->Getpatada()==1)vida-=1;
   if(Minotauroatk>=2 &  Minotauroatk <=4 &  player1->Getdash()==0) player1->Setvida(0.07);

}
if(Collision::PixelPerfectTest(player1->getTiro() , spNpc)){ // TIRO DESDE DERECHA
    player1->getTiro().setPosition(9999,9999);
    spNpc.move(20,0);
    vida-=40;
}
if(Collision::PixelPerfectTest(player1->getTiro2() , spNpc)){ // TIRO DESDE IZQUIERDA
    player1->getTiro2().setPosition(9999,9999);
    spNpc.move(-20,0);
    vida-=40;
}
///--------------------------------CON-PJ2 MINOTAURO-------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc)){ // ATAQUE ESPADA
  if( player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
    vida-=1.6;}
   if(Minotauroatk>=2 &  Minotauroatk <=4 &  player2->Getdash2()==0) player2->Setvida(0.07);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga1() , spNpc) ){ // ATAQUE GETSUGA DERECHA
    spNpc.move(20,0);
    vida-=40;
    player2->getSpritegetsuga1().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga2() , spNpc) ){ // ATAQUE GETSUGA IZQUIERDA
    spNpc.move(-20,0);
    vida-=40;
    player2->getSpritegetsuga2().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritedarkpiso() , spNpc) ){ // ATAQUE OSCURO PISO
    vida-=0.06;

}
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
    vida-=0.06;
    speed=0.4;
}
else speed=speedtotal;
}

void NPC2::ColisionesDragon(){
    ///-------------------CON PJ1 DRAGON----------------------------------------------------------
 if(Collision::PixelPerfectTest(player1->getSprite() , spNpc) ){ // ATAQUE GIRATORIO
   if(player1->Getizquierda()== 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)) {
        spNpc.move(-3,0);
   }
  else if(player1->Getderecha() == 1 & (player1->Getpinia()==1 || player1->getGiro()==1 || player1->Getpatada()==1)){
        spNpc.move(3,0);
        }

   if(player1->getGiro()==1)        vida-=1;
   else if (player1->Getpinia()==1) vida-=1.6;
   else if (player1->Getpatada()==1)vida-=1;
   }

   if(Collision::PixelPerfectTest(player1->getTiro() , spNpc)){ // TIRO DESDE DERECHA
    player1->getTiro().setPosition(9999,9999);
    spNpc.move(20,0);
    vida-=40;
}
if(Collision::PixelPerfectTest(player1->getTiro2() , spNpc)){ // TIRO DESDE IZQUIERDA
    player1->getTiro2().setPosition(9999,9999);
    spNpc.move(-20,0);
    vida-=40;
}

if(Collision::PixelPerfectTest(player1->getSprite() , spFuego2)){ // TIRO DESDE DERECHA
   if (player1->Getdash()==0){
    spFuego2.setPosition(-9999,-9999);
    player1->Setvida(15);
   }
}

///--------------------------------CON-PJ2 DRAGON----------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc)){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
   vida-=1.6;}
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga1() , spNpc) ){ // ATAQUE GETSUGA DERECHA
    spNpc.move(20,0);
   vida-=40;
    player2->getSpritegetsuga1().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga2() , spNpc) ){ // ATAQUE GETSUGA IZQUIERDA
    spNpc.move(-20,0);
   vida-=40;
    player2->getSpritegetsuga2().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritedarkpiso() , spNpc) ){ // ATAQUE OSCURO PISO
   vida-=0.06;
}
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
   vida-=0.06;
   speed=0.4;

}
else speed=speedtotal;

if(Collision::PixelPerfectTest(player2->getSprite2() , spFuego2)){ // ATAQUE IZQUIERDA
    if (player2->Getdash2()==0){
    spFuego2.setPosition(-9999,-9999);
    player2->Setvida(15);
   }
}

}

void NPC2::deteccion_ataque_Hechicero(){
    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spHechicero.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+550){
    activadoHechicero=1;
    }
    else if (posnpc.x <= posp2.x+550 & player1->Getvida()<=0){
    activadoHechicero=1;
    }
    if(activadoHechicero==1){
    ///HUD HP Y ANIMACION HP
    spHpHechicero.setPosition(8610 , 2805);
    spHpHechicero.setScale(1.2 , 1.2);
    Hechicerotext.setPosition(8620 , 2780);
    Hechicerotext.setFont(Fuente2);
    stringstream tmp;
    tmp << "Void    "<<int(vidaHechicero);
    Hechicerotext.setString(tmp.str());
    Hechicerotext.setColor(sf::Color::Red);
    if(porcentajevidaHechicero <=100)animacionvidaHechicero=0;
    if(porcentajevidaHechicero<=90)animacionvidaHechicero=1;
    if(porcentajevidaHechicero<=80)animacionvidaHechicero=2;
    if(porcentajevidaHechicero<=70)animacionvidaHechicero=3;
    if(porcentajevidaHechicero<=60)animacionvidaHechicero=4;
    if(porcentajevidaHechicero<=50)animacionvidaHechicero=5;
    if(porcentajevidaHechicero<=40)animacionvidaHechicero=6;
    if(porcentajevidaHechicero<=30)animacionvidaHechicero=7;
    if(porcentajevidaHechicero<=20)animacionvidaHechicero=8;
    if(porcentajevidaHechicero<=10)animacionvidaHechicero=9;
    if(porcentajevidaHechicero<=0)animacionvidaHechicero=100;
    spHpHechicero.setTextureRect(sf::IntRect(animacionvidaHechicero*300 , 0 , 300 , 300));
    ///AVISARLE AL JUEGO QUE EL PLAYER ESTA EN UNA BOSS FIGHT
     player1->SetBossfight2(1);
     player2->SetBossfight2(1);
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1Hechicero = posnpc.x - posp1.x;
     distancia2Hechicero = posnpc.x - posp2.x;
     if(  distancia1Hechicero < 0)   distancia1Hechicero =   distancia1Hechicero*(-1);
     if(distancia2Hechicero < 0) distancia2Hechicero = distancia2Hechicero*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(  distancia1Hechicero < distancia2Hechicero & FuegoH1atkon==0 & FuegoH2atkon==0 & Meteoritoatkon==0 & Hieloatkon==0){
        chasing1Hechicero=1; //PERSEGUIR AL PLAYER 1
        chasing2Hechicero=0; //PERSEGUIR AL PLAYER 2
     }
     else if(FuegoH1atkon==0 & FuegoH2atkon==0 & Meteoritoatkon==0 & Hieloatkon==0){
        chasing1Hechicero=0;
        chasing2Hechicero=1;
     }
///----------PERSEGUIR PJ1----------------------------------------------
        if(muerteHechicero==0){
        /// IZQUIERDA
        if(posnpc.x > posp1.x+80 & chasing2Hechicero == 0){
            spHechicero.move(-speedHechicero,0);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x > posp1.x+80 & posp1.y < posnpc.y+80 & chasing2Hechicero == 0){
            spHechicero.move(0,-speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;
        }

        else if(posnpc.x > posp1.x+80 & posp1.y > posnpc.y-25 & chasing2Hechicero == 0) {
            spHechicero.move(0,speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;
        }
         ///DERECHA
         if(posnpc.x < posp1.x-55 & chasing2Hechicero == 0){
             spHechicero.move(speedHechicero,0);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,0,150,100));
            izquierdaHechicero=0;
            derechaHechicero=1;
        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x < posp1.x-55 & posp1.y < posnpc.y+50 & chasing2Hechicero == 0){
            spHechicero.move(0,-speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150, 0, 150, 100));
            izquierdaHechicero=0;
            derechaHechicero=1;
        }

        else if(posnpc.x < posp1.x-55 & posp1.y > posnpc.y-25 & chasing2Hechicero == 0){
            spHechicero.move(0,speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150, 0, 150, 100));
            izquierdaHechicero=0;
            derechaHechicero=1;
        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// IZQUIERDA
        if(posnpc.x > posp2.x+90  & chasing1Hechicero == 0){
            spHechicero.move(-speedHechicero,0);
             spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;
        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x > posp2.x+90 & posp2.y < posnpc.y+80 & chasing1Hechicero == 0){
            spHechicero.move(0,-speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;
        }

        else if(posnpc.x > posp2.x+90 & posp2.y > posnpc.y+40 & chasing1Hechicero == 0){
            spHechicero.move(0,speedHechicero);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150,120,150,120));
            derechaHechicero=0;
            izquierdaHechicero=1;

        }
         ///DERECHA
         if(posnpc.x < posp2.x-35 & chasing1Hechicero == 0){
             spHechicero.move(speedHechicero,0);
            spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150, 0, 150, 100));
            izquierdaHechicero=0;
            derechaHechicero=1;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x < posp2.x-35 & posp2.y < posnpc.y+45 & chasing1Hechicero == 0){
            spHechicero.move(0,-speedHechicero);
          spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150, 0, 150, 100));
            izquierdaHechicero=0;
            derechaHechicero=1;

        }

        else if(posnpc.x < posp2.x-35 & posp2.y > posnpc.y+5 & chasing1Hechicero == 0){
            spHechicero.move(0,speedHechicero);
           spHechicero.setTextureRect(sf::IntRect(caminarHechicero*150, 0, 150, 100));
            izquierdaHechicero=0;
            derechaHechicero=1;

        }
        }
///------------------------------------------BOSS FIGHT-------------------------------
porcentajevidaHechicero = (vidaHechicero / vidainicialHechicero)*100;
sf::Time BossfightH = relojbossfightHechicero.getElapsedTime();
if(reiniciar == 1){
    relojbossfightHechicero.restart();
    reiniciar=0;
}
///-----------------------------------ATAQUES-----------------------------------
/// FUEGO 1 FASE 1
sf::Time FuegoH1 = relojFuegoH1.getElapsedTime();
if(derechaHechicero == 1 & posnpc.x < posp2.x+230 & chasing2Hechicero == 1){ //ATACAR DESDE IZQUIERDA
        timingFuegoH1++;
        if(timingFuegoH1<50){
            FuegoH1atkon=0;
        }
    }
    else if(izquierdaHechicero ==1 & posnpc.x > posp2.x-230 & chasing2Hechicero == 1){ // ATACAR DESDE DERECHA
         timingFuegoH1++;
        if(timingFuegoH1<50){
            FuegoH1atkon=0;
        }

}

if(derechaHechicero == 1 & posnpc.x < posp1.x+230 & chasing1Hechicero == 1){ //ATACAR DESDE IZQUIERDA
        timingFuegoH1++;
        if(timingFuegoH1<50){
            FuegoH1atkon=0;
        }
    }
    else if(izquierdaHechicero ==1 & posnpc.x > posp1.x-230 & chasing1Hechicero == 1){ // ATACAR DESDE DERECHA
         timingFuegoH1++;
        if(timingFuegoH1<50){
            FuegoH1atkon=0;
        }

}

if(derechaHechicero==1) {
        spFuegoH1.move(3, 0);
        spFuegoH1.setTextureRect(sf::IntRect(animacionFuegoH1*100, 0, 100, 80));
}
else if(izquierdaHechicero==1){
        spFuegoH1.move(-3, 0);
        spFuegoH1.setTextureRect(sf::IntRect(animacionFuegoH1*100, 90, 100, 90));
}

if(FuegoH1.asSeconds() >= 0.5){
    animacionFuegoH1++;
    relojFuegoH1.restart();
}
if(animacionFuegoH1>=5){
    animacionFuegoH1=5;
}

///FUEGO 2 FASE 1
sf::Time FuegoH2 = relojFuegoH2.getElapsedTime();
if(izquierdaHechicero == 1 & posnpc.x < posp2.x+230 & chasing2Hechicero == 1){ //ATACAR DESDE IZQUIERDA
        timingFuegoH2++;
        if(timingFuegoH2<50){
            FuegoH2atkon=0;
        }
    }
    else if(derechaHechicero ==1 & posnpc.x > posp2.x-230 & chasing2Hechicero == 1){ // ATACAR DESDE DERECHA
         timingFuegoH2++;
        if(timingFuegoH2<50){
            FuegoH2atkon=0;
        }

}

if(izquierdaHechicero == 1 & posnpc.x < posp1.x+230 & chasing1Hechicero == 1){ //ATACAR DESDE IZQUIERDA
        timingFuegoH2++;
        if(timingFuegoH2<50){
            FuegoH2atkon=0;
        }
    }
    else if(derechaHechicero ==1 & posnpc.x > posp1.x-230 & chasing1Hechicero == 1){ // ATACAR DESDE DERECHA
         timingFuegoH2++;
        if(timingFuegoH2<50){
            FuegoH2atkon=0;
        }

}

if(derechaHechicero==1) {
        spFuegoH2.move(3, 0);
        spFuegoH2.setTextureRect(sf::IntRect(animacionFuegoH2*100, 0, 100, 60));
}
else if(izquierdaHechicero==1){
        spFuegoH2.move(-3, 0);
        spFuegoH2.setTextureRect(sf::IntRect(animacionFuegoH2*100, 100, 100, 100));
}

if(FuegoH2.asSeconds() >= 0.5){
    animacionFuegoH2++;
    relojFuegoH2.restart();
}
if(animacionFuegoH2>=7){
    animacionFuegoH2=7;
}

/// HIELO FASE 2
sf::Time HieloAnimacion = relojHielo.getElapsedTime();
if(distancia1Hechicero < distancia2Hechicero){
if(posp1.x > posnpc.x ){
spHielo.setTextureRect(sf::IntRect(0, 0, 85, 125));
 }
 if(posp1.x < posnpc.x ){
spHielo.setTextureRect(sf::IntRect(1, 150, 85, 150));
 }
}
if(distancia2Hechicero < distancia1Hechicero){
if(posp2.x < posnpc.x ){
spHielo.setTextureRect(sf::IntRect(1, 150, 85, 150));
 }
if(posp2.x > posnpc.x ){
spHielo.setTextureRect(sf::IntRect(0, 0, 85, 125));
 }
}
spHielo.move(0 , 3.2);


///METEORITO FASE 2
sf::Time MeteoritoH= relojMeteorito.getElapsedTime();
if(distancia1Hechicero < distancia2Hechicero){
if(posp1.x > posnpc.x ){
spMeteorito.move(0.5 , 3);
spMeteorito.setTextureRect(sf::IntRect(animacionMeteorito*100, 0, 100, 75));
 }
 if(posp1.x < posnpc.x ){
spMeteorito.move(-0.5 , 3);
spMeteorito.setTextureRect(sf::IntRect(animacionMeteorito*100, 100, 100, 100));
 }
}

if(distancia2Hechicero < distancia1Hechicero){
if(posp2.x < posnpc.x ){
spMeteorito.move(-0.5 , 3);
spMeteorito.setTextureRect(sf::IntRect(animacionMeteorito*100, 100, 100, 100));
 }
if(posp2.x > posnpc.x ){
spMeteorito.move(0.5 , 3);
spMeteorito.setTextureRect(sf::IntRect(animacionMeteorito*100, 0, 100, 75));
 }

}
if(MeteoritoH.asSeconds() >= 0.07){
    animacionMeteorito++;
    relojMeteorito.restart();
}
if(animacionMeteorito>=4){
    animacionMeteorito=0;
}

///CLOCKS
sf::Vector2f hechiceropos = spHechicero.getPosition();
if(BossfightH.asSeconds() >=2 & BossfightH.asSeconds() <2.5  & reiniciar == 0){
FuegoH1atkon=1;
spFuegoH2.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=3.5 & BossfightH.asSeconds() <3.51 & reiniciar == 0 ){
if(derechaHechicero==1)spHechicero.setPosition(hechiceropos.x+300 , hechiceropos.y);
if(izquierdaHechicero==1)spHechicero.setPosition(hechiceropos.x-300 , hechiceropos.y);
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=4.2 &  BossfightH.asSeconds() <5 & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=6  & BossfightH.asSeconds() <6.5 & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=6.6  & BossfightH.asSeconds() <7  & reiniciar == 0 ){
FuegoH1atkon=1;
spFuegoH2.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=8  & BossfightH.asSeconds() <8.5  & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=11  & BossfightH.asSeconds() <11.5  & reiniciar == 0 ){
if(derechaHechicero==1)spHechicero.setPosition(hechiceropos.x+300 , hechiceropos.y);
if(izquierdaHechicero==1)spHechicero.setPosition(hechiceropos.x-300 , hechiceropos.y);
spFuegoH2.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=14  & BossfightH.asSeconds() <14.5 & reiniciar == 0 ){
FuegoH1atkon=1;
spFuegoH2.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=16  & BossfightH.asSeconds() <17  & reiniciar == 0 ){
FuegoH1atkon=1;
spFuegoH2.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=21  & BossfightH.asSeconds() <21.5  & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=24  & BossfightH.asSeconds() <24.5  & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=27  & BossfightH.asSeconds() <27.5  & reiniciar == 0 ){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(BossfightH.asSeconds() >=31  & BossfightH.asSeconds() <32  & reiniciar == 0 ){
FuegoH1atkon=1;
spFuegoH2.setPosition(-9999,9999);
relojbossfightHechicero.restart();
}
/// FASE 2
if(fase2 == 1)relojbossfightHechicero.restart();
if( porcentajevidaHechicero <= 50 & reiniciar == 0) fase2 =1;
sf::Time SegundafaseH = relojbossfightHechicero2.getElapsedTime();
if(fase2==0) relojbossfightHechicero2.restart();

if(SegundafaseH.asSeconds() >=2 & SegundafaseH.asSeconds() <10.5 & fase2 == 1){
Meteoritoatkon=1;
}
else if(SegundafaseH.asSeconds() >=12  & SegundafaseH.asSeconds() < 13.3 & fase2 == 1){
Meteoritoatkon=0;
if(derechaHechicero==1)spHechicero.setPosition(hechiceropos.x+300 , hechiceropos.y);
if(izquierdaHechicero==1)spHechicero.setPosition(hechiceropos.x-300 , hechiceropos.y);
}
else if(SegundafaseH.asSeconds() >=14.5  & SegundafaseH.asSeconds() <17.5 & fase2==1){
FuegoH2atkon=1;
}
else if(SegundafaseH.asSeconds() >=18.5  & SegundafaseH.asSeconds() <20.5 & fase2==1){
spFuegoH2.setPosition(-9999,9999);
FuegoH1atkon=1;
}
else if(SegundafaseH.asSeconds() >=21.5  & SegundafaseH.asSeconds() <25.5 & fase2==1){
FuegoH2atkon=1;
spFuegoH1.setPosition(-9999,9999);
}
else if(SegundafaseH.asSeconds() >=26  & SegundafaseH.asSeconds() <27 & fase2==1){
spFuegoH2.setPosition(-9999,9999);
if(derechaHechicero==1)spHechicero.setPosition(hechiceropos.x+300 , hechiceropos.y);
if(izquierdaHechicero==1)spHechicero.setPosition(hechiceropos.x-300 , hechiceropos.y);
}
else if(SegundafaseH.asSeconds() >=28  & SegundafaseH.asSeconds() <37.7 & fase2==1){
Hieloatkon=1;
}
else if(SegundafaseH.asSeconds() >=38  & SegundafaseH.asSeconds() <40 & fase2==1){
Hieloatkon=0;
if(derechaHechicero==1)spHechicero.setPosition(hechiceropos.x+300 , hechiceropos.y);
if(izquierdaHechicero==1)spHechicero.setPosition(hechiceropos.x-300 , hechiceropos.y);
}
else if(SegundafaseH.asSeconds() >=40.5  & SegundafaseH.asSeconds() <41.5 & fase2==1){

}
else if(SegundafaseH.asSeconds() >=42  &  fase2==1){
relojbossfightHechicero2.restart();
}




///------------MUERTE BOSS-------------------------------------------------------------
if(vidaHechicero<=0){
 muerteHechicero=1;
activadoHechicero=0;
Hechicerotext.setPosition(999,6000);
spHpHechicero.setPosition(-9999, -9999);
spFuegoH1.setPosition(-9999,-9999);
spFuegoH2.setPosition(-9999,-9999);
spMeteorito.setPosition(-9999,-9999);
spHielo.setPosition(-9999,-9999);
    }
    }
}

void NPC2::deteccion_ataque_Caballero(){
    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spNpc.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+1000|| posnpc.x <= posp2.x+1000){
    activado=1;
    }
    if(activado==1){
      ///HUD
    textVidanpc.setPosition(posnpc.x+45 , posnpc.y);
    textVidanpc.setFont(Fuente2);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
     ///RELOJ DE ATAQUE
     sf::Time timingCaballero = relojtimingCaballero.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Caballeroatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Caballeroatkon==0){
        chasing1=0;
        chasing2=1;
     }

    ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+80 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
         timingCaballeroatk++;
          if(timingCaballeroatk < 50){
           Caballeroatkon=1;
          }

    }
    else if(izquierda==1 & posnpc.x > posp2.x-34 & chasing2 == 1){ // ATACAR DESDE DERECHA
      timingCaballeroatk++;
          if(timingCaballeroatk < 50){
           Caballeroatkon=1;
          }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+80 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
          timingCaballeroatk++;
          if(timingCaballeroatk < 50){
           Caballeroatkon=1;
          }

    }
    else if(izquierda==1 & posnpc.x > posp1.x-34 & chasing1 == 1){ //ATACAR DESDE DERECGA
        timingCaballeroatk++;
          if(timingCaballeroatk < 50){
           Caballeroatkon=1;
          }
    }
    if(timingCaballero.asSeconds()>=2){
        timingCaballeroatk=0;
        relojtimingCaballero.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+55 & chasing2 == 0 ){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+55 & posp1.y < posnpc.y+10 & chasing2 == 0 ){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));


        }

        else if(posnpc.x > posp1.x+55 & posp1.y > posnpc.y-10 & chasing2 == 0 ) {
            spNpc.move(0,speed);
           spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-34 & chasing2 == 0 ){
            spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-34 & posp1.y < posnpc.y+10 & chasing2 == 0 ){
            spNpc.move(0,-speed);
               spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));


        }

        else if(posnpc.x < posp1.x-34 & posp1.y > posnpc.y-10 & chasing2 == 0 ){
            spNpc.move(0,speed);
              spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+55  & chasing1 == 0 ){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+55 & posp2.y < posnpc.y+25 & chasing1 == 0 ){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));

        }

        else if(posnpc.x > posp2.x+55 & posp2.y > posnpc.y+30 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 130, 100, 100));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-34 & chasing1 == 0 ){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-34 & posp2.y < posnpc.y+30 & chasing1 == 0 ){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));


        }

        else if(posnpc.x < posp2.x-34 & posp2.y > posnpc.y+30 & chasing1 == 0 ){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarCaballero*100, 0, 100, 120));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
muerteCaballero=1;
    }
///----------------------------------
}


}

void NPC2::deteccion_ataque_Minotauro(){

    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spNpc.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+1000|| posnpc.x <= posp2.x+1000){
    activado=1;
    }
    if(activado==1){
    ///HUD
     textVidanpc.setPosition(posnpc.x+45 , posnpc.y);
     textVidanpc.setFont(Fuente2);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
    sf::Time timingMinotauro = relojtimingMinotauro.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Minotauroatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Minotauroatkon==0){
        chasing1=0;
        chasing2=1;
     }

    ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+70 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
         timingMinotauroatk++;
        if(timingMinotauroatk<50)
        {
            Minotauroatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp2.x-80 & chasing2 == 1){ // ATACAR DESDE DERECHA
         timingMinotauroatk++;
        if(timingMinotauroatk<50)
        {
            Minotauroatkon=1;
        }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+70 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
         timingMinotauroatk++;
        if(timingMinotauroatk<50)
        {
            Minotauroatkon=1;
        }

    }
    else if(izquierda==1 & posnpc.x > posp1.x-80 & chasing1 == 1){ //ATACAR DESDE DERECGA
         timingMinotauroatk++;
        if(timingMinotauroatk<50)
        {
            Minotauroatkon=1;
        }
    }
    if(timingMinotauro.asSeconds() >= 5){
        timingMinotauroatk=0;
        relojtimingMinotauro.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+45 & chasing2 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130, 150, 130));
            derecha=1;
            izquierda=0;

        }

        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+45 & posp1.y < posnpc.y+40 & chasing2 == 0){
            spNpc.move(0,-speed);
           spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130, 150, 130));


        }

        else if(posnpc.x > posp1.x+45 & posp1.y > posnpc.y+40 & chasing2 == 0) {
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130, 150, 130));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-45 & chasing2 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));
            izquierda=1;
            derecha=0;

        }

        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-45 & posp1.y < posnpc.y+25 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));


        }

        else if(posnpc.x < posp1.x-45 & posp1.y > posnpc.y+25 & chasing2 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+45  & chasing1 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130*1, 150, 120));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+45 & posp2.y < posnpc.y+100 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130*1, 150, 120));

        }

        else if(posnpc.x > posp2.x+45 & posp2.y > posnpc.y+100 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 130*1, 150, 120));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-45 & chasing1 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-45 & posp2.y < posnpc.y+70 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));


        }

        else if(posnpc.x < posp2.x-45 & posp2.y > posnpc.y+70 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarMinotauro*150, 0, 150, 130));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
muerteMinotauro=1;

    }
///----------------------------------
}

   }

void NPC2::deteccion_ataque_Dragon(){

    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spNpc.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+1000|| posnpc.x <= posp2.x+1000){
    activado=1;
    }
    if(activado==1){
      ///BOLA DE FUEGO
      sf::Time Animacionfuegodrag = relojanimacionFuego.getElapsedTime();
      if(Animacionfuegodrag.asSeconds() >= 0.2){
        animacionfuego++;
        relojanimacionFuego.restart();
      }
      if(animacionfuego == 8){
        animacionfuego=5;
      }
     if(derecha==1) spFuego2.move(-2.2, 0) , spFuego2.setTextureRect(sf::IntRect(animacionfuego*200, 0, 190, 100));
     else if(izquierda==1) spFuego2.move(2.2, 0) , spFuego2.setTextureRect(sf::IntRect(animacionfuego*200, 100, 190, 100));


     ///HUD
     textVidanpc.setPosition(posnpc.x+45 , posnpc.y);
     textVidanpc.setFont(Fuente2);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
     ///RELOJ ATAQUE
     sf::Time timingDragon = relojataqueDragon.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Dragonatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Dragonatkon==0){
        chasing1=0;
        chasing2=1;
     }

   ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+500 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
        Dragontimeatack++;
        if(Dragontimeatack<50){
            Dragonatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp2.x-400 & chasing2 == 1){ // ATACAR DESDE DERECHA
         Dragontimeatack++;
        if(Dragontimeatack<50){
            Dragonatkon=1;
        }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+500 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
        Dragontimeatack++;
        if(Dragontimeatack<50){
            Dragonatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp1.x-400 & chasing1 == 1){ //ATACAR DESDE DERECGA
       Dragontimeatack++;
        if(Dragontimeatack<50){
            Dragonatkon=1;
        }
    }
    if(timingDragon.asSeconds() >= 2){
        Dragontimeatack=0;
        relojataqueDragon.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+45 & chasing2 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+45 & posp1.y < posnpc.y+60 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));


        }

        else if(posnpc.x > posp1.x+45 & posp1.y > posnpc.y+10 & chasing2 == 0) {
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-65 & chasing2 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-65 & posp1.y < posnpc.y+60 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));


        }

        else if(posnpc.x < posp1.x-65 & posp1.y > posnpc.y+10 & chasing2 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+45  & chasing1 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+45 & posp2.y < posnpc.y+70 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));

        }

        else if(posnpc.x > posp2.x+45 & posp2.y > posnpc.y+20 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 180, 200, 170));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-65 & chasing1 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-65 & posp2.y < posnpc.y+60 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));



        }

        else if(posnpc.x < posp2.x-65 & posp2.y > posnpc.y+10 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarDragon*200, 0, 200, 180));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
 muerteDragon=1;

    }
///----------------------------------


}

   }

void NPC2::update_movimiento(){

    if(caballero==1){
    ///ANIMACION CAMINAR CABALLERO
   sf::Time caminarCaballero2= relojcaminarCaballero.getElapsedTime();
   if(caminarCaballero2.asSeconds()>=0.12){
                caminarCaballero++;
                relojcaminarCaballero.restart();
        }


        if(caminarCaballero==4){
            caminarCaballero=0;
        }
         ///ANIMACION ATAQUE CABALLERO
   sf::Time Caballeroatake = relojataqueCaballero.getElapsedTime();
     if(Caballeroatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Caballeroatk*150 , 260, 150, 120 ));
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Caballeroatk*150 , 135*3, 150, 130 ));


        if(Caballeroatake.asSeconds()>=0.2)
       {
        Caballeroatk++;
        relojataqueCaballero.restart();
       }
       if(Caballeroatk>=3){
        Caballeroatk=0;
        Caballeroatkon=0;
        chasing1=1;
        chasing2=0;
       }

     }
     ///ANIMACION MUERTE CABALLERO
     sf::Time Caballeromuerte = relojmuerteCaballero.getElapsedTime();
     if(muerteCaballero==1){
      chasing1=2;
      chasing2=2;
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(caballeromuerteanimacion*150 , 130*4, 150, 130 ));
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(caballeromuerteanimacion*150 , 130*5, 150, 130 ));

       if(Caballeromuerte.asSeconds() >= 0.12){
        caballeromuerteanimacion++;
        relojmuerteCaballero.restart();
       }
       if(caballeromuerteanimacion>=4){
        caballero=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
        textVidanpc.setPosition(-9999,999);
       }


     }
}

   if(minotauro==1){
   ///ANIMACION CAMINAR MINOTAURO
   sf::Time caminarMinotauro2= relojcaminarMinotauro.getElapsedTime();
   if(caminarMinotauro2.asSeconds()>=0.12){
    caminarMinotauro++;
    relojcaminarMinotauro.restart();
   }
   if(caminarMinotauro==5){
    caminarMinotauro=0;
   }
   ///ANIMACION ATAQUE MINOTAURO
    sf::Vector2f posnpcMinotauro = spNpc.getPosition();
   sf::Time Minotauroataque = relojataqueMinotauro.getElapsedTime();
     if(Minotauroatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Minotauroatk*200 , 305, 200, 140 ));
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Minotauroatk*200 , 445, 200, 146 ));


        if(Minotauroataque.asSeconds()>=0.15)
       {
        Minotauroatk++;
        relojataqueMinotauro.restart();
       }
        if(Minotauroatk==4)
      {
        Minotauroatk=0;
        Minotauroatkon=0;
      }


     }
     ///ANIMACION MUERTE MINOTAURO
     sf::Time Minotauromuerte = relojmuerteMinotauro.getElapsedTime();
     if(muerteMinotauro==1){
      chasing1=2;
      chasing2=2;
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(Minotauromuerteanimacion*200 , 146*4, 200, 146 ));
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Minotauromuerteanimacion*200 , 146*5, 200, 146 ));

       if(Minotauromuerte.asSeconds() >= 0.13){
        Minotauromuerteanimacion++;
        relojmuerteMinotauro.restart();
       }
       if(Minotauromuerteanimacion>=4){
        minotauro=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
         textVidanpc.setPosition(-9999,999);
       }


     }
}

    if(dragon==1){
   ///ANIMNACION CAMINAR DRAGON
   sf::Time caminarDragon2= relojcaminarDragon.getElapsedTime();
   if(caminarDragon2.asSeconds()>=0.12){
    caminarDragon++;
    relojcaminarDragon.restart();
   }
   if(caminarDragon==4){
    caminarDragon=0;
   }
    ///ANIMACION ATAQUE DRAGON
   sf::Time  Dragonataque = relojanimacionDragon.getElapsedTime();
   sf::Time  Cooldown = relojCooldownfuego.getElapsedTime();
   sf::Vector2f dragonpos = spNpc.getPosition();
     if(Dragonatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Dragonatk*200 , 600, 200, 150 ));
        if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Dragonatk*200 , 420, 200, 150 ));


        if(Dragonataque.asSeconds()>=0.4)
       {
        Dragonatk++;
        relojanimacionDragon.restart();
       }
       if(Dragonatk>=3){
        Dragonatk=0;
        Dragonatkon=0;
        if(Cooldown.asSeconds()> 1){
       if(derecha== 1) spFuego2.setPosition(dragonpos.x-40 , dragonpos.y +50);
       if(izquierda== 1) spFuego2.setPosition(dragonpos.x+80 , dragonpos.y +30);
        animacionfuego=5;
        relojCooldownfuego.restart();}


       }

     }
      ///ANIMACION MUERTE DRAGON
     sf::Time Dragonmuerte = relojmuerteDragon.getElapsedTime();
     if(muerteDragon==1){
      chasing1=2;
      chasing2=2;
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Dragonmuerteanimacion*200 , 190*4, 200, 190 ));
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(Dragonmuerteanimacion*200 , 190*5, 250, 190 ));

       if(Dragonmuerte.asSeconds() >= 0.2){
        Dragonmuerteanimacion++;
        relojmuerteDragon.restart();
       }
       if(Dragonmuerteanimacion>=2){
        dragon=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
        textVidanpc.setPosition(-9999,999);
        spFuego2.setPosition(-9999,-9999);
       }


     }
}

    ///ANIMACION CAMINAR HECHICERO
    sf::Time caminarHechicero2 = relojcaminarHechicero.getElapsedTime();
   if(vidaHechicero>=1){
    if(caminarHechicero2.asSeconds()>=0.2){
                caminarHechicero++;
                relojcaminarHechicero.restart();
        }


        if(caminarHechicero>=7){
            caminarHechicero=0;
        }
   }
    ///ANIMACION ATAQUES HECHICERO
    ///FUEGO 1 FASE 1
    sf::Time AnimacionataqueHechicero = relojAtacandoHechicero.getElapsedTime();
    sf::Vector2f Hechiceropos= spHechicero.getPosition();
    sf::Vector2f player1pos= player1->getSprite().getPosition();
    sf::Vector2f player2pos= player2->getSprite2().getPosition();
    sf::Time CooldownFuegoH1=relojCooldownFuegoH1.getElapsedTime();
    if(FuegoH1atkon==1)
        {
        chasing1Hechicero=2;
        chasing2Hechicero=2;
        if(derechaHechicero==1)spHechicero.setTextureRect(sf::IntRect(AtacarHechicero*150 , 130*2, 150, 130 ));
        if(izquierdaHechicero==1)spHechicero.setTextureRect(sf::IntRect(AtacarHechicero*150 , 130*3, 150, 130 ));


        if(AnimacionataqueHechicero.asSeconds()>=0.2)
       {
        AtacarHechicero++;
        relojAtacandoHechicero.restart();
       }
       if(AtacarHechicero==3)//soundFuego.play();
       if(AtacarHechicero>=3){
        AtacarHechicero=0;
        FuegoH1atkon=0;
        if(CooldownFuegoH1.asSeconds()> 0.6){
       if(derechaHechicero == 1) spFuegoH1.setPosition(Hechiceropos.x-40 , Hechiceropos.y +50);
       if(izquierdaHechicero == 1) spFuegoH1.setPosition(Hechiceropos.x+80 , Hechiceropos.y +75);
        animacionFuegoH1=0;
        relojCooldownFuegoH1.restart();}


       }

     }
     ///FUEGO 2 FASE 1
    sf::Time CooldownFuegoH2=relojCooldownFuegoH2.getElapsedTime();
    if(FuegoH2atkon==1)
        {
        chasing1Hechicero=2;
        chasing2Hechicero=2;
        if(derechaHechicero==1)spHechicero.setTextureRect(sf::IntRect(AtacarHechicero*150 , 130*2, 150, 130 ));
        if(izquierdaHechicero==1)spHechicero.setTextureRect(sf::IntRect(AtacarHechicero*150 , 130*3, 150, 130 ));


        if(AnimacionataqueHechicero.asSeconds()>=0.2)
       {
        AtacarHechicero++;
        relojAtacandoHechicero.restart();
       }
       if(AtacarHechicero==3)//soundFuego.play();
       if(AtacarHechicero>=3){
        AtacarHechicero=0;
        FuegoH2atkon=0;
        if(CooldownFuegoH2.asSeconds()> 0.6){
       if(derechaHechicero == 1) spFuegoH2.setPosition(Hechiceropos.x-40 , Hechiceropos.y +50);
       if(izquierdaHechicero == 1) spFuegoH2.setPosition(Hechiceropos.x+80 , Hechiceropos.y +75);
        animacionFuegoH2=0;
        relojCooldownFuegoH2.restart();}


       }

     }
     ///HIELO FASE 2
     sf::Time CooldownHielo=relojCooldownHielo.getElapsedTime();
     if(Hieloatkon==1){
     spHechicero.setPosition(8650,2300);
     sf::Time TirarHielo = relojTirarHielo.getElapsedTime();
        if(CooldownHielo.asSeconds()>=10.2) relojCooldownHielo.restart();
        chasing1Hechicero=2;
        chasing2Hechicero=2;
        spHechicero.setTextureRect(sf::IntRect(1, 920, 65, 150));
       if(TirarHielo.asSeconds() >= 0.8){
       if(distancia1Hechicero < distancia2Hechicero){
        spHielo.setPosition(player1pos.x , Hechiceropos.y-200);
       if(player1pos.x < Hechiceropos.x) spHielo.setPosition(player1pos.x-30 , Hechiceropos.y-200);
       if(player1pos.x > Hechiceropos.x) spHielo.setPosition(player1pos.x+70 , Hechiceropos.y-200);
       }
       if(distancia2Hechicero < distancia1Hechicero) {
       if(player2pos.x+20 < Hechiceropos.x) spHielo.setPosition(player2pos.x-30 , Hechiceropos.y-200);
       if(player2pos.x-50 > Hechiceropos.x) spHielo.setPosition(player2pos.x+70 , Hechiceropos.y-200);
       }
        relojTirarHielo.restart();
       }
            if(reproducirHielo==1){
            //soundHielo.play();
             reproducirHielo=0;
        }


     }else reproducirHielo=1;
     ///METEORITO FASE 2
     sf::Time CooldownMeteorito=relojCooldownMeteorito.getElapsedTime();
     if(Meteoritoatkon==1){
     spHechicero.setPosition(8650,2300);
     sf::Time TirarMeteorito = relojTirarMeteorito.getElapsedTime();
        if(CooldownMeteorito.asSeconds()>=10.2) relojCooldownMeteorito.restart();
        chasing1Hechicero=2;
        chasing2Hechicero=2;
        spHechicero.setTextureRect(sf::IntRect(1, 590, 65, 150));
       if(TirarMeteorito.asSeconds() >= 0.8){
       if(distancia1Hechicero < distancia2Hechicero){
        spMeteorito.setPosition(player1pos.x , Hechiceropos.y-200);
       if(player1pos.x < Hechiceropos.x) spMeteorito.setPosition(player1pos.x+150 , Hechiceropos.y-200);
       if(player1pos.x > Hechiceropos.x) spMeteorito.setPosition(player1pos.x-100 , Hechiceropos.y-200);
       }
       if(distancia2Hechicero < distancia1Hechicero) {
       if(player2pos.x+20 < Hechiceropos.x) spMeteorito.setPosition(player2pos.x+150, Hechiceropos.y-200);
       if(player2pos.x-50 > Hechiceropos.x) spMeteorito.setPosition(player2pos.x-100 , Hechiceropos.y-200);
       }
        relojTirarMeteorito.restart();
       }

     }
     if(Meteoritoatkon==1){
        if(reproducirMeteoro==1){
            //soundMeteoro.play();
        }
        reproducirMeteoro=0;
     }else reproducirMeteoro=1;
    ///ANIMACION MUERTE HECHICERO
    sf::Time HechiceroMuerte = relojmuerteHechicero.getElapsedTime();
     if(muerteHechicero==1){
      chasing1Hechicero=99;
      chasing2Hechicero=99;
      FuegoH2atkon=0;
      FuegoH1atkon=0;
    if(derechaHechicero==1){
        spHechicero.move(-0.06, 0);
            spHechicero.setTextureRect(sf::IntRect(Hechiceroanimacionmuerte*150, 155*8, 150, 155));

    }
    if(izquierdaHechicero==1){
    spHechicero.move(0.06, 0);
    spHechicero.setTextureRect(sf::IntRect(Hechiceroanimacionmuerte*150, 155*9, 150, 155));
    }
       if(HechiceroMuerte.asSeconds() >= 0.2){
        Hechiceroanimacionmuerte++;
        relojmuerteHechicero.restart();
       }
       if(Hechiceroanimacionmuerte>=7){
        Hechiceroanimacionmuerte=0;
        hechicero=0;
        activadoHechicero=0;
        spHechicero.setPosition(-99999 , 999);
        player1->SetBossfight(0);
        player2->SetBossfight2(0);
       }


     }
   }

void NPC2::update(){
  if(player1 ->Getnivel2() == 1 || player2->Getnivel2()== 1){
  update_movimiento();
  if(minotauro == 1 & vida>=0){
   ColisionesMinotauro();
    deteccion_ataque_Minotauro();}
  else if (caballero == 1 & vida>=0){
  ColisionesCaballero();
  deteccion_ataque_Caballero();
  }
  else if (dragon==1 & vida >= 0) {
  ColisionesDragon();
  deteccion_ataque_Dragon();
  }
  else if (hechicero==1 ){
  deteccion_ataque_Hechicero();
  ColisionesHechicero();
  }
  }
}

void NPC2::dibujar(sf::RenderWindow &w){
    w.draw(spNpc);
    w.draw(textVidanpc);
    w.draw(spFuego2);
    w.draw(spHechicero);
    w.draw(spFuegoH1);
    w.draw(spFuegoH2);
    w.draw(spMeteorito);
    w.draw(spHielo);
    w.draw(spHpHechicero);
    w.draw(Hechicerotext);
}
