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

#define WITH_PREVIOUS(type, val, def, block)   {                               \
                                                   static type previous = def; \
                                                   type current = val;         \
                                                   block                       \
                                                   previous = current;         \
                                               }

#define STRAIGHT(ch)           (abs(vexRT[ch]) < 40 ? 0 : vexRT[ch])
#define JOYSTICK_DRIVE         STRAIGHT(Ch3)
#define JOYSTICK_STRAFE        STRAIGHT(Ch4)
#define JOYSTICK_ROTATE        STRAIGHT(Ch1)
#define BUTTON_ARM_UP          vexRT[Btn6U]
#define BUTTON_ARM_DOWN        vexRT[Btn6D]
#define BUTTON_CLAW_OPEN       vexRT[Btn5U]
#define BUTTON_CLAW_CLOSE      vexRT[Btn5D]
#define TOGGLE_LIMIT_ARM       vexRT[Btn8U]
#define TOGGLE_CLAW_ALWAYS_ON  vexRT[Btn7U]
#define TONE_LENGTH            50

static void dc_base(void);
static void dc_arm(void);
static void dc_limit_arm_check(void);
static void dc_claw(void);
static void dc_claw_auto_open(void);
static void dc_claw_always_on_check(void);
static void dc_lcd_buttons(void);

static bool dc_limit_arm = true;
static bool dc_claw_always_on = true;

task usercontrol()
{
    init_lcd();
    while (1) {
	    dc_base();
	    dc_arm();
	    dc_limit_arm_check();
	    dc_claw();
	    dc_claw_auto_open();
	    dc_claw_always_on_check();
	    dc_lcd_buttons();
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
    if (BUTTON_ARM_UP && !(dc_limit_arm && SensorValue(potArm) > ARM_LIMIT_POSITION)) {
        set_arm(127);
    } else if (BUTTON_ARM_DOWN) {
        set_arm(-127);
    } else {
        set_arm(0);
    }
}

static void dc_limit_arm_check(void)
WITH_PREVIOUS(int, TOGGLE_LIMIT_ARM, 0, {
    if (current && !previous) {
        dc_limit_arm = !dc_limit_arm;
        playImmediateTone(dc_limit_arm ? 1200 : 700, TONE_LENGTH);
    }
})

static void dc_claw(void)
{
    if (BUTTON_CLAW_OPEN) {
        set_claw(127);
    } else if (BUTTON_CLAW_CLOSE) {
        set_claw(-127);
    } else if (dc_claw_always_on) {
        set_claw(-10);
    } else {
        set_claw(0);
    }
}

static void dc_claw_auto_open(void)
WITH_PREVIOUS(int, SensorValue(potArm), 4096, {
    if (current > CLAW_OPEN_POSITION && previous <= CLAW_OPEN_POSITION) {
        startTask(open_claw);
    }
})

static void dc_claw_always_on_check(void)
WITH_PREVIOUS(int, TOGGLE_CLAW_ALWAYS_ON, 0, {
    if (current && !previous) {
        dc_claw_always_on = !dc_claw_always_on;
        playImmediateTone(dc_claw_always_on ? 1000 : 600, TONE_LENGTH);
    }
})

static void dc_lcd_buttons(void)
{
    if (nLCDButtons == 1) {
        playImmediateTone(523, 20);
    } else if (nLCDButtons == 3) {
        playImmediateTone(554, 20);
    } else if (nLCDButtons == 2) {
        playImmediateTone(587, 20);
    } else if (nLCDButtons == 6) {
        playImmediateTone(622, 20);
    } else if (nLCDButtons == 4) {
        playImmediateTone(659, 20);
    }
}
