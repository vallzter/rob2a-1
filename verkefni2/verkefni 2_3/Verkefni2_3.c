#pragma config(Sensor, dgtl9,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

// ummal hjols er 8,25cm
// ((8,25 * PI) / 50) * 360 = 694 = BASELENGTH fyrir 0,5m

const int BASELENGTH = 694;
const int BASETURN = 3;

void turn(int deg,int dir){
	while(deg*BASETURN > abs(SensorValue[leftEncoder])){
		motor[rightMotor] = -63*dir;         /* Run both motors        */
		motor[leftMotor]  = 63*dir;
	}

}

void driveForward(int counter){
	while(abs(SensorValue[rightEncoder]) < BASELENGTH)
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
	resetEncoder();
	wait1Msec(2000);
	for(int counter =1;counter < 5; counter ++){
		if(counter < 2){
			driveForward(BASELENGTH);
			stopMotors();
			resetEncoder();
			wait1Msec(2000);
			turn(120,-1);
			counter++;
		}

		if(counter >= 2){
			stopMotors();
			resetEncoder();
			wait1Msec(2000);
			driveForward(BASELENGTH);
			stopMotors();
			resetEncoder();
			wait1Msec(2000);
			turn(60,1);
			counter++;
		}

		if(counter >= 4){
			resetEncoder();
			stopMotors();
			wait1Msec(2000);
			driveForward(BASELENGTH);
			stopMotors();
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
