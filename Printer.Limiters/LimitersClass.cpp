#include <LimitersClass.h>



/**
*
*/
void LimitersClass::init()
{
  pinMode( LIMITER_START, INPUT );
  pinMode( LIMITER_FINISH, INPUT );
}



/**
*
*/
bool LimitersClass::isLimit( byte limit )
{
  
  if ( limit == 0 )
    if ( digitalRead( LIMITER_FINISH ) ) return true; else return false;

  if ( limit == 1 )
    if ( digitalRead( LIMITER_START ) ) return true; else return false;

}

