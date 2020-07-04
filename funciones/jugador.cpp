#include "jugador.h"
#include <sstream>
///CONSTRUCTOR PLAYER 1
Jugador::Jugador(){
      ///fuente Y texto game win
    Fuente.loadFromFile("Royal Inferno.ttf");
    Gamewin.setFont(Fuente);
    Gamewin.setString("GANASTE EL JUEGO!! :)");
    Gamewin.setScale(4,4);
    Gamewin.setColor(sf::Color::Red);
    Gamewin.setPosition(-999,-9999);
    ///efectos de sonido
    bufferDash.loadFromFile("sonidos/Dash.wav");
    bufferDisparo.loadFromFile("sonidos/Disparo.wav");
    bufferGolpe.loadFromFile("sonidos/Golpe.wav");
    bufferRecarga.loadFromFile("sonidos/Recarga pistola.wav");
    soundDash.setBuffer(bufferDash);
    soundDisparo.setBuffer(bufferDisparo);
    soundRecarga.setBuffer(bufferRecarga);
    soundGolpe.setBuffer(bufferGolpe);
    /// cargar texturas
    texPlayer.loadFromFile("imagenes player 1/Player1.png");
    ///crear sprites
    player.setTexture(texPlayer);
    ///posicionar y recortar sprite
    player.setTextureRect(sf::IntRect(46*frame,row,46,55));
    player.setPosition(50, 300);
    player.setScale(1.5,1.5);
    ///TEXTURA Y SPRITE PROYECTILES PJ1
    texBala.loadFromFile("imagenes player 1/Bala.png");
    spBala.setTexture(texBala);
    spBala.setPosition(9999,9999);
    texBala2.loadFromFile("imagenes player 1/Bala2.png");
    spBala2.setTexture(texBala2);
    spBala2.setPosition(-9999,-9999);
    ///VIDA PJ1
    texVida1.loadFromFile("imagenes player 1/Vida.png");
    spVida1.setTexture(texVida1);
    spVida1.setTextureRect(sf::IntRect(50*frame , row , 100 , 100));
    spVida1.setScale(0.8,0.8);
    if(!Fuente.loadFromFile("Royal Inferno.ttf")){
        }
    ///POSICION PROYECTILES
    sf::Vector2f balapos = spBala.getPosition();
    sf::Vector2f bala2pos = spBala2.getPosition();

}
///CONSTRUCTOR PLAYER2
Jugador::Jugador(int dato){
    ///fuente Y texto game over
    Fuente.loadFromFile("Royal Inferno.ttf");
    Gameover.setFont(Fuente);
    Gameover.setString("GAME OVER!");
    Gameover.setScale(4,4);
    Gameover.setColor(sf::Color::Red);
    Gameover.setPosition(-999,-9999);
    ///efectos de sonido
    bufferEspadaso.loadFromFile("sonidos/Espadazo.wav");
    bufferFuegoNegro.loadFromFile("sonidos/Fuego.wav");
    bufferGetsuga.loadFromFile("sonidos/Getsuga.wav");
    bufferDash2.loadFromFile("sonidos/Dash.wav");
    bufferAirEspadas.loadFromFile("sonidos/Lanzar Espadas.wav");
    soundDash2.setBuffer(bufferDash2);
    soundEspadaso.setBuffer(bufferEspadaso);
    soundFuegoNegro.setBuffer(bufferFuegoNegro);
    soundGetsuga.setBuffer(bufferGetsuga);
    soundAirEspadas.setBuffer(bufferAirEspadas);
    ///TEXTO DE VIDA
     if(!Fuente.loadFromFile("Royal Inferno.ttf")){
        }
    /// cargar texturas
    texPJ2.loadFromFile("imagenes player 2/Player2.png");
    ///crear sprites
    spPJ2.setTexture(texPJ2);
    ///TEXTURA , SPRITE Y CUALIDADES PJ2
    spPJ2.setTextureRect(sf::IntRect(60*frame,row,90,70));
    spPJ2.setPosition(100 , 300);
    spPJ2.setScale(1.4,1.4);
    ///TEXTURA Y SPRITE PROYECTILES PJ2
    texGetsuga.loadFromFile("imagenes player 2/Getsuga.png");
    spGetsuga.setTexture(texGetsuga);
    spGetsuga.setTextureRect(sf::IntRect(60*frame,row,100,180));
    spGetsuga.setPosition(9999,9999);
    texGetsuga2.loadFromFile("imagenes player 2/Getsuga2.png");
    spGetsuga2.setTexture(texGetsuga2);
    spGetsuga2.setTextureRect(sf::IntRect(60*frame,row,100,180));
    spGetsuga2.setPosition(9999,9999);
    texDark.loadFromFile("imagenes player 2/Dark.png");
    spDark.setTexture(texDark);
    spDark.setTextureRect(sf::IntRect(60*frame,row,100,180));
    spDark.setPosition(9999,9999);
    texDark2.loadFromFile("imagenes player 2/Piso.png");
    spDark2.setTexture(texDark2);
    spDark2.setTextureRect(sf::IntRect(60*frame,row,100,180));
    spDark2.setPosition(9999,9999);
    ///VIDA PJ2
    texVida2.loadFromFile("imagenes player 1/Vida.png");
    spVida2.setTexture(texVida2);
    spVida2.setTextureRect(sf::IntRect(50*frame , row , 100 , 100));
    spVida2.setScale(0.7,0.7);
}

