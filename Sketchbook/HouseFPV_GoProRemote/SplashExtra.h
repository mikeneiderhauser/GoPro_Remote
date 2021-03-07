#ifndef SPLASHEXTRA_H
#define SPLASHEXTRA_H
/* I typically don't like splitting just into header files,
 * but makes it a bit easier to read for those who aren't 
 * as comfortable with the code
 */

#include "UserConfig.h"

#include "SplashJpegHelper.h"
#include "SplashSendit.h"

void userSplashTransition() {
  tft.fillScreen(TFT_WHITE);
  delay(100);
  tft.fillScreen(TFT_BLACK);
  delay(100);
  tft.fillScreen(TFT_WHITE);
  delay(100);
  tft.fillScreen(TFT_BLACK);
  delay(100);
}

void userSplashExtra4LineText() {
  userSplashTransition();
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(4);
  tft.setCursor(30, 10);
  tft.println("THINK IT");
  delay(750);
  tft.setCursor(30, 40);
  tft.println("SEE IT");
  delay(750);
  tft.setCursor(30, 70);
  tft.println("SAY IT");
  delay(750);
  tft.setCursor(30, 100);
  tft.println("BE IT");
  delay(750);

}

void userSplashExtraImage() {
  // NOTE DO NOT USE PROGRESSIVE ENCODING ON THE JPEG!
  renderJPEG(housefpv_sendit, sizeof(housefpv_sendit), 0, 0);
  delay(3000);
}

void userSplashExtra() {
  //userSplashExtra4LineText();
  userSplashExtraImage();
}


#endif /* SPLASHEXTRA_H */
