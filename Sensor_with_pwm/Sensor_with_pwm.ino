#include "Sensor.h"
#include <PWM.h>
int32_t frequency1 = 440; // Establezca la Frecuencia en Hertz (HZ), se pueden operar frecuencias de 10Hz a 300kHz aprox
int32_t frequency2 = 493; 
int32_t frequency3 = 988;
int32_t frequency4 = 880;
int32_t frequency5 = 349;
int32_t frequency6 = 391;
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

//PINES- SENSORES ULTRASONIDO
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

  InitTimersSafe(); 

  //Establece la frecuencia para el pin especificado
  bool success = SetPinFrequencySafe(buzzer1, frequency1);
  bool success2 = SetPinFrequencySafe(buzzer2, frequency2);
  bool success3 = SetPinFrequencySafe(buzzer3, frequency3);
  bool success4 = SetPinFrequencySafe(buzzer4, frequency4);
  bool success5 = SetPinFrequencySafe(buzzer5, frequency5);
  bool success6 = SetPinFrequencySafe(buzzer6, frequency6);
  //SI LA FRECUENCIA DEL PIN SE CONFIGURO CORRECTAMENTE, ENCIENDA EL PIN 13.
  if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }
  //----Construct sensor class--
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
    pwmWrite(buzzer1, 127);
    }
    if(detectar2){
    pwmWrite(buzzer2, 127);
    }
    if(detectar3){
    pwmWrite(buzzer3, 127);
    }
    if(detectar4){
    pwmWrite(buzzer4, 127);
    }
    if(detectar5){
    pwmWrite(buzzer5, 127);
    }
    if(detectar6){
    pwmWrite(buzzer6, 127);
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
  delay(100);
}
