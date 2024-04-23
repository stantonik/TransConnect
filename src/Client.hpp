/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Client
 * @created     : Monday Apr 22, 2024 17:34:52 CEST
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Person.hpp"
#include <string>


class Client : public Person
{
    public:
      Client(std::string first_name, std::string last_name, std::string birth_date, std::string address, std::string mail, std::string phone_number) : Person(first_name, last_name, birth_date, address, mail, phone_number){ }

    private:
};

#endif 

