/*
 * Simone Ray. CS 300. Assignment4.
 * Implements method to build array of UPC objects, from given file. File must be in CSV format (UPC, name of item).
 * Implements method to search array for given UPC object containing only the key (UPC) so as to find name of item associated with it. 
 */

#include "UPC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

static int count = 0;	// global variable keeps track of number of elements in the array

// Builds array of UPC objects from given csv file
UPC* buildArray(char *filename) {
	ifstream infile;
	infile.open(filename);

	UPC *array = new UPC[1100000];				//initialize empty array

	string str;
	while (getline(infile, str)) {
		// parse string with first comma as delimiter
		size_t comma = str.find_first_of(",");
		string key = str.substr(0, comma);
		string value = str.substr(comma + 1);

		try {
			UPC *newItem = new UPC(stol(key), value);
			array[count] = *newItem;			//add new UPC object to array
			count++;
		} catch (exception e) {
		}	
	}
	return array;
}

// Searches for a given UPC code from the given array of a given size, returns object or NULL(if not found)
UPC* search(UPC& item, UPC *array, int size) {
	for (int i = 0; i < size; i++) {
		if (array[i] == item) 
			return &(array[i]);
	}
	return NULL;
}

// Perform search(es) from user inputted UPC code
void performSearchArray(UPC *array, UPC key) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now(); 	//start clock
	UPC *item = search(key, array, count);					//search
	high_resolution_clock::time_point t2 = high_resolution_clock::now();	//stop clock
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	
	if (item != NULL) { 		// if found
		string value = item->getValue();
		cout << "ITEM NAME: " << value << endl;
	} else {
		cout << "Not found." << endl;
	}
	cout << "Array time: " <<  duration << " microseconds" <<  endl;
}



