#ifndef CONTINUAR_H_INCLUDED
#define CONTINUAR_H_INCLUDED
struct Continuar{
int continuar=0;
};
struct Dificultad{
int dificultad=2;
};

const char Ubicacion[] = "archivos/Guardado.dat";
const char Ubicacion2[] = "archivos/Dificultad.dat";

///CONTINUADO-DE-PARTIDA---------------------------------------------
int Guardar(){
Continuar reg;
FILE *p;
p=fopen(Ubicacion , "wb");
if(p==NULL){return -1;}
reg.continuar=1;
fwrite(&reg , sizeof reg , 1 ,p);
fclose(p);
return 0;
}

int Guardar2(){
Continuar reg;
FILE *p;
p=fopen(Ubicacion , "wb");
if(p==NULL){return -1;}
reg.continuar=0;
fwrite(&reg , sizeof reg , 1 ,p);
fclose(p);
return 0;
}

int Comprobar(){
Continuar reg;
FILE *p;
p=fopen(Ubicacion , "rb");
if(p==NULL){return -1;}
while (fread(&reg , sizeof reg , 1 ,p)==1){
if(reg.continuar==1){
return 1;
fclose(p);
}
}
fclose(p);
return 0;
}
///---------------------------------------------------------
///----------------DIFICULTAD------------------------------
int GuardarFacil(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "wb");
if(p==NULL){return -1;}
reg.dificultad=1;
fwrite(&reg , sizeof reg , 1 ,p);
fclose(p);
return 0;
}

int GuardarNormal(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "wb");
if(p==NULL){return -1;}
reg.dificultad=2;
fwrite(&reg , sizeof reg , 1 ,p);
fclose(p);
return 0;
}
int GuardarDificil(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "wb");
if(p==NULL){return -1;}
reg.dificultad=3;
fwrite(&reg , sizeof reg , 1 ,p);
fclose(p);
return 0;
}

int ComprobarFacil(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "rb");
if(p==NULL){return -1;}
while (fread(&reg , sizeof reg , 1 ,p)==1){
if(reg.dificultad==1){
return 1;
fclose(p);
}
}
fclose(p);
return 0;
}
int ComprobarNormal(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "rb");
if(p==NULL){return -1;}
while (fread(&reg , sizeof reg , 1 ,p)==1){
if(reg.dificultad==2){
return 1;
fclose(p);
}
}
fclose(p);
return 0;
}
int ComprobarDificil(){
Dificultad reg;
FILE *p;
p=fopen(Ubicacion2 , "rb");
if(p==NULL){return -1;}
while (fread(&reg , sizeof reg , 1 ,p)==1){
if(reg.dificultad==3){
return 1;
fclose(p);
}
}
fclose(p);
return 0;
}
#endif // CONTINUAR_H_INCLUDED
