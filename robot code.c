#pragma config(Sensor, dgtl1,  Right,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  Left,           sensorQuadEncoder)
#pragma config(Motor,  port1,           RightMotor,    tmotorVex393_HBridge, openLoop, driveRight, encoderPort, dgtl1)
#pragma config(Motor,  port2,           LeftMotor,     tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnLeftDeg(int degrees, int power)
{
  SensorValue[Left] = 0;
  SensorValue[Right] = 0;

  int tickGoal = (23 * degrees) / 10;

  motor[LeftMotor] = -1 * power;
  motor[RightMotor] = power;

  while(SensorValue[Right] < tickGoal || SensorValue[Left] > -1 * tickGoal) {
    if(SensorValue[Right] > tickGoal) {motor[Right] = 0;}
    if(SensorValue[Left] < -1 * tickGoal) {motor[Left] = 0;}
  }
  motor[LeftMotor] = 0;
  motor[RightMotor] = 0;
}

void turnRightDeg(int degrees, int power)
{
  SensorValue[Left] = 0;
  SensorValue[Right] = 0;

  int tickGoal = (23 * degrees) / 10;

  motor[LeftMotor] = power;
  motor[RightMotor] = -1 * power;

  while(SensorValue[LeftMotor] < tickGoal || SensorValue[RightMotor] > -1 * tickGoal) {
    if(SensorValue[LeftMotor] > tickGoal) {motor[LeftMotor] = 0;}
    if(SensorValue[RightMotor] < -1 * tickGoal) {motor[RightMotor] = 0;}
  }

  motor[LeftMotor] = 0;
  motor[RightMotor] = 0;
}

task main()
{
 robotType(none);
 clearTimer(T1);
 while(time1[T1] < 60000)
   {
     moveStraightForRotations(4.5, dgtl1, dgtl3);
     stop();

     waitUntilMotorStop(port1);

     turnRightDeg(90,40);

     turnLeftDeg(90,40);

     stop();

   }
}
