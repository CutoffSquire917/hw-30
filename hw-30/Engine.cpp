#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "Engine.h"

Engine::Engine(const double volume, const std::string fuelType, const int horsepower)
	: volume(volume), fuelType(fuelType), horsepower(horsepower) {}

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
	std::cout << "\tvolume : " << volume << std::endl;
	std::cout << "\tfuelType : " << fuelType << std::endl;
	std::cout << "\thorsepower : " << horsepower << std::endl;
}

#endif