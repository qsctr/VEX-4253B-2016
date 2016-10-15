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

void base_main_set(int x);
void base_strafe_set(int x);
void base_rotate(int x);
void arm_move(int x);
void claw_move(int x);

void base_main_set(int x)
{
    motor[mBaseFL] = motor[mBaseFR] = motor[mBaseBL] = motor[mBaseBR] = x;
}

void base_strafe_set(int x)
{
    motor[mBaseStrafe] = x;
}

void base_rotate(int x)
{
    motor[mBaseFL] = motor[mBaseBL] = x;
    motor[mBaseFR] = motor[mBaseBR] = -x;
}

void arm_move(int x)
{
    motor[mArm1] = motor[mArm2] = motor[mArm3] = motor[mArm4] = x;
}

void claw_move(int x)
{
    motor[mClaw] = x;
}
