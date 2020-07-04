#include "ia.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "Colission.h"
#include "juego.h"
using namespace std;
void NPC::ColisionesCorazon(){
    ///COLISIONES CON CORAZON PLAYER 1
 if(Collision::PixelPerfectTest(player1->getSprite() , spCorazon)&player1->Getvida()<=99 ){
        player1->SetaumentoVida(33);
        spCorazon.setPosition(-9999,-10);
      }

             ///COLISIONES CON CORAZON PLAYER 2
      if(Collision::PixelPerfectTest(player2->getSprite2() , spCorazon)& player2->Getvida()<=99){
        player2->SetaumentoVida(33);
        spCorazon.setPosition(-9999,-10);
      }
}
void NPC::ColisionesDemonking(){

 ///----------------------------------CON PJ1 DEMONKING--------------------------------------------------------
if(Collision::PixelPerfectTest(player1->getSprite() , spDemonking) ){ // ATAQUE GIRATORIO

   if(player1->getGiro()==1)        vidaDemonking-=0.1 ;
   else if (player1->Getpinia()==1) vidaDemonking-=0.2;
   else if (player1->Getpatada()==1)vidaDemonking-=0.15;
   ///DAÑO POR PARTE DE DEMON KING
   if (Demonkingatack1 >= 7 & Demonkingatack1<= 8 & player1->Getdash()==0) player1->Setvida(0.15);
   if (Demonkingatack2 == 3 & player1->Getdash()==0 ) player1->Setvida(0.08);
   if(Demonkingatack4 >= 8 & Demonkingatack4<= 11 & player1->Getdash()==0) player1->Setvida(0.07);
   if(Demonkingatackndo3==1){
    player1->Setvida(0.02);
   }


}
if(Collision::PixelPerfectTest(player1->getTiro() , spDemonking)& player1->GetBossfight()==1){ // TIRO DESDE DERECHA
    player1->getTiro().setPosition(9999,9999);
    vidaDemonking-=40;

}
if(Collision::PixelPerfectTest(player1->getTiro2() , spDemonking)& player1->GetBossfight()==1){ // TIRO DESDE IZQUIERDA
    player1->getTiro2().setPosition(9999,9999);
    vidaDemonking-=40;
}
if(Collision::PixelPerfectTest(player1->getSprite() , spEspadas)){ // TIRO DESDE IZQUIERDA
   if (player1->Getdash()==0){
    spEspadas.setPosition(9999,9999);
    player1->Setvida(10);
   }
}

///----------------------------------------------------------------------------------------

///----------------------------------------------------------------------------------------
///--------------------------------CON-PJ2 DEMONKING---------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spDemonking) ){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
    vidaDemonking-=0.2;
}
   ///DAÑO POR PARTE DE DEMON KING
   if (Demonkingatack1 >= 7 & Demonkingatack1<= 8 & player2->Getdash2()==0) player2->Setvida(0.15);
   if (Demonkingatack2 == 3 & player2->Getdash2()==0 ) player2->Setvida(0.08);
   if(Demonkingatack4 >= 9 & Demonkingatack4<= 11 & player2->Getdash2()==0) player2->Setvida(0.08);
   if(Demonkingatackndo3==1){
   player2->Setvida(0.02);
   }

}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga1() , spDemonking) & player2->GetBossfight()==1 ){ // ATAQUE GETSUGA DERECHA
    vidaDemonking-=40;
    player2->getSpritegetsuga1().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritegetsuga2() , spDemonking) & player2->GetBossfight()==1){ // ATAQUE GETSUGA IZQUIERDA
    vidaDemonking-=40;
    player2->getSpritegetsuga2().setPosition(9999,9999);
}
if(Collision::PixelPerfectTest(player2->getSpritedarkpiso() , spDemonking) ){ // ATAQUE OSCURO PISO
    vidaDemonking-=0.06;
    Demonkingatackndo3=1;

}
if(Collision::PixelPerfectTest(player2->getSpritedark() , spDemonking) ){ // ATAQUE OSCURO
    vidaDemonking-=0.06;
    Demonkingatackndo3=1;

}
if(Collision::PixelPerfectTest(player2->getSprite2() , spEspadas)){ // TIRO DESDE IZQUIERDA
   if (player2->Getdash2()==0){
    spEspadas.setPosition(9999,9999);
    player2->Setvida(10);
   }
}

}

void NPC::ColisionesEsqueleto(){
    ///----------------------------------CON PJ1 ESQUELETO--------------------------------------------------------
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
   if(Esqueletatk == 5 & player1->Getdash()==0){
    player1->Setvida(10);
    Esqueletatk=0;
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
///--------------------------------CON-PJ2 ESQUELETO-------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc) ){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
    vida-=1.6;}
     if(Esqueletatk == 5 & player2->Getdash2()==0){
    player2->Setvida(10);
    Esqueletatk=0;
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
    speed=0.3;

}
else speed=speedtotal;
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
    vida-=0.06;
    speed=0.3;
}
else speed=speedtotal;
   }

void NPC::ColisionesHelldog(){

///----------------------------------CON PJ1 HELL DOG--------------------------------------------------------
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
   if(Helldogatk>=7 & Helldogatk <=12 & player1->Getdash()==0) player1->Setvida(0.1);

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
///--------------------------------CON-PJ2 HELL DOG-------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc)){ // ATAQUE ESPADA
  if( player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
    vida-=1.6;}
   if(Helldogatk>=7 &  Helldogatk <=12 &  player2->Getdash2()==0) player2->Setvida(0.2);
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
    speed=0.4;
}
else speed=speedtotal;
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
    vida-=0.06;
    speed=0.4;

}
else speed=speedtotal;

}

