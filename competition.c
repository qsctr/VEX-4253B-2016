#pragma config(Motor,  port2,           FR,            tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           BR,            tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FL,            tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           shooter1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           shooter2,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           shooter3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           shooter4,      tmotorVex393_MC29, openLoop, reversed)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

// motors listed in clockwise direction
// open side of the robot is front
void drive(){
	int x, y, r;

	x = vexRT[Ch1];
	y = vexRT[Ch2];
	r = vexRT[Ch4];

	motor[FL] = - y - x - r;
	motor[FR] = + y - x - r;
	motor[BR] = + y + x - r;
	motor[BL] = - y + x - r;
}

void shooter(){
	if (vexRT[Btn5D]){
		motor[shooter1] = 60;
		motor[shooter2] = 60;
		motor[shooter3] = 60;
		motor[shooter4] = 60;
	}
	else{
		motor[shooter1] = 0;
		motor[shooter2] = 0;
		motor[shooter3] = 0;
		motor[shooter4] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	// .....................................................................................
	// Insert user code here.
	// .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		while (true) {
			drive();
			shooter();
			sleep(20);
		}

		UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
