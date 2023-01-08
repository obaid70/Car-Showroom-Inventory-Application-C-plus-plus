#pragma once

#include "Vehicle.h"

class Truck : public Vehicle
{
	double containerSize;
	char* category;
	bool fourWheelDrive;
	static int numberOfTrucks;
public:
	Truck(char* companyName = nullptr, char* color = nullptr, int numberOfWheels = 0, int powerCC = 0, char* typeOfVehicle = nullptr, double containerSize = 0, char* category = nullptr, bool fourWheelDrive = true);
	Truck(const Truck&);
	void setContainerSize(double);
	void setCategory(char*);
	void setFourWheelDrive(bool);
	double getContainerSize() const;
	char* getCategory() const;
	bool getFourWheelDrive() const;
	static int getNumberOfTrucks();
	void checkType();
	Truck& operator=(const Truck&);
	void display() const;
	~Truck();
};

istream& operator >> (istream& in, Truck&);
ostream& operator << (ostream& in, const Truck&);
