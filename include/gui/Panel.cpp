/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Panel
 * @created     : Tuesday Apr 23, 2024 00:28:54 CEST
 */

#include "Panel.hpp"

Stanley::Panel *Stanley::Panel::active = nullptr;
int Stanley::Panel::count = -1;

Stanley::Panel::Panel(std::string title, std::vector<Button> buttons) : title(title), buttons(buttons)
{
  selected_line = 0;    

  if (count == -1)
  {
    count = 0;
    setlocale(LC_ALL, "");
    initscr();
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
  }

  count++;
}

Stanley::Panel::~Panel()
{
  count--;
}

void Stanley::Panel::setDefault() { active = this; }

void Stanley::Panel::scrollDown() 
{
  selected_line++;
  if (selected_line > buttons.size() - 1) selected_line = 0;  
}

void Stanley::Panel::scrollUp() 
{
  selected_line--;
  if (selected_line < 0) selected_line = buttons.size() - 1;  
}

void Stanley::Panel::select()
{
  Button &selected_button = buttons[selected_line];
  selected_button.action();
}

void Stanley::Panel::display()
{
  clear();
  int x, y;
  getmaxyx(stdscr, y, x);
  move(1, x / 2 - title.length() / 2);
  printw(title.c_str());
  for (int i = 0; i < buttons.size(); i++)
  {
    Button &button = buttons[i];
    std::string str;
    if (i == selected_line)
    {
      attron(COLOR_PAIR(1));
      str = "> " + button.title;
    }
    else
    {
      str = "  " + button.title;
    }
    if (button.alignement == Align::CENTER) move(3 + i, x / 2 - str.length() / 2);
    else if (button.alignement == Align::LEFT) move(3 + i, 0);
    else if (button.alignement == Align::RIGHT) move(3 + i, 0);
    printw(str.c_str()); 
    printw("\n");
    attron(COLOR_PAIR(2));
  }
  refresh();
}

void Stanley::Panel::update()
{
  cbreak();
  noecho();
  keypad(stdscr, true);
  int c = getch();

  if (c == KEY_UP)
  {
    scrollUp();
  }
  else if (c == KEY_DOWN)
  {
    scrollDown();
  }
  else if (c == 10)
  {
    nocbreak();
    echo();
    keypad(stdscr, false);
    select();
  }
  nocbreak();
  echo();
  keypad(stdscr, false);
}
