#ifndef WIFISETUP_H
#define WIFISETUP_H
/* I typically don't like splitting just into header files,
 * but makes it a bit easier to read for those who aren't 
 * as comfortable with the code
 */

#include <Arduino.h>
#include <WiFiManager.h>
#include <WiFi.h>
#include "UserConfig.h"
//#include "TFT_eSPI/TFT_eSPI.h"  // different version of lib avail upstream..
#include <TFT_eSPI.h>

void setupWifi() {
  WiFi.begin();  // needed to pull in saved network
  //wifiManager.setClass("invert");  // Set config portal to black

  /* Initial wifi connection messages */
  tft.fillScreen(USER_TFT_TITLE_BG);
  tft.setTextColor(USER_TFT_DEFAULT_TXT, USER_TFT_DEFAULT_BG);
  tft.setTextSize(USER_TFT_TEXT_SIZE);
  tft.setCursor(USER_TFT_INIT_CURSOR_X, USER_TFT_INIT_CURSOR_Y);

  String saved_ssid = wifiManager.getWiFiSSID(true);
  if(saved_ssid.length() > 0) {
    tft.println();
    tft.println("Connecting to");
    Serial.println("Connecting to");
    tft.println(saved_ssid);
    Serial.println(saved_ssid);
  }
  else
  {
    tft.println("0 Saved GoPro");
    Serial.println("0 Saved GoPro");
    tft.println();
    tft.println("Connect to AP");
    Serial.println("Connect to AP");
    String new_ap = String(USER_WIFI_AP_NAME);
    // note below check assumes size 3 for tft display
    if (new_ap.length() > 13) {
      tft.setTextSize(USER_TFT_TEXT_SIZE - 1);
    }

    tft.println();
    tft.println(new_ap);
    Serial.println(new_ap);
    
  }

  delay(2000);
  
  #ifndef USER_DISABLE_WIFI
  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  if (!wifiManager.autoConnect(USER_WIFI_AP_NAME)) {
    Serial.println("failed to connect and hit timeout");
    //reset and try again, or maybe put it to deep sleep
    ESP.restart();
    delay(1000);
  }
  #else
  delay(5000);
  #endif
}

#endif /* WIFISETUP.h */
