#ifndef VEHICLECOMPONENT_CPP
#define VEHICLECOMPONENT_CPP

#include "VehicleComponent.h"
#include "Engine.h"

VehicleComponent::VehicleComponent() : engine(nullptr) {}
VehicleComponent::VehicleComponent(Engine* engine) : engine(engine) {
    std::cout << "Engine successfully connected\n";
}

bool VehicleComponent::operator==(const VehicleComponent& other) const {
    return false;
}
bool VehicleComponent::operator!=(const VehicleComponent& other) const {
    return false;
}
bool VehicleComponent::operator>=(const VehicleComponent& other) const {
    return false;
}
bool VehicleComponent::operator<=(const VehicleComponent& other) const {
    return false;
}
bool VehicleComponent::operator>(const VehicleComponent& other) const {
    return false;
}
bool VehicleComponent::operator<(const VehicleComponent& other) const {
    return false;
}

Engine* VehicleComponent::getEngine() const {
    return engine;
}

void VehicleComponent::printInfo() const {
    std::cout << "VehicleComponentInfo()\n";
    if (&engine != nullptr) {
        std::cout << "Engine : connected\n";
    }
    else {
        std::cout << "Engine : disabled\n";
    }
}

#endif