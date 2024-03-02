#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_
/*
motorcycle.h
Author: M00835210
Created: 12/01/2023
Updated: 12/01/2023
*/

#include "vehicles.h"

// Motorcycle class with specific attributes to motorcycle
class Motorcycle : public Vehicle
{
private:
    int engine_size;
    std::string passenger_seat;
    std::string luggage_space;

public:
    Motorcycle(int engine_size, std::string passenger_seat, std::string luggage_space);
    std::string add();
};

#endif