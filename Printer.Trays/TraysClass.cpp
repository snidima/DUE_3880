#include <TraysClass.h>

void TraysClass::init(){
  changeTray();
  _zero = 9036;
}

void TraysClass::changeTray(){

  if ( _current_tray >= TRAYS_COUNT ) _current_tray = 0;

  if ( _current_tray == 0 ) {
    leds.off( RGB_RED );
    leds.on( RGB_GREEN );
    leds.on( RGB_BLUE );
    _zero = 9036;
  }
  if ( _current_tray == 1 ) {
    leds.off( RGB_GREEN );
    leds.on( RGB_RED );
    leds.on( RGB_BLUE );
    _zero = 24000;
  }

}


void TraysClass::allowsToChange(){

  if ( btns.isPress( BTN5, SHORT ) )
    _btn = 1;


  if ( !btns.isPress( BTN5, 0 ) )
    if ( _btn == 1 ){
      _btn = 0;
      _current_tray++;
      changeTray();
    }
      
}

int TraysClass::getZero(){
  return _zero;
}