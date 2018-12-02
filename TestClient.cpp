/*
 * Simone Ray. CS 300. Assignment4.
 * Client test program tests efficiency of search operations with three different data structures: BST, array, and hash table. 
 */

#include "BST.h"
#include "UPC.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

extern UPC* buildArray(char*);
extern BST<UPC> buildTree(char*);
extern HashTable<UPC> buildHashTable(char*);
extern void performSearchArray(UPC*, UPC);
extern void performSearchBST(BST<UPC>&, UPC);
extern void performSearchHashTable(HashTable<UPC>&, UPC);

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "You must supply a file." << endl;
		cerr << "Usage: " << argv[0] << " filename" << endl;
		return -1;
	}

	char *filename = argv[1];
	UPC *array = buildArray(filename);		// build array of UPC objects
	BST<UPC> tree = buildTree(filename);		// build binary search tree of UPC objects
	HashTable<UPC> table = buildHashTable(filename);// build hash table of UPC objects 

	string code;
	cout << "Please enter a UPC code(! to quit): ";
	cin >> code;
	while (code != "!") {
		try {
			long entry = stol(code);	//convert user inputted string to type long int
			UPC key(entry);
			cout << "UPC Code: " << entry << endl;
			performSearchArray(array, key);
			performSearchBST(tree, key);	
			performSearchHashTable(table, key);
		} catch (exception e) {
			cout << "Not valid code." << endl;
		}
		
		cout << "\nPlease enter a UPC code(! to quit): ";
		cin >> code;
	}

	delete[] array;
	return 0;
}
