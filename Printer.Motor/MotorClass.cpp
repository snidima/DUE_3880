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
    digitalWrite( MOTOR_ENB, HIGH);
    digitalWrite( RELE_DRIVER, HIGH);
    delay(3000);
    digitalWrite( MOTOR_ENB, LOW);
    delay(3000);
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




bool MotorClass::move( bool dir )
{

  unsigned long currentMillis = micros();

  if ( currentMillis - _previousMillis_manual_move >= speed ) {
      _previousMillis_manual_move = currentMillis;

      _step__manual_state = !_step__manual_state;


      /***********/
      if ( ( dir == 0 ) && ( _dir_manual_state == 0 ) ){
        digitalWrite( MOTOR_DIR, LOW);
        _dir_manual_state = 1;
      }
      if ( ( dir == 1 ) && ( _dir_manual_state == 1 ) ){
        digitalWrite( MOTOR_DIR, HIGH);
        _dir_manual_state = 0;
      }
       /***********/

      if ( !_limiters_detected ){
        digitalWrite( MOTOR_STEP, _step__manual_state);
        if ( _step__manual_state ) return true; else return false;
      } else {

        if ( ( dir == 0 ) && ( _current_cnt != _table_cnt ) ) {
          digitalWrite( MOTOR_STEP, _step__manual_state);
          if ( _step__manual_state ) _current_cnt++;
        }

        if ( ( dir == 1 ) && ( _current_cnt != 0 ) ) {
          digitalWrite( MOTOR_STEP, _step__manual_state);
          if ( _step__manual_state ) _current_cnt--;
        }

      }

    } else return false;
}



bool MotorClass::EncoderMove( long newPosition )
{

  if ( newPosition < oldPosition ){
    oldPosition = newPosition;

    long cnt = oldPosition * 100000;
    if ( abs(cnt % 928125) <= 100000){

      if ( _dir_manual_state == 0 ){
        digitalWrite( MOTOR_DIR, LOW);
        _dir_manual_state = 1;
      }
      if ( _current_cnt < _table_cnt ) {
        _current_cnt++;
        digitalWrite( MOTOR_STEP, LOW);
        digitalWrite( MOTOR_STEP, HIGH);
 
      }

    }

  }



  if ( newPosition > oldPosition ){
    oldPosition = newPosition;

    long cnt = oldPosition * 100000;
    if ( abs(cnt % 928125) <= 100000){

      if ( _dir_manual_state == 1 ){
        digitalWrite( MOTOR_DIR, HIGH);
        _dir_manual_state = 0;
      }
      if ( _current_cnt > 0 ) {
        _current_cnt--;
        digitalWrite( MOTOR_STEP, LOW);
        digitalWrite( MOTOR_STEP, HIGH);
      }

    }

  }

}

bool MotorClass::moveToZero( int zero )
{

  if ( _current_cnt != zero ){

    if ( _current_cnt < zero )
      move( TO_START );

    if ( _current_cnt > zero )
      move( TO_FINISH );

    return false;

  } else return true;
  
}