void NPC::ColisionesTroll(){
    ///-------------------CON PJ1 TROLL----------------------------------------------------------
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

   if(Trollatk ==4 & player1->Getdash()==0){
    player1->Setvida(16.5);
    Trollatk=0;
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
///--------------------------------CON-PJ2 TROLL----------------------------------------------------
if(Collision::PixelPerfectTest(player2->getSprite2() , spNpc)){ // ATAQUE ESPADA
   if(player2->Getespada()==1){
   if(player2->Getizquierda()== 1) spNpc.move(-3,0);
   if(player2->Getderecha() == 1) spNpc.move(3,0);
   vida-=1.6;}
   if(Trollatk ==4 & player2->Getdash2()==0){
    player2->Setvida(16.5);
    Trollatk=0;
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
   speed=0.4;

}
else speed=speedtotal;
if(Collision::PixelPerfectTest(player2->getSpritedark() , spNpc) ){ // ATAQUE OSCURO
   vida-=0.06;
   speed=0.4;

}
else speed=speedtotal;

}

void NPC::deteccion_ataque_Demonking(){
    sf::Time timingatacar1Demonking = relojtiminataque1Demonking.getElapsedTime();
    sf::Time timingatacar2Demonking = relojtiminataque2Demonking.getElapsedTime();
    sf::Time timingatacar3Demonking = relojtiminataque3Demonking.getElapsedTime();
    sf::Time timingatacar4Demonking = relojtiminataque4Demonking.getElapsedTime();
    sf::Time timingatacar5Demonking = relojtiminataque5Demonking.getElapsedTime();
    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spDemonking.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+550){
    activadoDemonking=1;
    }
    else if (posnpc.x <= posp2.x+550 & player1->Getvida()<=0){
    activadoDemonking=1;
    }
    if(activadoDemonking==1){
    ///HUD HP Y ANIMACION HP
    spHpDemonking.setPosition(8540 , 550);
    spHpDemonking.setScale(1.2 , 1.2);
    Demonkingtext.setPosition(8550 , 525);
    Demonkingtext.setFont(Fuente);
    stringstream tmp;
    tmp << "Demon King    "<<int(vidaDemonking);
    Demonkingtext.setString(tmp.str());
    Demonkingtext.setColor(sf::Color::Red);
    if(porcentajevidaDemonking <=100)animacionvidaDemonking=0;
    if(porcentajevidaDemonking<=90)animacionvidaDemonking=1;
    if(porcentajevidaDemonking<=80)animacionvidaDemonking=2;
    if(porcentajevidaDemonking<=70)animacionvidaDemonking=3;
    if(porcentajevidaDemonking<=60)animacionvidaDemonking=4;
    if(porcentajevidaDemonking<=50)animacionvidaDemonking=5;
    if(porcentajevidaDemonking<=40)animacionvidaDemonking=6;
    if(porcentajevidaDemonking<=30)animacionvidaDemonking=7;
    if(porcentajevidaDemonking<=20)animacionvidaDemonking=8;
    if(porcentajevidaDemonking<=10)animacionvidaDemonking=9;
    if(porcentajevidaDemonking<=0)animacionvidaDemonking=100;
    spHpDemonking.setTextureRect(sf::IntRect(animacionvidaDemonking*300 , 0 , 300 , 300));
    ///AVISARLE AL JUEGO QUE EL PLAYER ESTA EN UNA BOSS FIGHT
        player1->SetBossfight(1);
        player2->SetBossfight(1);
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1Demonking = posnpc.x - posp1.x;
     distancia2Demonking = posnpc.x - posp2.x;
     if(  distancia1Demonking < 0)   distancia1Demonking =   distancia1Demonking*(-1);
     if(distancia2Demonking < 0) distancia2Demonking = distancia2Demonking*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(  distancia1Demonking < distancia2Demonking & Demonkingatackndo1==0 & Demonkingatackndo2==0 & Demonkingatackndo3==0 & Demonkingatackndo4==0 & Demonkingatackndo5==0){
        chasing1Demonking=1; //PERSEGUIR AL PLAYER 1
        chasing2Demonking=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Demonkingatackndo1==0 & Demonkingatackndo2==0 & Demonkingatackndo3==0 & Demonkingatackndo4==0 & Demonkingatackndo5==0){
        chasing1Demonking=0;
        chasing2Demonking=1;
     }
///----------PERSEGUIR PJ1----------------------------------------------

        /// IZQUIERDA
        if(posnpc.x > posp1.x+45 & chasing2Demonking == 0){
            spDemonking.move(-speedDemonking,0);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x > posp1.x+45 & posp1.y < posnpc.y+80 & chasing2Demonking == 0){
            spDemonking.move(0,-speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;
        }

        else if(posnpc.x > posp1.x+45 & posp1.y > posnpc.y-25 & chasing2Demonking == 0) {
            spDemonking.move(0,speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;
        }
         ///DERECHA
         if(posnpc.x < posp1.x-65 & chasing2Demonking == 0){
             spDemonking.move(speedDemonking,0);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;
        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x < posp1.x-65 & posp1.y < posnpc.y+80 & chasing2Demonking == 0){
            spDemonking.move(0,-speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;
        }

        else if(posnpc.x < posp1.x-65 & posp1.y > posnpc.y & chasing2Demonking == 0){
            spDemonking.move(0,speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;
        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// IZQUIERDA
        if(posnpc.x > posp2.x+45  & chasing1Demonking == 0){
            spDemonking.move(-speedDemonking,0);
             spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;
        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x > posp2.x+45 & posp2.y < posnpc.y+70 & chasing1Demonking == 0){
            spDemonking.move(0,-speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;
        }

        else if(posnpc.x > posp2.x+45 & posp2.y > posnpc.y-20 & chasing1Demonking == 0){
            spDemonking.move(0,speedDemonking);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,100*2,200,180));
            derechaDemonking=0;
            izquierdaDemonking=1;

        }
         ///DERECHA
         if(posnpc.x < posp2.x-65 & chasing1Demonking == 0){
             spDemonking.move(speedDemonking,0);
            spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x < posp2.x-65 & posp2.y < posnpc.y+70 & chasing1Demonking == 0){
            spDemonking.move(0,-speedDemonking);
          spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;

        }

        else if(posnpc.x < posp2.x-65 & posp2.y > posnpc.y-10 & chasing1Demonking == 0){
            spDemonking.move(0,speedDemonking);
           spDemonking.setTextureRect(sf::IntRect(caminarDemonking*200,10,200,180));
            izquierdaDemonking=0;
            derechaDemonking=1;

        }
///------------------------------------------BOSS FIGHT-------------------------------
sf::Time Bossfight = relojbossfightDemonking.getElapsedTime();
sf::Time EspadasAnimacion = relojanimacionEspadas.getElapsedTime();
porcentajevidaDemonking = (vidaDemonking / vidainicialDemonking)*100;
if(reiniciar == 1){
    relojbossfightDemonking.restart();
    reiniciar=0;
}

if(distancia1Demonking < distancia2Demonking){
if(posp1.x > posnpc.x ){
spEspadas.move(3.2, 0);
spEspadas.setTextureRect(sf::IntRect(animacionEspadas*200, 0, 200, 160));
 }
 if(posp1.x < posnpc.x ){
spEspadas.move(-3.2 , 0);
spEspadas.setTextureRect(sf::IntRect(animacionEspadas*200, 150, 200, 160));
 }
}

if(distancia2Demonking < distancia1Demonking){
if(posp2.x < posnpc.x ){
spEspadas.move(-3.2 , 0);
spEspadas.setTextureRect(sf::IntRect(animacionEspadas*200, 150, 200, 160));
 }
if(posp2.x > posnpc.x ){
spEspadas.move(3.2 , 0);
spEspadas.setTextureRect(sf::IntRect(animacionEspadas*200, 0, 200, 160));
 }

}
if(EspadasAnimacion.asSeconds() >= 0.07){
    animacionEspadas++;
    relojanimacionEspadas.restart();
}
if(animacionEspadas>=9){
    animacionEspadas=0;
}
///CLOCKS
if(Bossfight.asSeconds() >=2 & Bossfight.asSeconds() <2.5  & reiniciar == 0){
Demonkingatackndo2=1;
}
else if(Bossfight.asSeconds() >=3.5 & Bossfight.asSeconds() <4 & reiniciar == 0 ){
Demonkingatackndo2=1;
}
else if(Bossfight.asSeconds() >=4.2 &  Bossfight.asSeconds() <5 & reiniciar == 0 ){
Demonkingatackndo1=1;
}
else if(Bossfight.asSeconds() >=6  & Bossfight.asSeconds() <6.5 & reiniciar == 0 ){
Demonkingatackndo2=1;
}
else if(Bossfight.asSeconds() >=6.6  & Bossfight.asSeconds() <7  & reiniciar == 0 ){
Demonkingatackndo3=1;
}
else if(Bossfight.asSeconds() >=8  & Bossfight.asSeconds() <8.5  & reiniciar == 0 ){
Demonkingatackndo2=1;
}
else if(Bossfight.asSeconds() >=11  & Bossfight.asSeconds() <11.5  & reiniciar == 0 ){
Demonkingatackndo1=1;
}
else if(Bossfight.asSeconds() >=14  & Bossfight.asSeconds() <14.5 & reiniciar == 0 ){
Demonkingatackndo3=1;
}
else if(Bossfight.asSeconds() >=16  & Bossfight.asSeconds() <17  & reiniciar == 0 ){
Demonkingatackndo2=1;
}
else if(Bossfight.asSeconds() >=21  & Bossfight.asSeconds() <21.5  & reiniciar == 0 ){
Demonkingatackndo1=1;
}
else if(Bossfight.asSeconds() >=24  & Bossfight.asSeconds() <24.5  & reiniciar == 0 ){
Demonkingatackndo1=1;
}
else if(Bossfight.asSeconds() >=27  & Bossfight.asSeconds() <27.5  & reiniciar == 0 ){
Demonkingatackndo1=1;
}
else if(Bossfight.asSeconds() >=31  & Bossfight.asSeconds() <32  & reiniciar == 0 ){
Demonkingatackndo2=1;
relojbossfightDemonking.restart();
}
/// FASE 2
if(fase2 == 1)relojbossfightDemonking.restart();
if( porcentajevidaDemonking <= 50 & reiniciar == 0) fase2 =1;
sf::Time Segundafase = relojbossfightDemonking2.getElapsedTime();
if(fase2==0) relojbossfightDemonking2.restart();

if(Segundafase.asSeconds() >=2 & Segundafase.asSeconds() <5 & fase2 == 1){
Demonkingatackndo4=1;
}
else if(Segundafase.asSeconds() >=7  & Segundafase.asSeconds() <17  & fase2 == 1){
Demonkingatackndo4=0;
Demonkingatackndo5=1;
}
else if(Segundafase.asSeconds() >=17  & Segundafase.asSeconds() <17.2 & fase2==1){
Demonkingatackndo5=0;
}
else if(Segundafase.asSeconds() >=18  & Segundafase.asSeconds() <19  & fase2==1){
Demonkingatackndo4=1;
}
else if(Segundafase.asSeconds() >=18  & Segundafase.asSeconds() <19  & fase2==1){
Demonkingatackndo2=1;
}
else if(Segundafase.asSeconds() >=20  & Segundafase.asSeconds() <20.5 & fase2==1){
Demonkingatackndo3=1;
}
else if(Segundafase.asSeconds() >=22  & Segundafase.asSeconds() <22.5 & fase2==1){
Demonkingatackndo1=1;
}
else if(Segundafase.asSeconds() >=26  & Segundafase.asSeconds() <27& fase2==1){
Demonkingatackndo4=1;
}
else if(Segundafase.asSeconds() >=29  & Segundafase.asSeconds() <35& fase2==1){
Demonkingatackndo5=1;
}
else if(Segundafase.asSeconds() >=35  & Segundafase.asSeconds() <36& fase2==1){
Demonkingatackndo5=0;
}
else if(Segundafase.asSeconds() >=36.5  &  fase2==1){
relojbossfightDemonking2.restart();
}




///------------MUERTE BOSS-------------------------------------------------------------
if(vidaDemonking<=0){
 spHpDemonking.setPosition(-9999,1840);
 Demonkingtext.setPosition(-9999,1890);
 muerteDemonking=1;
 player1->SetBossfight(0);
 player2->SetBossfight(0);
    }
///----------------------------------


}





}

void NPC::deteccion_ataque_Esqueleto(){
    ///POSICION DE LOS SPRITE PLAYERS Y NPCS
    sf::Vector2f posp1 = player1->getSprite().getPosition();
    sf::Vector2f posnpc = spNpc.getPosition();
    sf::Vector2f posp2 = player2->getSprite2().getPosition();
    ///ACTIVACION DE LA IA POR DISTANCIA
    if(posnpc.x <= posp1.x+1000|| posnpc.x <= posp2.x+1000){
    activado=1;
    }
     distancia3 = posp1.x  - posp2.x;
     if(distancia3 < 0) distancia3 = distancia3*(-1);
    if(activado==1){
      ///HUD
     textVidanpc.setPosition(posnpc.x+45 , posnpc.y);
     textVidanpc.setFont(Fuente);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
     ///RELOJ DE ATAQUE
     sf::Time timingesqueleto = relojtimingEsqueleto.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Esqueletoatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Esqueletoatkon==0){
        chasing1=0;
        chasing2=1;
     }

    ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+55 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
         timingEsqueletoatk++;
          if(timingEsqueletoatk < 50){
           Esqueletoatkon=1;
          }

    }
    else if(izquierda==1 & posnpc.x > posp2.x-55 & chasing2 == 1){ // ATACAR DESDE DERECHA
      timingEsqueletoatk++;
          if(timingEsqueletoatk < 50){
           Esqueletoatkon=1;
          }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+55 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
          timingEsqueletoatk++;
          if(timingEsqueletoatk < 50){
           Esqueletoatkon=1;
          }

    }
    else if(izquierda==1 & posnpc.x > posp1.x-55 & chasing1 == 1){ //ATACAR DESDE DERECGA
        timingEsqueletoatk++;
          if(timingEsqueletoatk < 50){
           Esqueletoatkon=1;
          }
    }
    if(timingesqueleto.asSeconds()>=2){
        timingEsqueletoatk=0;
        relojtimingEsqueleto.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+55 & chasing2 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+55 & posp1.y < posnpc.y+10 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));


        }

        else if(posnpc.x > posp1.x+55 & posp1.y > posnpc.y-10 & chasing2 == 0) {
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-55 & chasing2 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-55 & posp1.y < posnpc.y+10 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));


        }

        else if(posnpc.x < posp1.x-55 & posp1.y > posnpc.y-10 & chasing2 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+55  & chasing1 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+55 & posp2.y < posnpc.y+10 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));

        }

        else if(posnpc.x > posp2.x+55 & posp2.y > posnpc.y-10 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 89*1, 100, 89));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-55 & chasing1 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-55 & posp2.y < posnpc.y & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));


        }

        else if(posnpc.x < posp2.x-55 & posp2.y > posnpc.y & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarEsqueleto*100, 75*0, 100, 75));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
