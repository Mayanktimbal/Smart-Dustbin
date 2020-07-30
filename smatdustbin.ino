#include <Servo.h>

int heighttrigpin =2;
int heightechopin =3;
long heightduration;
int heightdistance;
int agaltrigpin =7;
int agalechopin =6;
long agalduration;
int agaldistance;

int servopin=13;
Servo servo;


void setup() {
  pinMode(heighttrigpin,OUTPUT);
 pinMode(heightechopin,INPUT);
  pinMode(agaltrigpin,OUTPUT);
 pinMode(agalechopin,INPUT);
 servo.attach(servopin);
 Serial.begin(9600);

}

void loop() {

  digitalWrite(heighttrigpin,LOW);
delayMicroseconds(2);
digitalWrite(heightechopin,HIGH);
delayMicroseconds(10);
digitalWrite(heighttrigpin,LOW);
heightduration=pulseIn(heightechopin,HIGH);

heightdistance = heightduration*0.034/2;
Serial.print(" height:  ");
Serial.println(heightdistance);
Serial.println(heightduration);


digitalWrite(agaltrigpin,LOW);
delayMicroseconds(2);
digitalWrite(agalechopin,HIGH);
delayMicroseconds(10);
digitalWrite(agaltrigpin,LOW);
agalduration=pulseIn(heightechopin,HIGH);
agaldistance=agalduration*0.034/2;
Serial.print(" agal nu distance: ");
Serial.println(agaldistance);

if(agaldistance<=12)
{
   servo.write(0);
 delay(1000);
 
 servo.write(180);
 delay(5000);

  servo.write(0);
 delay(1000);
  
  
  }


}
