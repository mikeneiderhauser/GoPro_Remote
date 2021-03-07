#ifndef BATTERYSETUP_H
#define BATTERYSETUP_H
/* I typically don't like splitting just into header files,
 * but makes it a bit easier to read for those who aren't 
 * as comfortable with the code
 */

#define ADC_PIN 34
#define VREF 1100

void setupBatMon() {
  // None in factoryTest ex
}

String readBatMon() {
  // Primarily taken from FactoryTest for TTGO Display
  uint16_t v = analogRead(ADC_PIN);
  float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (VREF / 1000.0);
  return "Bat: " + String(battery_voltage) + "V";
}

#endif /* BATTERYSETUP_H */
