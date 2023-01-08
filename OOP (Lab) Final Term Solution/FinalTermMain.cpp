#include <iostream>
#include "BilalMotors.h"
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"

int Bike::numberOfBikes = 0;
int Car::numberOfCars = 0;
int Truck::numberOfTrucks = 0;

void ShowVehicles(const BilalMotors& Vehicles)
{
	cout << "\nNumber of Total Vehicles: " << Vehicles.getCounter() << endl;
	cout << "--------------------------------------------------------------------" << endl;
	for (int i = 0; i < Vehicles.getCounter(); i++)
	{
		if (!strcmp(Vehicles[i]->getTypeOfVehicle(), "Bike"))
			cout << "Company" << setw(15) << "Color" << setw(10) << "Wheels" << setw(10) << "Power" << setw(10) << "Type" << setw(10) << "Height" << setw(10) << "SelfStart" << setw(10) << "DiscBrake" << endl;
		else if (!strcmp(Vehicles[i]->getTypeOfVehicle(), "Car"))
			cout << "Company" << setw(15) << "Color" << setw(10) << "Wheels" << setw(10) << "Power" << setw(10) << "Type" << setw(10) << "Doors" << setw(15) << "Transmission" << setw(10) << "Seats" << endl;
		else if (!strcmp(Vehicles[i]->getTypeOfVehicle(), "Truck"))
			cout << "Company" << setw(15) << "Color" << setw(10) << "Wheels" << setw(10) << "Power" << setw(10) << "Type" << setw(15) << "ContainerSize" << setw(10) << "Category" << setw(15) << "FourWheelDrive" << endl;
		Vehicles[i]->display();
		cout << "--------------------------------------------------------------------" << endl;
	}
}

int main()
{
	char choiceOne, choiceTwo;
	BilalMotors vehicles;

	do
	{
		cout << "\t*** BILAL MOTORS ***" << endl << endl;
		cout << "S\tShow vehicles list (brief)" << endl;
		cout << "E\tCreate a data file (output file)" << endl;
		cout << "A\tAdd new vehicle" << endl;
		cout << "F\tFind Vehicle by type" << endl;
		cout << "Q\tQuit Program" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> choiceOne;

		switch (choiceOne)
		{
		case 'S':
			ShowVehicles(vehicles);
			break;
		case 'E':
			char fileName[100];
			cout << "Enter a File Name: ";
			cin.ignore();
			cin.getline(fileName, 99);
			if (vehicles.saveData(fileName))
				cout << "Data Successfully Written to " << fileName << endl;
			else
				cout << "Data File could not be created. Try again!" << endl;
			break;
		case 'A':
			cout << "\t B for Bike" << endl;
			cout << "\t C for Car" << endl;
			cout << "\t T for Truck" << endl << endl;
			cout << "Enter Your Choice: ";
			cin >> choiceTwo;

			if (choiceTwo == 'B')
			{
				Bike *bike = new Bike();
				cin >> *bike;
				Vehicle* newVehicle = bike;
				vehicles.addVehicle(newVehicle);
			}
			else if (choiceTwo == 'C')
			{
				Car *car = new Car();
				cin >> *car;
				Vehicle* newVehicle = car;
				vehicles.addVehicle(newVehicle);
			}
			else if (choiceTwo == 'T')
			{
				Truck *truck = new Truck();
				cin >> *truck;
				Vehicle* newVehicle = truck;
				vehicles.addVehicle(newVehicle);
			}
			break;
		case 'F':
			char vehicleType[100];
			cout << "Enter the Vehicle Type (Bus/Car/Truck): ";
			cin >> vehicleType;
			vehicles.searchVehicle(vehicleType);
			break;
		case 'Q':
			break;
		default:
			cout << "\nInvalid Choice Entered!" << endl;
			break;
		}

		cout << endl;

	} while (choiceOne != 'Q');

	return 0;
}