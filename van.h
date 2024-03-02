#ifndef _VAN_H_
#define _VAN_H_
/*
van.h
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "vehicles.h"

// Van class with specific attributes to motorcycle
class Van : public Vehicle
{
private:
    int engine_size;
    int seat_number;
    double luggage_space;

public:
    Van(int engine_size, int seat_number, double luggage_space);
    std::string add();
};

#endif