/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Monday Apr 22, 2024 00:01:35 CEST
 */

#include "Button.hpp"
#include "Panel.hpp"

int Button::count = 0;

Button::Button(std::string title, Panel *panel_to_display, void(*callback)()) : title(title), callback(callback), id(mId), panel_to_display(panel_to_display)
{
  mId = count;
  count++; 
}

void Button::action()
{
  if (callback != nullptr) callback();
  if (panel_to_display != nullptr) 
  {
    Panel::selected = panel_to_display;
  }
}

Button::~Button()
{
  count--;
}

