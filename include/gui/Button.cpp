/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Tuesday Apr 23, 2024 00:49:27 CEST
 */

#include "Button.hpp"
#include "Panel.hpp"

Stanley::Button::Button(std::string title, Align alignement, Stanley::Panel *panel_to_display, void (*callback)(Stanley::Button *button)) : title(title), panel_to_display(panel_to_display), callback(callback), alignement(alignement)
{
}

Stanley::Button ret(Stanley::Panel *panel) { return Stanley::Button("Return", Stanley::Align::CENTER, panel); }

void Stanley::Button::action()
{
  if (callback != nullptr) callback(this);
  if (panel_to_display != nullptr) Panel::active = panel_to_display;
}
