#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle
{
	char* companyName;
	char* color;
	int numberOfWheels;
	int powerCC;
	char* typeOfVehicle;
public:
	char* boolToString(bool) const;
	void deepCopy(char*, char*&) const;
	Vehicle(char* companyName = nullptr, char* color = nullptr, int numberOfWheels = 0, int powerCC = 0, char* typeOfVehicle = nullptr);
	Vehicle(const Vehicle&);
	void setCompanyName(char*);
	void setColor(char*);
	void setNumberOfWheels(int);
	void setPowerCC(int);
	void setTypeOfVehicle(char*);
	char* getCompanyName() const;
	char* getColor() const;
	int getNumberOfWheels() const;
	int getPowerCC() const;
	char* getTypeOfVehicle() const;
	virtual void checkType() = 0;
	virtual void display() const;
	~Vehicle();
};
