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

static void dc_base(void);
static void dc_arm(void);

task usercontrol()
{
    while (1) {
	    dc_base();
	    dc_arm();
	    sleep(20);
    }
}

static void dc_base()
{
    if (JOYSTICK_ROTATE) {
        base_rotate(JOYSTICK_ROTATE);
    } else {
        base_main_set(JOYSTICK_DRIVE);
        base_strafe_set(JOYSTICK_STRAFE);
    }
}

static void dc_arm()
{
    if (JOYSTICK_ARM_UP) {
        arm_move(-127);
    } else if (JOYSTICK_ARM_DOWN) {
        arm_move(127);
    } else {
        arm_move(0);
    }
}
