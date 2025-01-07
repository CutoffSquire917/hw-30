#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Vehicle.h"
#include "Node.h"
#include <stdexcept>

class LinkedList {
private:
	Node* head;
	size_t size;
public:
	LinkedList();
	size_t GetSize() const;
	void InsertAtEnd(Vehicle* value);
	void InsertAtEnd(Vehicle* value, Vehicle* details);
	void RemoveAtBeginning();
	void RemoveAtEnd();
	void RemoveAtIndex(int index);
	Vehicle& GetMyVehicle(int index);
	Vehicle& GetMyDetails(int index);
	~LinkedList();
};

#endif