muerteEsqueleto=1;
    }
///----------------------------------
}


}

void NPC::deteccion_ataque_Helldog(){

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
     textVidanpc.setFont(Fuente);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
    sf::Time timingfuego = relojfuegoHelldo.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Helldogatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Helldogatkon==0){
        chasing1=0;
        chasing2=1;
     }

    ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+45 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
         timingFuego++;
        if(timingFuego<50)
        {
            Helldogatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp2.x-100 & chasing2 == 1){ // ATACAR DESDE DERECHA
         timingFuego++;
        if(timingFuego<50)
        {
            Helldogatkon=1;
        }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+45 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
         timingFuego++;
        if(timingFuego<50)
        {
            Helldogatkon=1;
        }

    }
    else if(izquierda==1 & posnpc.x > posp1.x-100 & chasing1 == 1){ //ATACAR DESDE DERECGA
         timingFuego++;
        if(timingFuego<50)
        {
            Helldogatkon=1;
        }
    }
    if(timingfuego.asSeconds() >= 5){
        timingFuego=0;
        relojfuegoHelldo.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+45 & chasing2 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));
            derecha=1;
            izquierda=0;

        }

        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+45 & posp1.y < posnpc.y-10 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));


        }

        else if(posnpc.x > posp1.x+45 & posp1.y > posnpc.y-10 & chasing2 == 0) {
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-45 & chasing2 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));
            izquierda=1;
            derecha=0;

        }

        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-45 & posp1.y < posnpc.y-10 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));


        }

        else if(posnpc.x < posp1.x-45 & posp1.y > posnpc.y-10 & chasing2 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+45  & chasing1 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+45 & posp2.y < posnpc.y-10 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));

        }

        else if(posnpc.x > posp2.x+45 & posp2.y > posnpc.y-10 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 75*1.2, 150, 70));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-45 & chasing1 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));
            izquierda=1;
            derecha=0;
        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-45 & posp2.y < posnpc.y-35 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));
     }

        else if(posnpc.x < posp2.x-45 & posp2.y > posnpc.y-35 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarHelldog*150, 69*0, 150, 75));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
