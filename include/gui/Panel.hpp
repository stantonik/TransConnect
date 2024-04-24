/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Panel
 * @created     : Tuesday Apr 23, 2024 00:28:35 CEST
 */

#ifndef PANEL_HPP
#define PANEL_HPP

#include <string>
#include <vector>
#include <ncurses.h>
#include <locale.h>

#include "Button.hpp"

namespace Stanley
{
  class Panel
  {
    public:
      Panel(std::string title, std::vector<Button> buttons = { });
      ~Panel();

      static Panel *active;
      std::string title;
      std::vector<Button> buttons;

      void setDefault();
      void scrollDown();
      void scrollUp();
      void select();
      void display();
      void update();

    private:
      int selected_line;
      static int count;
  };
}

#endif

