#include <Setting.h>
#include <Arduino.h>

#define ON  1
#define OFF 0

class EpsonClass
{

	private:
		int _power_time_cnt = 0;

    bool  _pd_state = 0,
          _pf_state = 0;

    unsigned long _previousMillis_pd = 0;


	public:
		void init();
    bool isPowerOn();
    void pdSensorEmulate();
		void pfSensor( byte );
		
};