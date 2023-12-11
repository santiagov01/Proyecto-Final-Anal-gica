#include "Sensor.h"

//-----Sensor pointer-
Sensor * s1;
Sensor * s2;
Sensor * s3;
Sensor * s4;
Sensor * s5;
Sensor * s6;
//Pines de Buzzer (tienen que ser salidas PWM)
#define buzzer1 2
#define buzzer2 3
#define buzzer3 4
#define buzzer4 5
#define buzzer5 6
#define buzzer6 44

//CONEXIONES SENSORES ULTRASONIDO
#define Pecho1 12
#define Ptrig1 13

#define Pecho2 10
#define Ptrig2 11

#define Pecho3 8
#define Ptrig3 9

#define Pecho4 6
#define Ptrig4 7  

#define Pecho5 23
#define Ptrig5 22 

#define Pecho6 25
#define Ptrig6 24 

void setup() {

  //Sensor(int pinTrig, int pinEcho)
  s1 = new Sensor(Ptrig1,Pecho1);
  s2 = new Sensor(Ptrig2,Pecho2);
  s3 = new Sensor(Ptrig3,Pecho3);
  s4 = new Sensor(Ptrig4,Pecho4);
  s5 = new Sensor(Ptrig5,Pecho5);
  s6 = new Sensor(Ptrig6,Pecho6);
  

  //Serial.begin(115200); 
  Serial.begin(9600); 
 
}

void loop() {
  //----Calculate the distance----
    unsigned long dist1 = s1->dist();
    unsigned long dist2 = s2->dist();
    unsigned long dist3 = s3->dist();  
    unsigned long dist4 = s4->dist();
    unsigned long dist5 = s5->dist();
    unsigned long dist6 = s6->dist();

    bool detectar1 = s1->detection();
    bool detectar2 = s2->detection();
    bool detectar3 = s3->detection();
    bool detectar4 = s4->detection();
    bool detectar5 = s3->detection();
    bool detectar6 = s4->detection();

    if(detectar1){
    tone(buzzer1, 880);
    }else if(detectar2){
    tone(buzzer2, 988);
    }else if(detectar2){
    tone(buzzer3, 261);
    }else if(detectar3){
    tone(buzzer4, 293);
    }else if(detectar4){
    tone(buzzer5, 349);
    }else if(detectar5){
    tone(buzzer6, 391);
    }

  
//----Pass the data as CSV to the Serial Port----
  Serial.print(dist1);
  Serial.print(",");
  Serial.print(dist2);
  Serial.print(",");
  Serial.print(dist3);
  Serial.print(",");
  Serial.print(dist4);
  // Serial.print(",");
  // Serial.print(dist5);
  // Serial.print(",");
  // Serial.print(dist6);
 
  
  Serial.print("\n");
  delay(10);
}
