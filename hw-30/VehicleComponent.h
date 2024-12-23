#ifndef VEHICLECOMPONENT_H
#define VEHICLECOMPONENT_H

#pragma once

#include <iostream>

class Engine;

class VehicleComponent {
private:
    Engine* engine;
public:
    VehicleComponent();
    VehicleComponent(Engine* engine);
    virtual bool operator==(const VehicleComponent& other) const;
    virtual bool operator!=(const VehicleComponent& other) const;
    virtual bool operator>=(const VehicleComponent& other) const;
    virtual bool operator<=(const VehicleComponent& other) const;
    virtual bool operator>(const VehicleComponent& other) const;
    virtual bool operator<(const VehicleComponent& other) const;
    Engine* getEngine() const;
    virtual void printInfo() const;
};

#endif