/* COR:a.bc PE:a.bc
   BAC:a.bc         */

void lcd_voltage() {

    string top, bottom;
    sprintf(top, "COR:%1.2f PE:%1.2f", nImmediateBatteryLevel * 0.001, SensorValue(PowerExpanderBattery) / 280.0);
    sprintf(bottom, "BAC:%1.2f", BackupBatteryLevel * 0.001);
    displayLCDString(LCD_LINE_TOP, 0, top);
    displayLCDString(LCD_LINE_BOTTOM, 0, bottom);

}

void lcd_clear() {

    clearLCDLine(LCD_LINE_TOP);
    clearLCDLine(LCD_LINE_BOTTOM);

}
