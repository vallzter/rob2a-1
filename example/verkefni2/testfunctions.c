#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

#include "../robheader/myconst.h"
#include "../robfunctions/motorfunctions.c"

task main()
{
	resetEncoder();
	turn(90,false);

}
