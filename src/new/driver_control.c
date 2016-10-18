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

#define STRAIGHT(ch)           (abs(vexRT[ch]) < 20 ? 0 : vexRT[ch])
#define JOYSTICK_DRIVE         STRAIGHT(Ch3)
#define JOYSTICK_STRAFE        STRAIGHT(Ch4)
#define JOYSTICK_ROTATE        STRAIGHT(Ch1)
#define JOYSTICK_ARM_UP        vexRT[Btn6U]
#define JOYSTICK_ARM_DOWN      vexRT[Btn6D]
#define JOYSTICK_CLAW_OPEN     vexRT[Btn5U]
#define JOYSTICK_CLAW_CLOSE    vexRT[Btn5D]

static void dc_base(void);
static void dc_arm(void);
static void dc_claw(void);

task usercontrol()
{
    while (1) {
	    dc_base();
	    dc_arm();
	    dc_claw();
	    sleep(20);
    }
}

static void dc_base(void)
{
    if (JOYSTICK_ROTATE) {
        base_rotate(JOYSTICK_ROTATE);
    } else {
        base_main_set(JOYSTICK_DRIVE);
        base_strafe_set(JOYSTICK_STRAFE);
    }
}

static void dc_arm(void)
{
    if (JOYSTICK_ARM_UP) {
        arm_move(-127);
    } else if (JOYSTICK_ARM_DOWN) {
        arm_move(127);
    } else {
        arm_move(0);
    }
}

static void dc_claw(void)
{
    if (JOYSTICK_CLAW_OPEN) {
        claw_move(-127);
    } else if (JOYSTICK_CLAW_CLOSE) {
        claw_move(127);
    } else {
        claw_move(0);
    }
}
