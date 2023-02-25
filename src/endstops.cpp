
#include <DIO2.h>

#include "endstops.h"
#include "macros.h"
#include "pins.h"



Endstops::Endstops(AXES axis) {
	switch(axis) {
		case X:
			this->MIN_PIN = X_MIN_PIN;
			this->MAX_PIN = X_MAX_PIN;
			HAS_ES = X_ES;
			break;

		case Y:
			this->MIN_PIN = Y_MIN_PIN;
			this->MAX_PIN = Y_MAX_PIN;
			HAS_ES = Y_ES;
			break;

		case Z:
			this->MIN_PIN = Z_MIN_PIN;
			this->MAX_PIN = Z_MAX_PIN;
			HAS_ES = Z_ES;
			break;

		default:
			// HAS_ES = false;
			break;
	}
}

// Return directly without using minStat & maxStat??
bool Endstops::minTrig() {
	this->minStat = GET(MIN_PIN);
	return minStat;
}

bool Endstops::maxTrig() {
	this->maxStat = GET(MAX_PIN);
	return maxStat;
}

bool Endstops::trig() {
	return (minTrig() || maxTrig());
}