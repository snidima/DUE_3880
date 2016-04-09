#include <LedsClass.h>
#include <EpsonClass.h>
#include <MotorClass.h>
#include <BtnsClass.h>
#include <LimitersClass.h>
#include <EncoderHelperClass.h>
#include <Encoder.h>
#include <UltrasonicHelperClass.h>

class PrinterMain
{

	private:
		LedsClass leds;
    EpsonClass epson;
    MotorClass motor;
    BtnsClass btns;
    LimitersClass limiters;
    EncoderHelperClass encoder;
    UltrasonicHelperClass ultrasonic;

    byte _steps_of_init = 0,
         _steps_of_turn_off = 0;

    unsigned long _OldMillis = 0,
                  _printer_off = 0;

    bool _printer_ready = false;

    long _oldPosition;



	public:
		void init();
    void main();
    void testMode();
    

};