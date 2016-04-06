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
}




/**
*
*/
void PrinterMain::main()
{
	if ( epson.isPowerOn() ){

		unsigned long currentMillis = millis();

		/*******Включение ШД, одноразовые действия*******/
		if ( _steps_of_init == 0 ) {

			motor.on();
			// epson.pfSensor( ON );

			_steps_of_init = 1;
			delay(500);
		}
		
		/*******Моргать светом на 1 и 2 шаге инициализации*******/
		if ( ( _steps_of_init == 1 ) || (_steps_of_init == 2) )
			leds.blinkOn( BLUE, 400 );

		/*******Включить эмуляцию датчика PD*******/
		// if ( ( _steps_of_init == 1 ) || (_steps_of_init == 2) )
			epson.pdSensorEmulate();

		/*******Светить, когда инициализация прошла успешно*******/
		if ( _steps_of_init == 3 )
			leds.on( BLUE );


		/*******Движение к концу*******/
		if ( _steps_of_init == 1 ){
			_OldMillis = currentMillis;
			if ( !motor.finish ) motor.manualMove( TO_FINISH ); else _steps_of_init = 2;
		}

		/*******Движение к началу*******/
		if ( currentMillis - _OldMillis >= 1000 )
			if ( _steps_of_init == 2 ){
				if ( !motor.start ) motor.manualMove( TO_START ); else _steps_of_init = 3;
			

		}





	} else {


		motor.off();
		leds.off( RED );
		leds.off( GREEN );
		leds.off( BLUE );
		leds.off( ORANGE );


	}
}