#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#pragma once

#include <string>
#include "Vehicle.h"

class Transmission : public Vehicle {
private:
	std::string transmissionType;
public:
	Transmission(const std::string transmissionType);

	virtual bool operator==(const Vehicle& other) const override;
	virtual bool operator!=(const Vehicle& other) const override;

	std::string getTransmissionType() const;

	virtual void printInfo() const override;
};

#endif