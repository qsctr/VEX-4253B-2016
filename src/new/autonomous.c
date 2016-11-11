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

static void a_base_encoders_reset(void);
static int a_base_encoders_avg(void);

void pre_auton(void)
{
    a_base_encoders_reset();
}

task autonomous()
{
    set_base_drive(-127);
    set_arm(127);
    while (a_base_encoders_avg() < 1500);
    set_base_drive(0);
    set_arm(0);
}

static void a_base_encoders_reset(void)
{
    FOR_EACH(tMotor, m, base_motors, {
        resetMotorEncoder(m);
    })
}

static int a_base_encoders_avg(void)
{
    int total = 0;
    FOR_EACH(tMotor, m, base_encoders, {
        total += abs(nMotorEncoder(m));
    })
    return total / LENGTH(base_encoders);
}
