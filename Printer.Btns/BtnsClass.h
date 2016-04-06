#include <Setting.h>
#include <Arduino.h>

#define BTN1   1
#define BTN2   2
#define BTN3   3
#define BTN4   4

class BtnsClass
{

	private:
		

	public:
    void init();
		bool isPressed( byte );
			
};