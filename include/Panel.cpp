/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Panel
 * @created     : Monday Apr 22, 2024 16:24:59 CEST
 */

#include "Panel.hpp"

Panel *Panel::selected = nullptr;

Panel::Panel(std::string title, std::vector<Button> buttons) : title(title), buttons(buttons) 
{
  if (selected == nullptr) selected = this;
}

void Panel::update()
{
  if (this == selected)
  {
    display(); 
  }
}

void Panel::display()
{
  std::cout << title << "\n" << std::endl;

  for (int i = 0; i < buttons.size(); i++)
  {
    if (i == selected_button_id)
    {
      std::cout << "-> " << "\e[48;5;37m" << buttons[i].title << "\e[0m" << std::endl;
    }
    else
    {
      std::cout << "   " << buttons[i].title << std::endl;
    }
  }
}
