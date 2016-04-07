#include <BtnsClass.h>


void BtnsClass::init()
{

  pinMode( BTN_1, INPUT );
  pinMode( BTN_2, INPUT );
  pinMode( BTN_3, INPUT );
  pinMode( BTN_4, INPUT );
  
}

bool BtnsClass::_isPress( byte btn, int cnt )
{

  if ( btn == 1 ) {
    if ( !digitalRead( BTN_1 ) ){
      if ( _btn_1 < cnt )_btn_1++;
      if ( _btn_1 >= cnt ) return true; else return false;
    } else { _btn_1 = 0; return false; }
  } 

  if ( btn == 2 ) {
    if ( !digitalRead( BTN_2 ) ){
      if ( _btn_2 < cnt )_btn_2++;
      if ( _btn_2 >= cnt ) return true; else return false;
    } else { _btn_2 = 0; return false; }
  } 

  if ( btn == 3 ) {
    if ( !digitalRead( BTN_3 ) ){
      if ( _btn_3 < cnt )_btn_3++;
      if ( _btn_3 >= cnt ) return true; else return false;
    } else { _btn_3 = 0; return false; }
  } 

  if ( btn == 4 ) {
    if ( !digitalRead( BTN_4 ) ){
      if ( _btn_4 < cnt )_btn_4++;
      if ( _btn_4 >= cnt ) return true; else return false;
    } else { _btn_4 = 0; return false; }
  } 

}

bool BtnsClass::isPress( byte btn, int cnt )
{
  _isPress( btn, cnt );
}


