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

typedef int encoder_value;

static void a_base_encoders_reset(void);
static encoder_value a_base_encoders_avg(void);

void pre_auton(void)
{
    a_base_encoders_reset();
}

#ifdef NORMAL_MATCH
task autonomous()
{
    set_base_drive(-127);
    set_arm(127);
    while (a_base_encoders_avg() < 1500) {
        if (SensorValue(potArm) > 2200) {
            set_arm(0);
        }
    }
    set_arm(0);
    set_claw(127);
    while (SensorValue(potClaw) > 1000);
    set_claw(-127);
    while (SensorValue(potClaw) < 1800);
    set_claw(0);
    set_base_drive(127);
    // while (a_base_encoders_avg() > 1600);
    sleep(200);
    set_base_drive(0);
    startTask(open_claw);
    set_arm(50);
    while (SensorValue(potArm) < 2900);
    set_arm(0);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(-50);
    while (SensorValue(potArm) > 1000 || SensorValue(potArm) < 500);
    set_arm(0);
    // startTask(open_claw);
    set_base_drive(127);
    while (a_base_encoders_avg() > 1300);
    set_base_drive(0);
    sleep(1000);
#ifdef LEFT_SIDE
    set_base_strafe(127);
#endif
#ifdef RIGHT_SIDE
    set_base_strafe(-127);
#endif
    unsigned long time = nPgmTime;
    while (nPgmTime - time <= 700); // {
    //    if (abs(nMotorEncoder(mBaseStrafe)) >= 750) {
    //        break;
    //    }
    //}
    set_base_strafe(0);
    set_base_drive(127);
    time = nPgmTime;
    while (nPgmTime - time <= 700) {
        if (a_base_encoders_avg() <= 500) {
            break;
        }
    }
    set_base_drive(0);
    set_claw(-127);
    while (SensorValue(potClaw) < 1800);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_arm(127);
    set_base_drive(0);
    while (SensorValue(potArm) < 2900);
    set_arm(0);
    set_claw(127);
    while (SensorValue(potClaw) > 1000);
    set_claw(-127);
    while (SensorValue(potClaw) < 1800);
    set_claw(0);
    set_base_drive(127);
    while (a_base_encoders_avg() > 1300);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(-127);
    while (SensorValue(potArm) > 600 || SensorValue(potArm) < 500);
    set_arm(0);
    // set_base_drive(127);
    // while (a_base_encoders_avg() > 1500);
    // set_base_drive(0);
//    resetMotorEncoder(mBaseStrafe);
//#ifdef LEFT_SIDE
//    set_base_strafe(-127);
//#endif
//#ifdef RIGHT_SIDE
//    set_base_strafe(127);
//#endif
//    while (abs(nMotorEncoder(mBaseStrafe)) < 1800);
//    set_base_strafe(0);
//    set_base_drive(127);
//    sleep(500);
//    set_base_drive(0);
//    set_claw(-127);
//    sleep(2000);
//    set_base_drive(-127);
//    while (a_base_encoders_avg() < 1500);
//    set_base_drive(0);
//    set_arm(127);
//    while (SensorValue(potArm) < 2200);
//    set_arm(0);
//    startTask(open_claw);
}
#endif

int asdf = 0;

#ifdef PROG_SKILLS
task autonomous()
{
    set_base_drive(-127);
    set_arm(127);
    while (a_base_encoders_avg() < 1500) {
        if (SensorValue(potArm) > 2200) {
            set_arm(0);
        }
    }
    set_base_drive(0);
    while (SensorValue(potArm) <= 2200);
    set_arm(0);
    set_claw(127);
    while (SensorValue(potClaw) > 1000);
    set_claw(0);
    for (int i = 0; i < 4; i++) {
	    set_arm(-127);
	    while (SensorValue(potArm) > 600 || SensorValue(potArm) < 500);
	    set_arm(0);
	    set_base_drive(127);
	    while (a_base_encoders_avg() > 1000);
	    set_base_drive(0);
	    sleep(3000);
	    set_claw(-127);
	    sleep(2000);
	    set_claw(-30);
	    set_base_drive(-127);
	    set_arm(127);
	    while (a_base_encoders_avg() < 1200) {
	        if (SensorValue(potArm) > 2200) {
	            set_arm(0);
	        }
	    }
        set_base_drive(0);
	    while (SensorValue(potArm) <= 2200);
	    set_arm(0);
	    set_claw(127);
	    while (SensorValue(potClaw) > 1000);
	    set_claw(0);
    }
    set_arm(50);
    while (SensorValue(potArm) < 2900);
    set_arm(0);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(-50);
    while (SensorValue(potArm) > 1000 || SensorValue(potArm) < 500);
    set_arm(0);
    set_base_drive(127);
    while (a_base_encoders_avg() > 1200);
    set_base_drive(0);
    sleep(1000);
#ifdef LEFT_SIDE
    set_base_strafe(127);
#endif
#ifdef RIGHT_SIDE
    set_base_strafe(-127);
#endif
    sleep(700);
    set_base_strafe(0);
    asdf = a_base_encoders_avg();
    set_base_drive(127);
    // while (a_base_encoders_avg() > 800);
    sleep(700);
    set_base_drive(0);
    asdf = 42;
    set_claw(-127);
    while (SensorValue(potClaw) < 1800);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_arm(70);
    set_base_drive(0);
    while (SensorValue(potArm) < 2900);
    set_arm(0);
    startTask(open_claw);
    set_base_drive(127);
    while (a_base_encoders_avg() > 1300);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(-127);
    while (SensorValue(potArm) > 600 || SensorValue(potArm) < 500);
    set_arm(0);
    set_base_drive(-127);
    sleep(500);
    set_base_drive(127);
    sleep(200);
    set_base_drive(0);
    resetMotorEncoder(mBaseStrafe);
#ifdef LEFT_SIDE
    set_base_strafe(-127);
#endif
#ifdef RIGHT_SIDE
    set_base_strafe(127);
#endif
    while (abs(nMotorEncoder(mBaseStrafe)) < 2000);
    set_base_strafe(0);
    set_base_drive(127);
    sleep(500);
    set_base_drive(0);
    set_claw(-127);
    sleep(2000);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(127);
    while (SensorValue(potArm) < 2200);
    set_arm(0);
    startTask(open_claw);
    sleep(500);
    set_arm(-127);
    while (SensorValue(potArm) > 600 || SensorValue(potArm) < 500);
    set_arm(0);
    set_base_drive(127);
    sleep(700);
    set_base_drive(0);
    set_claw(-127);
    while (SensorValue(potClaw) < 1800);
    set_base_drive(-127);
    while (a_base_encoders_avg() < 1500);
    set_arm(70);
    set_base_drive(0);
    while (SensorValue(potArm) < 2900);
    set_arm(0);
    startTask(open_claw);
    sleep(500);
    set_arm(-127);
    while (SensorValue(potArm) > 600 || SensorValue(potArm) < 500);
    set_arm(0);
}
#endif

static void a_base_encoders_reset(void)
{
    FOR_EACH(tMotor, m, base_motors, {
        resetMotorEncoder(m);
    })
}

static encoder_value a_base_encoders_avg(void)
{
    int total = 0;
    FOR_EACH(tMotor, m, base_encoders, {
        total += abs(nMotorEncoder(m));
    })
    return total / LENGTH(base_encoders);
}
