#define LCD_BUTTON_LEFT   1
#define LCD_BUTTON_CENTER 2
#define LCD_BUTTON_RIGHT  4
#define LCD_BUTTON_NONE   0
#define LCD_LINE_TOP      0
#define LCD_LINE_BOTTOM   1

void lcd_voltage(void);
void lcd_clear(void);

void lcd_voltage() {

    string voltage;
    sprintf(voltage, "%1.2f VOLTS", nImmediateBatteryLevel * 0.001);
    displayLCDCenteredString(LCD_LINE_TOP, voltage);

}

void lcd_clear() {

    clearLCDLine(LCD_LINE_TOP);
    clearLCDLine(LCD_LINE_BOTTOM);

}
