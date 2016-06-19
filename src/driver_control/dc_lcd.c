/*

Example driver control LCD screen

|   7.20 VOLTS   |
| DIRECT      ON |

*/

#define DC_LCD_POS_SHOOTER 1
#define DC_LCD_POS_BASE    8

void dc_lcd_init(void);
void dc_lcd(void);
void dc_lcd_buttons(void);
void dc_lcd_shooter(void);
void dc_lcd_base(void);

void dc_lcd_init() {

    lcd_clear();
    dc_lcd_shooter();
    dc_lcd_base();
    bLCDBacklight = true;

}

void dc_lcd() {

    lcd_voltage();
    dc_lcd_buttons();

}

void dc_lcd_buttons() {

    static int prev = nLCDButtons;

    if (prev != nLCDButtons && nLCDButtons == LCD_BUTTON_NONE)
        switch (prev) {

            case LCD_BUTTON_LEFT:
                dc_shooter_mode_next();
                dc_lcd_shooter();
                break;

            case LCD_BUTTON_CENTER:
                bLCDBacklight = !bLCDBacklight;
                break;

            case LCD_BUTTON_RIGHT:
                dc_base_mode_next();
                dc_lcd_base();
                break;

        }

    prev = nLCDButtons;

}

void dc_lcd_shooter() {

    displayLCDString(LCD_LINE_BOTTOM, DC_LCD_POS_SHOOTER, dc_shooter_mode_names[dc_shooter_mode]);

}

void dc_lcd_base() {

    displayLCDString(LCD_LINE_BOTTOM, DC_LCD_POS_BASE, dc_base_mode_names[dc_base_mode]);

}
