/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Employee
 * @created     : Sunday Apr 21, 2024 22:57:26 CEST
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>


namespace Stanley
{
  class Employee
  {
    public:
      std::string first_name;
      std::string last_name;
      std::string address;
      std::string mail;
      std::string phone_number;
      std::string job;
      float salary;
      const unsigned int ss;
      const std::string birth_date;
      const std::string hiring_date;

      Employee(unsigned int ss, std::string first_name, std::string last_name, std::string birth_date, std::string address, std::string mail, std::string phone_number, std::string hiring_date, std::string job, float salary);

    private:
  };
}

#endif 

