#pragma once

#ifndef NODE_H
#define NODE_H

#include "Vehicle.h"

class Node {
private:
    Vehicle* vehicle;
    Vehicle* details;
    Node* next;
public:
    Node(Vehicle* vehicle);
    Node(Vehicle* vehicle, Vehicle* details);
    Vehicle& GetVehicle() const;
    Vehicle& GetDetails() const;
    void SetDetails(Vehicle* details);
    Node* GetNext() const;
    void SetNext(Node* next);
    ~Node();
};

#endif