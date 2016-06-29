#ifndef BtnsClass_h_
#define BtnsClass_h_

#include <Setting.h>
#include <Arduino.h>

#define BTN1   1
#define BTN2   2
#define BTN3   3
#define BTN4   4
#define BTN5   5

#define SHORT   10000
#define LONG    50000
#define LONGEST 200000

class BtnsClass
{

	private:
    int _btn_1,
        _btn_2,
        _btn_3,
        _btn_4,
        _btn_5;

    bool _isPress( byte, int );

	public:
    void init();
		bool isPress( byte, int );
			
};



#endif