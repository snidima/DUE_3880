#include <LedsClass.h>
#include <EpsonClass.h>
#include <MotorClass.h>
#include <BtnsClass.h>
#include <LimitersClass.h>
#include <EncoderHelperClass.h>
#include <Encoder.h>

class PrinterMain
{

	private:
		LedsClass leds;
    EpsonClass epson;
    MotorClass motor;
    BtnsClass btns;
    LimitersClass limiters;
    EncoderHelperClass encoder;

    byte _steps_of_init = 0;

    unsigned long _OldMillis = 0;

    long _oldPosition;



	public:
		void init();
    void main();
    void testMode();
    

};