#include <Setting.h>
#include <Arduino.h>

#define RED     0
#define GREEN   1
#define BLUE    2
#define ORANGE  3

class LedsClass
{

	private:
		bool 	_red_state    = false, 
					_green_state  = false, 
					_blue_state   = false, 
					_orange_state = false;

		unsigned long _previousMillis_red    = 0,
									_previousMillis_green  = 0,
									_previousMillis_blue   = 0,
									_previousMillis_orange = 0;

		bool checkState( byte, bool );

	public:
		void init();
		void on( byte );
		void off( byte );
		void blinkOn( byte, int );
		void blinkOff( byte );
		
};