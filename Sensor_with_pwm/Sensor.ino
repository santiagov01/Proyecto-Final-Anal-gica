#include "Sensor.h"
#include <PWM.h>
int32_t frequency1 = 440; // Establezca la Frecuencia en Hertz (HZ), se pueden operar frecuencias de 10Hz a 300kHz aprox
int32_t frequency2 = 493; 
//-----Sensor pointer-
Sensor * s1;
Sensor * s2;
Sensor * s3;
Sensor * s4;
// Sensor * s5;
// Sensor * s6;

#define buzzer1 2
#define buzzer2 3

void setup() {

  InitTimersSafe(); 

  //Establece la frecuencia para el pin especificado
  bool success = SetPinFrequencySafe(buzzer1, frequency1);
  bool success2 = SetPinFrequencySafe(buzzer2, frequency2);
  //SI LA FRECUENCIA DEL PIN SE CONFIGURO CORRECTAMENTE, ENCIENDA EL PIN 13.
  if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }
  //----Construct sensor class--
  s1 = new Sensor(12, 13);
  s2 = new Sensor(10,11);
  s3 = new Sensor(8,9);
  s4 = new Sensor(6,7);
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
   
   if(dist1 < 120 && dist1 > 0){
    pwmWrite(buzzer1, 127); //El segundo parámetro es para ajustar el duty. (0-255 si no estoy mal)
   }
   if(dist2<120 && dist2 > 0){
    pwmWrite(buzzer2, 127); //El segundo parámetro es para ajustar el duty.
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
