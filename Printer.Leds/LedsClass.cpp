#include <LedsClass.h>
#include <Arduino.h>


/***************************************************/



/**
*
*/
void LedsClass::init()
{
	pinMode( LED_RED, OUTPUT );
	pinMode( LED_ORANGE, OUTPUT );
	pinMode( LED_BLUE, OUTPUT );
	pinMode( LED_GREEN, OUTPUT );
}



/**
*
*/
bool LedsClass::checkState( byte ledname, bool action )
{
	if ( action ){

		if ( ledname == 0 ) 
			if ( _red_state == false ) return true; else return false;
		if ( ledname == 1 ) 
			if ( _green_state == false ) return true; else return false;
		if ( ledname == 2 ) 
			if ( _blue_state == false ) return true; else return false;
		if ( ledname == 3 ) 
			if ( _orange_state == false ) return true; else return false;

	} else {

		if ( ledname == 0 ) 
			if ( _red_state == true ) return true; else return false;
		if ( ledname == 1 ) 
			if ( _green_state == true ) return true; else return false;
		if ( ledname == 2 ) 
			if ( _blue_state == true ) return true; else return false;
		if ( ledname == 3 ) 
			if ( _orange_state == true ) return true; else return false;

	}

}



/**
*
*/
void LedsClass::on( byte ledname )
{
	switch ( ledname ) {
    case 0:
    	if ( checkState( ledname, true ) ){
    		digitalWrite( LED_RED, LOW );
    		_red_state = !_red_state;
    	}
      break;
    case 1:
    	if ( checkState( ledname, true ) ){
    		digitalWrite( LED_GREEN, LOW );
    		_green_state = !_green_state;
    	}
      break;
    case 2:
    	if ( checkState( ledname, true ) ){
    		digitalWrite( LED_BLUE, LOW );
    		_blue_state = !_blue_state;
    	}
      break;
    case 3:
    	if ( checkState( ledname, true ) ){
    		digitalWrite( LED_ORANGE, LOW );
    		_orange_state = !_orange_state;
    	}
    	break;
  }
}



/**
*
*/
void LedsClass::off( byte ledname )
{
	switch ( ledname ) {
    case 0:
    	if ( checkState( ledname, false ) ){
    		digitalWrite( LED_RED, HIGH );
    		_red_state = !_red_state;
    	}
      break;
    case 1:
    	if ( checkState( ledname, false ) ){
    		digitalWrite( LED_GREEN, HIGH );
    		_green_state = !_green_state;
    	}
      break;
    case 2:
    	if ( checkState( ledname, false ) ){
    		digitalWrite( LED_BLUE, HIGH );
    		_blue_state = !_blue_state;
    	}
      break;
    case 3:
    	if ( checkState( ledname, false ) ){
    		digitalWrite( LED_ORANGE, HIGH );
    		_orange_state = !_orange_state;
    	}
    	break;
  }
}



/**
*
*/
void LedsClass::blinkOn( byte led, int interval )
{
	unsigned long currentMillis = millis();

	if ( led == 0 )
	  if (currentMillis - _previousMillis_red >= interval) {
	    _previousMillis_red = currentMillis;
	    _red_state = !_red_state;
	    digitalWrite( LED_RED, _red_state);
	  }

  if ( led == 1 )
	  if (currentMillis - _previousMillis_green >= interval) {
	    _previousMillis_green = currentMillis;
	    _green_state = !_green_state;
	    digitalWrite( LED_GREEN, _green_state);
	  }

  if ( led == 2 )
	  if (currentMillis - _previousMillis_blue >= interval) {
	    _previousMillis_blue = currentMillis;
	    _blue_state = !_blue_state;
	    digitalWrite( LED_BLUE, _blue_state);
	  }

  if ( led == 3 )
	  if (currentMillis - _previousMillis_orange >= interval) {
	    _previousMillis_orange = currentMillis;
	    _orange_state = !_orange_state;
	    digitalWrite( LED_ORANGE, _orange_state);
	  }

}




/**
*
*/
void LedsClass::blinkOff( byte led )
{

	if ( led == 0 ){
		_red_state = false;
    digitalWrite( LED_RED, HIGH);
	}

	if ( led == 1 ){
		_green_state = false;
    digitalWrite( LED_GREEN, HIGH);
	}

	if ( led == 2 ){
		_blue_state = false;
    digitalWrite( LED_BLUE, HIGH);
	}

	if ( led == 3 ){
		_orange_state = false;
    digitalWrite( LED_ORANGE, HIGH);
	}

}