#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

Node::Node(Vehicle* vehicle)
	: vehicle(vehicle), details(nullptr), next(nullptr) {}
Node::Node(Vehicle* vehicle, Vehicle* details)
	: vehicle(vehicle), details(details), next(nullptr) {}
Vehicle& Node::GetVehicle() const {
	return *vehicle;
}
Vehicle& Node::GetDetails() const {
	return *details;
}
void Node::SetDetails(Vehicle* other) {
	details = other;
}
Node* Node::GetNext() const
{
	return next;
}
void Node::SetNext(Node* next) {
	this->next = next;
}
Node::~Node() {
	delete vehicle;
	delete details;
	delete next;
}

#endif