const int BASETURN = 3;
const int POWER = 80;

void turn(int deg,int dir){
	while(deg*BASETURN > abs(SensorValue[leftEncoder])){
		motor[rightMotor] = -POWER*dir;
		motor[leftMotor]  = POWER*dir;
	}

}

void stopMotors(){
	motor[rightMotor] = 0;
	motor[leftMotor]	= 0;
}

void resetEncoder(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]	= 0;
}
