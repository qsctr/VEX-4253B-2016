/*

Example driver control LCD screen

|   7.20 VOLTS   |
| DIRECT      ON |

*/

#define DC_LCD_POS_SHOOTER 1
#define DC_LCD_POS_BASE    8

static void dc_lcd_buttons(void);
static void dc_lcd_base(void);

void dc_lcd_init() {

    lcd_clear();
    dc_lcd_base();
    bLCDBacklight = true;

}

void dc_lcd() {

    lcd_voltage();
    dc_lcd_buttons();

}

static void dc_lcd_buttons() {

    static int prev = nLCDButtons;

    if (prev != nLCDButtons && nLCDButtons == LCD_BUTTON_NONE)
        switch (prev) {

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

static void dc_lcd_base() {

    displayLCDString(LCD_LINE_BOTTOM, DC_LCD_POS_BASE, dc_base_mode_names[dc_base_mode]);

}

void dc_lcd_gyro_reset() {

    /* |/ _ \ / |_) / \ |
       |\_/  |  | \ \_/ | */

    lcd_clear();
    displayLCDString(LCD_LINE_TOP,    0, "/ _ \\ / |_) / \\");
    displayLCDString(LCD_LINE_BOTTOM, 0, "\\_/  |  | \\ \\_/");

}
