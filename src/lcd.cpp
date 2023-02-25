#include <LiquidCrystal_PCF8574.h>
#include "lcd.h"



LCD::LCD(int lightness): LiquidCrystal_PCF8574(0x27) {
	this->lightness = lightness;
}

void LCD::init() {
	begin(16, 2);
	setBacklight(this->lightness);
	clear();
}

// F(sentence)?
void LCD::write(int _row, int _col, bool clr, String sentence) {
	if(clr) clear();
	setCursor(_col, _row);
	print(sentence);
}

// Write 16 spaces
void LCD::clearLine(int _row) {
	write(_row, 0, false, "                ");
}