#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
	int noOfDoors;
	char* transmission;
	int noOfSeats;
	static int numberOfCars;
public:
	Car(char* companyName = nullptr, char* color = nullptr, int numberOfWheels = 0, int powerCC = 0, char* typeOfVehicle = nullptr, int noOfDoors = 0, char* transmission = nullptr, int noOfSeats = 0);
	Car(const Car&);
	void setNoOfDoors(int);
	void setTransmission(char*);
	void setNoOfSeats(int);
	int getNoOfDoors() const;
	char* getTransmission() const;
	int getNoOfSeats() const;
	static int getNumberOfCars();
	void checkType();
	Car& operator=(const Car&);
	void display() const;
	~Car();
};

istream& operator >> (istream& in, Car&);
ostream& operator << (ostream& in, const Car&);
