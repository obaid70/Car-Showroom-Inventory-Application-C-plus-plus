#include "Car.h"

Car::Car(char* companyName, char* color, int numberOfWheels, int powerCC, char* typeOfVehicle, int noOfDoors, char* transmission, int noOfSeats) : Vehicle(companyName, color, numberOfWheels, powerCC, typeOfVehicle)
{
	this->noOfDoors = noOfDoors;
	deepCopy(transmission, this->transmission);
	this->noOfSeats = noOfSeats;
	numberOfCars += 1;
}

Car::Car(const Car& obj) : Vehicle(obj)
{
	this->noOfDoors = obj.noOfDoors;
	deepCopy(obj.transmission, this->transmission);
	this->noOfSeats = obj.noOfSeats;
	numberOfCars += 1;
}

void Car::setNoOfDoors(int noOfDoors)
{
	this->noOfDoors = noOfDoors;
}

void Car::setTransmission(char* transmission)
{
	deepCopy(transmission, this->transmission);
}

void Car::setNoOfSeats(int noOfSeats)
{
	this->noOfSeats = noOfSeats;
}

int Car::getNoOfDoors() const
{
	return this->noOfDoors;
}

char* Car::getTransmission() const
{
	char* temp = nullptr;
	deepCopy(this->transmission, temp);
	return temp;
}

int Car::getNoOfSeats() const
{
	return this->noOfSeats;
}

int Car::getNumberOfCars()
{
	return numberOfCars;
}

void Car::checkType()
{
	if (this->getNumberOfWheels() == 2)
		this->setTypeOfVehicle("Bike");
	else if (this->getNumberOfWheels() == 4)
		this->setTypeOfVehicle("Car");
	else
		this->setTypeOfVehicle("Truck");
}

Car& Car::operator=(const Car& obj)
{
	this->setCompanyName(obj.getCompanyName());
	this->setColor(obj.getColor());
	this->setNumberOfWheels(obj.getNumberOfWheels());
	this->setPowerCC(obj.getPowerCC());
	this->setTypeOfVehicle(obj.getTypeOfVehicle());
	this->noOfDoors = obj.noOfDoors;
	deepCopy(obj.transmission, this->transmission);
	this->noOfSeats = obj.noOfSeats;
	return *this;
}

void Car::display() const
{
	Vehicle::display();
	cout << setw(10) << this->noOfDoors << setw(15) << this->transmission << setw(10) << this->noOfSeats << endl;
}

istream& operator >> (istream &in, Car& obj)
{
	char* companyName = new char[100];
	char* color = new char[100];
	int numberOfWheels;
	int powerCC;
	char* typeOfVehicle = new char[100];
	int noOfDoors;
	char* transmission = new char[100];
	int noOfSeats;
	in.ignore();
	cout << "Enter Company Name: ";
	in.getline(companyName, 99);
	cout << "Enter Color: ";
	in.getline(color, 99);
	cout << "Enter Number of Wheels: ";
	in >> numberOfWheels;
	cout << "Enter Power CC: ";
	in >> powerCC;
	cout << "Enter No. of Doors: ";
	in >> noOfDoors;
	cout << "Transmission (automatic/manual)? ";
	in >> transmission;
	cout << "Enter No. of Seats: ";
	in >> noOfSeats;
	obj.setCompanyName(companyName);
	obj.setColor(color);
	obj.setNumberOfWheels(numberOfWheels);
	obj.setPowerCC(powerCC);
	obj.checkType();
	obj.setNoOfDoors(noOfDoors);
	obj.setTransmission(transmission);
	obj.setNoOfSeats(noOfSeats);
	return in;
}

ostream& operator << (ostream &out, const Car& obj)
{
	out << obj.getCompanyName() << setw(15) << obj.getColor() << setw(10) << obj.getNumberOfWheels() << setw(10) << obj.getPowerCC() << setw(10) << obj.getTypeOfVehicle() << setw(10) << obj.getNoOfDoors() << setw(15) << obj.getTransmission() << setw(10) << obj.getNoOfSeats() << endl;
	return out;
}

Car::~Car()
{
	this->noOfDoors = 0;
	delete[]this->transmission;
	this->transmission = nullptr;
	this->noOfSeats = 0;
	numberOfCars -= 1;
}