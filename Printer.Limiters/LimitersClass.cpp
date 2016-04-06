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
  
  if ( limit == 0 ) {
    if ( digitalRead( LIMITER_FINISH ) ) k++; else k = 0;
    if ( k >= 200 ) {
      k = 0;
      return true;
    } else return false;
  }


  if ( limit == 1 ) {
    if ( digitalRead( LIMITER_START ) ) j++; else j = 0;
    if ( j >= 200 ) {
      j = 0;
      return true;
    } else return false;
  }

}

