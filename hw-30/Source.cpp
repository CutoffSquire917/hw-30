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


//Transmission (��������)
	//
	//���������:
	//��� ������� (string).
	//������:
	//������������ ��� �����������.
	//��������� ���������.
	//������ ��������� ����� (getType).
	//����� ��� ����������� ������������� �������.

int main()
{
	Vehicle* auto1 = new Vehicle(new Engine(2.2, "Gus", 36), new Transmission("STR"));

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