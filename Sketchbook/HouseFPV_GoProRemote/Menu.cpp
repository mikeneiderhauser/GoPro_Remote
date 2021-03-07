#ifndef MENU_CPP
#define MENU_CPP

#include <Arduino.h>
#include <stack>
#include "Menu.h"
#include "UserConfig.h"

ConsoleMenu::ConsoleMenu()
{
  curr_menu_idx = 0;
  cMenu = _root;
}

int ConsoleMenu::lenMenu(){
  int idx = 0;
  while (cMenu[idx].isValid)
  {
    idx++;
  }
  return idx;
}

MENU_POINTER ConsoleMenu::prevMenuItem()
{
  int len = lenMenu();
  if (curr_menu_idx == 0) {
    return &cMenu[(len - 1)];
  } else {
    return &cMenu[(curr_menu_idx - 1)];
  }
}

MENU_POINTER ConsoleMenu::currMenuItem() {
  return &cMenu[curr_menu_idx];  // TODO check invalid idx
}

MENU_POINTER ConsoleMenu::nextMenuItem(){
  int len = lenMenu();
  if (curr_menu_idx == (len-1)) {
    return &cMenu[0];
  } else {
    return &cMenu[(curr_menu_idx + 1)];
  }
}

String ConsoleMenu::currMenuName(){
    if (menuPrevPtr.empty()) {
      return rootMenuName;
    }

    return menuPrevPtr.top()[menuPrevIdx.top()].text;
}

void ConsoleMenu::incMenuIdx() {
  int len = lenMenu();
  if (curr_menu_idx == (len-1)) {
    // wrap around
    curr_menu_idx = 0;
  } else {
    curr_menu_idx++;
  }
}
void ConsoleMenu::decMenuIdx() {
  int len = lenMenu();
  if (curr_menu_idx == 0) {
    // wrap around
    curr_menu_idx = (len - 1);
  } else {
    curr_menu_idx--;
  }
}

MENU_POINTER ConsoleMenu::menuSelected() {
  MENU_POINTER curr = &cMenu[curr_menu_idx];
  if (curr->childMenu != NULL) {
    // Go into child menu

    // push existing menu to stack (keep track of last idx as well)
    menuPrevPtr.push(cMenu);
    menuPrevIdx.push(curr_menu_idx);

    // set ConsoleMenu to look at child menu now
    cMenu = curr->childMenu;
    curr_menu_idx = 0;
  } else {
    if (curr->text == MENU_BACK) {
      // if there is something on the stack, go back to that state
      if (!menuPrevPtr.empty()) {
        cMenu = menuPrevPtr.top();
        menuPrevPtr.pop();
        
        curr_menu_idx = menuPrevIdx.top();
        menuPrevIdx.pop();
      }
    } else if (curr->data != "") {
      // return selected menu, which contains data the outside routine can act on
      return curr;
   
    }
  }
  return NULL;
}
#endif /* MENU_CPP */
