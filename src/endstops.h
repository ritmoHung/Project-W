#pragma once

#include "pins.h"



class Endstops {
	protected:
		bool HAS_ES = false;
		bool minStat = 0;
		bool maxStat = 0;

		GPIO_pin_t MIN_PIN = DEFAULT_IN;
		GPIO_pin_t MAX_PIN = DEFAULT_IN;

		bool minTrig();
		bool maxTrig();

	public:
		Endstops(AXES);
		bool trig();
};