///posicionar camara al pj
void Jugador::posicionar_camara(){
    sf::View view;
    view.reset(sf::FloatRect(0, 0, 1200, 500));
    view.setViewport(sf::FloatRect(0, 0, 0.5f, 1.0f));
    sf::Vector2f position(0, 0);
}

///MOVIMIENTOS Y ANIMACIONES JUGADOR 1
void Jugador::updateMoveSet1(){
     if (sf::Joystick::isConnected(1)){
		// check how many buttons joystick number 0 has
		unsigned int buttonCount = sf::Joystick::getButtonCount(1);

		// check if joystick number 0 has a Z axis
		bool hasZ = sf::Joystick::hasAxis(1, sf::Joystick::Z);

		//std::cout << "Button count: " << buttonCount << std::endl;
		//std::cout << "Has a z-axis: " << hasZ << std::endl;
	}

     //JOYSTICK
     sf::Time caminar = relojcaminar.getElapsedTime(); //ANIMACION CAMINAR PJ1 Y 2
     sf::Time estatico = relojquieto.getElapsedTime(); //ANIMACION ESTATICA PJ1 Y 2
     sf::Time dashear = relojdash.getElapsedTime();//ANIMACION DASH PJ1 Y PJ2
     sf::Time duraciondash = relojduraciondash.getElapsedTime();//DURACION DASH PJ1 Y PJ2
     sf::Time disparo = relojdisparo.getElapsedTime(); // ANIMACION DISPARO PJ1
     sf::Time timingdisparar = relojtimingdisparo.getElapsedTime();//COOLDOWN DISPARO PJ1
     sf::Time giro = relojgiro.getElapsedTime();//ANIMACION ATAQUE GIRO PJ1
     sf::Time timinggirar = relojtiminggiro.getElapsedTime();//COOLDOWN ATAQUE GIRO PJ1
     sf::Time recorridodisparo = relojrecorridobala.getElapsedTime();//RECORRIDO DISPARO PJ1
     sf::Time pinia = relojpinia.getElapsedTime();//ANIMACION ATAQUE PIÑA PJ1
     sf::Time timingpegar = relojtimingpinia.getElapsedTime();//COOLDOWN PIÑA PJ1
     sf::Time patada = relojpatada.getElapsedTime();//ANIMACION ATAQUE PATADA PJ1
     sf::Time timingpateando = relojtimingpatada.getElapsedTime();//COOLDOWN PATADA J1
     sf::Time Recargando = relojRecargando.getElapsedTime();//CARGADOR P1
     ///LIMITE VIDA
     if(vida>=100) vida = 100;
     ///MOVIMIENTO PROYECTILES
    spBala.move(3.5,0); ///PJ1
    spBala2.move(-3.5,0);///PJ1
    ///CONSEGUIR POSICION DE JUGADOR1
    sf::Vector2f player1pos = player.getPosition();
    ///LIMITACION PJ1
    ///NIVEL 1
   if(nivel2==0){
    if(player1pos.y > 439) player1pos.y = 439;
    if(player1pos.y < 270) player1pos.y = 270;
    if(vida >=1 & Bossfight == 1){
    if(player1pos.x <8020) player1pos.x= 8020;
    if(player1pos.x >9182) player1pos.x =9182;}
    else if(vida >=1 & Bossfight == 0){
    if(player1pos.x >9680) player1pos.x =9680;
    }
}
    ///GENERAL
    if(vida >=1){if(player1pos.x <-30) player1pos.x=-30;}
   ///NIVEL 2
   if(nivel2==1){
    if(player1pos.y > 2686) player1pos.y = 2686;
    if(player1pos.y < 2512) player1pos.y = 2512;
     if(vida >=1 & Bossfight2 == 1){
    if(player1pos.x <8035) player1pos.x= 8035;
    if(player1pos.x >9180) player1pos.x =9180;}
    else if(vida >=1 & Bossfight2 == 0){
    if(player1pos.x >9680) player1pos.x =9680;
    }
   }
    player.setPosition(player1pos);
    ///SECCION PJ1
    ///HUD PJ1 VIDA
    spVida1.setPosition(player1pos.x+22 , player1pos.y -30);
    VidaPlayer1.setPosition(player1pos.x+42, player1pos.y-38);
    VidaPlayer1.setFont(Fuente);
    stringstream tmp;
    tmp << ""<<int(vida);
    VidaPlayer1.setScale(0.45,0.45);
    VidaPlayer1.setString(tmp.str());
    VidaPlayer1.setColor(sf::Color::White);
    ///SECCION MOVIMIENTOS PJ1
        /// ----------------------------MOVIMIENTO JOYSTICK ----------------------------------------------------------------------------------------
 speed2 = sf::Vector2f(sf::Joystick::getAxisPosition(1, sf::Joystick::X), sf::Joystick::getAxisPosition(1, sf::Joystick::Y));
if (speed2.x > 15.f || speed2.x < -15.f || speed2.y > 15.f || speed2.y < -15.f)player.move(speed2.x*TimePerFrame2.asSeconds(),speed2.y*TimePerFrame2.asSeconds());
    ///DERECHA PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Right)*/ speed2.x > 15.f && girando!= 1)
    {
     //player.move(speedpj1,0);
     player.setTextureRect(sf::IntRect(walk*98,62*0,90,67));
     quieto=0;
     derecha = 1;
     izquierda=0;

    }
    ///IZQUIERDA PJ1
    else if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Left)*/ speed2.x < -15.f && girando!= 1)
    {
    // player.move(-speedpj1,0);
     player.setTextureRect(sf::IntRect(walk*100,62*1.5,90,70));/// 60 es ancho , 65 es altura.
     quieto=0;
     izquierda = 1;
     derecha=0;

    }
    else
    {
     if(izquierda == 1) player.setTextureRect(sf::IntRect(parado*60,60.7*9,65,80));
     if(derecha == 1)   player.setTextureRect(sf::IntRect(parado*60,62.4*3,65,80));
     quieto=1;
    }

    ///ABAJO PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Down)*/ speed2.y > 15.f)
    {
     //player.move(0,speedpj1);
     arriba=0;
     abajo=1;
     if (izquierda==1)player.setTextureRect(sf::IntRect(walk*100, 62*1.5, 90,70));
     if (derecha==1)player.setTextureRect(sf::IntRect(walk*98,62*0,90,67));

    }
    ///ARRIBA PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Up)*/ speed2.y < -15.f)
    {
     //player.move(0,-speedpj1);
     arriba=1;
     abajo=0;
     if (izquierda==1)player.setTextureRect(sf::IntRect(walk*100,62*1.5,90,70));
     if (derecha==1)player.setTextureRect(sf::IntRect(walk*98,62*0,90,67));

    }
    ///DASH MOVE PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)*/ sf::Joystick::isButtonPressed(1, 5))
    {
       timingdash++;
        if(timingdash<50)
        {
            dash=1;
        }
    }else {quieto = 1;}
    if(duraciondash.asSeconds()>=1){
        relojduraciondash.restart();
        timingdash=0;

    }else quieto=1;



    ///SECCION ATAQUES PJ1
    ///ATAQUE DISTANCIA PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)*/ sf::Joystick::isButtonPressed(1, 0) && cargador >= 1)
    {
     timingdisparo++;
    if(timingdisparo<50){
     disparando=1;

    }
    }
    else {quieto = 1;}

    if(timingdisparar.asSeconds()>=0.9){

        timingdisparo=0;
        relojtimingdisparo.restart();

    }
    ///ATAQUE GIRATORIO PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)*/ sf::Joystick::isButtonPressed(1, 1))
    {
        timinggiro++;
        if(timinggiro<50)
        {
            girando=1;
        }
    }else {quieto = 1;}
    if(timinggirar.asSeconds()>=1.7 ){
        relojtiminggiro.restart();
        timinggiro=0;
    }
    ///ATAQUE DE PIÑA PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)*/ sf::Joystick::isButtonPressed(1, 2))
    {
        timingpinia++;
        if(timingpinia<50)
        {
            pegando=1;
        }
    }else {quieto = 1;}
    if(timingpegar.asSeconds()>=1){
        relojtimingpinia.restart();
        timingpinia=0;
    }
    ///ATAQUE PATADA PJ1
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)*/ sf::Joystick::isButtonPressed(1, 3))
    {
        timingpatada++;
        if(timingpatada<50)
        {
            pateando=1;
        }
    }else {quieto = 1;}
    if(timingpateando.asSeconds()>=2){
        relojtimingpatada.restart();
        timingpatada=0;
    }


