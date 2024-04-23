/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Tuesday Apr 23, 2024 00:49:27 CEST
 */

#include "Button.hpp"
#include "Panel.hpp"

Button::Button(std::string title, int alignement, Panel *panel_to_display, void (*callback)()) : title(title), panel_to_display(panel_to_display), callback(callback), alignement(alignement)
{
}

void Button::action()
{
  if (callback != nullptr) callback();
  if (panel_to_display != nullptr) Panel::active = panel_to_display;
}
