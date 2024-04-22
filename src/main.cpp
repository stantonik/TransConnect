/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : main
 * @created     : Sunday Apr 21, 2024 22:06:57 CEST
 */

#include "Panel.hpp"
#include <cstdlib>
#include <ncurses.h>

using namespace std;

int main(int c, char *v[])
{
  Panel home("Home", { Button("Test"), Button("Hello"), Button("Bite") });
  Panel test("Test", { Button ("Return", &home) });
  Button test2("Test2", &test);
  home.buttons.push_back(test2);

  system("clear");
  Panel::selected->display();

  int line = 0;

  initscr();
  noecho();
  clear();
  refresh();
  endwin();

  while (1)
  {
    cbreak();
    keypad(stdscr, TRUE);
    int c = 0;
    switch((c = getch())) {
      case KEY_UP:
        line--;
        break;
      case KEY_DOWN:
        line++;
        break;
      case 10:
        {
          cout << "enter" << endl;
          Panel::selected->buttons[Panel::selected->selected_button_id].action();
          break;
        }
      default:
        break;
    }
    endwin();

    if (line < 0) line = Panel::selected->buttons.size() - 1;
    else if (line > Panel::selected->buttons.size() - 1) line = 0;

    system("clear");
    Panel::selected->selected_button_id = line;

    Panel::selected->display();

  }

  return 0;
}
