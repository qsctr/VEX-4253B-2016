#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    ShooterPot,     sensorPotentiometer)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           P1,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FR,            tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port3,           BR,            tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           BL,            tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port5,           FL,            tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port6,           D1,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           D2,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           D3,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           D4,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          P2,            tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define GYRO_PORT in2

// motors listed in clockwise direction
// open side of the robot is front

/*

=========================================================================================================
   ___________________________________________________________________________________________________
  |  __        __   ________   __     __       __        ______   __     __   _________    ________   |
  |  \ \      / /  |   _____|  \ \   / /      /  \      |  _   \  \ \   / /  |___   ___|  |   _____|  |
  |   \ \    / /   |  |_____    \ \_/ /      / /\ \     | |_|  /   \ \_/ /       | |      |  |_____   |
  |    \ \  / /    |   _____|    ) _ (      / /__\ \    |  _  |     \   /        | |      |   _____|  |
  |     \ \/ /     |  |_____    / / \ \    / ______ \   | |_|  \     | |         | |      |  |_____   |
  |      \__/      |________|  /_/   \_\  /_/      \_\  |______/     |_|         |_|      |________|  |
  |___________________________________________________________________________________________________|

=========================================================================================================
                                                                                           (by Bretton)
*/

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"
#include "common.c"
// #include "shooter.c"
#include "dump.c"
#include "lcd.c"
#include "autonomous/autonomous.c"
#include "driver_control/driver_control.c"
