#ifndef TRANSMISSION_CPP
#define TRANSMISSION_CPP

#include "Transmission.h"

Transmission::Transmission(const std::string transmissionType)
	: transmissionType(transmissionType) {}

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
	std::cout << "\ttransmissionType : " << transmissionType << std::endl;
}

#endif