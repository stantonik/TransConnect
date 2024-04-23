/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Employee
 * @created     : Sunday Apr 21, 2024 22:57:26 CEST
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"
#include <string>
#include <vector>


namespace Stanley
{
  class Employee : Person 
  {
    public:
      std::string job;
      float salary;
      const unsigned int ss;
      const std::string hiring_date;

      std::vector<Employee> sub_employees;

      Employee(unsigned int ss, std::string first_name, std::string last_name, std::string birth_date, std::string address, std::string mail, std::string phone_number, std::string hiring_date, std::string job, float salary) : Person(first_name, last_name, birth_date, address, mail, phone_number), ss(ss), hiring_date(hiring_date), salary(salary), job(job) { }

    static std::string getOrganigramTree(Employee const &employee) { return getOrganigramBranch(employee, true, 0); }

    private:

    static std::string getOrganigramBranch(Employee const &employee, bool is_last, int padding)
{
  int spacing = 8;
  std::stringstream ss;

  ss << employee.first_name << " " << employee.last_name << '\n';

  for (Employee const &sub_obj : employee.sub_employees)
  {
    for (int i = 0; i < padding; i+= spacing)
    {
      if (is_last and i == padding - spacing and i != 0)
        ss << std::string(spacing, ' ');
      else
        ss << "\u2502" << std::string(spacing - 1, ' ');
    }

    ss << "\u2502\n";

    for (int i = 0; i < padding; i+= spacing)
    {
      if (is_last and i == padding - spacing and i != 0)
        ss << std::string(spacing, ' ');
      else
        ss << "\u2502" << std::string(spacing - 1, ' ');
    }

    if (&sub_obj == &employee.sub_employees.back()) ss << "\u2514";
    else ss << "\u251C";

    for (int i = 0; i < spacing - 1; i++) ss << "\u2500";
    ss << ' ' << getOrganigramBranch(sub_obj, &sub_obj == &employee.sub_employees.back(), padding + spacing);
  }

  return ss.str();
}
  };
}

#endif 

