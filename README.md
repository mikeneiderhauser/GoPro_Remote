# GoPro_Remote

Rewrite of [DrDrone/GP_PT_Remote_Public](https://github.com/Dr-Drone/GP_PT_Remote_Public) to provide more visuals on the TFT Display.

Refactors with a full and extensible menu driver.

[GoPro Commands Reference](https://github.com/KonradIT/goprowifihack/blob/master/HERO5/HERO5-Commands.md)

[Menu System Reference](https://github.com/lcd11001/opencv/blob/ConsoleMenu/LearningOpenCV/LearningOpenCV/ConsoleMenu.cpp)

## Hardware
[TTGO T-Display - Banggood](https://www.banggood.com/TTGO-T-Display-ESP32-CP2104-WiFi-bluetooth-Module-1_14-Inch-LCD-Development-Board-LILYGO-for-Arduino-products-that-work-with-official-Arduino-boards-p-1522925.html?channel=youtube&utm_source=youtube&utm_medium=cussku&utm_campaign=marblekit_prdshare_copy&utm_content=zhikejian&_branch_match_id=888901708827552088&cur_warehouse=CN)

## Board Managers
https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json

## Libraries
### Manually checked in and referenced in the Sketch
https://github.com/Xinyuan-LilyGO/TTGO-T-Display

Follow instructions on their github to install a copy without library manager

### Used in the Sketch
* [DebounceEvent v2.0.5](https://github.com/xoseperez/debounceevent)
* [WiFiManager v2.0.3-alpha (tzapu)](https://github.com/tzapu/WiFiManager)
* WiFi - Arduino Built-In
* [ArduinoHTTPClient v0.4.0](https://github.com/arduino-libraries/ArduinoHttpClient)

## Setup / Usage
* Download and install Arduino (Tested on 1.8.13)
* Install boards through board manager
* Install Libs through library manager (listed above)
* Customization
    * Change UserConfig.h if desired (customization)
    * Change SplashExtra.h if desired (customization)
* Compile and Upload

Use the ESP32 Dev Module 4MB Target

## Functional Usage
### Initial Connection
* Connect to SoftAP (first boot)
* Use SoftAP to connect to GoPro cam network
    * Once connected, device reboots
* Will attempt to auto connect to GoPro

### Normal Operation
* Top Button
    * Short Press -> Cycle menu forward
    * Long Press -> Cycle menu reverse
* Bottom Button
    * Enter Menu / Apply setting / Action

### Connecting to a different GoPro
Navigate to the RESET WIFI menu in main menu. Long press the BOTTOM BUTTON for 10 Seconds.  If successful, the device will reboot.


