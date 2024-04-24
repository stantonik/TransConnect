/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : main
 * @created     : Sunday Apr 21, 2024 22:06:57 CEST
 */

#include "gui/Panel.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include <map>

using namespace Stanley;

bool isRunning = true;

std::vector<Client> clients = { 
  Client("Maili", "Truong", "04/10/2002", "14 ajuzd, Vincennes", "noalimai@hotmail.fr", "0777"), 
};

Employee chief(1383, "Stanley", "Arnaud", "mai", "47 reuinon", "akd", "zoij", "ljnda", "Chief", 82937);

/* CALLBACKS */
void editClientCallback()
{
}

void addClientCallback(Button *button)
{
  char first_name[64];
  char last_name[64];
  char birth_date[64];
  char address[64];
  char mail[64];
  char phone_number[64];

  clear();
  printw("Add a client : \n");
  printw("\nFirst name : "); getstr(first_name);
  printw("\nLast name : "); getstr(last_name);
  printw("\nBirth date (format:dd/mm/yy ex:01/02/2003) : "); getstr(birth_date);
  printw("\nAddress : "); getstr(address);
  printw("\nE-mail : "); getstr(mail);
  printw("\nPhone number : "); getstr(phone_number);
  printw("\n\nThe client has been well added !\n");
  getch();

  clients.push_back(Client(first_name, last_name, birth_date, address, mail, phone_number));
}


int main(int c, char *v[])
{
  /* PANELS */
  Panel home_panel("Menu");
  home_panel.setDefault();

  Panel clients_panel("Clients", { 
      Button("Return", Align::CENTER, &home_panel),
      Button("Research"),
      Button("Filters"),
      Button("Add client", Align::CENTER, nullptr, addClientCallback),
      Button(),
      });

  Panel employees_panel("Employees", {
      Button("Return", Align::CENTER, &home_panel),
      Button("Print the organigram", Align::CENTER, nullptr, [](Button *button){ clear(); printw(Employee::getOrganigramTree(chief).c_str()); getch(); }),
      Button("Research"),
      Button("Filters"),
      Button("Add employees", Align::CENTER, nullptr, addClientCallback),
      Button(),
      });

  Panel edit_panel("Choose an action", {
      Button("Return", Align::CENTER, &clients_panel),
      Button("Edit first name"),
      Button("Edit last name"),
      Button("Remove client"),
      });

  Panel statistics_panel("Statistics", { 
      Button("Return", Align::CENTER, &home_panel),
      Button()
      });
  std::map<std::string, float> statistics;
  statistics["Average"] = 10;
  statistics["Variance"] = 20;
  for (auto item : statistics)
  {
    std::string str = item.first + " = " + std::to_string(item.second);
    statistics_panel.buttons.push_back(Button(str));
  }

  home_panel.buttons.push_back(Button("Clients", Align::CENTER, &clients_panel));
  home_panel.buttons.push_back(Button("Employees", Align::CENTER, &employees_panel));
  home_panel.buttons.push_back(Button("Statistics", Align::CENTER, &statistics_panel));
  home_panel.buttons.push_back(Button("Quit", Align::CENTER, nullptr, [](Button *button){ isRunning = false; }));

  /* EMPLOYEES */
  Employee e1(1383, "Maxime", "Arnaud", "mai", "47 reuinon", "akd", "zoij", "ljnda", "Chief", 82937);
  Employee e2(1383, "Maili", "Arnaud", "mai", "47 reuinon", "akd", "zoij", "ljnda", "Chief", 82937);

  chief.sub_employees.push_back(e1);
  chief.sub_employees.push_back(e2);

  /* LOOP */
  Panel::active->display();
  while(isRunning)
  {
    clients_panel.buttons.erase(clients_panel.buttons.begin() + 5, clients_panel.buttons.end());
    for (Client const &client : clients)
    {
      clients_panel.buttons.push_back(Button(std::string(client), Align::LEFT, &edit_panel));
    }

    Panel::active->display();
    Panel::active->update();
  }

  endwin();

  return 0;
}
