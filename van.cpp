/*
van.cpp
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "van.h"
#include <iostream>

// for usage of setprecision() to get a double number with a fixed number of numbers after the decimal point:
#include <iomanip>
// for usage of ostringstream to get only the output stream and store it in a variable
#include <sstream>

Van::Van(int engine_size, int seat_number, double luggage_space) : Vehicle("van", "", "", 0, "", "", "", "")
{
    this->engine_size = engine_size;
    this->seat_number = seat_number;
    this->luggage_space = luggage_space;
}

/*
    Displays the three attributes specific to the van
    @param none
    @return the engine size of the vehicle in L, the number of seats and luggage space
*/
std::string Van::add()
{
    std::ostringstream a;
    std::cout << "\nWhat is the engine size of the vehicle? (in litres-L): ";
    std::cin >> engine_size;
    std::cout << "\nHow many seats are there in the vehicle?: ";
    std::cin >> seat_number;
    std::cout << "\nHow much luggage space is there in the vehicle? (In cubic meters): ";
    std::cin >> luggage_space;
    a << std::setprecision(3) << luggage_space;
    std::string luggage = a.str();
    return (std::to_string(engine_size) + "L:" + std::to_string(seat_number) +
            " seats:" + luggage + " cubic meters luggage space:");
}
