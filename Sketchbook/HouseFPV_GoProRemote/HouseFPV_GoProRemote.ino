#include <DebounceEvent.h>
#include <WiFiManager.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <stack>

//#include "TFT_eSPI/TFT_eSPI.h"  // different version of lib avail upstream..
#include <TFT_eSPI.h>  // different version of lib avail upstream..
#include <SPI.h>

#include "Menu.h"
#include "Menu_data.h"

/* Some globally accessible vars */
ConsoleMenu* remote_menu = NULL;
MENU_POINTER m = NULL;
bool menu_displayed = false;
String batStr = "";
TFT_eSPI tft = TFT_eSPI();
WiFiManager wifiManager;
std::stack <String> updates;

/* for screen update interval */
unsigned long currentMillis = 0;
unsigned long prevScreeUpdate = 0;
unsigned long updateMillisInterval = (60 * 1000);


/* Helper includes */
#include "ButtonSetup.h"
#include "UpdateDisplay.h"
#include "BatterySetup.h"
#include "SplashSetup.h"
#include "WifiSetup.h"

void setup() {
  setupSerial();
  setupTFT();
  setupButtons();
  setupBatMon();

  /* New instance of primary menu system driver */
  remote_menu = new ConsoleMenu();

  /* Display user Splash Screen */
  userSplash();

  setupWifi();
}

void sendGPUpdate(String m) {
#ifdef USER_IGNORE_WIFI
  sendingWifiTFT();
  delay(2000);
#endif
  /* HTTP WORK */
  if (WiFi.status() == WL_CONNECTED) {
    sendingWifiTFT();
    String req;
    if (m.startsWith("http")) {
      req = m;
    } else {
      req = USER_GP_CONNECTION_SETTINGS_STR + m;
    }

    /* Start HTTP Client request */
    HTTPClient http_client;
    bool complete = false;
    byte ct = 0;
    while (!complete) {
      /* Create Request */
      Serial.print("Sending request: "); Serial.println(req);
      int resp = 0;
      http_client.begin(req.c_str());
      /* Send request */
      resp = http_client.GET();
      yield();
      if (resp == 200) {
        complete = true;
      }
      else
      {
        ct++;
        if (ct < USER_RETRY_MAX) {
          Serial.println("Did not get 200 back, retrying..");
        } else {
          Serial.println("USER_RETRY_MAX reached. Canceling Request.");
          failedWifiTFT();
          delay(2000);
          complete = true;
        }
      } // end resp 200
    } // end while
    http_client.end();
    /* END HTTP WORK */
  } else {
    Serial.println("Wifi not connected..");
  }
  menu_displayed = false; // force next loop to redraw display
}

void loop() {
  /* Main Processing loop */
  currentMillis = millis();
  /* Force screen update every updateMillisInterval */
  if (currentMillis - prevScreeUpdate >= updateMillisInterval) {
    menu_displayed = false;
    Serial.println("Forcing Screen Refresh");
  }

  /* Handle display update */
  if (! menu_displayed) {
    batStr = readBatMon();
    updateSerialMenu();
    updateTFTMenu();
    menu_displayed = true;
    prevScreeUpdate = millis();
  }

  /* Handle button presses / menu state changes */
  if (unsigned int event = button0->loop()) {
    if (event == EVENT_RELEASED) {

      Serial.print("Top button -> "); Serial.print("Count : "); Serial.print(button0->getEventCount());
      Serial.print(" Length: "); Serial.print(button0->getEventLength());
      Serial.println();

      /* short press increment idx, long press decrement idx */
      if (button0->getEventLength() >= LONGPRESS_LEN) {
        remote_menu->decMenuIdx();
      } else {
        remote_menu->incMenuIdx();
      }
      menu_displayed = false;
    }
  }
  if (unsigned int event = button1->loop()) {
    if (event == EVENT_RELEASED) {

      Serial.print("Bot button -> "); Serial.print("Count : "); Serial.print(button1->getEventCount());
      Serial.print(" Length: "); Serial.print(button1->getEventLength());
      Serial.println();

      m = remote_menu->menuSelected();
      if (m != NULL) {
        /* WIFI Reset menu */
        if (m->data == USER_RESET_WIFI_STR) {
          if (button1->getEventLength() >= WIFI_RESET_LEN) {
            Serial.println("RESETTING STORED WIFI SETTINGS...");
            wifiManager.resetSettings();
            delay(200);
            Serial.println("Rebooting...");
            ESP.restart();
          } else {
            Serial.println("Not held long enough to reset WIFI..");
          }
        } else {
          /* Add gopro cmd to update stack */
          updates.push(m->data);
        }
      }
      menu_displayed = false;
    }
  }

  /* Handle sending cfg updates */
  if (!updates.empty()) {
    sendGPUpdate(updates.top());
    updates.pop();
  }
}
