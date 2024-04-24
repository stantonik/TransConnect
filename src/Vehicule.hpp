/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Vehicule
 * @created     : Tuesday Apr 23, 2024 19:53:34 CEST
 */

#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <string>


namespace Stanley
{
  class Vehicule
  {
    public:
      std::string type;
      float consumption;

      Vehicule(std::string type, float consumption) : type(type), consumption(consumption)
    {

    }

    private:
  };
}

#endif

