#pragma config(Sensor, dgtl10, pushButton,     sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)

#include "../robheader/myconst.h"
#include "../robfunctions/motorfunctions.c"
#include "mytasks.c"
task main()
{
	StartTask(one);
	StartTask(two);
	StartTask(three);
	StartTask(four);
	while(true){
		int number = rand()%4;
		if(number ==1){
			StartTask(one);
			StopTask(two);
			StopTask(three);
			StopTask(four);
		}
		if(number ==2){
			StartTask(two);
			StartTask(three);
			StopTask(four);
		}
		if(number ==3){
			StartTask(three);
			StopTask(four);
			StopTask(two);
			StopTask(one);

		}
		else{
			StopTask(four);
			StopTask(three);
			StopTask(two);
			StopTask(one);
			wait1Msec(1000);
		}
	}
}
