#ifndef BUTTONSETUP_H
#define BUTTONSETUP_H
/* I typically don't like splitting just into header files,
 * but makes it a bit easier to read for those who aren't 
 * as comfortable with the code
 */

#include <Arduino.h>

// Button config
#define BTN0_PIN 35
#define BTN1_PIN 0
#define CUSTOM_DEBOUNCE_DELAY   50
// Time the library waits for a second (or more) clicks
// Set to 0 to disable double clicks but get a faster response
#define CUSTOM_REPEAT_DELAY     0
DebounceEvent * button0;
DebounceEvent * button1;
#define LONGPRESS_LEN 400
#define WIFI_RESET_LEN 1000*10

static void setupButtons() {
  button0 = new DebounceEvent(BTN0_PIN, BUTTON_PUSHBUTTON | BUTTON_DEFAULT_HIGH | BUTTON_SET_PULLUP, CUSTOM_DEBOUNCE_DELAY, CUSTOM_REPEAT_DELAY);
  button1 = new DebounceEvent(BTN1_PIN, BUTTON_PUSHBUTTON | BUTTON_DEFAULT_HIGH | BUTTON_SET_PULLUP, CUSTOM_DEBOUNCE_DELAY, CUSTOM_REPEAT_DELAY);
}

#endif /* BUTTONSETUP_H */
