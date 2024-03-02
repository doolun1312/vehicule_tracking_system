/*
mainvehicles.cpp
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "mainvehicles.h"

/*
    Output the vehicle information in the file
    @param file, vehcile file to read from and write to inputted by user in the beginning, vehicle that is added
    @return vehicle
*/

std::string addinput(std::string file, std::string vehicle)
{
    std::ofstream outputfile;
    std::ifstream inputfile;
    outputfile.open(file, std::ios::app);
    outputfile << "\n"
               << vehicle;
    outputfile.close();
    return vehicle;
}

/*
    Calls the description function as output to the file to add a line for a vehicle
    @param file file to read from and write to inputted by user in the beginning
    @return 0
*/
int add(std::string file)
{
    std::string typen;
    std::vector<Vehicle *> vehicles;
    vehicles.push_back(new Motorcycle(0, "", ""));
    vehicles.push_back(new Car(0, 0, 0));
    vehicles.push_back(new Van(0, 0, 0));
    std::cout << "Please choose a type of vehicle to add: \n\n1)Bike \n2)Car \n3)Van \n\nChoose a number: ";
    std::cin >> typen;
    if (typen == "1")
    {
        addinput(file, vehicles[0]->description());
        std::cout << "\nVehicle successfully added!";
    }
    else if (typen == "2")
    {
        addinput(file, vehicles[1]->description());
        std::cout << "\nVehicle successfully added!";
    }
    else if (typen == "3")
    {
        addinput(file, vehicles[2]->description());
        std::cout << "\nVehicle successfully added!";
    }
    else
    {
        std::cout << "Error please try again";
        return 0;
    }
    for (Vehicle *v : vehicles)
    {
        delete v;
    }
    vehicles.clear();

    return 0;
}

/*
    Read each line from the file
    @param file file to read from and write to inputted by user in the beginning
    @return 0
*/
int read(std::string file)
{
    std::fstream vehicle_file;
    std::string word;
    int str;
    std::string line;
    std::string make;
    std::string model;
    std::string registration_number;
    std::string available;
    int start1;
    vehicle_file.open(file, std::ios::in);
    while (getline(vehicle_file, word))
    {
        int start = 0;
        int c = 0;
        /* Everytime a ":" is found, the count is incremented,
        when the count reaches a specific number it means that a specific attribute
        that is needed is stored so we use the word to display it*/
        for (int i = 0; i < 10; i++)
        {
            str = word.find(":", start);
            start1 = start;
            start = str + 1;
            c += 1;
            if (c == 2)
            {
                make = word.substr(start1, str - start1);
            }
            if (c == 3)
            {
                model = word.substr(start1, str - start1);
            }
            if (c == 8)
            {
                registration_number = word.substr(start1, str - start1);
            }
            if (c == 10)
            {
                available = word.substr(start1, str - start1);
            }
        }
        if (word != "")
        {
            std::cout << "MAKE: " + make << "  MODEL: " + model << "  REGISTRATION NUMBER: " + registration_number << "  AVAILABLE: " + available + "\n";
        };
    }
    vehicle_file.close();
    return 0;
}

/*
    Ask user for a word to read
    @param file file to read from and write to inputted by user in the beginning
    @return 0
*/
int read1(std::string file)
{
    std::string word;
    std::cout << "Please enter a detail of the vehicle you want to read: ";
    std::cin >> word;
    readline(file, word);
    return 0;
}

/*
    Read only one line from the file with a specific word
    @param file, word file to read from and write to inputted by user in the beginning, word to read
    @return line
*/
std::string readline(std::string file, std::string word)
{
    // Look for the line with the word we are looking for and displaying that line
    std::fstream vehicle_file;
    std::string line;
    vehicle_file.open(file, std::ios::in);
    while (getline(vehicle_file, line))
    {
        size_t pos = line.find(word);
        if (pos != std::string::npos)
        {
            std::cout << line << std::endl;
            return line;
        }
    }
    vehicle_file.close();
    return "error";
}

