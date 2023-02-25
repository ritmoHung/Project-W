#include <DIO2.h>

#include "stepper.h"
#include "endstops.h"
#include "config.h"
#include "macros.h"
#include "pins.h"



Stepper::Stepper(AXES axis): Endstops(axis) {
	this->axis = axis;
	switch(this->axis) {
		case X:
			DIR_PIN = X_DIR_PIN;
			STEP_PIN = X_STEP_PIN;
			ENABLE_PIN = X_ENABLE_PIN;
			mode = X_STEP_MODE;
			ratio = X_RATIO;
			break;

		case Y:
			DIR_PIN = Y_DIR_PIN;
			STEP_PIN = Y_STEP_PIN;
			ENABLE_PIN = Y_ENABLE_PIN;
			mode = Y_STEP_MODE;
			ratio = Y_RATIO;
			break;

		case Z:
			DIR_PIN = Z_DIR_PIN;
			STEP_PIN = Z_STEP_PIN;
			ENABLE_PIN = Z_ENABLE_PIN;
			mode = Z_STEP_MODE;
			ratio = Z_RATIO;
			break;

		case E0:
			DIR_PIN = E0_DIR_PIN;
			STEP_PIN = E0_STEP_PIN;
			ENABLE_PIN = E0_ENABLE_PIN;
			mode = E0_STEP_MODE;
			ratio = E0_RATIO;
			break;

		case E1:
			DIR_PIN = E1_DIR_PIN;
			STEP_PIN = E1_STEP_PIN;
			ENABLE_PIN = E1_ENABLE_PIN;
			mode = E1_STEP_MODE;
			ratio = E1_RATIO;
			break;

		default:
			break;
	}
}

// Never put init() inside constructor! Arduino functions cannot be used before setup().
void Stepper::init() {
	if(HAS_ES) {
		// Enables motor, attempting to find original
		POS(DIR_PIN);
		EN(ENABLE_PIN);
		setPosition(this->position + INIT_OFFSET);

		NEG(DIR_PIN);
		EN(ENABLE_PIN);
		while(allowNeg()) pulse();

		// Disables motor, decides origin
		DIS(ENABLE_PIN);
		POS(DIR_PIN);
	}
	this->position = 0;
}

void Stepper::setPosition(long position) {
	long posDif = SUB(this->ratio * position, this->position);
	
	Serial.print(position);
	Serial.print(", ");
	Serial.print(this->ratio);
	Serial.print(", ");
	Serial.print(this->ratio * position);
	Serial.print(", ");
	Serial.print(this->position);
	Serial.print(", ");
	Serial.println(posDif);
	
	if(posDif != 0) {
		// Decides direction
		int sign = posDif / ABS(posDif);
		(posDif > 0) ? POS(DIR_PIN) : NEG(DIR_PIN);

		// Approach & set actual position
		EN(ENABLE_PIN);
		if(this->axis == E0 || this->axis == E1) {
			this->position += sign * pulseNoES(posDif);
		}
		else {
			this->position += sign * pulseHasES(posDif);
		}
		DIS(ENABLE_PIN);
	}
}

void Stepper::origin() {
	if(HAS_ES) {
		NEG(DIR_PIN);
		EN(ENABLE_PIN);
		while(allowNeg()) pulse();
	
		// Disables motor, decides origin
		DIS(ENABLE_PIN);
		POS(DIR_PIN);
	}
	this->position = 0;
}

void Stepper::pulse() {
	// Send a single pulse
	POS(STEP_PIN);
	delayMicroseconds(PERIOD);
	NEG(STEP_PIN);
}

long Stepper::pulseHasES(long dif) {
	long p = 0;
	if(dif >= 0) {
		for(; p < ABS(dif) && allowPos(); p++) {
			pulse();
		}
	}
	else if(dif < 0) {
		for(; p < ABS(dif) && allowNeg(); p++) {
			pulse();
		}
	}
	return p;
}

long Stepper::pulseNoES(long dif) {
	long p = 0;
	for(; p < ABS(dif); p++) {
		pulse();
	}
	return p;
}

bool Stepper::allowPos() {
	return !maxTrig();
}

bool Stepper::allowNeg() {
	return !minTrig();
}