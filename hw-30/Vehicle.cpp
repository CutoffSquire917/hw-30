#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include "Vehicle.h"
#include "Engine.h"
#include "Transmission.h"

Vehicle::Vehicle() : vehicleType("unknow"), brand("unknow"), model("unknow"), year(0000), price(0.0),
                     engine(nullptr), transmission(nullptr) {}
Vehicle::Vehicle(const std::string vehicleType, const std::string brand, const std::string model,
                 const int year, const double price, Engine* engine, Transmission* transmission)
    : vehicleType(vehicleType), brand(brand), model(model), year(year), price(price),
      engine(engine), transmission(transmission) {}

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

Engine* Vehicle::getEngine() const {
    return engine;
}
Transmission* Vehicle::getTransmission() const {
    return transmission;
}

void Vehicle::printInfo() const {
    std::cout << "VehicleInfo()\n";
    if (engine != nullptr) {
        std::cout << "Engine : connected\n";
    }
    else {
        std::cout << "Engine : disabled\n";
    }
    if (transmission != nullptr) {
        std::cout << "Transmission : connected\n";
    }
    else {
        std::cout << "Transmission : disabled\n";
    }


}

#endif