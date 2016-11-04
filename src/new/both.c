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

#define CLAW_OPEN_POSITION                 2200
#define ARM_LIMIT_POSITION                 2700

typedef int motor_power;

void set_base_drive(motor_power x);
void set_base_strafe(motor_power x);
void set_base_rotate(motor_power x);
void set_arm(motor_power x);
void set_claw(motor_power x);
task open_claw();
void init_lcd(void);
void update_lcd(void);

tMotor base_motors[] = { mBaseFL, mBaseFR, mBaseBL, mBaseBR };
tMotor arm_motors[] = { mArmL1, mArmL2, mArmR1, mArmR2 };

static bool claw_in_use = false;

void set_base_drive(motor_power x)
{
    FOR_EACH(tMotor, m, base_motors, {
        motor[m] = x;
    })
}

void set_base_strafe(motor_power x)
{
    motor[mBaseStrafe] = x;
}

void set_base_rotate(motor_power x)
{
    motor[mBaseFL] = motor[mBaseBL] = x;
    motor[mBaseFR] = motor[mBaseBR] = -x;
}

void set_arm(motor_power x)
{
    FOR_EACH(tMotor, m, arm_motors, {
        motor[m] = x;
    })
}

void set_claw(motor_power x)
{
    if (!claw_in_use) {
        motor[mClaw] = x;
    }
}

task open_claw()
{
    claw_in_use = true;
    motor[mClaw] = 127;
    while (SensorValue(potClaw) > 600);
    motor[mClaw] = 0;
    claw_in_use = false;
}

/* ----------------
  |BATTERY COR=X.XX|
  |BAC=X.XX PE=X.XX|
   ---------------- */

void init_lcd(void)
{
    clearLCDLine(0);
    clearLCDLine(1);
    displayLCDString(0, 0, "BATTERY COR=X.XX");
    displayLCDString(1, 0, "BAC=X.XX PE=X.XX");
}

void update_lcd(void)
{
	static string s;
	sprintf(s, "%1.2f", nImmediateBatteryLevel * 0.001);
	displayLCDString(0, 12, s);
	sprintf(s, "%1.2f", BackupBatteryLevel * 0.001);
	displayLCDString(1, 4, s);
	sprintf(s, "%1.2f", SensorValue(powerExpander) / 280.0);
	displayLCDString(1, 12, s);
}
