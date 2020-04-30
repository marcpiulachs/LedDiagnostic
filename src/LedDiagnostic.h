
#pragma once

#ifndef LEDDIAGNOSTIC_H
#define LEDDIAGNOSTIC_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define BLINK_LENGHT 200

class LedDiagnostic
{
public:
	LedDiagnostic(int ledPin);
	~LedDiagnostic();

	void begin();
	void reset();
	// Restart timer.
	void blink(int);
	void run();
	void turnOn();
	void turnOff();

private:
	int _ledPin;
	int _times;
	int _count;

		// Variables will change:
	int _ledState = LOW;             // ledState used to set the LED

	// Generally, you should use "unsigned long" for variables that hold time
	// The value will quickly become too large for an int to store
	unsigned long _previousMillis = 0;        // will store last time LED was updated
};

#endif
