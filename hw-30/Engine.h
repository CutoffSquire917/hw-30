#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#include <string>
#include "VehicleComponent.h"

class Engine : public VehicleComponent {
private:
	double volume;
	std::string fuelType;
	int horsepower;
public:
	Engine(const double volume, const std::string fuelType, const int horsepower);

	virtual bool operator==(const VehicleComponent& other) const override;
	virtual bool operator!=(const VehicleComponent& other) const override;
	virtual bool operator>=(const VehicleComponent& other) const override;
	virtual bool operator<=(const VehicleComponent& other) const override;
	virtual bool operator>(const VehicleComponent& other) const override;
	virtual bool operator<(const VehicleComponent& other) const override;

	double getVolume() const;
	std::string getFuelType() const;
	int getHorsepower() const;

	virtual void printInfo() const override;
};

#endif