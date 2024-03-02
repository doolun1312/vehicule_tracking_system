/*
motorcycle.cpp
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle(int engine_size, std::string passenger_seat, std::string luggage_space) : Vehicle("bike", "", "", 0, "", "", "", "")
{
    this->engine_size = engine_size;
    this->passenger_seat = passenger_seat;
    this->luggage_space = luggage_space;
}

/*
    Displays the three attributes specific to the motorcycle
    @param none
    @return the engine size in cc, if there is passenger seat and if there is luggage space
*/
std::string Motorcycle::add()
{
    std::string passengern;
    std::string luggagen;
    std::cout << "\nWhat is the engine size of the vehicle? (in cubic centimetres-cc): ";
    std::cin >> engine_size;
    std::cout << "\nIs there passenger seat on the vehicle? \n\n1)Yes\n2)No \nChoose a number: ";
    std::cin >> passengern;
    if (passengern == "1")
    {
        passenger_seat = "Passenger seat";
    }
    else if (passengern == "2")
    {
        passenger_seat = "No passenger";
    }
    else
    {
        std::cout << "PLease try again and choose an appropriate number";
    }
    std::cout << "\nIs there luggage space in the vehicle? \n\n1)Yes\n2)No \nChoose a number: ";
    std::cin >> luggagen;
    if (luggagen == "1")
    {
        luggage_space = "Has luggage";
    }
    else if (luggagen == "2")
    {
        luggage_space = "No luggage";
    }
    else
    {
        std::cout << "PLease try again and choose an appropriate number";
    }

    return (std::to_string(engine_size) + "cc:" + passenger_seat + ":" + luggage_space + ":");
}
