#include <Setting.h>
#include <Arduino.h>
#include <Encoder.h>

class EncoderHelperClass
{




    
  

	private:
    Encoder *encoder;

    int _start_print_cnt = 0;
    long _oldPosition;

    long _step_cnt;
        
    bool isMove();
    bool isStepCalc();

	public:
    
    void init();
    bool isStartPrinting();
    bool isStep();
};