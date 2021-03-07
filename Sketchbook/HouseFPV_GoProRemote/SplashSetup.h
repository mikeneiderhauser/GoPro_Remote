#ifndef SPLASHSETUP_H
#define SPLASHSETUP_H
/* I typically don't like splitting just into header files,
 * but makes it a bit easier to read for those who aren't 
 * as comfortable with the code
 */

#include "UserConfig.h"
#ifdef USER_SPLASH_INCLUDE_EXTRA
  #include "SplashExtra.h"
#endif

void userSplash()
{
  tft.fillScreen(USER_SPLASH_DEFAULT_BG);
  tft.setTextColor(USER_SPLASH_DEFAULT_TXT, USER_SPLASH_DEFAULT_BG);
  
  tft.setTextSize(USER_SPLASH_LINE_1_SZ);
  tft.setTextColor(USER_SPLASH_LINE_1_TXT, USER_SPLASH_LINE_1_BG);
  tft.setCursor(USER_SPLASH_LINE_1_X, USER_SPLASH_LINE_1_Y);
  tft.println(USER_SPLASH_LINE_1);

  tft.setTextSize(USER_SPLASH_LINE_2_SZ);
  tft.setTextColor(USER_SPLASH_LINE_2_TXT, USER_SPLASH_LINE_2_BG);
  tft.setCursor(USER_SPLASH_LINE_2_X, USER_SPLASH_LINE_2_Y);
  tft.println(USER_SPLASH_LINE_2);

  tft.setTextSize(USER_SPLASH_LINE_3_SZ);
  tft.setTextColor(USER_SPLASH_LINE_3_TXT, USER_SPLASH_LINE_3_BG);
  tft.setCursor(USER_SPLASH_LINE_3_X, USER_SPLASH_LINE_3_Y);
  tft.println(USER_SPLASH_LINE_3);
  
  delay(USER_SPLASH_DISPLAY_SHOW_TIME);

  #ifdef USER_SPLASH_INCLUDE_EXTRA
  userSplashExtra();
  #endif
}

#endif /* SPLASHSETUP.h */
