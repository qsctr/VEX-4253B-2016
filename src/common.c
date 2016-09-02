#define BASE_SPEED_FULL   127

void base_set(int fr, int br, int bl, int fl);
void base_set(int power);

// void shooter_set(int x);

#define LCD_BUTTON_LEFT   1
#define LCD_BUTTON_CENTER 2
#define LCD_BUTTON_RIGHT  4
#define LCD_BUTTON_NONE   0
#define LCD_LINE_TOP      0
#define LCD_LINE_BOTTOM   1

void lcd_voltage(void);
void lcd_clear(void);
