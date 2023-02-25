#pragma once

#include "endstops.h"
#include "pins.h"



class Stepper: public Endstops {
	private:
		AXES axis = DEFAULT_AXIS;
		long position = 0,
		     ratio = 0;
		int  mode = 0;

		GPIO_pin_t DIR_PIN = DEFAULT_OUT,
			       STEP_PIN = DEFAULT_OUT,
			       ENABLE_PIN = DEFAULT_OUT;

	public:
		Stepper(AXES);
		void init();
		void setPosition(long);
		void origin();
		void pulse();

	private:
		//void pulse();
		long pulseHasES(long);
		long pulseNoES(long);
		bool allowPos();
		bool allowNeg();
};