#pragma once

#include <fstream>
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"

class BilalMotors
{
	Vehicle **arr;
	int counter;
public:
	BilalMotors();
	void addVehicle(Vehicle*);
	void searchVehicle(char*);
	Vehicle* operator[](int);
	const Vehicle* operator[](int) const;
	int getCounter() const;
	bool saveData(const char* fileName) const;
	~BilalMotors();
};

