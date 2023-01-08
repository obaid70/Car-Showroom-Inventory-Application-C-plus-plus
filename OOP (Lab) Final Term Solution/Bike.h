#pragma once

#include "Vehicle.h"

class Bike : public Vehicle
{
	double height;
	bool selfStart;
	bool discBrake;
	static int numberOfBikes;
public:
	Bike(char* companyName = nullptr, char* color = nullptr, int numberOfWheels = 0, int powerCC = 0, char* typeOfVehicle = nullptr, double height = 0, bool selfStart = true, bool discBrake = true);
	Bike(const Bike&);
	void setHeight(double);
	void setSelfStart(bool);
	void setDiscBrake(bool);
	double getHeight() const;
	bool getSelfStart() const;
	bool getDiscBrake() const;
	static int getNumberOfBikes();
	void checkType();
	Bike& operator=(const Bike&);
	void display() const;
	~Bike();
};

istream& operator >> (istream& in, Bike&);
ostream& operator << (ostream& in, const Bike&);

