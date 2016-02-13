/* 2016 Vincent Limorté
Motor driver using L298 component.

*/


#ifndef MOTOR_DRIVE_H
#define MOTOR_DRIVE_H

#include "Arduino.h"


#ifndef SERIAL_DEBUG
#define SERIAL_DEBUG (0)
#endif //SERIAL_DEBUG

class MotorDriver{
	public:
		/* Constructor.
			pinEnable must be a PWM capable pin
			pinSense may be set to 0. Sensing is then not activated
		*/		
		MotorDriver(int pinEnable, int pinCtl1, int pinCtl2, int pinSense = 0);
		/* 
			Speed: from 0 to 255, 
			Direction: stricly negative for one direction (HIGH on pinCtl2), positive for other direction */
		void run(int speed, char direction);
		void brake();
		int sense();	
	private:
		int _pinEnable;
		int _pinCtl1;
		int _pinCtl2;
		int _pinSense;

};

#endif //MOTOR_DRIVE_H