/*
   Ask what line to delete
    @param file file to read from and write to inputted by user in the beginning
    @return 0
*/
int Delete(std::string file)
{
    std::fstream vehicle_file;
    vehicle_file.open(file, std::ios::in);
    std::string yesno;
    std::string word;
    std::string line;
    std::cout << "Please enter the registration number of the vehicle you want to delete,"
              << "or press the ESC key then the ENTER to go back to the main menu : ";

    std::cin >> word;
    /* Look for the line with the word we want to delete,
    print every line in the document except that line in a new temporary file,
    delete the original file and rename the temporary file to the original file*/
    while (getline(vehicle_file, line))
    {
        size_t pos = line.find(word);
        if (pos != std::string::npos)
        {
            std::cout << "Are you sure you want to delete " << line << "?\n1)Yes\n2)No\nEnter a number to continue: ";
            std::cin >> yesno;
            if (yesno == "1")
            {
                deleteline(file, line);
            }
            else if (yesno == "2")
            {
                std::cout << "Cancelling deletion...\n";
                Delete(file);
            }

            else
            {
                std::cout << "Error, please try again.";
                Delete(file);
            }
        }
    }

    return 0;
}

/*
    Dele a line from the file
    @param file, line file to read from and write to inputted by user in the beginning, line to delete
    @return line
*/
std::string deleteline(std::string file, std::string line)
{
    std::ofstream outputfile("test1.txt");
    std::ifstream inputfile(file);
    std::string str;
    while (getline(inputfile, str))
    {
        if (str != line)
        {
            str += "\n";
            outputfile << str;
        }
    }
    inputfile.close();
    outputfile.close();
    const char *file1 = file.c_str();
    remove(file1);
    rename("test1.txt", file1);
    std::cout << "\nVehicle successfully deleted!";
    return line;
}

/*
    Validate the menu
    @param x x a number to choose from the menu
    @return a message stating what option we chose or a error message
*/
std::string menuverification(std::string x)
{
    if (x == "1" || x == "2" || x == "3" || x == "4" || x == "5")
    {
        return "You chose " + x;
    }
    else
    {
        return "Error";
    }
}

/*
    Main menu to choose what to do next
    @param file file to read from and write to inputted by user in the beginning
    @return 0
*/
int mainmenu(std::string file)
{
    std::string x;
    std::cout << "\n\nWelcome to the vehicles description menu:"
              << "\n\n1) Add a vehicle"
              << "\n2) Remove a vehicle"
              << "\n3) List all vehicles"
              << "\n4) Display all details of a vehicle"
              << "\n5) Exit \n\nChoose a number: ";
    std::cin >> x;
    std::cout << menuverification(x) + "\n\n";
    if (menuverification(x) == "You chose 1")
    {
        add(file);
        mainmenu(file);
    }
    else if (menuverification(x) == "You chose 2")
    {
        Delete(file);
        mainmenu(file);
    }
    else if (menuverification(x) == "You chose 3")
    {
        read(file);
        mainmenu(file);
    }
    else if (menuverification(x) == "You chose 4")
    {
        read1(file);
        mainmenu(file);
    }
    else if (menuverification(x) == "You chose 5")
    {
        std::cout << "Closing the program...";
        return 0;
    }
    else
    {
        std::cout << "Wrong, please try again";
        mainmenu(file);
    }
    return 0;
}

/*
    Verify the file
    @param file file to read from and write to inputted by user in the beginning
    @return true/false
*/
bool fileverification(std::string file)
{
    std::fstream vehicle_file;
    vehicle_file.open(file, std::ios::in);
    if (vehicle_file)
    {
        std::cout << "File exists\n";
        return true;
    }
    else
    {
        std::cout << "File does not exist, please try again\n";
        return false;
    }
    return false;
}

/*
    Ask user to input file name
    @param none
    @return true/false
*/
bool fileselection()
{
    bool filev = false;
    std::string file;
    while (!filev)
    {
        std::cout << "Please enter a file to read from and modify the vehicles: ";
        std::cin >> file;
        filev = fileverification(file);
        if (filev)
        {
            mainmenu(file);
        }
    }

    return false;
}
