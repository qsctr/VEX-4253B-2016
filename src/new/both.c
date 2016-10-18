/* ======================================================================================================
   ___________________________________________________________________________________________________
  |  __        __   ________   __     __       __        ______   __     __   _________    ________   |
  |  \ \      / /  |   _____|  \ \   / /      /  \      |  _   \  \ \   / /  |___   ___|  |   _____|  |
  |   \ \    / /   |  |_____    \ \_/ /      / /\ \     | |_|  /   \ \_/ /       | |      |  |_____   |
  |    \ \  / /    |   _____|    ) _ (      / /__\ \    |  _  |     \   /        | |      |   _____|  |
  |     \ \/ /     |  |_____    / / \ \    / ______ \   | |_|  \     | |         | |      |  |_____   |
  |      \__/      |________|  /_/   \_\  /_/      \_\  |______/     |_|         |_|      |________|  |
  |___________________________________________________________________________________________________|

====================================================================================================== */

typedef int motor_power;

void base_main_set(motor_power x);
void base_strafe_set(motor_power x);
void base_rotate(motor_power x);
void arm_move(motor_power x);
void claw_move(motor_power x);

void base_main_set(motor_power x)
{
    motor[mBaseFL] = motor[mBaseFR] = motor[mBaseBL] = motor[mBaseBR] = x;
}

void base_strafe_set(motor_power x)
{
    motor[mBaseStrafe] = x;
}

void base_rotate(motor_power x)
{
    motor[mBaseFL] = motor[mBaseBL] = x;
    motor[mBaseFR] = motor[mBaseBR] = -x;
}

void arm_move(motor_power x)
{
    motor[mArm1] = motor[mArm2] = motor[mArm3] = motor[mArm4] = x;
}

void claw_move(motor_power x)
{
    motor[mClaw] = x;
}
