/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Button
 * @created     : Sunday Apr 21, 2024 23:45:04 CEST
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <string>

class Panel;

class Button
{
    public:
      std::string title;
      void(*callback)();
      Panel *panel_to_display;

      const unsigned int &id;
      static int count;

      Button(std::string title, Panel *panel_to_display = nullptr, void(*callback)() = nullptr);
      ~Button();

      void action();

    private:
      unsigned int mId;
};

#endif 

