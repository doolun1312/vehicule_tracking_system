#ifndef _VEHICLES_H_
#define _VEHICLES_H_
/*
vehicles.h
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include <string>

/*Vehicle class defining and displaying the common attributes of all the vehicles in a function returning one part,
then the specific attributes then the rest of the common attributes in another function.*/
class Vehicle
{
private:
  std::string name;
  std::string make;
  std::string model;
  int price;
  std::string registration_number;
  std::string colour;
  std::string available;
  std::string return_date;

public:
  Vehicle(std::string name, std::string make, std::string model, int price, std::string registration_number,
          std::string colour, std::string available, std::string return_date);
  virtual ~Vehicle();
  std::string description();
  virtual std::string add() = 0;
  std::string add1();
  std::string add2();
};

#endif
