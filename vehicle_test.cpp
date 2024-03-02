/*
vehicle_test.cpp
Author: M00835210
Created: 02/01/2023
Updated: 12/01/2023
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mainvehicles.h"

// Check if file exists
TEST_CASE("file test", "[file]")
{
    REQUIRE(fileverification("vehicles.dat") == true);
    REQUIRE(fileverification("abc.txt") == false);
    REQUIRE(fileverification("123.dat") == false);
    REQUIRE(fileverification("test.txt") == false);
    REQUIRE(fileverification("testing.txt") == false);
}

// Check if menu input works well
TEST_CASE("menu test", "[menu]")
{
    std::vector<std::string> menu;
    menu.push_back("1");
    menu.push_back("2");
    menu.push_back("3");
    menu.push_back("4");
    menu.push_back("5");
    REQUIRE(menuverification(menu[0]) == "You chose " + menu[0]);
    REQUIRE(menuverification(menu[2]) == "You chose " + menu[2]);
    REQUIRE(menuverification(menu[3]) == "You chose " + menu[3]);
    REQUIRE(menuverification(menu[1]) == "You chose " + menu[1]);
    REQUIRE(menuverification(menu[4]) == "You chose " + menu[4]);
    REQUIRE(menuverification("9") == "Error");
    REQUIRE(menuverification("hello") == "Error");
}

// Check if vehicle is added and if it is displayed later on
TEST_CASE("add input", "[add]")
{
    std::vector<std::string> added;
    added.push_back(addinput("vehicles.dat", "car:mercedes:e-class:£25:1.5L:4 seats:4 door:mercdes:white:Yes:N/A"));
    added.push_back(addinput("vehicles.dat", "bike:scott:spark:£25:15cc:Passenger seat:Has luggage:abc:blue:No:12/12/2003"));
    added.push_back(addinput("vehicles.dat", "van:Ford:fdfadffs:£8000:2L:9 seats:15.3 cubic meters luggage space:VAN123:white:Yes:N/A"));
    REQUIRE(readline("vehicles.dat", "mercdes") == added[0]);
    REQUIRE(readline("vehicles.dat", "abc") == added[1]);
    REQUIRE(readline("vehicles.dat", "VAN123") == added[2]);
}

// Check if a vehicle is deleted 
TEST_CASE("delete input", "[delete]")
{
    std::vector<std::string> deleteline1;
    deleteline1.push_back(deleteline("vehicles.dat", "car:mercedes:e-class:£25:1.5L:4 seats:4 door:mercdes:white:Yes:N/A"));
    deleteline1.push_back(deleteline("vehicles.dat", "bike:scott:spark:£25:15cc:Passenger seat:Has luggage:abc:blue:No:12/12/2003"));
    deleteline1.push_back(deleteline("vehicles.dat", "van:Ford:fdfadffs:£8000:2L:9 seats:15.3 cubic meters luggage space:VAN123:white:Yes:N/A"));
    REQUIRE(readline("vehicles.dat", deleteline1[0]) == "error");
    REQUIRE(readline("vehicles.dat", deleteline1[1]) == "error");
    REQUIRE(readline("vehicles.dat", deleteline1[2]) == "error");
}
