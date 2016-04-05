#include "Printer.h"


/**
*
*/
void PrinterMain::init()
{	
	leds.init();

	pinMode( BTN_EPSON, INPUT );

	pinMode( RELE_EPSON, OUTPUT );
	digitalWrite( RELE_EPSON, HIGH );
}




/**
*
*/
void PrinterMain::main()
{
	int interval = 200000;

	if ( digitalRead( BTN_EPSON ) ){
		if ( k < interval ) k++;
	}
	else
		k = 0;

	if ( k >= interval )
		leds.blinkOn( ORANGE, 800 );
	else
		leds.blinkOff( ORANGE );
	

}