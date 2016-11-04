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

#define STRAIGHT(ch)           (abs(vexRT[ch]) < 40 ? 0 : vexRT[ch])
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

bool dc_limit_lift = true;

task usercontrol()
{
    init_lcd();
    while (1) {
	    dc_base();
	    dc_arm();
	    dc_claw();
	    update_lcd();
	    sleep(20);
    }
}

static void dc_base(void)
{
    if (JOYSTICK_ROTATE) {
        set_base_rotate(JOYSTICK_ROTATE);
    } else {
        set_base_drive(JOYSTICK_DRIVE);
        set_base_strafe(JOYSTICK_STRAFE);
    }
}

static void dc_arm(void)
{
    static int prev_sensor_value = 4096;
    int current_sensor_value = SensorValue(potArm);
    if (current_sensor_value > CLAW_OPEN_POSITION && prev_sensor_value <= CLAW_OPEN_POSITION) {
        startTask(open_claw);
    }
    if (JOYSTICK_ARM_UP) {
        if (dc_limit_lift && current_sensor_value > ARM_LIMIT_POSITION) {
	        set_arm(0);
	        return;
	    }
        set_arm(127);
    } else if (JOYSTICK_ARM_DOWN) {
        set_arm(-127);
    } else {
        set_arm(0);
    }
    prev_sensor_value = current_sensor_value;
}

static void dc_claw(void)
{
    if (JOYSTICK_CLAW_OPEN) {
        set_claw(127);
    } else if (JOYSTICK_CLAW_CLOSE) {
        set_claw(-127);
    } else {
        set_claw(0);
    }
}
