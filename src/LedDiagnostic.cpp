#include "LedDiagnostic.h"

LedDiagnostic::LedDiagnostic(int ledPin)
{
	_ledPin = ledPin;
	_previousMillis = 0;

	// Set pin as output.
	pinMode(ledPin, OUTPUT);

	reset();
}

LedDiagnostic::~LedDiagnostic()
{

}

void LedDiagnostic::begin()
{

}

void LedDiagnostic::reset()
{
	_count = 0;
	_times = 0;

	_ledState = LOW;

	// poner el Pin en HIGH
	digitalWrite(_ledPin, _ledState);
}

void LedDiagnostic::turnOn()
{
	// poner el Pin en HIGH
	digitalWrite(_ledPin, HIGH);
}

void LedDiagnostic::turnOff()
{
	// poner el Pin en HIGH
	digitalWrite(_ledPin, LOW);
}

void LedDiagnostic::blink(int times)
{
	_count = 0;
	_times = times;
}

void LedDiagnostic::run()
{
	// here is where you'd put code that needs to be running all the time.

	// check to see if it's time to blink the LED; that is, if the difference
	// between the current time and last time you blinked the LED is bigger than
	// the interval at which you want to blink the LED.
	unsigned long currentMillis = millis();

	if (currentMillis - _previousMillis >= BLINK_LENGHT)
	{
		// save the last time you blinked the LED
		_previousMillis = currentMillis;

		if (_count == _times)
		{
			reset();
			return;

		}

		// if the LED is off turn it on and vice-versa:
		if (_ledState == LOW)
		{
			_ledState = HIGH;
			_count++;
		}
		else
		{
			_ledState = LOW;
		}

		/* set the LED with the ledState of the variable */
		digitalWrite(_ledPin, _ledState);
	}
}
