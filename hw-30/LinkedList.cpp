#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), size(0) {}
size_t LinkedList::GetSize() const
{
	return size;
}
void LinkedList::InsertAtEnd(Vehicle* value)
{
	if (head == nullptr)
	{
		Node* newNode = new Node(value);
		newNode->SetNext(head);
		head = newNode;
		size++;
		return;
	}
	Node* newNode = new Node(value);
	Node* temp = head;
	while (temp->GetNext() != nullptr) {
		temp = temp->GetNext();
	}
	temp->SetNext(newNode);
	size++;
}
void LinkedList::InsertAtEnd(Vehicle* value, Vehicle* details)
{
	if (head == nullptr)
	{
		Node* newNode = new Node(value, details);
		newNode->SetNext(head);
		head = newNode;
		size++;
		return;
	}
	Node* newNode = new Node(value, details);
	Node* temp = head;
	while (temp->GetNext() != nullptr) {
		temp = temp->GetNext();
	}
	temp->SetNext(newNode);
	size++;
}
void LinkedList::RemoveAtBeginning() {
	if (head == nullptr) {
		return;
	}
	else if (head->GetNext() == nullptr) {
		delete head;
		return;
	}
	Node* temp = head;
	head = head->GetNext();
	delete temp;
	size--;
}
void LinkedList::RemoveAtEnd()
{
	if (head == nullptr) {
		return;
	}
	else if (head->GetNext() == nullptr) {
		delete head;
		return;
	}
	Node* temp = head;
	while (temp->GetNext() != nullptr) {
		temp = temp->GetNext();
	}
	delete temp;
	size--;
}
void LinkedList::RemoveAtIndex(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("LinkedList don't have enough indexes");
	}
	if (index == 0) {
		RemoveAtBeginning();
		return;
	}
	else if (index == size) {
		RemoveAtEnd();
		return;
	}
	int item = 0;
	Node* prev_temp = head;
	while (item != index - 1) {
		prev_temp = prev_temp->GetNext();
		item++;
	}
	Node* temp = prev_temp->GetNext();
	prev_temp->SetNext(temp->GetNext());
	delete temp;
	size--;
}
Vehicle& LinkedList::GetMyVehicle(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("LinkedList don't have enough indexes");
	}
	int item = 0;
	Node* temp = head;
	while (item != index) {
		temp = temp->GetNext();
		item++;
	}
	return temp->GetVehicle();
}
Vehicle& LinkedList::GetMyDetails(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("LinkedList don't have enough indexes");
	}
	int item = 0;
	Node* temp = head;
	while (item != index) {
		temp = temp->GetNext();
		item++;
	}
	if (&temp->GetDetails() == nullptr) {
		return temp->GetVehicle();
	}
	else {
		return temp->GetDetails();
	}
}
LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->GetNext();
		delete temp;
	}
}

#endif