muerteHelldog=1;

    }
///----------------------------------
}

   }

void NPC::deteccion_ataque_Troll(){

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
     textVidanpc.setFont(Fuente);
     stringstream tmp;
     tmp << ""<<int(vida);
     textVidanpc.setScale(0.5,0.5);
     textVidanpc.setString(tmp.str());
     textVidanpc.setColor(sf::Color::White);
     ///RELOJ ATAQUE
     sf::Time timingtroll = relojataqueTroll.getElapsedTime();
    ///CALCULOS DE DISTANCIA ENTRE IA Y PLAYERS
     distancia1 = posnpc.x - posp1.x;
     distancia2 = posnpc.x - posp2.x;
     if(distancia1 < 0) distancia1 = distancia1*(-1);
     if(distancia2 < 0) distancia2 = distancia2*(-1);
    ///PERSEGUIR AL QUE TENGA MAS CERCA
     if(distancia1 < distancia2 & Trollatkon==0){
        chasing1=1; //PERSEGUIR AL PLAYER 1
        chasing2=0; //PERSEGUIR AL PLAYER 2
     }
     else if (Trollatkon==0){
        chasing1=0;
        chasing2=1;
     }

   ///ATACAR PJ2
    if(derecha == 1 & posnpc.x < posp2.x+45 & chasing2 == 1){ //ATACAR DESDE IZQUIERDA
        Trolltimeatack++;
        if(Trolltimeatack<50){
            Trollatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp2.x-65 & chasing2 == 1){ // ATACAR DESDE DERECHA
         Trolltimeatack++;
        if(Trolltimeatack<50){
            Trollatkon=1;
        }
    }
    ///ATACAR PJ1
    if(derecha == 1 & posnpc.x < posp1.x+45 & chasing1 == 1){ //ATACAR DESDE IZQUIERDA
        Trolltimeatack++;
        if(Trolltimeatack<50){
            Trollatkon=1;
        }
    }
    else if(izquierda==1 & posnpc.x > posp1.x-65 & chasing1 == 1){ //ATACAR DESDE DERECGA
       Trolltimeatack++;
        if(Trolltimeatack<50){
            Trollatkon=1;
        }
    }
    if(timingtroll.asSeconds() >= 2){
        Trolltimeatack=0;
        relojataqueTroll.restart();
    }

///----------PERSEGUIR PJ1----------------------------------------------

        /// DERECHA
        if(posnpc.x > posp1.x+45 & chasing2 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp1.x+45 & posp1.y < posnpc.y+50 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));


        }

        else if(posnpc.x > posp1.x+45 & posp1.y > posnpc.y-25 & chasing2 == 0) {
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));

        }
         ///IZQUIERDA
         if(posnpc.x < posp1.x-65 & chasing2 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp1.x-65 & posp1.y < posnpc.y+40 & chasing2 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));


        }

        else if(posnpc.x < posp1.x-65 & posp1.y > posnpc.y & chasing2 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));


        }
