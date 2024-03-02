/*
vehicles.cpp
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "vehicles.h"
#include <iostream>

Vehicle::Vehicle(std::string name, std::string make, std::string model, int price, std::string registration_number,
                 std::string colour, std::string available, std::string return_date)
{
    this->name = name;
    this->make = make;
    this->model = model;
    this->price = price;
    this->registration_number = registration_number;
    this->colour = colour;
    this->available = available;
    this->return_date = return_date;
}

Vehicle::~Vehicle()
{
}

/* 
    Merge the output of three other functions
    @param none
    @return all the common and specific attributes of the vehicles in a single line
*/
std::string Vehicle::description()
{
    return (name + ":" + add1() + add() + add2());
}

/*
    Displays the three first elements of a vehicle
    @param none
    @return the make, the model and the price which are the common attributes that the vehicles have
*/
std::string Vehicle::add1()
{
    std::cout << "\nPlease enter the make of the vehicle: ";
    std::cin >> make;
    std::cout << "\nPlease enter the model of the vehicle: ";
    std::cin >> model;
    std::cout << "\nPlease enter the price of the vehicle: £";
    std::cin >> price;
    return (make + ":" + model + ":£" + std::to_string(price) + ":");
}


/*
    Displays the four last elements of a vehicle
    @param none
    @return the registration number, the colour, if available and the return date
*/
std::string Vehicle::add2()
{
    std::string availablen;
    std::cout << "\nPlease enter the registration number of the vehicle: ";
    std::cin >> registration_number;
    std::cout << "\nPlease enter the colour of the vehicle: ";
    std::cin >> colour;
    std::cout << "\nIs the vehicle available: \n\n1)Yes\n2)No \nChoose a number: ";
    std::cin >> availablen;
    if (availablen == "1")
    {
        available = "Yes";
        return_date = "N/A";
    }
    else if (availablen == "2")
    {
        available = "No";
        std::cout << "Please enter the return date of the vehicle in DD/MM/YYYY format: ";
        std::cin >> return_date;
    }
    else
    {
        std::cout << "PLease try again and choose an appropriate number";
    }
    return (registration_number + ":" + colour + ":" + available + ":" + return_date);
}
