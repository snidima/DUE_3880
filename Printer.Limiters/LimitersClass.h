#ifndef LimitersClass_h_
#define LimitersClass_h_





#include <Setting.h>
#include <Arduino.h>

#define START  1
#define FINISH 0

class LimitersClass
{

	private:
		int k, j;

	public:
    void init();
		bool isLimit( byte );
			
};






#endif