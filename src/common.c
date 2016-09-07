#define BASE_SPEED_FULL   127

void base_set(int fr, int br, int bl, int fl);
void base_set(int power);

#define DUMP_UP           127
#define DUMP_DOWN         -60
#define DUMP_HOLD         15

void dump_set(int x);

void lift_set(int x);

#define LCD_BUTTON_LEFT   1
#define LCD_BUTTON_CENTER 2
#define LCD_BUTTON_RIGHT  4
#define LCD_BUTTON_NONE   0
#define LCD_LINE_TOP      0
#define LCD_LINE_BOTTOM   1

void lcd_voltage(void);
void lcd_clear(void);

///////////////////////////////////////////////////////////

// Get rid of annoying "unreferenced function" warnings
static void DO_NOT_CALL_THIS_FUNCTION(void) {

    DO_NOT_CALL_THIS_FUNCTION();
    UserControlCodePlaceholderForTesting();
    AutonomousCodePlaceholderForTesting();

}
