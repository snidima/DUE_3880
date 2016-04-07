#include <LedsClass.h>
#include <EpsonClass.h>
#include <MotorClass.h>
#include <BtnsClass.h>
#include <LimitersClass.h>


class PrinterMain
{

	private:
		LedsClass leds;
    EpsonClass epson;
    MotorClass motor;
    BtnsClass btns;
    LimitersClass limiters;

    byte _steps_of_init = 0;
    int _steps_count_for_init = 0;

    unsigned long _OldMillis = 0;


	public:
		void init();
    void main();
    void testMode();
    

};