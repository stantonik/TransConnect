/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Tuesday Apr 23, 2024 00:39:48 CEST
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <string>

#define ALIGN_CENTER 0
#define ALIGN_LEFT -1
#define ALIGN_RIGHT 1

class Panel;

class Button
{
    public:
      Button(std::string title = "", int alignement = ALIGN_CENTER, Panel *panel_to_display = nullptr, void (*callback)() = nullptr);

      std::string title;
      Panel *panel_to_display;
      int alignement;

      void (*callback)();
      void action();
};

#endif

