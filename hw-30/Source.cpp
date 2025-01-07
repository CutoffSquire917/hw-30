#include <iostream>
#include <cstring>
#include <string>
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
	double consumption;
public:
	Motorcycle() : consumption(0.0) {}
	Motorcycle(const double consumption) : consumption(consumption) {}
	virtual void displayDetails() const override {
		std::cout << "MotorcycleDetails()\n\t";
		std::cout << "consumption : " << consumption << "\n";
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
		std::cout << "max speed : " << max_speed << "\n";
	}
};

string toLowercase(string text);
bool isValidInt(const string toInt);
bool isValidFloat(const string toFloat);
bool isValidDouble(const string toDouble);

void SearchByType(LinkedList* autopark);
void SearchByYearProd(LinkedList* autopark);
void SearchByPrice(LinkedList* autopark);
void SearchBySeveralParameters(LinkedList* autopark);

void InsertAtEnd_local(LinkedList* autopark);

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
	autopark->InsertAtEnd(auto3);
	autopark->SetMyDetails(2, new Sedan(true));

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
		enter = toLowercase(enter);
		cout << endl;
		if (enter == "help") {
			cout << "Enter number of the vehicle to get details\n"
				"Enter \"+\" to add vehicle\n"
				"Enter \"-\" to remove vehicle\n"
				"Enter \"help\" to get help\n"
				"Enter \"out\" for out\n\n";
		}
		else if (enter == "+") {
			InsertAtEnd_local(autopark);
		}
		else if (enter == "-") {
			cout << "Enter \"out\" to out\n"
					"Enter index of the vehicle to delete it\n";
			for (size_t i = 0; i < autopark->GetSize(); i++)
			{
				cout << i + 1 << " : " << autopark->GetMyVehicle(i).getBrand()
					<< " " << autopark->GetMyVehicle(i).getModel() << endl;
			}
			string choice;
			while (true) {
				cout << "\nEnter : ";
				cin >> choice;
				choice = toLowercase(choice);
				cout << endl;
				if (isValidInt(choice)) {
					int del_index = stoi(choice) - 1;
					if (del_index < 0 || del_index >= int(autopark->GetSize()) || int(autopark->GetSize()) == 0) {
						cout << "Index out of the range\n";
					}
					else {
						cout << "Vehicle " << autopark->GetMyVehicle(del_index).getBrand()
							<< " " << autopark->GetMyVehicle(del_index).getModel() << " is deleted\n\n";
						autopark->RemoveAtIndex(del_index);
						break;
					}
				}
				else if (choice == "help") {
					cout << "Enter \"out\" to out\n"
							"Enter index of the vehicle to delete it\n";
					for (size_t i = 0; i < autopark->GetSize(); i++)
					{
						cout << i + 1 << " : " << autopark->GetMyVehicle(i).getBrand()
							<< " " << autopark->GetMyVehicle(i).getModel() << endl;
					}
				}
				else if (choice == "out") {
					break;
				}
				else {
					cout << "Unknown command\n";
				}

			}
		}
		else {
			cout << "Unknown command\n\n";
		}
	}
	cout << "The program is finished\n";

	//SearchByType(autopark);
	//SearchByYearProd(autopark);
	//SearchByPrice(autopark);
	//SearchBySeveralParameters(autopark);

	//Необхідно створити класову ієрархію для опису транспортних засобів, їх характеристик
	//(двигун, трансмісія), 
	//а також реалізувати функції пошуку за різними параметрами. Вся інформація повинна бути
	//організована у вигляді об'єктів класів з відповідними методами та атрибутами.
	//
	//3. Вимоги:
	//
	//3.1. Класи
	//
	//Engine (Двигун)
	//
	//Параметри:
	//Об'єм двигуна (double).
	//Тип пального (string).
	//Потужність (horsepower) (int).
	//
	//Методи:
	//Конструктори для ініціалізації.
	//Оператори порівняння.
	//Методи отримання даних (getVolume, getFuelType, getPower).
	//Метод для відображення характеристик двигуна.
	//
	//
	//Transmission (Трансмісія)
	//
	//Параметри:
	//Тип трансмісії (string).
	//Методи:
	//Конструктори для ініціалізації.
	//Оператори порівняння.
	//Методи отримання даних (getType).
	//Метод для відображення характеристик трансмісії.
	//
	//
	//Vehicle (Транспортний засіб)
	//
	//Параметри:
	//Тип транспортного засобу (string).
	//Бренд (string).
	//Модель (string).
	//Рік випуску (int).
	//Ціна (double).
	//Двигун (Engine).
	//Трансмісія (Transmission).
	//
	//Методи:
	//Конструктори для ініціалізації.
	//Оператори порівняння.
	//Методи для отримання та встановлення даних (getTypeVehicle, getBrand, getModel, getYear,
	//getPrice, getEngine, getTransmission тощо).
	//Метод для відображення всіх характеристик транспортного засобу, включаючи двигун та трансмісію.
	//
	//Класи-нащадки:
	//
	//Sedan (Седан)
	//Додаткові параметри: наявність люка (bool).
	//Перевизначений метод displayDetails для відображення специфічних даних.
	//Truck (Грузовик)
	//Додаткові параметри: вантажопідйомність (float).
	//Перевизначений метод displayDetails для відображення специфічних даних.
	//Motorcycle (Мотоцикл)
	//Додаткові параметри: витрати пального (double).
	//Перевизначений метод displayDetails для відображення специфічних даних.
	//Moped (Мопед)
	//Додаткові параметри: максимальна швидкість (double).
	//Перевизначений метод displayDetails для відображення специфічних даних.
	//
	//
	//3.2. Функції пошуку:
	//
	//SearchByType — Функція для пошуку транспортних засобів за типом (наприклад, седан, вантажівка,
	//мотоцикл).
	//SearchByYearProd — Функція для пошуку за роком випуску.
	//SearchByPrice — Функція для пошуку транспортних засобів за діапазоном цін (від мінімальної до
	//максимальної ціни).
	//SearchBySeveralParameters — Функція для пошуку транспортних засобів за кількома параметрами:
	//Бренд.
	//Модель.
	//Рік випуску.
	//3.4. Вимоги до коду:
	//
	//Класи повинні бути реалізовані з використанням принципів ООП:
	//
	//Наслідування (наприклад, класи Sedan, Truck тощо успадковують від Vehicle).
	//Інкапсуляція (дані, такі як характеристики двигуна та трансмісії, приховані від прямого
	//доступу і доступні через методи).
	//Поліморфізм (перевизначення методів, наприклад, displayDetails() в наслідуваних класах).
	//Методи:
	//
	//В класі Vehicle методи повинні дозволяти змінювати та отримувати дані про транспортний засіб.
	//В класах-нащадках метод displayDetails() повинен бути перевизначений для виведення додаткових
	//характеристик.
	//Пошук:
	//
	//Функції пошуку повинні бути універсальними та ефективно шукати за потрібними параметрами.
	//Необхідно обробляти помилки вводу, використовуючи виключення.
	//4. Додаткові вимоги:
	//
	//Усі транспортні засоби повинні бути представлені як об'єкти класів, і з ними повинні бути
	//можливі маніпуляції (додавання, пошук, виведення на екран).
	//Для зручності взаємодії з користувачем всі виведені дані повинні бути відформатовані
	//у вигляді читаємої строки.
	//5. Очікувані результати:
	//
	//Початковий код у вигляді програми на C++ з описаними класами та функціями пошуку.
	//Програма повинна коректно працювати для кількох транспортних засобів (наприклад, 5-10
	//об'єктів типу Sedan, Truck, Motorcycle, Moped).
	//Усі функції пошуку повинні повертати правильний результат.
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
bool isValidInt(const string toInt) {
	try {
		stoi(toInt);
		return true;
	}
	catch (...) {
		return false;
	}
}
bool isValidFloat(const string toFloat) {
	try {
		stof(toFloat);
		return true;
	}
	catch (...) {
		return false;
	}
}
bool isValidDouble(const string toDouble) {
	try {
		stod(toDouble);
		return true;
	}
	catch (...) {
		return false;
	}
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
		"To refinding enter \"/\"\n\n";
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
		else if (enter == "/") {
			SearchByType(autopark);
			break;
		}
		else {
			cout << "Unknown command\n\n";
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
		"To refinding enter \"/\"\n\n";
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
		else if (enter == "/") {
			SearchByYearProd(autopark);
			break;
		}
		else {
			cout << "Unknown command\n\n";
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
		"To refinding enter \"/\"\n\n";
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
		else if (enter == "/") {
			SearchByPrice(autopark);
			break;
		}
		else {
			cout << "Unknown command\n\n";
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
		"To refinding enter \"/\"\n\n";
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
		else if (enter == "/") {
			SearchBySeveralParameters(autopark);
			break;
		}
		else {
			cout << "Unknown command\n\n";
		}
	}
}

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
		new Vehicle{ vehicleType, brand, model, year, price,
		new Engine(volume, fuelType, horsepower),
		new Transmission(transmissionType) });
	cout << endl;
	autopark->GetMyVehicle(autopark->GetSize() - 1).printInfo();
	autopark->GetMyDetails(autopark->GetSize() - 1).displayDetails();
	cout << endl;
	bool details_key = true;
	string enter;
	cout << "Enter \"=\" to confirm vehicle\n"
		"Enter \"-\" to delete vehicle\n"
		"Enter \"+\" to add details\n"
		"Enter \"/\" to reset vehicle\n";
	while (true) {
		cout << "\nEnter : ";
		cin >> enter;
		cout << endl;
		if (enter == "=") {
			cout << "Creating vehicle is done\n";
			break;
		}
		else if (enter == "-") {
			autopark->RemoveAtEnd();
			cout << "Creating vehicle is ruined\n\n";
			break;
		}
		else if (enter == "/") {
			autopark->RemoveAtEnd();
			InsertAtEnd_local(autopark);
			break;
		}
		else if (enter == "+") {
			if (!details_key) {
				cout << "Vehicle already have details\n";
			}
			else {
				while (true) {
					int details_choice = 0;
					if (toLowercase(vehicleType) == "sedan") {
						details_choice = 1;
					}
					else if (toLowercase(vehicleType) == "truck") {
						details_choice = 2;
					}
					else if (toLowercase(vehicleType) == "motorcycle") {
						details_choice = 3;
					}
					else if (toLowercase(vehicleType) == "moped") {
						details_choice = 4;
					}
					else {
						string details_choice_another;
						cout << "Enter number of your vehicle type\n"
							"1. Sedan\n"
							"2. Truck\n"
							"3. Motorcycle\n"
							"4. Moped\n"
							"Enter \"/\" to out\n";
						cout << "\nEnter : ";
						cin >> details_choice_another;
						if (details_choice_another == "1") {
							details_choice = 1;
						}
						else if (details_choice_another == "2") {
							details_choice = 2;
						}
						else if (details_choice_another == "3") {
							details_choice = 3;
						}
						else if (details_choice_another == "4") {
							details_choice = 4;
						}
						else if (details_choice_another == "/") {
							break;
						}
						else {
							cout << "Unknown command\n";
						}
					}
					cout << endl;
					string details_enter;
					if (details_choice == 1) {
						cout << "Enter \"+\" to confirm sunroof\n"
							"Enter \"-\" to disaible sunroof\n"
							"Enter \"/\" to out\n";
						while (true) {
							cout << "\nEnter : ";
							cin >> details_enter;
							if (details_enter == "+") {
								autopark->SetMyDetails(autopark->GetSize() - 1, new Sedan(true));
								break;
							}
							else if (details_enter == "-") {
								autopark->SetMyDetails(autopark->GetSize() - 1, new Sedan(false));
								break;
							}
							else if (details_enter == "/") {
								break;
							}
							else if (details_enter == "help") {
								cout << "\nEnter \"+\" to confirm sunroof\n"
									"Enter \"-\" to disaible sunroof\n"
									"Enter \"/\" to out\n";
							}
							else {
								cout << "\nUnknown command\n";
							}
						}
					}
					else if (details_choice == 2) {
						cout << "Enter weight for load capacity\n"
							"Enter \"/\" to out\n";
						while (true) {
							cout << "\nEnter : ";
							cin >> details_enter;
							if (isValidFloat(details_enter)) {
								float load_capacity = stof(details_enter);
								autopark->SetMyDetails(autopark->GetSize() - 1, new Truck(load_capacity));
								break;
							}
							else if (details_enter == "/") {
								break;
							}
							else if (details_enter == "help") {
								cout << "\nEnter weight for load capacity\n"
									"Enter \"/\" to out\n";
							}
							else {
								cout << "\nUnknown command\n";
							}
						}
					}
					else if (details_choice == 3) {
						cout << "Enter consumption for motorcycle\n"
							"Enter \"/\" to out\n";
						while (true) {
							cout << "\nEnter : ";
							cin >> details_enter;
							if (isValidDouble(details_enter)) {
								double consumption = stod(details_enter);
								autopark->SetMyDetails(autopark->GetSize() - 1, new Motorcycle(consumption));
								break;
							}
							else if (details_enter == "/") {
								break;
							}
							else if (details_enter == "help") {
								cout << "\nEnter consumption for motorcycle\n"
									"Enter \"/\" to out\n";
							}
							else {
								cout << "\nUnknown command\n";
							}
						}
					}
					else if (details_choice == 4) {
						cout << "Enter max speed for moped\n"
							"Enter \"/\" to out\n";
						while (true) {
							cout << "\nEnter : ";
							cin >> details_enter;
							if (isValidDouble(details_enter)) {
								double max_speed = stod(details_enter);
								autopark->SetMyDetails(autopark->GetSize() - 1, new Moped(max_speed));
								break;
							}
							else if (details_enter == "/") {
								break;
							}
							else if (details_enter == "help") {
								cout << "\nEnter max speed for moped\n"
									"Enter \"/\" to out\n";
							}
							else {
								cout << "\nUnknown command\n";
							}
						}
					}
					else {
						cout << "Unknown command\n";
					}
					if (&autopark->GetMyVehicle(autopark->GetSize() - 1) != &autopark->GetMyDetails(autopark->GetSize() - 1)) {
						cout << endl;
						autopark->GetMyVehicle(autopark->GetSize() - 1).printInfo();
						autopark->GetMyDetails(autopark->GetSize() - 1).displayDetails();
						details_key = false;
					}
					break;
				}
			}
		}
		else if (enter == "help") {
			cout << "Enter \"=\" to confirm vehicle\n"
				"Enter \"-\" to delete vehicle\n"
				"Enter \"+\" to add details\n"
				"Enter \"/\" to reset vehicle\n";
		}
		else {
			cout << "Unknown command\n\n";
		}
	}
}