#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "LinkedList.h"
#include "Node.h"
#include "Engine.h"
#include "Transmission.h"
using namespace std;

class Sedan : public Vehicle {
private:
	bool sunroof;
public:
	Sedan() : sunroof(false) {}
	Sedan(const bool sunroof) : sunroof(sunroof) {}
	virtual void displayDetails() const override {
		std::cout << "SedanDetails()\n\t";
		std::cout << "sunroof : " ;
		if (sunroof) {
			std::cout << "true";
		}
		else {
			std::cout << "false";
		}
		std::cout << "\n";
	}
};
class Truck : public Vehicle {
private:
	float load_capacity;
public:
	Truck() : load_capacity(0.0) {}
	Truck(const float load_capacity) : load_capacity(load_capacity) {}
	virtual void displayDetails() const override {
		std::cout << "TruckDetails()\n\t";
		std::cout << "load_capacity : " << load_capacity << "\n";
	}
};
class Motorcycle : public Vehicle {
private:
	double sunroof;
public:
	Motorcycle() : sunroof(0.0) {}
	Motorcycle(const double sunroof) : sunroof(sunroof) {}
	virtual void displayDetails() const override {
		std::cout << "MotorcycleDetails()\n\t";
		std::cout << "sunroof : " << sunroof << "\n";
	}
};
class Moped : public Vehicle {
private:
	double max_speed;
public:
	Moped() : max_speed(0.0) {}
	Moped(const double max_speed) : max_speed(max_speed) {}
	virtual void displayDetails() const override {
		std::cout << "MopedDetails()\n\t";
		std::cout << "sunroof : " << max_speed << "\n";
	}
};

string toLowercase(string text);

void SearchByType(LinkedList* autopark);
void SearchByYearProd(LinkedList* autopark);
void SearchByPrice(LinkedList* autopark);
void SearchBySeveralParameters(LinkedList* autopark);

void InsertAtEnd_local(LinkedList* autopark) {
	std::string vehicleType;
	std::string brand;
	std::string model;
	int year;
	double price;

	double volume;
	std::string fuelType;
	int horsepower;

	std::string transmissionType;
	cout << "Enter vehicle type : ";
	cin >> vehicleType;
	cout << "Enter brand : ";
	cin >> brand;
	cout << "Enter model : ";
	cin >> model;
	cout << "Enter year : ";
	cin >> year;
	cout << "Enter price : ";
	cin >> price;
	cout << "Enter engine volume : ";
	cin >> volume;
	cout << "Enter fuel type : ";
	cin >> fuelType;
	cout << "Enter engine horsepower : ";
	cin >> horsepower;
	cout << "Enter transmission type : ";
	cin >> transmissionType;
	autopark->InsertAtEnd(
		new Vehicle{vehicleType, brand, model, year, price,
		new Engine(volume, fuelType, horsepower),
		new Transmission(transmissionType)});
	if (toLowercase(vehicleType) == "sedan") {
		cout << "Enter availability of sunroof: ";
		cin >> transmissionType;
		autopark->GetMyVehicle(autopark->GetSize()-1).
	}
}

