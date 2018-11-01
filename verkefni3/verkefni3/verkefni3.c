#pragma config(Sensor, dgtl9,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,	 port2,						rightMotor,		 tmotorNormal, openLoop)
#pragma config(Motor,	 port3,						leftMotor,		 tmotorNormal, openLoop, reversed)
#pragma config(Motor,	 port6,						armMotor,		 tmotorNormal, openLoop)
#pragma config(Motor,	 port7,						clawMotor,		tmotorNormal, openLoop)

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{

	while(1 == 1)
	{
		motor[leftMotor]	= (vexRT[Ch3] + vexRT[Ch4])/2;
		motor[rightMotor] = (vexRT[Ch3] - vexRT[Ch4])/2;
		motor[armMotor] = (vexRT[Ch1] - vexRT[Ch2])/2;

		if(vexRT[Btn8D]){
			motor[clawMotor] = 80;
		}

		else if(vexRT[Btn8L]){
			motor[clawMotor] = -80;
		}

		else {
		motor[clawMotor] = 0;
		}

		if(vexRT[Btn5D]){
			StopAllTasks();
		}

	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
