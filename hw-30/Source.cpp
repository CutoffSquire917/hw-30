#include <iostream>
#include "Vehicle.h"
#include "Engine.h"
#include "Transmission.h"
using namespace std;


//class VehicleComponent {
//public:
//	virtual void printInfo() const {}
//};
//
//class Engine : VehicleComponent {
//private:
//	double volume;
//	string fuelType;
//	int horsepower;
//public:
//	Engine() : volume(0.0), fuelType("none"), horsepower(0) {}
//	Engine(const double volume, const string fuelType, const int horsepower)
//		: volume(volume), fuelType(fuelType), horsepower(horsepower) {}
//	//virtual bool operator==(const Engine& other) const {
//	//	return volume == other.volume &&
//	//		fuelType == other.fuelType &&
//	//		horsepower == other.horsepower;
//	//}
//	//virtual bool operator!=(const Engine& other) const {
//	//	return !(volume == other.volume &&
//	//		fuelType == other.fuelType &&
//	//		horsepower == other.horsepower);
//	//}
//	//virtual bool operator>= (const Engine & other) const {
//	//	return horsepower >= other.horsepower;
//	//}
//	//virtual bool operator<= (const Engine& other) const {
//	//	return horsepower <= other.horsepower;
//	//}
//	//virtual bool operator> (const Engine& other) const {
//	//	return horsepower > other.horsepower;
//	//}
//	bool operator< (const VehicleComponent& other) const {
//		return horsepower < other.Engine.horsepower;
//	}
//	double getVolume() const {
//		return volume;
//	}
//	string getFuelType() const {
//		return fuelType;
//	}
//	int getPower() const {
//		return horsepower;
//	}
//	virtual void printInfo() const {
//		cout << "EngineInfo()" << endl;
//		cout << "volume : " << volume << endl;
//		cout << "fuelType : " << fuelType << endl;
//		cout << "horsepower : " << horsepower << endl;
//	}
//};
//
//class Transmission : public VehicleComponent {
//private:
//	string transmission;
//public:
//	Transmission(const string transmission) : transmission(transmission) {}
//	virtual bool operator==(const Transmission& other) const {
//		return transmission == other.transmission;
//	}
//	virtual bool operator!=(const Transmission& other) const {
//		return !(transmission == other.transmission);
//	}
//	virtual bool operator>= (const Transmission& other) const {
//		return transmission >= other.transmission;
//	}
//	virtual bool operator<= (const Transmission& other) const {
//		return transmission <= other.transmission;
//	}
//	virtual bool operator> (const Transmission& other) const {
//		return transmission > other.transmission;
//	}
//	virtual bool operator< (const Transmission& other) const {
//		return transmission < other.transmission;
//	}
//	string getTransmission() const {
//		return transmission;
//	}
//	virtual void printInfo() const override {
//		cout << "TransmissionInfo()" << endl;
//		cout << "transmission : " << transmission << endl;
//	}
//};


//Transmission (Трансмісія)
	//
	//Параметри:
	//Тип трансмісії (string).
	//Методи:
	//Конструктори для ініціалізації.
	//Оператори порівняння.
	//Методи отримання даних (getType).
	//Метод для відображення характеристик трансмісії.

int main()
{
	Vehicle* auto1 = new Vehicle(new Engine(2.2, "Gus", 36), new Transmission("STR"));

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