///-------------------------------------------------------------------------------


///--------------------------PERSEGUIR PJ2 ---------------------------------------
         /// DERECHA
        if(posnpc.x > posp2.x+45  & chasing1 == 0){
            spNpc.move(-speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));
            derecha=1;
            izquierda=0;

        }
        ///ARRIBA Y ABAJO DERECHA
         if( posnpc.x > posp2.x+45 & posp2.y < posnpc.y+40 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));

        }

        else if(posnpc.x > posp2.x+45 & posp2.y > posnpc.y-25 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*1, 200, 140));


        }
         ///IZQUIERDA
         if(posnpc.x < posp2.x-65 & chasing1 == 0){
             spNpc.move(speed,0);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));
            izquierda=1;
            derecha=0;

        }
        ///ARRIBA Y ABAJO IZQUIERDA
         if( posnpc.x < posp2.x-65 & posp2.y < posnpc.y+40 & chasing1 == 0){
            spNpc.move(0,-speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));


        }

        else if(posnpc.x < posp2.x-65 & posp2.y > posnpc.y-25 & chasing1 == 0){
            spNpc.move(0,speed);
            spNpc.setTextureRect(sf::IntRect(caminarTroll*200, 140*0, 200, 140));


        }
///------------MUERTE NPC-------------------------------------------------------------
if(vida<=0){
 muerteTroll=1;

    }
