/*
 * Simone Ray. Assignment5.
 * Builds hash table of size 1000, where UPC keys and values from a given file are stored. 
 * Collisions are resolved through separate chaining. Chains implement linked list data structure. 
 */

#include "UPC.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Builds array of UPC objects from given csv file
HashTable<UPC> buildHashTable(char *filename) {
	ifstream infile;
	infile.open(filename);

	HashTable<UPC> table;						//initialize hash table 

	string str;
	while (getline(infile, str)) {
		size_t comma = str.find_first_of(",");
		string key = str.substr(0, comma);
		string value = str.substr(comma + 1);
		UPC *newItem;
		try {
			newItem = new UPC(stol(key), value);		//create UPC object
			table.add(*newItem);
		} catch (exception e) {
		}	
	}
	return table;
}

// Perform search(es) from user inputted UPC code
void performSearchHashTable(HashTable<UPC>& table, UPC key) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now(); 	//start clock
	UPC *item = table.get(key);						//search
	high_resolution_clock::time_point t2 = high_resolution_clock::now();	//stop clock
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	
	cout << "Hash Table time: " <<  duration << " microseconds" <<  endl;
}
