#include "Sensor.h"

//-----Sensor pointer-
Sensor * s1;
Sensor * s2;
Sensor * s3;
Sensor * s4;
// Sensor * s5;
// Sensor * s6;

#define buzzer1 2
#define buzzer2 3

#define Pecho1 12
#define Ptrig1 13
#define Pecho2 10
#define Ptrig2 11
#define Pecho3 8
#define Ptrig3 9
#define Pecho4 6
#define Ptrig4 7  
void setup() {

  //Sensor(int pinTrig, int pinEcho)
  s1 = new Sensor(Ptrig1,Pecho1);
  s2 = new Sensor(Ptrig2,Pecho2);
  s3 = new Sensor(Ptrig3,Pecho3);
  s4 = new Sensor(Ptrig4,Pecho4);
  // s5 = new Sensor(13,14);
  // s6 = new Sensor(15,16);
  

  //Serial.begin(115200); 
  Serial.begin(9600); 
 
}

void loop() {
  //----Calculate the distance----
   unsigned long dist1 = s1->dist();
   unsigned long dist2 = s2->dist();
   unsigned long dist3 = s3->dist();  
   unsigned long dist4 = s4->dist();
  //  unsigned long dist5 = s5->dist();
  //  unsigned long dist6 = s6->dist();
  bool detectar1 = s1->detection();
  bool detectar2 = s2->detection();
  bool detectar3 = s3->detection();
  bool detectar4 = s4->detection();
   if(detectar1){
    tone(buzzer1, 880);
   }
   else if(detectar2){
    tone(buzzer2, 988);
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
