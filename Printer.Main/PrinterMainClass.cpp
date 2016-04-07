#include <PrinterMainClass.h>


void PrinterMain::init()
{	
	leds.init();
	epson.init();	
	motor.init();	
	btns.init();	
	limiters.init();
}



void PrinterMain::main()
{
	if ( epson.isPowerOn() ){

		unsigned long currentMillis;
		
		if ( _steps_of_init == 0 ) {

      leds.blinkOff( BLUE );
      leds.on( BLUE );
			motor.on();

      motor._table_cnt = 0; 
      motor._current_cnt = 0;
      motor._limiters_detected = 0;

			epson.pfSensor( OFF );

			_steps_of_init = 1;

			delay(2000);
		}
		
		
		

		/*******Движение к концу*******/
		if ( _steps_of_init == 1 )
			if ( !limiters.isLimit( FINISH ) ) motor.move( TO_FINISH ); else {_steps_of_init = 2; _OldMillis = millis(); }
		

    if ( _steps_of_init < 4 )
      leds.blinkOn( ORANGE, 400 );
      
    if ( _steps_of_init <= 4 )
      epson.pdSensorEmulate();
      


		/*******Пауза, движение к началу*******/
    if ( _steps_of_init == 2 ){
      currentMillis = millis();
		  if ( currentMillis - _OldMillis >= 1000 )
				if ( !limiters.isLimit( START ) ) { 
          if ( motor.move( TO_START ) ){
            motor._table_cnt++; 
            motor._current_cnt = motor._table_cnt;
          } 

        } else { _steps_of_init = 4; motor._limiters_detected = true; }
			

		}


    if ( _steps_of_init == 4 ){
      leds.blinkOff( ORANGE );
      leds.blinkOff( GREEN );

      if ( btns.isPress( BTN3, SHORT ) ) motor.move( TO_START );
      if ( btns.isPress( BTN2, SHORT ) ) motor.move( TO_FINISH );
      if ( btns.isPress( BTN1, LONG  ) ) _steps_of_init = 7;

      if ( btns.isPress( BTN3, LONG  ) ) _steps_of_init = 5;
      if ( btns.isPress( BTN2, LONG  ) ) _steps_of_init = 6;

    }

      
      if ( _steps_of_init == 5 ){
        if ( motor.moveToZero( motor._table_cnt ) ) _steps_of_init = 4;
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
        leds.blinkOn( ORANGE, 400 );
      }

      if ( _steps_of_init == 6 ){
        if ( motor.moveToZero( 0 ) ) _steps_of_init = 4;
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
        leds.blinkOn( ORANGE, 400 );
      }

      if ( _steps_of_init == 7 ){
        leds.blinkOn( ORANGE, 400 );
        if ( motor.moveToZero( motor._table_cnt / 2 ) ) _steps_of_init = 8;
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
      }

      if ( _steps_of_init == 8 ){
        leds.blinkOff( ORANGE );
        leds.blinkOn( GREEN, 400 );
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
      }
    


	} else {

		_steps_of_init = 0;
		motor.off();
		leds.blinkOn( BLUE, 400 );

	}
}



void PrinterMain::testMode()
{

  if ( btns.isPress( BTN1, SHORT ) ) leds.on( GREEN ); else leds.off( GREEN );
  if ( btns.isPress( BTN2, LONG ) ) leds.on( ORANGE ); else leds.off( ORANGE );
  if ( btns.isPress( BTN3, LONGEST ) ) leds.on( BLUE ); else leds.off( BLUE );
  
}