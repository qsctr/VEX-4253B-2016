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

#define LENGTH(arr)                        (sizeof(arr) / sizeof(arr[0]))
#define FOR_EACH(type, x, arr, block)      {                                        \
                                               type x;                              \
                                               for (int for_each_internal = 0;      \
                                                   for_each_internal < LENGTH(arr); \
                                                   for_each_internal++) {           \
                                                       x = arr[for_each_internal];  \
                                                       block                        \
                                               }                                    \
                                           }

typedef int motor_power;

void base_main_set(motor_power x);
void base_strafe_set(motor_power x);
void base_rotate(motor_power x);
void arm_move(motor_power x);
void claw_move(motor_power x);

tMotor base_motors[] = { mBaseFL, mBaseFR, mBaseBL, mBaseBR };
tMotor arm_motors[] = { mArmL1, mArmL2, mArmR1, mArmR2 };

void base_main_set(motor_power x)
{
    FOR_EACH(tMotor, m, base_motors, {
        motor[m] = 100;
    })
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
    FOR_EACH(tMotor, m, arm_motors, {
        motor[m] = x;
    })
}

void claw_move(motor_power x)
{
    motor[mClaw] = x;
}
