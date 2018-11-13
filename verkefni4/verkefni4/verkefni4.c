#pragma config(Sensor, in1,    LightSensor,    sensorReflection)
#pragma config(Sensor, dgtl7,  sonarSensor,    sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, dgtl9,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)

//This program operates while the Light sensor displays that the lights are on, and will stop when the lights are on.
//The robot will continue it's process once the lights are back on.
//The program makes the robot move foward while it is more than 70cm from any obsticle.
//Once the robot goes under 70cm from any obsticle it makes a right turn, until it is more than 70cm away from any obsticle.
//The program will loop this process forever until stopped or lights are turned off

#include "../myincludes/myincludes.c"

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
wait1Msec(2000);
while(true){

		while(SensorValue(sonarSensor) > 70 && SensorValue(LightSensor) < 300){
				resetEncoder();
				drive();
			}
		if(SensorValue(sonarSensor) < 70){
		turn(60,1);
		stopMotors();
		}
		else	if(SensorValue(LightSensor) > 300){
			stopMotors();
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
