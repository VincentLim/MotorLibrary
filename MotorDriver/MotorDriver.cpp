#include "MotorDriver.h"

MotorDriver::MotorDriver(int pinEnable, int pinCtl1, int pinCtl2, int pinSense /* = 0 */){
	_pinEnable = pinEnable;
	_pinCtl1 = pinCtl1;
	_pinCtl2 = pinCtl2;
	_pinSense = pinSense;
		
	pinMode(_pinEnable, OUTPUT);
	pinMode(_pinCtl1, OUTPUT);
	pinMode(_pinCtl2, OUTPUT);
	if(pinSense){
		pinMode(_pinSense, INPUT);
	}
	
	analogWrite(_pinEnable, 0);
	digitalWrite(_pinCtl1, HIGH);
	digitalWrite(_pinCtl2, HIGH);
}

void MotorDriver::run(int speed, char direction){
	
	if(direction<0){
		digitalWrite(_pinCtl1, LOW);
		digitalWrite(_pinCtl2, HIGH);
	} else {
		digitalWrite(_pinCtl1, HIGH);
		digitalWrite(_pinCtl2, LOW);
	}
	
	analogWrite(_pinEnable, constrain(speed, 0, 255));
}

void MotorDriver::run(int speed){
	if(speed>0){
		run(speed,1);
	} else if(speed<0){
		run(0-speed, -1);
	} else {
		brake();
	}
	
}

void MotorDriver::brake(){
	analogWrite(_pinEnable, 0);
	digitalWrite(_pinCtl1, HIGH);
	digitalWrite(_pinCtl2, HIGH);
}

int MotorDriver::sense(){
	if(_pinSense == 0){
		return 0;
	} else {
		return analogRead(_pinSense);
	}
}



