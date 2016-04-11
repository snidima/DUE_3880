#include <Setting.h>
#include <Arduino.h>
#include <LimitersClass.h>

#define TO_START     0
#define TO_FINISH    1
#define ENCODER      1

class MotorClass
{

	private:
		LimitersClass limiters;

		bool _enb_state = false;

		int speed = 6400 / MOTOR_STEPS_DPI * MOTOR_SPEED;

		unsigned long _previousMillis_manual_move = 0;
		bool 					_dir_manual_state = 0,
									_step__manual_state = 0;
		long _cnt = 0;

		




	public:
		int _table_cnt = 0, 
				_current_cnt = 0,
				_zero = 0;
		bool _limiters_detected = 0;
		long oldPosition = 0;

		void init();
		void on();
		void off();		
		bool move( bool );
		bool EncoderMove( long );
		bool moveToZero( int );
};