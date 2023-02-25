#pragma once

#include <LiquidCrystal_PCF8574.h>



class LCD: public LiquidCrystal_PCF8574 {
	private:
		int lightness = 255;

	public:
		LCD(int);
		void init();
		void write(int, int, bool, String);
		void clearLine(int);
};