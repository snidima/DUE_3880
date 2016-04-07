#include <EncoderHelperClass.h>


void EncoderHelperClass::init()
{
  
  encoder = new Encoder( ENCODER_A, ENCODER_B );

  _start_print_cnt = 0;
  _oldPosition = 0;
  _step_cnt = 0;
}



bool EncoderHelperClass::isMove()
{
  long newPosition = encoder->read();
  if (newPosition != _oldPosition) {
    _oldPosition = newPosition;
    return true;
  } else return false;
}

bool EncoderHelperClass::isStartPrinting()
{

  if ( isMove() ) _start_print_cnt++;
  if ( _start_print_cnt > 400 ) return true; else return false;

}

bool EncoderHelperClass::isStep()
{
  if ( isMove() ) {
    _step_cnt++;
    if ( isStepCalc() ) return true; else return false;
  } else return false;
}


bool EncoderHelperClass::isStepCalc()
{
  if ( _step_cnt >= 2159 ) _step_cnt = 0;
  long cnt = _step_cnt * 100000;
  if ( (cnt % 928125) <= 100000) return true; else return false;
}