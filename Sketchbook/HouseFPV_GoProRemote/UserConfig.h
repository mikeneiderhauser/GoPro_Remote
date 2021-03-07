#ifndef USERCONFIG_H
#define USERCONFIG_H

/* Colors from TFT_eSPI.h
TFT_BLACK, TFT_NAVY, TFT_DARKGREEN, TFT_DARKCYAN, TFT_MAROON, TFT_PURPLE,
TFT_OLIVE, TFT_LIGHTGREY, TFT_DARKGREY, TFT_BLUE, TFT_GREEN, TFT_CYAN,
TFT_RED, TFT_MAGENTA, TFT_YELLOW, TFT_WHITE, TFT_ORANGE, TFT_GREENYELLOW,
TFT_PINK, TFT_BROWN, TFT_GOLD, TFT_SILVER, TFT_SKYBLUE, TFT_VIOLET
*/

/* Serial Port Config */
#define USER_SERIAL_PORT_SPEED 115200
#define USER_RETRY_MAX 2
#define USER_GP_CONNECTION_SETTINGS_STR "http://10.5.5.9/gp/gpControl/setting/"

/* Menu Control Options */
#define USER_MENU_ACTIVE_STR ""
//#define USER_MENU_ACTIVE_STR ">"
#define USER_MENU_BACK_STR "<- Back"

/* Chars around menu title */
#define USER_MENU_TITLE_WRAPPER_PRE  ""
#define USER_MENU_TITLE_WRAPPER_POST ""

/* TFT Formatting Options */
//#include "TFT_eSPI/TFT_eSPI.h"
#include <TFT_eSPI.h>
#define USER_TFT_ROTATION 1 /* Landscape == 1*/
#define USER_TFT_INIT_CURSOR_X 0
#define USER_TFT_INIT_CURSOR_Y 5

/* TFT User Specific Formatting Options */
/* NOTE: Max char len (len of USER_MENU_ACTIVE_STR and Menu Entry TEXT)
 * cannot exceed 13 chars when TEXT_SIZE is 3.
 * Offest chars in menu settings above and use colors below to make it fit.
 * Alt, modify Menu_data.h to get text to fit.
 */
#define USER_TFT_TEXT_SIZE 3

/* For colors , see TFT_eSPI/TFT_eSPI.h - Section 6 */
/* Color for Menu Title */
#define USER_TFT_TITLE_BG  TFT_BLACK
#define USER_TFT_TITLE_TXT TFT_GOLD

/* Color for non-selected menu items */
#define USER_TFT_DEFAULT_BG  TFT_BLACK
#define USER_TFT_DEFAULT_TXT TFT_WHITE

/* Color for Active selected menu items*/
#define USER_TF_DEFAULT_SEL_BG  TFT_SILVER
#define USER_TF_DEFAULT_SEL_TXT TFT_BLUE

/* User Splash Screen */
#define USER_SPLASH_DISPLAY_SHOW_TIME 2000
#define USER_SPLASH_JPEG
//#define USER_SPLASH_TEXT
#ifdef USER_SPLASH_TEXT
  #define USER_SPLASH_DEFAULT_BG TFT_BLACK
  #define USER_SPLASH_DEFAULT_TXT TFT_WHITE
  
  #define USER_SPLASH_LINE_1_X 40
  #define USER_SPLASH_LINE_1_Y 5
  #define USER_SPLASH_LINE_1_SZ 5
  #define USER_SPLASH_LINE_1_BG TFT_BLACK
  #define USER_SPLASH_LINE_1_TXT TFT_WHITE
  #define USER_SPLASH_LINE_1 "GoPro"
  
  #define USER_SPLASH_LINE_2_X 40
  #define USER_SPLASH_LINE_2_Y 50
  #define USER_SPLASH_LINE_2_SZ 5
  #define USER_SPLASH_LINE_2_BG TFT_BLACK
  #define USER_SPLASH_LINE_2_TXT TFT_WHITE
  #define USER_SPLASH_LINE_2 "Remote"
  
  #define USER_SPLASH_LINE_3_X 5
  #define USER_SPLASH_LINE_3_Y 100
  #define USER_SPLASH_LINE_3_SZ 3
  #define USER_SPLASH_LINE_3_BG TFT_BLACK
  #define USER_SPLASH_LINE_3_TXT TFT_WHITE
  #define USER_SPLASH_LINE_3 "By: HouseFPV"
#endif /* USER_SPLASH_TEXT */

/* See SplashExtra.h */
#define USER_SPLASH_INCLUDE_EXTRA

#define USER_RESET_WIFI_STR "rWifi"
#define USER_WIFI_AP_NAME "HouseFPV Remote"

// #define USER_DISABLE_WIFI  /* Uncomment to disable connection to GoPro and SoftAP for testing */

#endif /* USERCONFIG_H */
