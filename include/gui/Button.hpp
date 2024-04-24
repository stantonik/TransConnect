/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Tuesday Apr 23, 2024 00:39:48 CEST
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <string>


namespace Stanley
{
  class Panel;

  enum class Align
  {
    LEFT,
    CENTER,
    RIGHT
  };

  class Button
  {
    public:
      Button(std::string title = "", Align alignement = Align::CENTER, Panel *panel_to_display = nullptr, void (*callback)(Button *button) = nullptr);

      static Button ret(Panel *panel);

      std::string title;
      Panel *panel_to_display;
      Align alignement;

      void (*callback)(Button *button);
      void action();
  };
}

#endif

