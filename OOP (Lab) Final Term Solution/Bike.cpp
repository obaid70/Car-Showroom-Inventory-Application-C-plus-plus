#include "Bike.h"
#include "Vehicle.h"

Bike::Bike(char* companyName, char* color, int numberOfWheels, int powerCC, char* typeOfVehicle, double height, bool selfStart, bool discBrake) : Vehicle(companyName, color, numberOfWheels, powerCC, typeOfVehicle)
{
	this->height = height;
	this->selfStart = selfStart;
	this->discBrake = discBrake;
	numberOfBikes += 1;
}

Bike::Bike(const Bike& obj) : Vehicle(obj)
{
	this->height = obj.height;
	this->selfStart = obj.selfStart;
	this->discBrake = obj.discBrake;
	numberOfBikes += 1;
}

void Bike::setHeight(double height)
{
	this->height = height;
}

void Bike::setSelfStart(bool selfStart)
{
	this->selfStart = selfStart;
}

void Bike::setDiscBrake(bool discBrake)
{
	this->discBrake = discBrake;
}

double Bike::getHeight() const
{
	return this->height;
}

bool Bike::getSelfStart() const
{
	return this->selfStart;
}

bool Bike::getDiscBrake() const
{
	return this->discBrake;
}

int Bike::getNumberOfBikes()
{
	return numberOfBikes;
}

void Bike::checkType()
{
	if (this->getNumberOfWheels() == 2)
		this->setTypeOfVehicle("Bike");
	else if (this->getNumberOfWheels() == 4)
		this->setTypeOfVehicle("Car");
	else
		this->setTypeOfVehicle("Truck");
}

Bike& Bike::operator=(const Bike& obj)
{
	this->setCompanyName(obj.getCompanyName());
	this->setColor(obj.getColor());
	this->setNumberOfWheels(obj.getNumberOfWheels());
	this->setPowerCC(obj.getPowerCC());
	this->setTypeOfVehicle(obj.getTypeOfVehicle());
	this->height = obj.height;
	this->selfStart = obj.selfStart;
	this->discBrake = obj.discBrake;
	return *this;
}

void Bike::display() const
{
	Vehicle::display();
	cout << setw(10) << this->height << setw(10) << this->boolToString(this->selfStart) << setw(10) << this->boolToString(this->discBrake) << endl;
}

istream& operator >> (istream &in, Bike& obj)
{
	char* companyName = new char[100];
	char* color = new char[100];
	int numberOfWheels;
	int powerCC;
	char* typeOfVehicle = new char[100];
	double height;
	bool selfStart;
	bool discBrake;
	in.ignore();
	cout << "Enter Company Name: ";
	in.getline(companyName, 99);
	cout << "Enter Color: ";
	in.getline(color, 99);
	cout << "Enter Number of Wheels: ";
	in >> numberOfWheels;
	cout << "Enter Power CC: ";
	in >> powerCC;
	cout << "Enter Height: ";
	in >> height;
	cout << "Self Start (1/0)? ";
	in >> selfStart;
	cout << "Disc Brake (1/0)? ";
	in >> discBrake;
	obj.setCompanyName(companyName);
	obj.setColor(color);
	obj.setNumberOfWheels(numberOfWheels);
	obj.setPowerCC(powerCC);
	obj.checkType();
	obj.setHeight(height);
	obj.setSelfStart(selfStart);
	obj.setDiscBrake(discBrake);
	return in;
}

ostream& operator << (ostream &out, const Bike& obj)
{
	out << obj.getCompanyName() << setw(15) << obj.getColor() << setw(10) << obj.getNumberOfWheels() << setw(10) << obj.getPowerCC() << setw(10) << obj.getTypeOfVehicle() << setw(10) << obj.getHeight() << setw(10) << obj.boolToString(obj.getSelfStart()) << setw(10) << obj.boolToString(obj.getDiscBrake()) << endl;
	return out;
}

Bike::~Bike()
{
	this->height = 0;
	this->selfStart = true;
	this->discBrake = true;
	numberOfBikes -= 1;
}