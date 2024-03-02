#ifndef _CAR_H_
#define _CAR_H_
/*
car.h
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "vehicles.h"

// Car class with specific attributes to motorcycle
class Car : public Vehicle
{
private:
    double engine_size = 0;
    int seat_number;
    int door_number;

public:
    Car(double engine_size, int seat_number, int door_number);
    std::string add();
};

#endif