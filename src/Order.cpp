/**
 * @author      : stanleyarn (stanleyarn@$HOSTNAME)
 * @file        : Order
 * @created     : Tuesday Apr 23, 2024 15:16:58 CEST
 */

#include "Order.hpp"

std::vector<Stanley::Vehicule> Stanley::Order::vehicules = { 
  Vehicule("Dump truck", 20),
  Vehicule("Tanker", 20),
  Vehicule("Refrigirated truck", 20),
};

Stanley::Order::Order(Client *client, std::string A, std::string B, std::string date) : client(client), A(A), B(B), date(date), distance(mDistance)
{

}

std::vector<Stanley::Road> Stanley::Order::getRoads(std::string path)
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
    return { };
  }

  /* extract data */
  std::vector<Road> roads;

  for(std::string line; getline(file, line); )
  {
    if (line.find('#') != std::string::npos) continue;

    Road road;
    char spacer = ';';
    int spacer_ind = line.find(spacer);
    int count = 0;

    while (spacer_ind != std::string::npos)
    {
      std::string word = line.substr(0, spacer_ind);
      line.erase(0, spacer_ind);

      switch (count) 
      {
        case 0:
          road.A = word;
          break;
        case 1:
          road.B = word;
          break;
        case 2:
          road.distance = word;
          break;
        case 3:
          {
            try
            {
              int hpos = word.find('h');
              std::string hour_str = word.substr(0, hpos);
              std::string minutes_str = word.substr(hpos + 1, word.length());
              int hour = std::stoi(hour_str);
              int minutes = 0;
              if (minutes_str.size() > 0)
                minutes = std::stoi(minutes_str);
              road.time = hour * 60 * 60 + minutes * 60;
            }
            catch(...) { }
            break;
          }
      }

      spacer_ind = line.find(spacer);
      count++;
    }

    if (count == 4) roads.push_back(road);
  }

  file.close();

  return roads;
}

float Stanley::Order::getPrice() const
{
  return 0;
}

