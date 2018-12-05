/*
 * Simone Ray. Assignment5.
 *
 * Header file implements a generic Hash Table of size 1000.
 * Seperate chaining implements Linked List data structure.  
 * T must be an implementation of Hashable ADT, as it needs to provide a hash function. 
 */


#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
using namespace std;

template <class T>
struct HashNode {
	T data;
	HashNode* next;
};

template <class T>
class HashTable {
	private:
		int size;				
		HashNode<T> **hashTable;	
	public:
		HashTable();
		void add(T&);
		T* get(T&);
};

// Default constructor
template <class T>
HashTable<T>::HashTable(){
     size = 1000;  				// default size = 1000
     hashTable = new HashNode<T>*[size];
     for (int i = 0; i < size; i++) {
     	hashTable[i] = NULL;			// initialize pointers to NULL
     }
}

// Inserts given item through hashing
template <class T>
void HashTable<T>::add(T& item) {
	int index = item.hash() % size;		// perform hash function
	HashNode<T> *newNode = new HashNode<T>;	
	// insert at the beginning of linked list
	newNode->data = item;
	newNode->next = hashTable[index];
	hashTable[index] = newNode;
}

// Searches for given item in the hash table and returns the pointer to object, if found
template <class T>
T* HashTable<T>::get(T& item) {
	int index = item.hash() % size;
	for (HashNode<T> *p = hashTable[index]; p != NULL; p = p->next) {
		if (p->data == item) {
			return &(p->data);
		}
	}
	return NULL;	// if not found
}

#endif /* HASHTABLE_H */
