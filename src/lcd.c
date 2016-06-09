#define LCD_BUTTON_LEFT   1
#define LCD_BUTTON_CENTER 2
#define LCD_BUTTON_RIGHT  4
#define LCD_BUTTON_NONE   0
#define LCD_LINE_TOP      0
#define LCD_LINE_BOTTOM   1
#define LCD_POS_SHOOTER   1
#define LCD_POS_BASE      12

void lcd_voltage(void);
void lcd_buttons(void);
void lcd_shooter(void);
void lcd_base(void);
void lcd_clear(void);

/*

Example driver control LCD screen

|   7.20 VOLTS   |
| DIRECT      ON |

Example autonomous LCD screen

|   7.20 VOLTS   |
|   AUTONOMOUS   |

*/

void lcd_init_auto() {

    lcd_clear();
    displayLCDCenteredString(LCD_LINE_BOTTOM, "AUTONOMOUS");
    bLCDBacklight = true;

}

void lcd_init_driver() {

    lcd_clear();
    lcd_shooter();
    lcd_base();
    bLCDBacklight = true;

}

void lcd_auto() {

    lcd_voltage();

}

void lcd_driver() {

    lcd_voltage();
    lcd_buttons();

}

void lcd_voltage() {

    string voltage;
    sprintf(voltage, "%1.2f VOLTS", nImmediateBatteryLevel * 0.001);
    displayLCDCenteredString(LCD_LINE_TOP, voltage);

}

void lcd_buttons() {

    static int prev = nLCDButtons;

    if (prev != nLCDButtons && nLCDButtons == LCD_BUTTON_NONE)
        switch (prev) {

	        case LCD_BUTTON_LEFT:
	            shooter_stop();
	            shooter_mode++;
	            if (shooter_mode == SHOOTER_MODE_OVER)
	                shooter_mode = SHOOTER_MODE_NONE;
	            lcd_shooter();
	            break;

            case LCD_BUTTON_CENTER:
                bLCDBacklight = !bLCDBacklight;
                break;

            case LCD_BUTTON_RIGHT:
	            base_enabled = !base_enabled;
	            if (!base_enabled)
	                base_stop();
	            lcd_base();
	            break;
        }

    prev = nLCDButtons;

}

void lcd_shooter() {

    displayLCDString(LCD_LINE_BOTTOM, LCD_POS_SHOOTER, shooter_mode_names[shooter_mode]);

}

void lcd_base() {

    displayLCDString(LCD_LINE_BOTTOM, LCD_POS_BASE, base_enabled ? " ON" : "OFF");

}

void lcd_clear() {

    clearLCDLine(LCD_LINE_TOP);
    clearLCDLine(LCD_LINE_BOTTOM);

}
