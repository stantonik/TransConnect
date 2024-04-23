/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Person
 * @created     : Monday Apr 22, 2024 17:07:54 CEST
 */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <sstream>
#include <string>

class Person
{
    public:
      std::string first_name;
      std::string last_name;
      std::string address;
      std::string mail;
      std::string phone_number;
      const std::string birth_date;

      Person(std::string first_name, std::string last_name, std::string birth_date, std::string address, std::string mail, std::string phone_number) : first_name(first_name), last_name(last_name), address(address), mail(mail), phone_number(phone_number), birth_date(birth_date) { }

      operator std::string() const 
      {
        std::stringstream ss;
        ss << first_name << " " << last_name << " | " << birth_date << " | " << address << " | " << phone_number << " | " << mail;
        return ss.str();
      }

    private:
};

#endif 

