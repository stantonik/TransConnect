/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Order
 * @created     : Sunday Apr 21, 2024 23:23:09 CEST
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include "Client.hpp"
#include "Driver.hpp"
#include "Employee.hpp"
#include "Vehicule.hpp"
#include <string>
#include <fstream>
#include <vector>


namespace Stanley
{
  struct Road
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
      std::string date;
      float const &distance;
      static std::vector<Vehicule> vehicules;
      Vehicule *vehicule;
      Driver *driver;
      Client *client;

      Order(Client *client, std::string A, std::string B, std::string date);

      static std::vector<Road> getRoads(std::string filepath);

    private:
      float mDistance;

      float getPrice() const;
      std::string getRoute() const;

  };
}

#endif 

