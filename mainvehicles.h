#ifndef _MAINVEHICLES_H_
#define _MAINVEHICLES_H_
/*
mainvehicles.h
Author: M00835210
Created: 12/12/2022
Updated: 12/01/2023
*/

#include "vehicles.h"
#include "motorcycle.h"
#include "car.h"
#include "van.h"

std::string addinput(std::string file, std::string vehicle);
int add(std::string file);
int read(std::string file);
std::string readline(std::string file, std::string word);
int read1(std::string file);
int Delete(std::string file);
std::string deleteline(std::string file, std::string line);
std::string menuverification(std::string x);
int mainmenu(std::string file);
bool fileverification(std::string file);
bool fileselection();

#endif