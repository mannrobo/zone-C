#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           rightBack,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           rightLS,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftLS,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightCone,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftCone,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           cone,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"


int threshold = 75;
int LSMAX = 1000;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(){
	SensorValue(rightEncoder) = 0;
	SensorValue(leftEncoder) = 0;

  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous(){
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void drive(int x, int y) {
	//positive drive values = backwards
			if(abs(x) > threshold) {
					motor[rightBack] = x;
					motor[leftBack] = -x;
			}
			else if(abs(y) > threshold) {
					motor[rightBack] = -y;
					motor[leftBack] = -y;
			}
		motor[rightBack] = 0;
		motor[leftBack] = 0;
}

void test() {
	if(vexRT[Btn8U] == 1) {
		motor[rightBack] = 100;
		motor[leftBack] = 100;
	}
	if(vexRT[Btn8D] == 1) {
		motor[rightBack] = 0;
		motor[leftBack] = 0;
	}
}

void LS() {
	//positive LS moves backward
			//right trigger, button 6D extends out
					if(vexRT[Btn6D] == 1) {
							//if(abs(SensorValue(rightEncoder)) < LSMAX && abs(SensorValue(leftEncoder)) < LSMAX) {
									motor[rightLS] = 90;
									motor[leftLS] = 80;
							//}
					}
			//right trigger, button 6U brings in
					if(vexRT[Btn6U] == 1) {
							motor[rightLS] = -90;
							motor[leftLS] = -80;
					}
		motor[rightLS] = 0;
		motor[leftLS] = 0;
}

task usercontrol() {

		  while(true) {
		  		drive(vexRT[Ch1], vexRT[Ch3]);
		  		test();
		  		LS();
		  }

}