int main() {
	LinkedList* autopark = new LinkedList();

	Vehicle* auto1 = new Vehicle("Sedan", "Audi", "A4", 2009, 1200.50,
		new Engine(1.8, "gas", 200),
		new Transmission("automatic"));
	Vehicle* auto2 = new Vehicle("Truck", "Toyota", "RAV4", 2021, 1500.75,
		new Engine(2.5, "hybrid", 250),
		new Transmission("mechanic"));
	Vehicle* auto3 = new Vehicle("Sedan", "Audi", "A5", 2021, 1200.50,
		new Engine(1.8, "disel", 200),
		new Transmission("automatic"));

	autopark->InsertAtEnd(auto1, new Sedan(true));
	autopark->InsertAtEnd(auto2, new Truck(222.2));
	autopark->InsertAtEnd(auto3, new Sedan(false));

	string enter = "";
	cout << "\tAutopark\n";
	cout << "Enter number of the vehicle to get details\n"
		"Enter \"+\" to add vehicle\n"
		"Enter \"-\" to remove vehicle\n"
		"Enter \"help\" to get help\n"
		"Enter \"out\" for out\n\n";
	while (enter != "out") {
		if (autopark->GetSize() > 0) {
			for (size_t i = 0; i < autopark->GetSize(); i++)
			{
				cout << i+1 << " : " << autopark->GetMyVehicle(i).getBrand()
					<< " " << autopark->GetMyVehicle(i).getModel() << endl;
			}
		}
		else {
			cout << "Autopark is empty\n";
		}
		cout << "\nEnter : ";
		cin >> enter;
		cout << endl;
		if (enter == "help") {
			cout << "Enter number of the vehicle to get details\n"
				"Enter \"+\" to add vehicle\n"
				"Enter \"-\" to remove vehicle\n"
				"Enter \"help\" to get help\n"
				"Enter \"out\" for out\n\n";
		}
		else if (enter == "+") {
			autopark->InsertAtEnd(Vehicle, new Sedan(true));
		}
	}
	cout << "The program is finished\n";

	//SearchByType(autopark);
	//SearchByYearProd(autopark);
	//SearchByPrice(autopark);
	//SearchBySeveralParameters(autopark);

	//��������� �������� ������� �������� ��� ����� ������������ ������, �� �������������
	//(������, ��������), 
	//� ����� ���������� ������� ������ �� ������ �����������. ��� ���������� ������� ����
	//����������� � ������ ��'���� ����� � ���������� �������� �� ����������.
	//
	//3. ������:
	//
	//3.1. �����
	//
	//Engine (������)
	//
	//���������:
	//��'�� ������� (double).
	//��� �������� (string).
	//��������� (horsepower) (int).
	//
	//������:
	//������������ ��� �����������.
	//��������� ���������.
	//������ ��������� ����� (getVolume, getFuelType, getPower).
	//����� ��� ����������� ������������� �������.
	//
	//
	//Transmission (��������)
	//
	//���������:
	//��� ������� (string).
	//������:
	//������������ ��� �����������.
	//��������� ���������.
	//������ ��������� ����� (getType).
	//����� ��� ����������� ������������� �������.
	//
	//
	//Vehicle (������������ ����)
	//
	//���������:
	//��� ������������� ������ (string).
	//����� (string).
	//������ (string).
	//г� ������� (int).
	//ֳ�� (double).
	//������ (Engine).
	//�������� (Transmission).
	//
	//������:
	//������������ ��� �����������.
	//��������� ���������.
	//������ ��� ��������� �� ������������ ����� (getTypeVehicle, getBrand, getModel, getYear,
	//getPrice, getEngine, getTransmission ����).
	//����� ��� ����������� ��� ������������� ������������� ������, ��������� ������ �� ��������.
	//
	//�����-�������:
	//
	//Sedan (�����)
	//�������� ���������: �������� ���� (bool).
	//�������������� ����� displayDetails ��� ����������� ����������� �����.
	//Truck (��������)
	//�������� ���������: ���������������� (float).
	//�������������� ����� displayDetails ��� ����������� ����������� �����.
	//Motorcycle (��������)
	//�������� ���������: ������� �������� (double).
	//�������������� ����� displayDetails ��� ����������� ����������� �����.
	//Moped (�����)
	//�������� ���������: ����������� �������� (double).
	//�������������� ����� displayDetails ��� ����������� ����������� �����.
	//
	//
	//3.2. ������� ������:
	//
	//SearchByType � ������� ��� ������ ������������ ������ �� ����� (���������, �����, ���������,
	//��������).
	//SearchByYearProd � ������� ��� ������ �� ����� �������.
	//SearchByPrice � ������� ��� ������ ������������ ������ �� ��������� ��� (�� �������� ��
	//����������� ����).
	//SearchBySeveralParameters � ������� ��� ������ ������������ ������ �� ������� �����������:
	//�����.
	//������.
	//г� �������.
	//3.4. ������ �� ����:
	//
	//����� ������ ���� ��������� � ������������� �������� ���:
	//
	//����������� (���������, ����� Sedan, Truck ���� ������������ �� Vehicle).
	//������������ (���, ��� �� �������������� ������� �� �������, �������� �� �������
	//������� � ������� ����� ������).
	//���������� (�������������� ������, ���������, displayDetails() � ����������� ������).
	//������:
	//
	//� ���� Vehicle ������ ������ ��������� �������� �� ���������� ��� ��� ������������ ����.
	//� ������-�������� ����� displayDetails() ������� ���� �������������� ��� ��������� ����������
	//�������������.
	//�����:
	//
	//������� ������ ������ ���� ������������� �� ��������� ������ �� ��������� �����������.
	//��������� ��������� ������� �����, �������������� ����������.
	//4. �������� ������:
	//
	//�� ���������� ������ ������ ���� ����������� �� ��'���� �����, � � ���� ������ ����
	//������ ���������� (���������, �����, ��������� �� �����).
	//��� �������� �����䳿 � ������������ �� ������� ��� ������ ���� ������������
	//� ������ ������ ������.
	//5. �������� ����������:
	//
	//���������� ��� � ������ �������� �� C++ � ��������� ������� �� ��������� ������.
	//�������� ������� �������� ��������� ��� ������ ������������ ������ (���������, 5-10
	//��'���� ���� Sedan, Truck, Motorcycle, Moped).
	//�� ������� ������ ������ ��������� ���������� ���������.
}