///----------------------------------


}

   }

void NPC::update_movimiento(){

    if(esqueleto==1){
    ///ANIMACION CAMINAR ESQUELETO
   sf::Time caminarEsqueleto2= relojcaminarEsqueleto.getElapsedTime();
   if(caminarEsqueleto2.asSeconds()>=0.12){
                caminarEsqueleto++;
                relojcaminarEsqueleto.restart();
        }


        if(caminarEsqueleto==8){
            caminarEsqueleto=0;
        }
         ///ANIMACION ATAQUE ESQUELETO
   sf::Time Esqueletoatake = relojataqueEsqueleto.getElapsedTime();
     if(Esqueletoatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Esqueletatk*199.5 , 103*2.9, 200, 100 ));
        if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Esqueletatk*200 , 116*1.7, 200, 100 ));


        if(Esqueletoatake.asSeconds()>=0.17)
       {
        Esqueletatk++;
        relojataqueEsqueleto.restart();
       }

       if(Esqueletatk>=6){
        Esqueletatk=0;
        Esqueletoatkon=0;
        chasing1=1;
        chasing2=0;
       }

     }
     ///ANIMACION MUERTE ESQUELETO
     sf::Time Esqueletomuerte = relojmuerteEsqueleto.getElapsedTime();
     if(muerteEsqueleto==1){
      chasing1=2;
      chasing2=2;
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(Esqueletomuerteanimacion*100 , 103*5, 100, 100 ));
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Esqueletomuerteanimacion*100 , 103*4, 100, 100 ));

       if(Esqueletomuerte.asSeconds() >= 0.12){
        Esqueletomuerteanimacion++;
        relojmuerteEsqueleto.restart();
       }
       if(Esqueletomuerteanimacion>=6){
        esqueleto=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
        textVidanpc.setPosition(-9999,999);
       }


     }
    }
if(helldog == 1){
   ///ANIMACION CAMINAR HELLDOG
   sf::Time caminarHelldog2= relojcaminarHelldog.getElapsedTime();
   if(caminarHelldog2.asSeconds()>=0.12){
    caminarHelldog++;
    relojcaminarHelldog.restart();
   }
   if(caminarHelldog==7){
    caminarHelldog=0;
   }
   ///ANIMACION ATAQUE HELLDOG
    sf::Vector2f posnpcHelldog = spNpc.getPosition();
   sf::Time tirarfuego = relojAnimacionfuego.getElapsedTime();
     if(Helldogatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Helldogatk*250 , 108*2.9, 250, 130 ));
        if(izquierda==1){
        spNpc.setTextureRect(sf::IntRect(Helldogatk*250 , 110*1.7, 250, 120 ));
        }

        if(tirarfuego.asSeconds()>=0.10)
       {
        Helldogatk++;
        relojAnimacionfuego.restart();
       }
        if(Helldogatk==12)
      {
        Helldogatk=0;
        Helldogatkon=0;
      }


     }
     ///ANIMACION MUERTE HELLDOG
     sf::Time Helldogmuerte = relojmuerteHelldog.getElapsedTime();
     if(muerteHelldog==1){
      chasing1=2;
      chasing2=2;
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(Helldogmuerteanimacion*150 , 96*5, 150, 90 ));
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Helldogmuerteanimacion*149 , 102*4.75, 150, 90 ));

       if(Helldogmuerte.asSeconds() >= 0.13){
        Helldogmuerteanimacion++;
        relojmuerteHelldog.restart();
       }
       if(Helldogmuerteanimacion>=7){
        helldog=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
         textVidanpc.setPosition(-9999,999);
       }


     }
}

