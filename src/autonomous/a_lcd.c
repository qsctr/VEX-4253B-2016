/*

Example autonomous LCD screen

|   7.20 VOLTS   |
|   AUTONOMOUS   |

*/

void a_lcd_init(void);
void a_lcd(void);

void a_lcd_init() {

    lcd_clear();
    displayLCDCenteredString(LCD_LINE_BOTTOM, "AUTONOMOUS");
    bLCDBacklight = true;

}

void a_lcd() {

    lcd_voltage();

}