///FIN SECCION ATAQUES PJ1
///SECCION ANIUMACIONES PJ1
    ///ANIMACION PJ1 MOVIMIENTO
   if(caminar.asSeconds()>= 0.12){
        walk ++;
        relojcaminar.restart();
    }
    if(walk == 6){
        walk=0;
    }
    ///FIN  PJ1 MOVIMIENTO
    ///ANIMACION ESTATICA PJ1
    if(quieto==1)
        {
       if(estatico.asSeconds()>=0.4)
       {
        parado++;
        relojquieto.restart();
       }
    if(parado==2){
        parado=0;
    }

       }
       ///FIN ANIMACION ESTATICA PJ1
       ///ANIMACION DISPARO PJ1
        if(disparando==1)
        {
        dash=0;
        relojrecorridobala.restart();
        speedpj1=0;
        setTiempo2(TiempoNulo2);
        if(derecha == 1 )player.setTextureRect(sf::IntRect(disparar*302,60.5*4.5,200,80));
        if(izquierda == 1 )player.setTextureRect(sf::IntRect(disparar*300,61*7.5,200,80));
        if(disparo.asSeconds()>=0.09)
       {
        disparar++;
        relojdisparo.restart();
       }
       if(disparar==1 & vida >=1)soundDisparo.play();
       if(disparar==4)
       {
        disparar=0;
        disparando=0;
        quieto=1;
        if (derecha == 1 )spBala.setPosition(player1pos.x+50, player1pos.y+35);
        if (izquierda == 1 )spBala2.setPosition(player1pos.x+50, player1pos.y+35);
        cargador--;
       }
       }else{disparar=0 , speedpj1=0.95;}
       if(disparando!=1)setTiempo2(TiempoDevuelto2);
       ///FUNCION CARGADOR ARMA PJ1
       if (cargador<=0)
         {
            if(reproducircargador==0 & vida>=1){
                soundRecarga.play();
                reproducircargador=1;
              }
             if(Recargando.asSeconds()>=2.1){
             cargador = 6; }
         }
         if(cargador>=1){
            reproducircargador=0;
            relojRecargando.restart();
         }
         ///FUNCION RECORRIDO PROYECTIL PJ1
          if(recorridodisparo.asSeconds()>=0.8)
          {
           spBala.setPosition(999,999);
           spBala2.setPosition(999,999);
           relojrecorridobala.restart();
          }
       ///FIN ANIMACION DISPARO PJ1
       ///ANIMACION GIRO PJ1
       if(girando==1)
        {
        dash=0;
        if(derecha==1)player.move(1,0);
        if(izquierda==1)player.move(-1,0);
        if(derecha==1)player.setTextureRect(sf::IntRect(girar*102,61.2*6,95,80));//ir probando
        if(izquierda==1)player.setTextureRect(sf::IntRect(girar*100,59*13.5,95,80));
        if(giro.asSeconds()>= 0.07)
       {
        girar++;
        relojgiro.restart();

       }
       if(girar==1 & vida >=1)soundDash.play();
    if(girar==10 )
    {
        girar=0;
        girando=0;
        quieto=1;
    }

     }else{girar=0 ;}
       ///FIN ANIMACION ATAQUE GIRO PJ1

       ///ANIMACION PIÑA PJ1
       if(pegando==1)
        {
        if(derecha==1)player.setTextureRect(sf::IntRect(pegar*100,59.5*10.5,95,70));//ir probando
        if(izquierda==1)player.setTextureRect(sf::IntRect(pegar*100,58.3*15,95,80));
        if(pinia.asSeconds()>=0.08)
       {
        pegar++;
        relojpinia.restart();
       }
       if(pegar==1 & vida >=1)soundGolpe.play();
        if(pegar==6)
      {
        pegar=0;
        pegando=0;
        quieto=1;
      }

     }else{pegar=0;}
     ///FIN ANIMACION ATAQUE PIÑA PJ1
     ///ANIMACION PATADA PJ1
      if(pateando==1)
        {
        if(derecha==1)player.setTextureRect(sf::IntRect(patar*100,59.5*12,100,70));
        if(izquierda==1)player.setTextureRect(sf::IntRect(patar*100,58.5*16.5,100,80));
        if(patada.asSeconds()>=0.08)
       {
        patar++;
        relojpatada.restart();
       }
       if(patar==1 & vida >=1)soundGolpe.play();
    if(patar==9)
    {
        patar=0;
        pateando=0;
        quieto=1;
    }

     }else{patar=0;}
     ///FIN ANIMACION PATADA PJ1
     ///ANIMACION DASH PJ1
     if(dash==1)
        {
        pateando=0;
        pegando=0;
        if(derecha==1)player.move(1,0);
        if(izquierda==1)player.move(-1,0);
        if(derecha==1)player.setTextureRect(sf::IntRect(dashing*100,58.5*18,100,80));
        if(izquierda==1)player.setTextureRect(sf::IntRect(dashing*100,58.5*19.5,100,80));

        if(dashear.asSeconds()>=0.20)
        {
          dashing++;
          relojdash.restart();
        }
        if(dashing==1 & vida >=1)soundDash.play();
        if(dashing==4)
        {
            dashing=0;
            dash=0;
            quieto=1;
        }

     }else {dashing=0;}
     ///FIN ANIMACION DASH
     ///ANIMACION VIDA
     if(vida<=100) animacionvida=0;
     if(vida<= 66) animacionvida=1;
     if(vida<= 33) animacionvida=2;
     if(vida<=  0) animacionvida=3;
     spVida1.setTextureRect(sf::IntRect(animacionvida*100 , 60*0 , 100 , 100));


}
///MOVIMIENTOS Y ANIMACIONES JUGADOR 2
void Jugador::updateMoveSet2(){
    if (sf::Joystick::isConnected(0)){
		// check how many buttons joystick number 0 has
		unsigned int buttonCount = sf::Joystick::getButtonCount(0);

		// check if joystick number 0 has a Z axis
		bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

		//std::cout << "Button count: " << buttonCount << std::endl;
		//std::cout << "Has a z-axis: " << hasZ << std::endl;
	}
///------------------------------------------------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------------------------------------------------
     TiempoNulo.Zero;
     sf::Time caminar = relojcaminar.getElapsedTime(); //ANIMACION CAMINAR PJ1 Y 2
     sf::Time estatico = relojquieto.getElapsedTime(); //ANIMACION ESTATICA PJ1 Y 2
     sf::Time dashear = relojdash.getElapsedTime();//ANIMACION DASH PJ1 Y PJ2
     sf::Time duraciondash = relojduraciondash.getElapsedTime();//DURACION DASH PJ1 Y PJ2
     sf::Time getsuga = relojgetsuga.getElapsedTime();//ANIMACION ATAQUE GETSUGA PJ2
     sf::Time timinggetsuga = relojtiminggetsu.getElapsedTime();//COOLDOW GETSUGA PJ2
     sf::Time recorridogetsu = relojrecorridogetsu.getElapsedTime();//RECORRIDO GETSUGA PJ2
     sf::Time animaciongetsu = relojanimaciongetsu.getElapsedTime(); //ANIMACION OBJETO GETSUGA PJ2
     sf::Time espada = relojespada.getElapsedTime();//ANIMACION ATAQUE ESPADA PJ2
     sf::Time timingespada = relojtimingespada.getElapsedTime();//COOLDOWN ESPADAZO PJ2
     sf::Time dark = relojdark.getElapsedTime();//ANIMACION ATAQUE OSCURO PJ2
     sf::Time timingdark = relojtimingdark.getElapsedTime();//COOLDOWN ATAQUE OSCURO PJ2
     sf::Time darkrecorrido = relojduraciondark.getElapsedTime();//DURACION ATAQUE OSCURO PJ2
     sf::Time darkanimacion = relojanimaciondark.getElapsedTime();//ANIMACION OBJETO ATAQUE OSCURO PJ2
     sf::Time piso = relojpiso.getElapsedTime();//ANIMACION ATAQUE OSCURO PJ2
     sf::Time pisotiming = relojtimingpiso.getElapsedTime();//COOLDOWN ATAQUE OSCURO PJ2
     sf::Time pisoduracion = relojduracionpiso.getElapsedTime();//DURACION ATAQUE OSCURO PJ2
     sf::Time pisoanimacion = relojanimacionpiso.getElapsedTime();//ANIMACION OBJETO ATAQUE OSCURO PJ2
      ///LIMITE VIDA
     if(vida>=100) vida = 100;
     ///MOVIMIENTO PROYECTILES
     spGetsuga.move(2,0);///PJ2
     spGetsuga2.move(-2,0);///PJ2
    ///posicionar sprites
    sf::Vector2f player2pos = spPJ2.getPosition();
    ///LIMITACION PJ2
    ///NIVEL 1
   if(nivel2==0){
    if(player2pos.y > 430) player2pos.y = 430;
    if(player2pos.y < 259) player2pos.y = 259;
    if(vida>=1 & Bossfight==1) {
    if(player2pos.x <8005) player2pos.x= 8005;
    if(player2pos.x >9195) player2pos.x =9195;}
    else if(vida >=1 & Bossfight==0 ){
    if(player2pos.x >9650) player2pos.x =9650;}
    }
    if(vida>=0){if(player2pos.x <-48) player2pos.x = -48;}
    ///NIVEL 2
    if(nivel2==1){
    if(player2pos.y > 2680) player2pos.y = 2680;
    if(player2pos.y < 2503) player2pos.y = 2503;
    if(Bossfight2==1 & vida>=1){
    if(player2pos.x <8015) player2pos.x= 8015;
    if(player2pos.x >9195) player2pos.x =9195;
    }
    else if(vida >=1 & Bossfight2==0 ){
    if(player2pos.x >9650) player2pos.x =9650;}
    }
    spPJ2.setPosition(player2pos);
    ///HUD PJ2 VIDA
    spVida2.setPosition(player2pos.x+45 , player2pos.y -19);
    VidaPlayer2.setPosition(player2pos.x+65 , player2pos.y-25);
    VidaPlayer2.setFont(Fuente);
    stringstream tmp;
    tmp << ""<<int(vida);
    VidaPlayer2.setScale(0.45,0.45);
    VidaPlayer2.setString(tmp.str());
    VidaPlayer2.setColor(sf::Color::White);
    ///SECCION JUGADOR 2
    ///SECCION MOVIMIENTOS PJ2
    ///DERECHA PJ2
/// ----------------------------MOVIMIENTO JOYSTICK ----------------------------------------------------------------------------------------
 speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
if (speed.x > 15.f || speed.x < -15.f || speed.y > 15.f || speed.y < -15.f)spPJ2.move(speed.x*TimePerFrame.asSeconds(),speed.y*TimePerFrame.asSeconds());

    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::D)*/ speed.x > 15.f)
    {
     //spPJ2.move(speedpj2,0);
     spPJ2.setTextureRect(sf::IntRect(walk*101,90*0,99,80));/// 43 es ancho , 52 es altura.
     quieto=0;
     derecha = 1;
     izquierda=0;
      abajo=0;
     arriba=0;
    }
    ///IZQUIERDA PJ2
     else if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::A)*/ speed.x < -15.f)
    {
     //spPJ2.move(-speedpj2,0);
     spPJ2.setTextureRect(sf::IntRect(walk*101.5,60*1.23,99,80));/// 41 es ancho , 60 es altura.
     quieto=0;
     izquierda = 1;
     derecha=0;
      abajo=0;
     arriba=0;
    }
    else
    {
     if(derecha == 1)   spPJ2.setTextureRect(sf::IntRect(parado*100,80*1.8,100,90));
     if (izquierda == 1)spPJ2.setTextureRect(sf::IntRect(parado*100,77*3,95,90));
     quieto=1;
    }
    ///ABAJO PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::S)*/ speed.y > 15.f )
    {
     //spPJ2.move(0,speedpj2);
     arriba=0;
      abajo=1;
     if (izquierda == 1) spPJ2.setTextureRect(sf::IntRect(walk*101.5,60*1.23,99,80));
     if (derecha == 1) spPJ2.setTextureRect(sf::IntRect(walk*101,90*0,99,80));
    }
    ///ARRIBA PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::W)*/ speed.y < -15.f)
    {
     //spPJ2.move(0,-speedpj2);
     arriba=1;
      abajo=0;
     if (izquierda == 1) spPJ2.setTextureRect(sf::IntRect(walk*101.5,60*1.23,99,80));
     if (derecha == 1) spPJ2.setTextureRect(sf::IntRect(walk*101,90*0,99,80));

    }

    ///SECCION ATAQUES PJ2
    ///ATAQUE GETSUGA PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::J)*/ sf::Joystick::isButtonPressed(0, 1))
    {
      timingdisparop2++;
    if(timingdisparop2<50){
     disparando2=1;
    }

    }
    else {quieto = 1;}
    if(timinggetsuga.asSeconds()>=2){
      relojtiminggetsu.restart();
      timingdisparop2=0;
    }
    ///FIN ATAQUE GETSUGA PJ2
    ///ATAQUE DE ESPADA PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::U)*/sf::Joystick::isButtonPressed(0, 0))
    {
        timinggirop2++;
        if(timinggirop2<50)
        {
            girando2=1;
        }
    }else {quieto = 1;}
    if(timingespada.asSeconds()>=1){
        relojtimingespada.restart();
        timinggirop2=0;
    }
    ///FIN ATAQUE DE ESPADA PJ2
    ///ATAQUE OSCURO PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::K)*/sf::Joystick::isButtonPressed(0, 2))
    {
        timingpiniap2++;
        if(timingpiniap2<50)
        {
            pegando2=1;
        }
    }else {quieto = 1;}
    if(timingdark.asSeconds()>=3){
        relojtimingdark.restart();
        timingpiniap2=0;
    }
    ///FIN ATAQUE OSCURO PJ2
    ///ATAQUE PISO PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::I)*/sf::Joystick::isButtonPressed(0, 3))
    {
        timingpiso++;
        if(timingpiso<50)
        {
            pisando=1;
        }
    }else {quieto = 1;}
    if(pisotiming.asSeconds()>=4){
       relojtimingpiso.restart();
        timingpiso=0;
    }
    ///FIN ATAQUE PISO PJ2
    ///MOVIMIENTO DASH PJ2
    if(/*sf::Keyboard::isKeyPressed(sf::Keyboard::L)*/sf::Joystick::isButtonPressed(0, 5)) ///IBA EL 0,5
    {
        timingdash2++;
        if(timingdash2<50)
        {
            dash2=1;
        }
    }else {quieto = 1;}
    if(duraciondash.asSeconds()>= 0.98){
        relojduraciondash.restart();
        timingdash2=0;

    }else quieto=1;

