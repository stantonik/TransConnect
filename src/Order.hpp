/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Order
 * @created     : Sunday Apr 21, 2024 23:23:09 CEST
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Client.hpp"
#include "Employee.hpp"
#include <string>
#include <fstream>

struct Travel
{
  std::string A;
  std::string B;
  std::string distance;
  float time;
};

class Order
{
    public:
      std::string A;
      std::string B;
      float const &distance;
      Client client;

      Order(Client client, std::string A, std::string B);

    private:
      float mDistance;

      Travel findTravel(std::string path, std::string A, std::string B);
};

#endif 

