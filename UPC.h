/*
 * Simone Ray. CS 300. Assignment5.
 * UPC class objects contain UPC code and item name. This class implements getters and setters. 
 */

#ifndef UPC_H
#define UPC_H

#include <string>
#include "HashableADT.h"
using namespace std;

class UPC : HashableADT<UPC> {
	private:
		long key;
		string name;
	public:
		UPC() { }			//default constructor
		UPC(long);
		UPC(long, string);
		void setKey(long);
		void setValue(string);
		long getKey();
		string getValue();
		int hash();
		bool operator<(UPC&);
		bool operator>(UPC&);
		bool operator==(UPC&);
		~UPC() { }			//destructor
		UPC(const UPC&);		//copy constructor
		UPC& operator=(const UPC&);	//assignment operator
};

#endif

