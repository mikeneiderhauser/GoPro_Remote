#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <stack>
#include "UserConfig.h"

#define MENU_BACK USER_MENU_BACK_STR

//https://github.com/lcd11001/opencv/blob/ConsoleMenu/LearningOpenCV/LearningOpenCV/ConsoleMenu.cpp
//https://github.com/lcd11001/opencv/blob/ConsoleMenu/LearningOpenCV/LearningOpenCV/ConsoleMenu.h

typedef int (*MENU_FUNCTION_POINTER)();

typedef struct _MENU MENU;
typedef MENU* MENU_POINTER;

struct _MENU
{
  bool isValid; // C++ can not compare struct is NULL
  String text;
  String data;
  MENU_POINTER childMenu;
};

class ConsoleMenu
{
  public:
    ConsoleMenu(); // constructor
    int lenMenu();

    MENU_POINTER prevMenuItem();
    MENU_POINTER currMenuItem();
    MENU_POINTER nextMenuItem();

    String currMenuName();

    void incMenuIdx();
    void decMenuIdx();

    MENU_POINTER menuSelected();


  private:
    static String rootMenuName;
    static MENU _root[];
    static MENU _protune[];
    static MENU _whitebalance[];
    static MENU _color[];
    static MENU _isolimit[];
    static MENU _isomode[];
    static MENU _sharpness[];
    static MENU _expval[];
    static MENU _expfps[];
    static MENU _expfps_24[];
    static MENU _expfps_30[];
    static MENU _expfps_48[];
    static MENU _expfps_60[];
    static MENU _expfps_90[];
    static MENU _expfps_120[];
    static MENU _expfps_240[];
    static MENU _locate[];

    uint8_t curr_menu_idx;
    MENU_POINTER cMenu;

    std::stack <MENU_POINTER> menuPrevPtr;
    std::stack <int> menuPrevIdx;
};

#endif /* MENU_H */
