#ifndef UPDATEDISPLAY_H
#define UPDATEDISPLAY_H
/* I typically don't like splitting just into header files,
   but makes it a bit easier to read for those who aren't
   as comfortable with the code
*/

#include "UserConfig.h"

void setupSerial() {
  Serial.begin(USER_SERIAL_PORT_SPEED);
}

void setupTFT() {
  tft.begin();
  tft.setRotation(USER_TFT_ROTATION); //Landscape
}

void updateSerialMenu()  {
  // Serial Framing
  Serial.println("--------");

  // Menu Name
  Serial.print(USER_MENU_TITLE_WRAPPER_PRE);
  Serial.print(remote_menu->currMenuName());
  Serial.println(USER_MENU_TITLE_WRAPPER_POST);

  // Prev
  m = remote_menu->prevMenuItem();
  Serial.println(m->text);

  // Current
  m = remote_menu->currMenuItem();
  Serial.print(USER_MENU_ACTIVE_STR); Serial.println(m->text);

  // Next
  m = remote_menu->nextMenuItem();
  Serial.println(m->text);

  // Serial Framing
  Serial.println("--------");
  Serial.println("");
}

void updateTFTMenu() {
  tft.fillScreen(USER_TFT_DEFAULT_BG);
  tft.setTextSize(USER_TFT_TEXT_SIZE);

  // Menu Name
  // TODO BAT
  tft.setTextColor(USER_TFT_TITLE_TXT, USER_TFT_TITLE_BG);
  tft.setCursor(USER_TFT_INIT_CURSOR_X, USER_TFT_INIT_CURSOR_Y);
  tft.print(USER_MENU_TITLE_WRAPPER_PRE);
  tft.print(remote_menu->currMenuName());
  tft.println(USER_MENU_TITLE_WRAPPER_POST);

  // Prev
  tft.setTextColor(USER_TFT_DEFAULT_TXT, USER_TFT_DEFAULT_BG);
  m = remote_menu->prevMenuItem();
  tft.println(m->text);

  // Current
  tft.setTextColor(USER_TF_DEFAULT_SEL_TXT, USER_TF_DEFAULT_SEL_BG);
  m = remote_menu->currMenuItem();
  tft.print(USER_MENU_ACTIVE_STR); tft.println(m->text);

  // Next
  tft.setTextColor(USER_TFT_DEFAULT_TXT, USER_TFT_DEFAULT_BG);
  m = remote_menu->nextMenuItem();
  tft.println(m->text);

  // TODO Battery size / font / color
  tft.println(batStr);
}

void sendingWifiTFT() {
  tft.fillScreen(USER_TFT_DEFAULT_BG);
  tft.setTextSize(USER_TFT_TEXT_SIZE);
  tft.setTextColor(USER_TFT_DEFAULT_TXT, USER_TFT_DEFAULT_BG);
  tft.setCursor(USER_TFT_INIT_CURSOR_X, USER_TFT_INIT_CURSOR_Y);
  
  tft.println("Sending CMD");
  tft.println("to GoPro");
  tft.println("via WiFi");
  tft.println("Please Wait");
}

void failedWifiTFT() {
  tft.fillScreen(TFT_RED);
  tft.setTextSize(3);
  tft.setTextColor(TFT_BLACK, TFT_RED);
  tft.setCursor(USER_TFT_INIT_CURSOR_X, USER_TFT_INIT_CURSOR_Y);
  
  tft.println("Failed");
  tft.println("Sending");
  tft.println("WiFi CMD!");
}

#endif /* UPDATEDISPLAY_H */
