#include "Truck.h"

Truck::Truck(char* companyName, char* color, int numberOfWheels, int powerCC, char* typeOfVehicle, double containerSize, char* categorybool, bool fourWheelDrive) : Vehicle(companyName, color, numberOfWheels, powerCC, typeOfVehicle)
{
	this->containerSize = containerSize;
	deepCopy(category, this->category);
	this->fourWheelDrive = fourWheelDrive;
	numberOfTrucks += 1;
}

Truck::Truck(const Truck& obj) : Vehicle(obj)
{
	this->containerSize = obj.containerSize;
	deepCopy(obj.category, this->category);
	this->fourWheelDrive = obj.fourWheelDrive;
	numberOfTrucks += 1;
}

void Truck::setContainerSize(double containerSize)
{
	this->containerSize = containerSize;
}

void Truck::setCategory(char* category)
{
	deepCopy(category, this->category);
}

void Truck::setFourWheelDrive(bool fourWheelDrive)
{
	this->fourWheelDrive = fourWheelDrive;
}

double Truck::getContainerSize() const
{
	return this->containerSize;
}

char* Truck::getCategory() const
{
	char* temp = nullptr;
	deepCopy(this->category, temp);
	return temp;
}

bool Truck::getFourWheelDrive() const
{
	return this->fourWheelDrive;
}

int Truck::getNumberOfTrucks()
{
	return numberOfTrucks;
}

void Truck::checkType()
{
	if (this->getNumberOfWheels() == 2)
		this->setTypeOfVehicle("Bike");
	else if (this->getNumberOfWheels() == 4)
		this->setTypeOfVehicle("Car");
	else
		this->setTypeOfVehicle("Truck");
}

Truck& Truck::operator=(const Truck& obj)
{
	this->setCompanyName(obj.getCompanyName());
	this->setColor(obj.getColor());
	this->setNumberOfWheels(obj.getNumberOfWheels());
	this->setPowerCC(obj.getPowerCC());
	this->setTypeOfVehicle(obj.getTypeOfVehicle());
	this->containerSize = obj.containerSize;
	deepCopy(obj.category, this->category);
	this->fourWheelDrive = obj.fourWheelDrive;
	return *this;
}

void Truck::display() const
{
	Vehicle::display();
	cout << setw(15) << this->containerSize << setw(10) << this->category << setw(15) << this->boolToString(this->fourWheelDrive) << endl;
}

istream& operator >> (istream &in, Truck& obj)
{
	char* companyName = new char[100];
	char* color = new char[100];
	int numberOfWheels;
	int powerCC;
	char* typeOfVehicle = new char[100];
	double containerSize;
	char* category = new char[100];
	bool fourWheelDrive;
	in.ignore();
	cout << "Enter Company Name: ";
	in.getline(companyName, 99);
	cout << "Enter Color: ";
	in.getline(color, 99);
	cout << "Enter Number of Wheels: ";
	in >> numberOfWheels;
	cout << "Enter Power CC: ";
	in >> powerCC;
	cout << "Enter Container Size: ";
	in >> containerSize;
	in.ignore();
	cout << "Enter Category: ";
	in.getline(category, 99);
	cout << "Four Wheel Drive (1/0)? ";
	in >> fourWheelDrive;
	obj.setCompanyName(companyName);
	obj.setColor(color);
	obj.setNumberOfWheels(numberOfWheels);
	obj.setPowerCC(powerCC);
	obj.checkType();
	obj.setContainerSize(containerSize);
	obj.setCategory(category);
	obj.setFourWheelDrive(fourWheelDrive);
	return in;
}

ostream& operator << (ostream &out, const Truck& obj)
{
	out << obj.getCompanyName() << setw(15) << obj.getColor() << setw(10) << obj.getNumberOfWheels() << setw(10) << obj.getPowerCC() << setw(10) << obj.getTypeOfVehicle() << setw(15) << obj.getContainerSize() << setw(10) << obj.getCategory() << setw(15) << obj.boolToString(obj.getFourWheelDrive()) << endl;
	return out;
}

Truck::~Truck()
{
	this->containerSize = 0;
	delete[]this->category;
	this->category = nullptr;
	this->fourWheelDrive = true;
	numberOfTrucks -= 1;
}
