bool base_enabled = true;

#define SHOOTER_MODE_NONE   0
#define SHOOTER_MODE_DIRECT 1
#define SHOOTER_MODE_SLIP   2
#define SHOOTER_MODE_KICKER 3
#define SHOOTER_MODE_OVER   4

const string shooter_mode_names[] = {"NONE  ", "DIRECT", "SLIP  ", "KICKER"};

int shooter_mode = SHOOTER_MODE_NONE;

void base_toggle(void);
void shooter_mode_next(void);
