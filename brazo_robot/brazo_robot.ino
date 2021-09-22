
#include <Servo.h>

char dato;
Servo hombro, codo, muneca,pinzas, base;
int phombro, pcodo, pmuneca,ppinzas, pbase, contador =0 ;


void setup() {
hombro.attach(6);
codo.attach(5);
muneca.attach(11);
pinzas.attach(10);
base. attach(9);
Serial.begin (9600);
}

void loop() {
  if (contador==0){
    phombro=hombro.read();
    pcodo=codo.read();
    pmuneca=muneca.read();
    ppinzas=pinzas.read();
    pbase=base.read();

    //INITIAL POSITION 
    hombro.write(phombro);
    codo.write(pcodo);
    muneca.write(pmuneca);
    pinzas.write(ppinzas);
    base.write(pbase);
    contador++;
  }
  dato='x';
  dato=Serial.read();
  switch(dato){
  case 'A'://HOMBRO DERECHA
{
 while( Serial.read()!='x'){
  if(phombro>=175)
  phombro=175;
  if(phombro<=180&&phombro>=0)
  {
    phombro++;
    hombro.write(phombro);
    delay(15);
  }
 }
 break;
}
case 'a'://LEFT SHOULDER
{
while(Serial.read()!='x'){
  if (phombro<=5)
  phombro=5;
  if (phombro<=180&&phombro>=0){
    phombro++;
    hombro.write(phombro);
    delay(159);
    }
  }
  break;}
  case 'C': //ELBOW UP
  {
    if(pcodo=175)
    pcodo=175;
    while(Serial.read()!='x'){
      if(pcodo<=180&&pcodo>=0){
        pcodo++;
        codo.write(pcodo);
        delay(15);}}
        break ;
      }
      case 'c': //ELBOW DOWN
      { 
        if (pcodo<=5)
        pcodo=5;
        while(Serial.read()!='x'){
          if (pcodo<=180 && pcodo>=0)
          {
            pcodo++;
            codo.write(pcodo);
            delay(15);
          }}
          break;
          }
          case 'I': //WRIST UP 
          {
            if (pmuneca=170)
            pmuneca=170;
            while(Serial.read()!='x'){
              if (pmuneca <=180&&pmuneca>=0){
                pmuneca++;
                muneca.write(pmuneca);
                delay(15);}}
                break;
          }
          case 'i': //WRIST DOWN
          {
          if (pmuneca<=10)
          pmuneca=10;
          while(Serial.read()!='x'){
            if(pmuneca<=180&&pmuneca>=0){
              pmuneca--;
              muneca.write(pmuneca);
              delay(15); }}
              break;}

           case 'P'://CLAMP UP
              {
           if (ppinzas>=165)
                ppinzas=165;
                while(Serial.read()!='x'){
                  if(ppinzas<=180 && ppinzas>=0)
              {
                ppinzas++;
                pinzas.write(ppinzas);
                delay(15);}}
                break; }
            case 'p': //CLOSED CLAMP 
              {
                if (ppinzas<=15)
                ppinzas=15;
                while(Serial.read()!='x'){
                  if (ppinzas<=180&&ppinzas>=0){
                    ppinzas--;
                    pinzas.write(ppinzas);
                    delay(15);}}
                    break;}
                    
                    case 'B'://BASE LEFT {
                    if(pbase=175)
                    pbase=175;
                    while(Serial.read()!='x')
                    {
                      if(pbase<=180 && pbase>=0)
                      {
                        pbase++;
                        base.write(pbase);
                        delay(15);
                      }}
                      break;
                    case 'b' : //BASE RIGHT   
                    {
                     if (pbase<=5)
                     pbase=5;
                     while(Serial.read()!='x'){
                       if (pbase <=100 && pbase>=0)
    {
                          pbase--;
                          base.write(pbase);
                          delay(15); }}
                           break;
                  
                    }}}
