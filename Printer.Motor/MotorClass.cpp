#include <MotorClass.h>



/**
*
*/
void MotorClass::init()
{

  pinMode( MOTOR_STEP, OUTPUT );
  pinMode( MOTOR_DIR, OUTPUT );
  pinMode( MOTOR_ENB, OUTPUT );
  pinMode( RELE_DRIVER, OUTPUT );
  digitalWrite( RELE_DRIVER, LOW);

}



/**
*
*/
void MotorClass::on()
{
  if ( _enb_state == false ){
    digitalWrite( RELE_DRIVER, HIGH);
    digitalWrite( MOTOR_ENB, LOW);
    _enb_state = !_enb_state;
  }
}



/**
*
*/
void MotorClass::off()
{
  if ( _enb_state == true ){
    digitalWrite( RELE_DRIVER, LOW);
    digitalWrite( MOTOR_ENB, HIGH);
    _enb_state = !_enb_state;
  }
}



/**
*
*/
void MotorClass::manualMove( bool dir )
{

  unsigned long currentMillis = micros();

  if ( currentMillis - _previousMillis_manual_move >= speed ) {
      _previousMillis_manual_move = currentMillis;
      _step__manual_state = !_step__manual_state;

      if ( ( dir == 0 ) && ( _dir_manual_state == 0 ) ){
        digitalWrite( MOTOR_DIR, LOW);
        _dir_manual_state = 1;
      }
      

      if ( ( dir == 1 ) && ( _dir_manual_state == 1 ) ){
        digitalWrite( MOTOR_DIR, HIGH);
        _dir_manual_state = 0;
      }

      start  = limiters.isLimit( START );
      finish = limiters.isLimit( FINISH );
        
      if ( ( ( dir == 0 ) && ( !start ) ) || ( ( dir == 1 ) && ( !finish ) ) )
        digitalWrite( MOTOR_STEP, _step__manual_state);

      

    }
}