string toLowercase(string text) {
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i] = text[i] + ('a' - 'A');
		}
	}
	return text;
}

void SearchByType(LinkedList* autopark) {
	int count = 0;
	string search;
	string enter;
	cout << "Enter type of the vehicle to find : ";
	cin >> search;
	LinkedList* temp_autopark = new LinkedList();
	for (size_t i = 0; i < autopark->GetSize(); i++)
	{
		if (toLowercase(autopark->GetMyVehicle(i).getVehicleType()) == toLowercase(search)) {
			Vehicle* temp = &autopark->GetMyVehicle(i);
			temp_autopark->InsertAtEnd(temp);
			count++;
		}
	}
	if (!count) {
		cout << "Autopark does`t have vehicles with this type(" << search << ")\n\n";
		return;
	}
	cout << "\nThe count of finded vehicles with this type is " << count << endl;
	cout << "To see this vehicles enter \"+\"\n"
		"To out enter \"-\"\n"
		"To refinding enter \"\\\"\n\n";
	while (true) {
		cout << "Enter : ";
		cin >> enter;
		cout << endl;
		if (enter == "+") {
			for (size_t i = 0; i < temp_autopark->GetSize(); i++)
			{
				temp_autopark->GetMyVehicle(i).printInfo();
				cout << endl;
			}
			cout << endl;
		}
		else if (enter == "-") {
			cout << "SearchByType is finished\n\n";
			break;
		}
		else if (enter == "\\") {
			SearchByType(autopark);
			break;
		}
		else {
			cout << "Noname command\n\n";
		}
	}
}
void SearchByYearProd(LinkedList* autopark) {
	int count = 0;
	int search;
	string enter;
	cout << "Enter year of the vehicle to find : ";
	cin >> search;
	LinkedList* temp_autopark = new LinkedList();
	for (size_t i = 0; i < autopark->GetSize(); i++)
	{
		if (autopark->GetMyVehicle(i).getYear() == search) {
			Vehicle* temp = &autopark->GetMyVehicle(i);
			temp_autopark->InsertAtEnd(temp);
			count++;
		}
	}
	if (!count) {
		cout << "Autopark does`t have vehicles with this year(" << search << ")\n\n";
		return;
	}
	cout << "\nThe count of finded vehicles with this year is " << count << endl;
	cout << "To see this vehicles enter \"+\"\n"
		"To out enter \"-\"\n"
		"To refinding enter \"\\\"\n\n";
	while (true) {
		cout << "Enter : ";
		cin >> enter;
		cout << endl;
		if (enter == "+") {
			for (size_t i = 0; i < temp_autopark->GetSize(); i++)
			{
				temp_autopark->GetMyVehicle(i).printInfo();
				cout << endl;
			}
			cout << endl;
		}
		else if (enter == "-") {
			cout << "SearchByYearProd is finished\n\n";
			break;
		}
		else if (enter == "\\") {
			SearchByYearProd(autopark);
			break;
		}
		else {
			cout << "Noname command\n\n";
		}
	}
}
void SearchByPrice(LinkedList* autopark) {
	int count = 0;
	double search_min, search_max;
	string enter;
	cout << "Enter min price of the vehicle to find : ";
	cin >> search_min;
	cout << "Enter max price of the vehicle to find : ";
	cin >> search_max;
	LinkedList* temp_autopark = new LinkedList();
	for (size_t i = 0; i < autopark->GetSize(); i++)
	{
		if (autopark->GetMyVehicle(i).getPrice() >= search_min &&
			autopark->GetMyVehicle(i).getPrice() <= search_max) {
			Vehicle* temp = &autopark->GetMyVehicle(i);
			temp_autopark->InsertAtEnd(temp);
			count++;
		}
	}
	if (!count) {
		cout << "Autopark does`t have vehicles with this price(" << search_min << "-" << search_max << ")\n\n";
		return;
	}
	cout << "\nThe count of finded vehicles with this price is " << count << endl;
	cout << "To see this vehicles enter \"+\"\n"
		"To out enter \"-\"\n"
		"To refinding enter \"\\\"\n\n";
	while (true) {
		cout << "Enter : ";
		cin >> enter;
		cout << endl;
		if (enter == "+") {
			for (size_t i = 0; i < temp_autopark->GetSize(); i++)
			{
				temp_autopark->GetMyVehicle(i).printInfo();
				cout << endl;
			}
			cout << endl;
		}
		else if (enter == "-") {
			cout << "SearchByPrice is finished\n\n";
			break;
		}
		else if (enter == "\\") {
			SearchByPrice(autopark);
			break;
		}
		else {
			cout << "Noname command\n\n";
		}
	}
}
void SearchBySeveralParameters(LinkedList* autopark) {
	int count = 0;
	string search_brand, search_model;
	int search_year;
	string enter;
	cout << "Enter brand of the vehicle to find : ";
	cin >> search_brand;
	cout << "Enter model of the vehicle to find : ";
	cin >> search_model;
	cout << "Enter year of the vehicle to find : ";
	cin >> search_year;
	LinkedList* temp_autopark = new LinkedList();
	for (size_t i = 0; i < autopark->GetSize(); i++)
	{
		if (toLowercase(autopark->GetMyVehicle(i).getBrand()) == toLowercase(search_brand)
			&& toLowercase(autopark->GetMyVehicle(i).getModel()) == toLowercase(search_model)
			&& autopark->GetMyVehicle(i).getYear() == search_year) {
			Vehicle* temp = &autopark->GetMyVehicle(i);
			temp_autopark->InsertAtEnd(temp);
			count++;
		}
	}
	if (!count) {
		cout << "Autopark does`t have vehicles with this parameters(" <<
			search_brand << ", " << search_model << ", " << search_year << ")\n\n";
		return;
	}
	cout << "\nThe count of finded vehicles with this parameters is " << count << endl;
	cout << "To see this vehicles enter \"+\"\n"
		"To out enter \"-\"\n"
		"To refinding enter \"\\\"\n\n";
	while (true) {
		cout << "Enter : ";
		cin >> enter;
		cout << endl;
		if (enter == "+") {
			for (size_t i = 0; i < temp_autopark->GetSize(); i++)
			{
				temp_autopark->GetMyVehicle(i).printInfo();
				cout << endl;
			}
			cout << endl;
		}
		else if (enter == "-") {
			cout << "SearchBySeveralParameters is finished\n\n";
			break;
		}
		else if (enter == "\\") {
			SearchBySeveralParameters(autopark);
			break;
		}
		else {
			cout << "Noname command\n\n";
		}
	}
}