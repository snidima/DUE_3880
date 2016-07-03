#include <PrinterMainClass.h>


void PrinterMain::init()
{	
	leds.init();
	epson.init();	
	motor.init();	
	btns.init();	
  limiters.init();
  trays.init();
}



void PrinterMain::main()
{
  unsigned long currentMillis;
    
	if ( epson.isPowerOn() ){

		currentMillis = millis();

    
		
		if ( _steps_of_init == 0 ) {

      leds.blinkOff( BLUE );
      leds.on( BLUE );
			motor.on();

      motor._table_cnt = 0; 
      motor._current_cnt = 0;
      motor._limiters_detected = 0;

			epson.pfSensor( OFF );

			_steps_of_init = 1;
      
		}
		
		
		

		/*******Движение к концу*******/
		if ( _steps_of_init == 1 )
			if ( !limiters.isLimit( FINISH ) ) 
        motor.move( TO_FINISH ); 
      else 
      {
        _steps_of_init = 2; _OldMillis = millis(); 
      }
		

      
      
    if ( _steps_of_init <= 4 ){
      if ( !_printer_ready ){
        epson.pdSensorEmulate();
        leds.blinkOn( ORANGE, 400 );
      } 

      currentMillis = millis();
      if ( currentMillis - _printer_off >= 1000 * EPSON_READY_TIME ) 
            _printer_ready = true;
    }
      


		/*******Пауза, движение к началу*******/
    if ( _steps_of_init == 2 ){
      currentMillis = millis();
		  if ( currentMillis - _OldMillis >= 1000 )
				if ( !limiters.isLimit( START ) ) { 
          if ( motor.move( TO_START ) ){
            motor._table_cnt++; 
            motor._current_cnt = motor._table_cnt;
          } 

        } else {
          _steps_of_init = 4; 
          motor._limiters_detected = true; 
        }
        
			

		}


    if ( (_steps_of_init == 4) ){

      trays.allowsToChange();

      if ( _printer_ready )
        leds.blinkOff( ORANGE );

      leds.blinkOff( GREEN );

      if ( btns.isPress( BTN3, SHORT ) ) motor.move( TO_START );
      if ( btns.isPress( BTN2, SHORT ) ) motor.move( TO_FINISH );
      if ( btns.isPress( BTN1, LONG  ) ) _steps_of_init = 7;

      if ( btns.isPress( BTN3, LONGEST  ) ) _steps_of_init = 5;
      if ( btns.isPress( BTN2, LONGEST  ) ) _steps_of_init = 6;




    }


    

      
      if ( _steps_of_init == 5 ){
        if ( motor.moveToZero( motor._table_cnt ) ) _steps_of_init = 4;
        if ( btns.isPress( BTN4, SHORT ) ) _steps_of_init = 4;
        leds.blinkOn( ORANGE, 400 );
      }


      if ( _steps_of_init == 6 ){
        if ( motor.moveToZero( 0 ) ) _steps_of_init = 4;
        if ( btns.isPress( BTN4, SHORT ) ) _steps_of_init = 4;
        leds.blinkOn( ORANGE, 400 );
      }


      if ( _steps_of_init == 7 ){
        leds.blinkOn( ORANGE, 400 );
        if ( motor.moveToZero( trays.getZero() ) ) { 
          _steps_of_init = 8; 
          encoder = new Encoder( ENCODER_A, ENCODER_B ); 
        }
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
      }


      if ( _steps_of_init == 8 ){
        leds.blinkOff( ORANGE );
        leds.blinkOn( GREEN, 400 );
        if ( btns.isPress( BTN4, LONG ) ) _steps_of_init = 4;
        if ( abs(encoder->read()) >= 500 ) { _steps_of_init = 9;_OldMillis = millis(); epson.pfSensor( ON ); }
      }

      if ( _steps_of_init == 9 ){
        epson.pdSensorEmulate();
        leds.blinkOn( GREEN, 400 );
        currentMillis = millis();
      if ( currentMillis - _OldMillis >= 100 ) { _steps_of_init = 10; _OldMillis = currentMillis; }
      }
    
      
      if ( _steps_of_init == 10 ){
        epson.pdSensorEmulate();
        leds.blinkOn( GREEN, 400 );

        currentMillis = millis();
        if ( currentMillis - _OldMillis >= 2000 ) {
          _steps_of_init = 11;
          leds.blinkOff( GREEN );
          leds.on( GREEN );
          encoder->write(0);
        }
      }

      /****Печать****/
      if (_steps_of_init == 11)
          if ( motor.EncoderMove( encoder->read() ) == 0 ) _steps_of_init = 12;
        
      

      


      if ( _steps_of_init == 12 ){
        leds.off( GREEN );
        leds.off( RED );
        leds.blinkOff( GREEN );
        epson.pfSensor( OFF );
        _steps_of_init = 4;
      }

      


	} else {

    motor.off();
    leds.blinkOn( BLUE, 400 );
    epson.pfSensor( OFF );
    
		_steps_of_init = 0;
    _printer_ready = false;
    _printer_off = millis();		
	}
}



void PrinterMain::testMode()
{
    trays.allowsToChange();
}