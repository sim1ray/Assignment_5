/*
 * Simone Ray. Assignment5.
 * Implements method that builds binary search tree of UPC objects, from given file. 
 * Implements method that searches BST for given object containing only UPC key and returns object with both key and item name.
 */

#include "BST.h"
#include "UPC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Build binary search tree from given csv file
BST<UPC> buildTree(char *filename) {
	ifstream infile;
	infile.open(filename);

	BST<UPC> tree;

	string str;
	while (getline(infile, str)) {
		// parse string with first comma as delimiter
		size_t comma = str.find_first_of(",");
		string key = str.substr(0, comma);
		string value = str.substr(comma + 1);
		try {
			UPC *newItem = new UPC(stol(key), value);	//create new UPC object from given key, value
			tree.insert(*newItem);
		} catch (exception e) {
		}	
	}
	return tree;
}

// Searches for a given UPC code from the given binary search tree
// Prints name of item if found, and total search time 
void performSearchBST(BST<UPC>& tree, UPC key) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();	//start clock
	UPC *item = tree.search(key);						//search tree
	high_resolution_clock::time_point t2 = high_resolution_clock::now();	//stop clock
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	
	cout << "BST time: " <<  duration << " microseconds" <<  endl;
}

