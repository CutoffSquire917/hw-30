#ifndef VEHICLE_H
#define VEHICLE_H

#pragma once

#include <string>
#include <iostream>

class Engine;
class Transmission;

class Vehicle {
private:
    std::string vehicleType;
    std::string brand;
    std::string model;
    int year;
    double price;
    Engine* engine;
    Transmission* transmission;
public:
    Vehicle();
    Vehicle(const std::string vehicleType, const std::string brand, const std::string model, const int year,
        const double price, Engine* engine, Transmission* transmission);
    Vehicle& operator=(const Vehicle& other);
    virtual bool operator==(const Vehicle& other) const;
    virtual bool operator!=(const Vehicle& other) const;
    virtual bool operator>=(const Vehicle& other) const;
    virtual bool operator<=(const Vehicle& other) const;
    virtual bool operator>(const Vehicle& other) const;
    virtual bool operator<(const Vehicle& other) const;
    virtual void displayDetails() const;
    std::string getVehicleType() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;
    Engine* getEngine() const;
    Transmission* getTransmission() const;
    virtual void printInfo() const;
    ~Vehicle();
};

#endif