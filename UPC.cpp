/*
 * Simone Ray. Assignment5.
 * UPC class objects contain UPC code and item name. This class implements getters and setters. 
 */

#include "UPC.h"
#include <string>
using namespace std;

UPC::UPC(long _key) {			// Constructs UPC object with given key and empty item name
	key = _key;
	name = "";
}

UPC::UPC(long _key, string value) {	// Constructs UPC object with given key and item name
	key = _key;
	name = value;
}

// Setters
void UPC::setKey(long _key) {
	key = _key;
}

void UPC::setValue(string value) {
	name = value;
}

// Getters
long UPC::getKey() {
	return key;
}

string UPC::getValue() {
	return name;
}

int UPC::hash() {				// Hash function
	int hash = key % 1000;
	return hash;
}

bool UPC::operator<(UPC& other) {		// Operator overloading of <
	return key < other.getKey();
}

bool UPC::operator>(UPC& other) {		// Operator overloading of >
	return key > other.getKey();
}

bool UPC::operator==(UPC& other) {		// Operator overloading of ==
	return key == other.getKey();
}

UPC::UPC(const UPC& other){			// Copy constructor
	this->key = other.key;
	this->name = other.name;
}

UPC& UPC:: operator=(const UPC& other) {	// Assignment operator
	this->key = other.key;
	this->name = other.name;
	return *this;
}
