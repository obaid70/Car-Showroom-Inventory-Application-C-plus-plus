#include "BilalMotors.h"

BilalMotors::BilalMotors()
{
	this->arr = nullptr;
	this->counter = 0;
}

void BilalMotors::addVehicle(Vehicle* obj)
{
	Vehicle **temp = new Vehicle*[++counter];

	if (this->arr != nullptr) {
		for (int i = 0; i < counter - 1; i++)
			temp[i] = this->arr[i];
		delete[]this->arr;
	}

	temp[counter - 1] = obj;
	this->arr = temp;
	temp = nullptr;
}

void BilalMotors::searchVehicle(char* vehicleType)
{
	if (this->arr == nullptr)
		cout << "No Vehicles Found!" << endl;
	else
		for (int i = 0; i < counter; i++)
			if (strcmp(this->arr[i]->getTypeOfVehicle(), vehicleType))
				this->arr[i]->display();
}

Vehicle* BilalMotors::operator[](int index)
{
	if (index >= counter) {
		cout << "Index out of bound, exiting!" << endl;
		exit(0);
	}
	return this->arr[index];
}

const Vehicle* BilalMotors::operator[](int index) const
{
	if (index >= counter) {
		cout << "Index out of bound, exiting!" << endl;
		exit(0);
	}
	return this->arr[index];
}

int BilalMotors::getCounter() const
{
	return this->counter;
}

bool BilalMotors::saveData(const char* fileName) const
{
	ofstream fout;
	fout.open(fileName, ios::out);
	if (!fout.is_open())
		return false;
	fout << "Vehicle Information" << endl;
	fout << "---------------------" << endl;
	fout << "Number of Bikes: " << Bike::getNumberOfBikes() << endl;
	fout << "Number of Cars: " << Car::getNumberOfCars() << endl;
	fout << "Number of Trucks: " << Truck::getNumberOfTrucks() << endl << endl;
	fout << "Company Name" << setw(15) << "Type" << setw(10) << "Color" << setw(10) << "Power" << endl;
	fout << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < this->counter; i++)
		fout << this->arr[i]->getCompanyName() << setw(15) << this->arr[i]->getTypeOfVehicle() << setw(10) << this->arr[i]->getColor() << setw(10) << this->arr[i]->getPowerCC() << endl;
	fout.close();
	return true;
}

BilalMotors::~BilalMotors()
{
	if (this->arr != nullptr) {
		for (int i = 0; i < this->counter; i++) {
			delete[]this->arr[i];
			this->arr[i] = nullptr;
		}
		delete[]this->arr;
		this->arr = nullptr;
	}
	this->counter = 0;
}