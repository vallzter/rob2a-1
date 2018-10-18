#pragma config(Sensor, dgtl9,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

// ummal hjols er 8,25cm
// ((8,25 * PI) / 50) * 360 = 694 = BASELENGTH fyrir 0,5m
\*-----------------------------------------------------------------------------------------------4246-*/

const int BASELENGTH = 694;

void driveForward(int counter){
	while(abs(SensorValue[rightEncoder]) < counter * BASELENGTH)
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = 80;				// Right Motor is run at power level 80
		motor[leftMotor]	= 80;				// Left Motor is run at power level 80
	}
	else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder])) // If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = 60;				// Right Motor is run at power level 60
		motor[leftMotor]	= 80;				// Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = 80;				// Right Motor is run at power level 80
		motor[leftMotor]	= 60;				// Left Motor is run at power level 60
	}
}
void driveBackward(int counter){
	while(abs(SensorValue[rightEncoder]) < counter * BASELENGTH)
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = -80;				// Right Motor is run at power level 80
		motor[leftMotor]	= -80;				// Left Motor is run at power level 80
	}
	else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder])) // If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = -60;				// Right Motor is run at power level 60
		motor[leftMotor]	= -80;				// Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = -80;				// Right Motor is run at power level 80
		motor[leftMotor]	= -60;				// Left Motor is run at power level 60
	}
}
void stopMotors(){
	motor[rightMotor] = 0;
	motor[leftMotor]	= 0;
}

void resetEncoder(){
	SensorValue[rightEncoder] = 0;		// Set the encoder so that it starts counting at 0
	SensorValue[leftEncoder]	= 0;
}


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);
	for(int counter =1;counter < 6; counter ++){
		driveForward(counter);
		stopMotors();
		resetEncoder();
		wait1Msec(1000);
		driveBackward(counter);
		stopMotors();
		resetEncoder();
		wait1Msec(1000);
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
