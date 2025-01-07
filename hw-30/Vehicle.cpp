#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include "Vehicle.h"
#include "Engine.h"
#include "Transmission.h"

Vehicle::Vehicle() : vehicleType("unknown"), brand("unknown"), model("unknown"), year(0000), price(0.0),
                     engine(nullptr), transmission(nullptr) {}
Vehicle::Vehicle(const std::string vehicleType, const std::string brand, const std::string model,
                 const int year, const double price, Engine* engine, Transmission* transmission)
    : vehicleType(vehicleType), brand(brand), model(model), year(year), price(price),
      engine(engine), transmission(transmission) {}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this == &other) {
        return *this;
    }
    vehicleType = other.getVehicleType();
    brand = other.brand;
    model = other.model;
    year = other.year;
    price = other.price;
    engine = other.engine;
    transmission = other.transmission;
    return *this;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return false;
}
bool Vehicle::operator!=(const Vehicle& other) const {
    return false;
}
bool Vehicle::operator>=(const Vehicle& other) const {
    return false;
}
bool Vehicle::operator<=(const Vehicle& other) const {
    return false;
}
bool Vehicle::operator>(const Vehicle& other) const {
    return false;
}
bool Vehicle::operator<(const Vehicle& other) const {
    return false;
}
void Vehicle::displayDetails() const {
    std::cout << "DetailsInfo()\n\tVehicle does`t have details\n";
}

std::string Vehicle::getVehicleType() const {
    return vehicleType;
}
std::string Vehicle::getBrand() const {
    return brand;
}
std::string Vehicle::getModel() const {
    return model;
}
int Vehicle::getYear() const {
    return year;
}
double Vehicle::getPrice() const {
    return price;
}
Engine* Vehicle::getEngine() const {
    return engine;
}
Transmission* Vehicle::getTransmission() const {
    return transmission;
}

void Vehicle::printInfo() const {
    std::cout << "VehicleInfo()\n";
    std::cout << "\tvehicleType : " << vehicleType << "\n";
    std::cout << "\tbrand : " << brand << "\n";
    std::cout << "\tmodel : " << model << "\n";
    std::cout << "\tyear : " << year << "\n";
    std::cout << "\tprice : " << price << "\n";
    if (engine != nullptr) {
        engine->printInfo();
    }
    else {
        std::cout << "Engine : disabled\n";
    }
    if (transmission != nullptr) {
        transmission->printInfo();
    }
    else {
        std::cout << "Transmission : disabled\n";
    }
}

Vehicle::~Vehicle() {
    delete engine;
    delete transmission;
}

#endif