///FIN SECCION ATAQUES PJ2
///SECCION ANIMACIONES PJ2.

    ///ANIMACION PJ2 MOVIMIENTO
   if(caminar.asSeconds()>= 0.12){
        walk ++;
        relojcaminar.restart();
    }
    if(walk == 7){
        walk=1;
    }
    ///FIN ANIMACION PJ2 MOVIMIENTO
    ///ANIMACION ESTATICA PJ2
    if(quieto==1)
        {
       if(estatico.asSeconds()>=0.4)
       {
        parado++;
        relojquieto.restart();
       }
    if(parado==3)
        {
        parado=1;
        }
        }
       ///FIN ANIMACION ESTATICA PJ2
       ///ANIMACION GETSUGA TENSHOU PJ2
        if(disparando2==1)
        {
        dash2=0;
        speedpj2=0;
        relojtiminggetsu.restart();
        relojrecorridogetsu.restart();
        if (derecha==1) spPJ2.setTextureRect(sf::IntRect(disparar2*150,71*4.6,130,90));
        if (izquierda==1) spPJ2.setTextureRect(sf::IntRect(disparar2*150,71.5*5.85,130,90));
        if(getsuga.asSeconds()>=0.18)
       {
        relojgetsuga.restart();
        disparar2++;
       }
       if(disparar2==1 & vida >=1)soundGetsuga.play();
    if(disparar2==3)
    {
        if (derecha == 1 )spGetsuga.setPosition(player2pos.x+50, player2pos.y-20);
        if (izquierda == 1 )spGetsuga2.setPosition(player2pos.x+20, player2pos.y-30);
        disparar2=0;
        disparando2=0;
        quieto=1;

    }
       }else{disparar2=0 , speedpj2=0.95;}
       ///FUNCION RECORRIDO GETSUGA PJ2
          if(recorridogetsu.asSeconds()>=1.7)
          {
           spGetsuga.setPosition(9999,9999);
           spGetsuga2.setPosition(9999,9999);
          }
       ///FIN ANIMACION GETSUGA TENSHOU PJ2
       ///ANIMACION ESPADAZO PJ2
        if(girando2==1)
        {
        if(derecha == 1) spPJ2.setTextureRect(sf::IntRect(girar2*157,67*7.37,150,80));
        if(izquierda == 1) spPJ2.setTextureRect(sf::IntRect(girar2*157,68*8.55,150,80));
        if(espada.asSeconds()>=0.08)
       {
        girar2++;
        relojespada.restart();
       }
       if(girar2==1 & vida >=1 & dash2==0 )soundEspadaso.play();
    if(girar2==7)
    {
        girar2=0;
        girando2=0;
        quieto=1;

    }
       }else{girar2=0;}
       ///FIN ANIMACION ATAQUE ESPADAZO PJ2
       ///ANIMACION ATAQUE OSCURO PJ2
       if(pegando2==1)
        {
        dash2=0;
        relojduraciondark.restart();
        if(derecha==1)spPJ2.setTextureRect(sf::IntRect(pegar2*150,67*9.9,140,80));//ir probando
        if(izquierda==1)spPJ2.setTextureRect(sf::IntRect(pegar2*150,68.8*10.8,140,70));
        if(dark.asSeconds()>=0.08)
       {
        pegar2++;
       relojdark.restart();
       }
       if(pegar2==1 & vida >=1 )soundAirEspadas.play();
    if(pegar2==6)
    {
        pegar2=0;
        pegando2=0;
        quieto=1;
        if(derecha == 1) spDark.setPosition(player2pos.x+150 , player2pos.y);
        if(izquierda == 1) spDark.setPosition(player2pos.x-150 , player2pos.y);
    }
    }
     ///FUNCION DURACION DARK PJ2
          if(darkrecorrido.asSeconds()>=1.5)
          {
           spDark.setPosition(9999,9999);
          }
   ///FIN ANIMACION ATAQUE OSCURO PJ2
   ///ANIMACION ATAQUE PISO PJ2
   if(pisando==1)
        {
        dash2=0;
        speedpj2=0;
        setTiempo(TiempoNulo);
        relojduracionpiso.restart();
        if(derecha==1)spPJ2.setTextureRect(sf::IntRect(pisar*150,66.8*12.35,140,80));//ir probando
        if(izquierda==1)spPJ2.setTextureRect(sf::IntRect(pisar*155,66.4*13.8,140,70));
        if(piso.asSeconds()>=0.08)
       {
        pisar++;
        relojpiso.restart();
       }
    if(pisar==1 & vida >=1 )soundFuegoNegro.play();
    if(pisar==7)
    {
        pisar=0;
        pisando=0;
        quieto=1;
       if(derecha==1) spDark2.setPosition(player2pos.x+100 , player2pos.y+50);
       if(izquierda==1) spDark2.setPosition(player2pos.x-80 , player2pos.y+50);
    }

       }else speedpj2=0.95;
       if(pisando!=1)setTiempo(TiempoDevuelto);
    ///FUNCION DURACION PISO PJ2
          if(pisoduracion.asSeconds()>=2)
          {
           spDark2.setPosition(9999,9999);
          }
    ///FIN ANIMACION ATAQUE PISO PJ2
    ///ANIMACION DASH PJ2
     if(dash2==1)
        {
            girando2=0;
        if(derecha==1)spPJ2.move(1,0);
        if(izquierda==1)spPJ2.move(-1,0);
        if(derecha==1)spPJ2.setTextureRect(sf::IntRect(dashing2*150,65.7*15.2,140,80));
        if(izquierda==1)spPJ2.setTextureRect(sf::IntRect(dashing2*150,65.7*16.5,140,80));
        if(dashear.asSeconds()>=0.20)
        {
          dashing2++;
          relojdash.restart();
        }
        if(dashing2==1 & vida>=1)soundDash2.play();
        if(dashing2==4)
        {
            dashing2=0;
            dash2=0;
            quieto=1;
        }

     }else {dashing2=0;}

    ///FIN ANIMACION DASH PJ2
    ///ANIMACION PROYECTILES PJ2
    ///ANIMACION GETSUGA PJ2
     spGetsuga.setTextureRect(sf::IntRect(animaciongetsuga*130,65*0,100,150));
     spGetsuga2.setTextureRect(sf::IntRect(animaciongetsuga*130,66*0,100,150));
    if(animaciongetsu.asSeconds()>=0.3)
    {
        animaciongetsuga++;
        relojanimaciongetsu.restart();
    }
    if(animaciongetsuga==2)
    {
        animaciongetsuga=0;
    }
    ///ANIMACION DARK PJ2
    spDark.setTextureRect(sf::IntRect(animaciondark*150,66*0,150,150));
    if(darkanimacion.asSeconds()>=0.12)
    {
        animaciondark++;
        relojanimaciondark.restart();
    }
    if(animaciondark==3)
    {
        animaciondark=0;
    }
    ///ANIMACION PISO PJ2
     spDark2.setTextureRect(sf::IntRect(animaciondarkK*150,66*0,150,150));
    if(pisoanimacion.asSeconds()>=0.08)
    {
        animaciondarkK++;
        relojanimacionpiso.restart();
    }
    if(animaciondarkK==4)
    {
        animaciondarkK=0;
    }
   ///FIN ANIMACION PISO
   ///ANIMACION VIDA
    if(vida<=100) animacionvida=0;
    if(vida<= 66) animacionvida=1;
    if(vida<= 33) animacionvida=2;
    if(vida<=  0) animacionvida=3;
    spVida2.setTextureRect(sf::IntRect(animacionvida*100 , 60*0 , 100 , 100));

}


void Jugador::update(){
    posicionar_camara();
    if(player1==1){
    updateMoveSet1();
    }
    if(player2==1){
   updateMoveSet2();
    }
}


void Jugador::dibujar(sf::RenderWindow &w){
    ///dibujar sprite en la ventana
    ///PLAYER 1
    w.draw(spBala);
    w.draw(spBala2);
    w.draw(player);
    w.draw(spVida1);
    w.draw(VidaPlayer1);
    ///PLAYER 2
    w.draw(spPJ2);
    w.draw(spGetsuga);
    w.draw(spGetsuga2);
    w.draw(spDark);
    w.draw(spDark2);
    w.draw(spVida2);
    w.draw(VidaPlayer2);
    w.draw(Gameover);
    w.draw(Gamewin);

}
