#pragma config(Sensor, dgtl10, pushButton,     sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#include "../robheader/myconst.h"
#include "../robfunctions/motorfunctions.c"

task driveMotors()
{
	while(true){
		motor[rightMotor] = full_power;
		motor[leftMotor]  = full_power;
	}
}

task clawMotors()
{
	while(true){
		motor[clawMotor] = full_power;
		wait1Msec(200);
		motor[clawMotor] = -full_power;
		wait1Msec(200);
	}
}




task main()
{

  StartTask(driveMotors);
  StartTask(clawMotors);

  while(SensorValue[pushButton]==0)
  {
    // Keep the program alive until pushButton is pressed
  }
	StopAllTasks();
}
