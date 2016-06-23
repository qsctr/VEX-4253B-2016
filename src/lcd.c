void lcd_voltage() {

    string voltage;
    sprintf(voltage, "%1.2f VOLTS", nImmediateBatteryLevel * 0.001);
    displayLCDCenteredString(LCD_LINE_TOP, voltage);

}

void lcd_clear() {

    clearLCDLine(LCD_LINE_TOP);
    clearLCDLine(LCD_LINE_BOTTOM);

}
