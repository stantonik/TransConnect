/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Panel
 * @created     : Sunday Apr 21, 2024 23:41:48 CEST
 */

#ifndef PANEL_HPP
#define PANEL_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Button.hpp"

class Panel
{
  public:
    std::string title;
    std::vector<Button> buttons;
    static Panel *selected;

    unsigned int selected_button_id = 0;

    Panel(std::string title, std::vector<Button> buttons);

    void update();
    void display();

    private:
};

#endif 

