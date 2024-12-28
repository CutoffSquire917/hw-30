#ifndef TRANSMISSION_CPP
#define TRANSMISSION_CPP

#include "Transmission.h"

Transmission::Transmission(const std::string transmissionType)
	: transmissionType(transmissionType) {
	std::cout << "Transmission successfully created\n";
}

bool Transmission::operator==(const Vehicle& other) const {
	return transmissionType == other.getTransmission()->getTransmissionType();
}
bool Transmission::operator!=(const Vehicle& other) const {
	return transmissionType != other.getTransmission()->getTransmissionType();
}

std::string Transmission::getTransmissionType() const {
	return transmissionType;
}

void Transmission::printInfo() const {
	std::cout << "TransmissionInfo()\n";
	std::cout << "transmissionType : " << transmissionType << std::endl;
}

#endif