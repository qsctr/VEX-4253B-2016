#define DC_BASE_MODE_OFF       0
#define DC_BASE_MODE_NO_GYRO   1
#define DC_BASE_MODE_GYRO      2
#define DC_BASE_MODE_OVER      3

const string dc_base_mode_names[] = {"    OFF", "NO GYRO", "   GYRO"};
int dc_base_mode = DC_BASE_MODE_GYRO;

#define DC_SHOOTER_MODE_NONE   0
#define DC_SHOOTER_MODE_DIRECT 1
#define DC_SHOOTER_MODE_SLIP   2
#define DC_SHOOTER_MODE_KICKER 3
#define DC_SHOOTER_MODE_OVER   4

const string dc_shooter_mode_names[] = {"NONE  ", "DIRECT", "SLIP  ", "KICKER"};
int dc_shooter_mode = DC_SHOOTER_MODE_DIRECT; // mode on startup

void dc_base_mode_next(void);
void dc_shooter_mode_next(void);
void dc_lcd_gyro_reset(void);
