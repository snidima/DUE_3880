#include <PrinterMainClass.h>


/**
*
*/
void PrinterMain::init()
{	
	leds.init();
	epson.init();	
	motor.init();	
	btns.init();	
	limiters.init();

	leds.blinkOn( BLUE, 400 );
}




/**
*
*/
void PrinterMain::main()
{
	if ( epson.isPowerOn() ){

		leds.blinkOff( BLUE );
		leds.on( BLUE );
		epson.pdSensorEmulate();
		epson.pfSensor( OFF );
		unsigned long currentMillis = millis();

		
		if ( _steps_of_init == 0 ) {


			motor.on();
			

			_steps_of_init = 1;
			delay(2000);
		}
		
		
		if ( _steps_of_init <= 2 )
			leds.blinkOn( ORANGE, 400 );


		
		if ( _steps_of_init == 3 ){
			leds.blinkOff( ORANGE );
			_steps_of_init = 4;
		}

		// if ( _steps_of_init == 4 )
		// 	leds.on( GREEN );

		if ( _steps_of_init == 4 ){
			if ( ( btns.isPressed( BTN3 ) ) && ( !btns.isPressed( BTN2 ) ) ) motor.manualMove( TO_START, true );
			if ( ( btns.isPressed( BTN2 ) ) && ( !btns.isPressed( BTN3 ) ) ) motor.manualMove( TO_FINISH, true );
		}


		/*******Движение к концу*******/
		if ( _steps_of_init == 1 ){
			_OldMillis = currentMillis;
			if ( !limiters.isLimit( FINISH ) ) motor.manualMove( TO_FINISH, false ); else _steps_of_init = 2;
		}

		/*******Движение к началу*******/
		if ( currentMillis - _OldMillis >= 1000 )
			if ( _steps_of_init == 2 ){
				if ( !limiters.isLimit( START ) ) motor.manualMove( TO_START, false ); else _steps_of_init = 3;
			

		}





	} else {

		_steps_of_init = 0;
		motor.off();
		leds.blinkOn( BLUE, 400 );
		// leds.off( RED );
		// leds.off( GREEN );
		// // leds.off( BLUE );
		// leds.off( ORANGE );

	}
}