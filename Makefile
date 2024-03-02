# Makefile
# Author: M00835210
# Created: 10/01/2023
# Updated: 12/01/2023

# Using g++ compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all : program
# Compiling test file
.PHONY : test
test: tester

tester : vehicle_test.cpp mainvehicles.o vehicles.o motorcycle.o car.o van.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling program files
program : main.cpp mainvehicles.o vehicles.o motorcycle.o car.o van.o 
# Instruction to build executables
	$(CXX) $(CXXFLAGS) -o $@ $^

# Building object main vehicle
mainvehicles.o : mainvehicles.cpp mainvehicles.h 
	$(CXX) $(CXXFLAGS) -c $<

# Building object vehicle
vehicles.o : vehicles.cpp vehicles.h 
	$(CXX) $(CXXFLAGS) -c $<

# Building object motorcycle
motorcycle.o : motorcycle.cpp motorcycle.h
	$(CXX) $(CXXFLAGS) -c $<

# Building object car
car.o : car.cpp car.h
	$(CXX) $(CXXFLAGS) -c $<


# Building object van
van.o : van.cpp van.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	$(RM) * . o
	$(RM) tester
	$(RM) program
