#include <MPU6050.h>
#include "I2Cdev.h"
MPU6050 mpu;
int i;
int16_t ax, ay, az, gx, gy, gz;

int adelante = 3;
int izquierda = 4;
int atras = 5;
int derecha = 6;

const int numReadings= 15;
int readings[numReadings];
int index = 0;
int total = 0;
float averageX =0;

const int numReadings2= 15;
int readings2[numReadings2];
int index2 = 0;
int total2 = 0;
float averageY =0;
 
void setup() {
  Serial.begin (9600) ; 

  for (int thisReading=0 ; thisReading < numReadings; thisReading++)
  readings[thisReading]=0;

  for (int thisReading2=0 ; thisReading2 < numReadings2; thisReading2++)
  readings2[thisReading2]=0;

  mpu.initialize();
 
  if (!mpu.testConnection()) 
 while (1); }

void loop(){

  for (i=3;i<6;i++){
    pinMode (i,OUTPUT);}
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
ax= -(ax/1000);
ay= (ay/1000);

total = total-readings[index];
readings[index] = ax;
total= total+readings[index];
index=index+1;

if (index >= numReadings){

index = 0;
averageX = total/numReadings;
total2 = total2-readings2[index2];
readings[index2]=ay;
total2=total2+readings2[index2];
index2=index2+1;}

if (index2 >= numReadings2)
index = 0;
averageY = total2 / numReadings2;
Serial.print (ax);
Serial.print(",");
Serial.print(ay);
Serial.print(",");
Serial.println(az); 
Serial.print(",");


Serial.print("Eje X:   ");
Serial.print(averageX);
Serial.print("__");
Serial.print("Eje Y:   ");
Serial.print(averageY);
//"X"
if (averageX <= -1)
{
digitalWrite(adelante,HIGH);
digitalWrite(atras,LOW);
digitalWrite(izquierda,LOW);
digitalWrite(derecha,LOW);
delay(5000);}

if (averageX >=5) {

  digitalWrite(adelante,LOW);
digitalWrite(atras,HIGH);
digitalWrite(izquierda,LOW);
digitalWrite(derecha,LOW);
delay(5000);}


if (averageY <= -5) {

  digitalWrite(adelante,LOW);
digitalWrite(atras,LOW);
digitalWrite(izquierda,HIGH);
digitalWrite(derecha,LOW);
delay(5000);}

if (averageY >=1) {

  digitalWrite(adelante,LOW);
digitalWrite(atras,LOW);
digitalWrite(izquierda,LOW);
digitalWrite(derecha,HIGH);
delay(2000);}

if (averageX >=  0 && averageX <=0 && averageY >=0 && averageY <= 0) {

  digitalWrite(adelante,LOW);
digitalWrite(atras,LOW);
digitalWrite(izquierda,LOW);
digitalWrite(derecha,LOW);
delay(1000);} }
