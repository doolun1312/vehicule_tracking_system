/*
car.cpp
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "car.h"
#include <iostream>

// for usage of setprecision() to get a double number with a fixed number of numbers after the decimal point:
#include <iomanip>
// for usage of ostringstream to get only the output stream and store it in a variable
#include <sstream>

Car::Car(double engine_size, int seat_number, int door_number) : Vehicle("car", "", "", 0, "", "", "", "")
{
    this->engine_size = engine_size;
    this->seat_number = seat_number;
    this->door_number = door_number;
}

/*
    Displays the three attributes specific to the car
    @param none
    @return the engine size in L, the number of seats and the number of doors
*/
std::string Car::add()
{
    std::ostringstream a;
    std::cout << "\nWhat is the engine size of the vehicle? (in litres-L): ";
    std::cin >> engine_size;
    a << std::setprecision(2) << engine_size;
    std::string engine = a.str();
    std::cout << "\nHow many seats are there in the vehicle?:";
    std::cin >> seat_number;
    std::cout << "\nHow many doors are there in the vehicle?: ";
    std::cin >> door_number;
    return (engine + "L:" + std::to_string(seat_number) + " seats:" + std::to_string(door_number) + " door:");
}