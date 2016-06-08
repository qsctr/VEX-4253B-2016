bool base_enabled = true;

#define SHOOTER_MODE_NONE   0
#define SHOOTER_MODE_DIRECT 1
#define SHOOTER_MODE_SLIP   2
#define SHOOTER_MODE_OVER   3

const string shooter_mode_names[] = {"NONE  ", "DIRECT", "SLIP  "};

int shooter_mode = SHOOTER_MODE_NONE;

void base_stop(void);
void shooter_stop(void);
