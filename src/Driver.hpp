/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Driver
 * @created     : Wednesday Apr 24, 2024 01:03:51 CEST
 */

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "Person.hpp"
#include <string>

namespace Stanley
{
  class Driver : public Person
  {
    public:
      Driver(std::string first_name, std::string last_name, std::string birth_date, std::string address, std::string mail, std::string phone_number) : Person(first_name, last_name, birth_date, address, mail, phone_number) { }

      float fees;
      bool disponible;

    private:
  };
}

#endif

