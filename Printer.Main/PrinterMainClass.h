#include <LedsClass.h>
#include <EpsonClass.h>

class PrinterMain
{

	private:
		LedsClass leds;
    EpsonClass epson;
    int k = 0;

	public:
		void init();
		void main();

};