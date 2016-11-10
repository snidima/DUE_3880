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


bool MotorClass::moveOneStep()
{
  unsigned long currentMillis = micros();

  if ( currentMillis - _previousMillis_print_move >= 100 ) {
      _previousMillis_print_move = currentMillis;

      _one_step__manual_state = !_one_step__manual_state;

      if ( _dir_manual_state == 0 ){
        digitalWrite( MOTOR_DIR, LOW);
        _dir_manual_state = 1;
      }


        digitalWrite( MOTOR_STEP, _one_step__manual_state);

        
        if ( _one_step__manual_state ) { 

          _current_cnt++;  return true; 

        }
      

      

  } else return false;

}



int MotorClass::EncoderMove( long newPosition )
{

  if ( _current_cnt >= _table_cnt ) {
    oldPosition = 0;
    return 0;
  } else {

    bool go = false;
    
    if ( newPosition < oldPosition ) { oldPosition-=1; go = true; }

    if ( go ) {
      long cnt = oldPosition * 100000;
      if ( abs(cnt % 928125) <= 100000) steps+=1;
    }
    

    if ( steps > 0 ) 
      if ( moveOneStep() ) { steps-=1;return 1; }
      
    
    return 2;

  }
  


}



bool MotorClass::moveToZero( int zero )
{
	
	if ( zero == 0 ){
		
		if ( !limiters.isLimit( FINISH ) ){
			move( TO_FINISH );
			return false;
		} else return true;
		
	} else {
		if ( !limiters.isLimit( START ) ){
			move( TO_START );
			return false;
		} else return true;
	}

  
}

