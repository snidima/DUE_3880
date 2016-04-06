#include <BtnsClass.h>



/**
*
*/
void BtnsClass::init()
{

  pinMode( BTN_1, INPUT );
  pinMode( BTN_2, INPUT );
  pinMode( BTN_3, INPUT );
  pinMode( BTN_4, INPUT );
  
}



/**
*
*/
bool BtnsClass::isPressed( byte btn )
{
  
  if ( btn == 1 )
    if ( !digitalRead( BTN_1 ) ) return true; else return false;

  if ( btn == 2 )
    if ( !digitalRead( BTN_2 ) ) return true; else return false;

  if ( btn == 3 )
    if ( !digitalRead( BTN_3 ) ) return true; else return false;

  if ( btn == 4 )
    if ( !digitalRead( BTN_4 ) ) return true; else return false;

}