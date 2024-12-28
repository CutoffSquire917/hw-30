#ifndef VEHICLE_H
#define VEHICLE_H

#pragma once

#include <string>
#include <iostream>

class Engine;
class Transmission;

// Тип транспортного засобу(string).
//Бренд (string).
//Модель (string).
//Рік випуску (int).
//Ціна (double).
//Двигун (Engine).
//Трансмісія (Transmission).

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
    virtual bool operator==(const Vehicle& other) const;
    virtual bool operator!=(const Vehicle& other) const;
    virtual bool operator>=(const Vehicle& other) const;
    virtual bool operator<=(const Vehicle& other) const;
    virtual bool operator>(const Vehicle& other) const;
    virtual bool operator<(const Vehicle& other) const;
    Engine* getEngine() const;
    Transmission* getTransmission() const;
    virtual void printInfo() const;
};

#endif