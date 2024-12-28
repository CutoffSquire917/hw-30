#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "Engine.h"

Engine::Engine(const double volume, const std::string fuelType, const int horsepower)
	: volume(volume), fuelType(fuelType), horsepower(horsepower) {
	std::cout << "Engine successfully created\n";
}

bool Engine::operator==(const Vehicle& other) const {
	return volume == other.getEngine()->getVolume() &&
		fuelType == other.getEngine()->getFuelType() &&
		horsepower == other.getEngine()->getHorsepower();
}
bool Engine::operator!=(const Vehicle& other) const {
	return volume != other.getEngine()->getVolume() &&
		fuelType != other.getEngine()->getFuelType() &&
		horsepower != other.getEngine()->getHorsepower();
}
bool Engine::operator>=(const Vehicle& other) const {
	return horsepower >= other.getEngine()->getHorsepower();
}
bool Engine::operator<=(const Vehicle& other) const {
	return horsepower <= other.getEngine()->getHorsepower();
}
bool Engine::operator>(const Vehicle& other) const {
	return horsepower > other.getEngine()->getHorsepower();
}
bool Engine::operator<(const Vehicle& other) const {
	return horsepower < other.getEngine()->getHorsepower();
}

double Engine::getVolume() const {
	return volume;
}
std::string Engine::getFuelType() const {
	return fuelType;
}
int Engine::getHorsepower() const {
	return horsepower;
}

void Engine::printInfo() const {
	std::cout << "EngineInfo()\n";
	std::cout << "volume : " << volume << std::endl;
	std::cout << "fuelType : " << fuelType << std::endl;
	std::cout << "horsepower : " << horsepower << std::endl;
}

#endif