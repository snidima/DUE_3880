#include <LedsClass.h>
#include <BtnsClass.h>



class TraysClass
{

	private:
    LedsClass leds;
    BtnsClass btns;

    int _current_tray = 0;

    int _btn = 0;

    int _zero;

    void changeTray();

	public:
    void allowsToChange();
    void init();
    int getZero();

};