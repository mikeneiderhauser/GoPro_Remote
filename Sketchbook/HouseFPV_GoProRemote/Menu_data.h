#ifndef MENU_DATA_H
#define MENU_DATA_H

#include "Menu.h"

// https://github.com/KonradIT/goprowifihack/blob/master/HERO5/HERO5-Commands.md

String ConsoleMenu::rootMenuName = "Main Menu";
MENU ConsoleMenu::_root[] = {
  {true, "ProTune",       "", ConsoleMenu::_protune},
  {true, "White Balance", "", ConsoleMenu::_whitebalance},
  {true, "Color Profile", "", ConsoleMenu::_color},
  {true, "ISO Limit",     "", ConsoleMenu::_isolimit},
  {true, "ISO Mode",      "", ConsoleMenu::_isolimit},
  {true, "Sharpness",     "", ConsoleMenu::_sharpness},
  {true, "Exp. Val",      "", ConsoleMenu::_expval},
  {true, "Exp. FPS",      "", ConsoleMenu::_expfps},
  {true, "Locate",        "", ConsoleMenu::_locate},
  {true, "RESET WIFI",    USER_RESET_WIFI_STR, NULL}, // Special Menu
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_protune[] = {
  {true, "On",  "10/1", NULL},
  {true, "Off", "10/0", NULL},
  {true, MENU_BACK, "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_whitebalance[] = {
  {true, "Auto",   "11/0", NULL},
  {true, "3000K",  "11/1", NULL},
  {true, "4000K",  "11/5", NULL},
  {true, "4800K",  "11/6", NULL},
  {true, "5500K",  "11/2", NULL},
  {true, "6000K",  "11/7", NULL},
  {true, "6500K",  "11/3", NULL},
  {true, "Native", "11/4", NULL},
  {true, MENU_BACK,    "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_color[] = {
  {true, "GoPro", "12/0", NULL},
  {true, "Flat",  "12/1", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_isolimit[] = {
  {true, "6000", "13/0", NULL},
  {true, "3200", "13/3", NULL},
  {true, "1600", "13/1", NULL},
  {true, "800 ", "13/4", NULL},
  {true, "400 ", "13/2", NULL},
  {true, "200 ", "13/7", NULL},
  {true, "100 ", "13/8", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_isomode[] = {
  {true, "Max", "74/0", NULL},
  {true, "Lock","74/1", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_sharpness[] = {
  {true, "High",   "14/0", NULL},
  {true, "Medium", "14/2", NULL},
  {true, "Low"   , "14/1", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL},
};

MENU ConsoleMenu::_expval[] = {
  {true, "+2.0", "15/0", NULL},
  {true, "+1.5", "15/1", NULL},
  {true, "+1.0", "15/2", NULL},
  {true, "+0.5", "15/3", NULL},
  {true, "+0.0", "15/4", NULL},
  {true, "-0.5", "15/5", NULL},
  {true, "-1.0", "15/6", NULL},
  {true, "-1.5", "15/7", NULL},
  {true, "-2.0", "15/8", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps[] = {
  {true, "Auto FPS", "73/0", NULL},
  {true, "24 FPS",  "", NULL},
  {true, "30 FPS",  "", NULL},
  {true, "48 FPS",  "", NULL},
  {true, "60 FPS",  "", NULL},
  {true, "90 FPS",  "", NULL},
  {true, "120 FPS", "", NULL},
  {true, "240 FPS", "", NULL},
  {true, MENU_BACK,   "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_24[] = {
  {true, "1/24", "73/3", NULL},
  {true, "1/48", "73/6", NULL},
  {true, "1/96", "73/11", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_30[] = {
  {true, "1/24", "73/5", NULL},
  {true, "1/48", "73/8", NULL},
  {true, "1/96", "73/13", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_48[] = {
  {true, "1/24", "73/6", NULL},
  {true, "1/48", "73/11", NULL},
  {true, "1/96", "73/16", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_60[] = {
  {true, "1/24", "73/8", NULL},
  {true, "1/48", "73/13", NULL},
  {true, "1/96", "73/18", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_90[] = {
  {true, "1/24", "73/10", NULL},
  {true, "1/48", "73/15", NULL},
  {true, "1/96", "73/20", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_120[] = {
  {true, "1/24","73/13", NULL},
  {true, "1/48", "73/18", NULL},
  {true, "1/96", "73/22", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_expfps_240[] = {
  {true, "1/24", "73/13", NULL},
  {true, "1/48", "73/18", NULL},
  {true, "1/96", "73/22", NULL},
  {true, MENU_BACK,  "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

MENU ConsoleMenu::_locate[] = {
  {true, "On",  "http://10.5.5.9/gp/gpControl/command/system/locate?p=1", NULL},
  {true, "Off", "http://10.5.5.9/gp/gpControl/command/system/locate?p=0", NULL},
  {true, MENU_BACK, "", NULL},
  {false, "unused", "", NULL}  // null ref for menu
};

#endif /* MENU_DATA_H */
