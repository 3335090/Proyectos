#include <Servo.h>
Servo miservo;

const int LEDPin = 13;
const int LDRPin = A0;
const int threshold = 100;
int pos;
int puenteHblue = 11;
int puenteHgreen = 5;
int yellow = 4;
int white = 7;
int blue = 8;
int red = 2;
unsigned long pulso;
float distance;
float right;
float left;
int trig = 12;
int echo = 10;
int duration = 0;
void setup() {
  pinMode(LEDPin, OUTPUT);
   pinMode(LDRPin, INPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  miservo.attach(9);
  Serial.begin(9600);
  pinMode(puenteHblue, OUTPUT);
  pinMode(puenteHgreen, OUTPUT);
  pinMode (yellow , OUTPUT);
  pinMode (white, OUTPUT);
  pinMode (blue, OUTPUT);
  pinMode (red, OUTPUT);
  digitalWrite(puenteHblue, LOW);
  digitalWrite(puenteHgreen, LOW);
}

void loop() 
{
int input = analogRead(LDRPin);
   if (input > threshold) {
      digitalWrite(LEDPin, HIGH);
   }
   else {
      digitalWrite(LEDPin, LOW);
   }
   
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);

  duration = pulseIn( echo,HIGH);
  distance = (duration/2)/28.5;
  Serial.println(distance);
  delay(100);

  
if (distance < 35)

  {
  digitalWrite(yellow, LOW);
  digitalWrite(white, LOW);
  digitalWrite(puenteHblue, LOW);
  digitalWrite(puenteHgreen, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red,LOW );
  
  miservo.write(pos = 0);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duration =pulseIn(echo,HIGH);
  right = (duration/2)/28.5;
  delay(1000 + right);
  Serial.print("derecha =");
  Serial.print(right);
    
  miservo.write(pos = 180);
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duration =pulseIn(echo,HIGH);
  left = (duration/2)/28.5;
  delay(1000 + left);
  Serial.print(", izquierda =");
  Serial.println(left);
  
  miservo.write(pos = 90);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duration =pulseIn(echo,HIGH);
  distance = (duration/2)/28.5;
  delay(1000); 
  
  digitalWrite(yellow, HIGH);
  digitalWrite(white, LOW);
  digitalWrite(puenteHblue, HIGH);
  digitalWrite(puenteHgreen, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red,LOW );
  delay(400);

if ( right > left)
{
  digitalWrite(yellow, HIGH);
  digitalWrite(white, LOW);
  digitalWrite(puenteHblue, HIGH);
  digitalWrite(puenteHgreen,HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(400); 
  }
else 
{ 
  digitalWrite(yellow, LOW);
  digitalWrite(white, HIGH);
  digitalWrite(puenteHblue, HIGH);
  digitalWrite(puenteHgreen,HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  delay(400); 
  }   
  }
else 
  {
  miservo.write(pos = 90);  
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duration =pulseIn(echo,HIGH);
  distance = (duration/2)/28.5;  
  digitalWrite(yellow, LOW);
  digitalWrite(white, HIGH);
  digitalWrite(puenteHblue, HIGH);
  digitalWrite(puenteHgreen,HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red,HIGH);
  delay(1000); 
  }
  
  
  
  // put your main code here, to run repeatedly:

}
