#include <EpsonClass.h>



/**
*
*/
void EpsonClass::init()
{
	pinMode( SENSOR_PD, OUTPUT );
	// pinMode( SENSOR_PF, OUTPUT );
	pinMode( BTN_EPSON, INPUT );
	pinMode( RELE_EPSON, OUTPUT );
	pinMode( ENCODER_A, INPUT );
	pinMode( ENCODER_B, INPUT );

  //Дать питание Epson сразу, после включения контроллера
  digitalWrite( RELE_EPSON, HIGH );
}



/**
*
*/
bool EpsonClass::isPowerOn()
{

	if ( digitalRead( BTN_EPSON ) ){
		if ( _power_time_cnt < EPSON_BTN_POWER_TIME ) _power_time_cnt++;
	}
	else
		_power_time_cnt = 0;

	if ( _power_time_cnt >= EPSON_BTN_POWER_TIME )
		return true;
	else
		return false;

}




/**
*
*/
void EpsonClass::pdSensorEmulate()
{
	unsigned long currentMillis = millis();

	if (currentMillis - _previousMillis_pd >= 80) {
	    _previousMillis_pd = currentMillis;
	    _pd_state = !_pd_state;
	    digitalWrite( SENSOR_PD, _pd_state);
	  }

}




/**
*
*/
void EpsonClass::pfSensor( byte state )
{
	if ( (state == 1) && (_pf_state == 0) ){
		digitalWrite( SENSOR_PF, HIGH );
		_pf_state = 1;
	}

	if ( (state == 0) && (_pf_state == 1) ){
		digitalWrite( SENSOR_PF, LOW );
		_pf_state = 0;
	}

}