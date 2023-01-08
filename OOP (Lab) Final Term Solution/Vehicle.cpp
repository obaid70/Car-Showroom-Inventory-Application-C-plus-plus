#include "Vehicle.h"

Vehicle::Vehicle(char* companyName, char* color, int numberOfWheels, int powerCC, char* typeOfVehicle)
{
	deepCopy(companyName, this->companyName);
	deepCopy(color, this->color);
	this->numberOfWheels = numberOfWheels;
	this->powerCC = powerCC;
	deepCopy(typeOfVehicle, this->typeOfVehicle);
}

Vehicle::Vehicle(const Vehicle& obj)
{
	deepCopy(obj.companyName, this->companyName);
	deepCopy(obj.color, this->color);
	this->numberOfWheels = obj.numberOfWheels;
	this->powerCC = obj.powerCC;
	deepCopy(obj.typeOfVehicle, this->typeOfVehicle);
}

char* Vehicle::boolToString(bool value) const
{
	if (value)
		return "Yes";
	else
		return "No";
}

void Vehicle::deepCopy(char* source, char*& destination) const
{
	if (source != nullptr)
	{
		int length = strlen(source);
		destination = new char[length + 1];
		for (int i = 0; i < length; i++)
			destination[i] = source[i];
		destination[length] = '\0';
	}
	else
	{
		destination = nullptr;
	}
}

void Vehicle::setCompanyName(char* companyName)
{
	deepCopy(companyName, this->companyName);
}

void Vehicle::setColor(char* color)
{
	deepCopy(color, this->color);
}

void Vehicle::setNumberOfWheels(int numberOfWheels)
{
	this->numberOfWheels = numberOfWheels;
}

void Vehicle::setPowerCC(int powerCC)
{
	this->powerCC = powerCC;
}

void Vehicle::setTypeOfVehicle(char* typeOfVehicle)
{
	deepCopy(typeOfVehicle, this->typeOfVehicle);
}

char* Vehicle::getCompanyName() const
{
	char* temp = nullptr;
	deepCopy(this->companyName, temp);
	return temp;
}

char* Vehicle::getColor() const
{
	char* temp = nullptr;
	deepCopy(this->color, temp);
	return temp;
}

int Vehicle::getNumberOfWheels() const
{
	return this->numberOfWheels;
}

int Vehicle::getPowerCC() const
{
	return this->powerCC;
}

char* Vehicle::getTypeOfVehicle() const
{
	char* temp = nullptr;
	deepCopy(this->typeOfVehicle, temp);
	return temp;
}

void Vehicle::display() const
{
	cout << this->companyName << setw(15) << this->color << setw(10) << this->numberOfWheels << setw(10) << this->powerCC << setw(10) << this->typeOfVehicle;
}

Vehicle::~Vehicle()
{
	if (companyName)
	{
		delete[] companyName, typeOfVehicle, color;
		companyName, typeOfVehicle, color = nullptr;
	}
	/*delete[]this->companyName;
	this->companyName = nullptr;
	delete[]this->color;
	this->color = nullptr;
	this->numberOfWheels = 0;
	this->powerCC = 0;
	delete[]this->typeOfVehicle;
	this->typeOfVehicle = nullptr;*/
}