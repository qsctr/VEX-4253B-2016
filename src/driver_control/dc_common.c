bool dc_base_enabled = true;

#define DC_SHOOTER_MODE_NONE   0
#define DC_SHOOTER_MODE_DIRECT 1
#define DC_SHOOTER_MODE_SLIP   2
#define DC_SHOOTER_MODE_KICKER 3
#define DC_SHOOTER_MODE_OVER   4

const string dc_shooter_mode_names[] = {"NONE  ", "DIRECT", "SLIP  ", "KICKER"};

int dc_shooter_mode = DC_SHOOTER_MODE_NONE;

void dc_base_toggle(void);
void dc_shooter_mode_next(void);