if(troll==1){
   ///ANIMNACION CAMINAR TROLL
   sf::Time caminarTroll2= relojcaminarTroll.getElapsedTime();
   if(caminarTroll2.asSeconds()>=0.12){
    caminarTroll++;
    relojcaminarTroll.restart();
   }
   if(caminarTroll==8){
    caminarTroll=0;
   }
    ///ANIMACION ATAQUE TROLL
   sf::Time  Trollataque = relojanimacionTroll.getElapsedTime();
     if(Trollatkon==1)
        {
        chasing1=2;
        chasing2=2;
        if(derecha==1)spNpc.setTextureRect(sf::IntRect(Trollatk*200 , 98*5, 200, 150 ));
        if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Trollatk*200 , 94*3.5, 200, 150 ));


        if(Trollataque.asSeconds()>=0.15)
       {
        Trollatk++;
        relojanimacionTroll.restart();
       }
       if(Trollatk>=5){
        Trollatk=0;
        Trollatkon=0;
       }

     }
      ///ANIMACION MUERTE TROLL
     sf::Time Trollmuerte = relojmuerteTroll.getElapsedTime();
     if(muerteTroll==1){
      chasing1=2;
      chasing2=2;
    if(derecha==1)spNpc.setTextureRect(sf::IntRect(Trollmuerteanimacion*250 , 96.8*12, 250, 100 ));
    if(izquierda==1)spNpc.setTextureRect(sf::IntRect(Trollmuerteanimacion*250 , 98*10, 250, 100 ));

       if(Trollmuerte.asSeconds() >= 0.2){
        Trollmuerteanimacion++;
        relojmuerteTroll.restart();
       }
       if(Trollmuerteanimacion>=6){
        troll=0;
        activado=0;
        spNpc.setPosition(-99999 , 999);
        textVidanpc.setPosition(-9999,999);
       }


     }
}
     ///ANIMACION CAMINAR DEMON KING
   sf::Time caminarDemonking2= relojcaminarDemonking.getElapsedTime();
   if(caminarDemonking2.asSeconds()>=0.2){
                caminarDemonking++;
                relojcaminarDemonking.restart();
        }


        if(caminarDemonking>=5){
            caminarDemonking=0;
        }
      ///SECCION ANIMACION ARTAQUES DEMON KING
      ///ATAQUE 1 DEMON KING
   sf::Vector2f player1pos = player1->getSprite().getPosition();
   sf::Vector2f player2pos = player2->getSprite2().getPosition();
   sf::Vector2f Demonkingpos = spDemonking.getPosition();
   sf::Time Demonkingataque = relojanimacionataque1Demonking.getElapsedTime();
     if(Demonkingatackndo1==1 )
        {
        chasing1Demonking=2;
        chasing2Demonking=2;
        if(izquierdaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack1*304 ,640, 295, 190 ));
        spDemonking.move(-0.4 , 0);
        }
        if(derechaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack1*303, 400, 295, 190 ));
        spDemonking.move(0.4 , 0);
        }
        if(Demonkingataque.asSeconds()>=0.13)
       {
        Demonkingatack1++;
        relojanimacionataque1Demonking.restart();
       }
      // if(Demonkingatack1==4)soundEspadazo.play();
       if(Demonkingatack1>=8){
        Demonkingatackndo1=0;
        Demonkingatack1=8;
        if (Demonkingataque.asSeconds()>=0.11){
        spDemonking.setTextureRect(sf::IntRect(0, 200, 200,200 ));
        Demonkingatack1=0;
        }
       }
     }
      ///ATAQUE 2 DEMON KING
   sf::Time Demonkingataque2 = relojanimacionataque2Demonking.getElapsedTime();
   sf::Time Freeze = relojfreezeEstocada.getElapsedTime();
     if(Demonkingatackndo2==1 )
        {
        sf::Time Freeze = relojfreezeEstocada.getElapsedTime();
        if(Freeze.asSeconds() >= 0.7) relojfreezeEstocada.restart();
        chasing1Demonking=2;
        chasing2Demonking=2;
        if(izquierdaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack2*300 ,1030, 295, 190 ));
        if(Demonkingatack2>=2) spDemonking.move(-1.8 , 0);
        }
        if(derechaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack2*300, 820, 295, 190 ));
        if(Demonkingatack2>=2) spDemonking.move(1.8 , 0);
        }
        if(Demonkingataque2.asSeconds()>=0.11)
       {
        Demonkingatack2++;
        relojanimacionataque2Demonking.restart();
       }
      // if(Demonkingatack2==1)soundEspadazo.play();
       if(Demonkingatack2>=4){
        Demonkingatack2=3;
        if (Freeze.asSeconds()>=0.6){
        spDemonking.setTextureRect(sf::IntRect(0, 200, 200,200 ));
        Demonkingatack2=0;
        Demonkingatackndo2=0;
        }
       }
     }
       ///ATAQUE 3 DEMON KING
   sf::Time Demonkingataque3 = relojanimacionataque3Demonking.getElapsedTime();
     if(Demonkingatackndo3==1 )
        {
        chasing1Demonking=2;
        chasing2Demonking=2;
        if(izquierdaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack3*304 ,1470, 295, 190 ));
        spDemonking.move(-0.4 , 0);
        }
        if(derechaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack3*303, 1260, 295, 190 ));
        spDemonking.move(0.4 , 0);
        }
        if(Demonkingataque3.asSeconds()>=0.13)
       {
        Demonkingatack3++;
        relojanimacionataque3Demonking.restart();
       }
      // if(Demonkingatack3==1)soundEspadazo.play();
       if(Demonkingatack3>=5){
        Demonkingatackndo3=0;
        Demonkingatack3=0;
        spDemonking.setTextureRect(sf::IntRect(0, 200, 200,200 ));

       }
     }
      ///ATAQUE 4 DEMON KING
   sf::Time Demonkingataque4 = relojanimacionataque4Demonking.getElapsedTime();
     if(Demonkingatackndo4==1 )
        {
        chasing1Demonking=2;
        chasing2Demonking=2;
        if(izquierdaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack4*300 ,1880, 295, 180 ));
        }
        if(derechaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack4*300, 1680, 295, 180 ));
        }
        if(Demonkingataque4.asSeconds()>=0.09)
       {
        Demonkingatack4++;
        relojanimacionataque4Demonking.restart();
       }
      // if(Demonkingatack4==5)soundDashDemon.play();
       if(Demonkingatack4==5){
         if (izquierdaDemonking==1) {
         if(distancia1Demonking < distancia2Demonking) spDemonking.setPosition(player1pos.x+30 , player1pos.y-50);
         if(distancia2Demonking < distancia1Demonking) spDemonking.setPosition(player2pos.x+30 , player2pos.y-50);
         }
         if (derechaDemonking==1){
          if(distancia1Demonking < distancia2Demonking) spDemonking.setPosition(player1pos.x-150 , player1pos.y-50);
          if(distancia2Demonking < distancia1Demonking) spDemonking.setPosition(player2pos.x-150 , player2pos.y-50);
         }
       }

       if(Demonkingatack4>=11){
        Demonkingatackndo4=0;
        Demonkingatack4=0;
        spDemonking.setTextureRect(sf::IntRect(0, 200, 200,200 ));

       }
     }
        ///ATAQUE 5 DEMON KING
   sf::Time Demonkingataque5 = relojanimacionataque5Demonking.getElapsedTime();
   sf::Time FreezeEspadas = relojfreezeEspadas.getElapsedTime();
     if(Demonkingatackndo5==1 )
        {
        sf::Time TirarEspadas = relojTirarEspadas.getElapsedTime();
        if(FreezeEspadas.asSeconds()>=10.2) relojfreezeEspadas.restart();
        chasing1Demonking=2;
        chasing2Demonking=2;
        if(izquierdaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack5*300 ,2260, 295, 180 ));
        }
        if(derechaDemonking==1){
        spDemonking.setTextureRect(sf::IntRect(Demonkingatack5*300, 2050, 295, 180 ));
        }
        if(Demonkingataque5.asSeconds()>=0.3)
       {
        Demonkingatack5++;
        relojanimacionataque5Demonking.restart();
       }
       if(Demonkingatack5==5){
        Demonkingatack5=4;
       }
       if(TirarEspadas.asSeconds() >= 0.8 & Demonkingatack5==4){
       if(distancia1Demonking < distancia2Demonking) spEspadas.setPosition(Demonkingpos.x , player1pos.y-50);
       if(distancia2Demonking < distancia1Demonking) spEspadas.setPosition(Demonkingpos.x , player2pos.y-50);
        relojTirarEspadas.restart();
       }

       }
      /* if(Demonkingatackndo5==1){
        if(reproducirEspadas==1){
        soundEspadas.setLoop(true);
        soundEspadas.play();
        }
        reproducirEspadas=0;
       }
       if(Demonkingatackndo5==0 && reproducirEspadas==0){
            soundEspadas.stop();
       }*/
        ///ANIMACION MUERTE DEMON KING
     sf::Time DemonkingMuere = relojmuerteDemonking.getElapsedTime();
     if(muerteDemonking==1){
      chasing1Demonking=2;
      chasing2Demonking=2;
      Demonkingatackndo1=0;
      Demonkingatackndo2=0;
      Demonkingatackndo3=0;
      Demonkingatackndo4=0;
      Demonkingatackndo5=0;
    if(derechaDemonking==1)spDemonking.setTextureRect(sf::IntRect(Demonkinganimacionmuerte*302 ,2450 , 300, 180 ));
    if(izquierdaDemonking==1)spDemonking.setTextureRect(sf::IntRect(Demonkinganimacionmuerte*303 ,2600 , 300, 180 ));

       if(DemonkingMuere.asSeconds() >= 0.2){
        Demonkinganimacionmuerte++;
        relojmuerteDemonking.restart();
       }
       if(Demonkinganimacionmuerte>=5){
       Demonkinganimacionmuerte=0;
        spDemonking.setPosition(-99999 , 999);
        player1->SetBossfight(0);
        player2->SetBossfight(0);
        demonking=0;
        activadoDemonking=0;
        activarPortal=1;
       }


     }
     ///ANIMACION Y ACTIVACION PORTAL
     if(activarPortal==1 || activarPortal ==0){
     if(activarPortal==1) spPortal.setPosition(9100 , 300);
      sf::Time Portalframe = relojPortalanimacion.getElapsedTime();
      if(Portalframe.asSeconds() >= 0.2){
        Portalanimacion++;
        relojPortalanimacion.restart();
      }
      if(Portalanimacion==6){
        Portalanimacion=2;
      }
      spPortal.setTextureRect(sf::IntRect(Portalanimacion*200 ,0 , 200, 300 ));

    if(activarPortal==1){
        if(Collision::PixelPerfectTest(spPortal , player2->getSprite2())){
        player2->getSprite2().setPosition(150 , 2550);
        player1->getSprite().setPosition(100 , 2550);
        player2->Setnivel2(1);
        player1->Setnivel2(1);
        activarPortal=0;
        spPortal.setPosition(100 , 2446);
      }
       if(Collision::PixelPerfectTest(spPortal , player1->getSprite())){
        player2->getSprite2().setPosition(150 , 2550);
        player1->getSprite().setPosition(100 , 2550);
        player2->Setnivel2(1);
        player1->Setnivel2(1);
        activarPortal=0;
        spPortal.setPosition(100 , 2446);
      }
    }
     }
     }

void NPC::update(){
  if(player1->Getnivel2()== 0 & player2->Getnivel2() == 0){
  if(helldog == 1 & vida>=0){
   ColisionesHelldog();
    deteccion_ataque_Helldog();}
  else if (esqueleto == 1 & vida>=0){
  ColisionesEsqueleto();
  deteccion_ataque_Esqueleto();}
  else if (troll==1 & vida >= 0) {
  ColisionesTroll();
  deteccion_ataque_Troll();
  }
   if(demonking==1 & vidaDemonking >= 0){
    ColisionesDemonking();
    deteccion_ataque_Demonking();
  }
   }
   update_movimiento();
 if(corazon == 1){
  ColisionesCorazon();
 }
}

void NPC::dibujar(sf::RenderWindow &w){
    w.draw(spNpc);
    w.draw(spDemonking);
    w.draw(spEspadas);
    w.draw(spHpDemonking);
    w.draw(Demonkingtext);
    w.draw(textVidanpc);
    w.draw(spPortal);
    w.draw(spCorazon);

}
