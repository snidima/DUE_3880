#include <UltrasonicHelperClass.h>


void UltrasonicHelperClass::init()
{

  pinMode( TRIG, OUTPUT );
  pinMode( ECHO, INPUT );
  
}



int UltrasonicHelperClass::getDistance()
{
  int duration, cm; 
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW); 
  duration = pulseIn(ECHO, HIGH); 
  cm = duration / 58;
  return cm;
}