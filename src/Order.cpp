/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Order
 * @created     : Tuesday Apr 23, 2024 15:16:58 CEST
 */

#include "Order.hpp"

Order::Order(Client client, std::string A, std::string B) : client(client), A(A), B(B), distance(mDistance)
{

}

Travel Order::findTravel(std::string path, std::string A, std::string B)
{
  /* open file and cvt to str */
  std::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    file.open(path);
  }
  catch (std::ifstream::failure &e)
  {
    return Travel { };
  }

  Travel travel { };

  int col = 0;

  /* extract data */
  for(std::string line; getline(file, line); )
  {
    
  }

  file.close();

  return travel;
}
