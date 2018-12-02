/*
 * Simone Ray. CS300. Assignment4.
 * Binary Search Tree interface. Implements insertion, deletion, search and print methods. 
 *
 */

#ifndef BST_H
#define BST_H 

#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;			//value at the node
	node<T>* left;		//pointer to left subtree
	node<T>* right;		//pointer to right subtree
};

template <class T>
class BST {
	node<T>* root;
	public:
		BST() {root = NULL;}		//constructor
		T* search(T&);
		void insert(T&);
		void deleteNode(T&);
		int height();
		T findMax();
		T findMin();
		void printPreOrder();
		void printPostOrder();
		void printInOrder();
	private:
		T* search(node<T>*&, T&);
		void insert(node<T>*&, T&);
		void deleteNode(node<T>*&, T&);
		int height(node<T>*);
		T findMax(node<T>*, T);
		T findMin(node<T>*, T);
		void printPreOrder(node<T>*);
		void printPostOrder(node<T>*);
		void printInOrder(node<T>*);
		int max(int, int);
};

#endif

template <class T>
T* BST<T>::search(T& item) {
	return search(root, item); 
}

template <class T>
T* BST<T>::search(node<T>*& root, T& item) {		//searches tree for item and returns item if found
	if (root != NULL) {
		if (item == root->data) 
			return &(root->data);
		else if (item < root->data) 
			return search(root->left, item);
		else
			return search(root->right, item);
	}
	return NULL;
}


template <class T>
void BST<T>::insert(T& item) {
	insert(root, item);
}

template <class T>
void BST<T>::insert(node<T>*& root, T& item) {		//inserts given item into tree
	if (root == NULL) {
		root = new node<T>;
		root->data = item;
		root->left = root->right = NULL;	
	} else if (item < root->data) {
		insert(root->left, item);
	} else {
		insert(root->right, item);
	}
}


template <class T>
void BST<T>::deleteNode(T& item) {
	deleteNode(root, item);
}

template <class T>
void BST<T>::deleteNode(node<T>*& root, T& item) {	//deletes given item from tree
	if (root != NULL) {
		T element = root->data;
		if (item == element) {
			node<T> *temp = root;
			if (root->left != NULL && root->right != NULL) {
				T leftMax = findMax(root->left);
				root->data = leftMax; 
				deleteNode(root->left, leftMax);
			} else if (root->right == NULL) 
				root = root->left;
			else if (root->left == NULL) 
				root = root->left;
			else 
				root = NULL;
			delete temp;
		} 
		else if (item < element) 
			deleteNode(root->left, item);
		else
			deleteNode(root->right, item);
	}
}


template <class T>
int BST<T>::height() {
	return height(root);
}

template <class T>
int BST<T>::height(node<T>* root) {			//returns height of the tree
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return 0;
	} else {
		return 1 + max(height(root->left), height(root->right));
	}
}

template <class T>
int BST<T>::max(int a, int b) {
	if (a > b) 
		return a;
	return b;
}


template <class T>
T BST<T>::findMax() {					//returns largest item in the tree
	return findMax(root);
}

template <class T>
T BST<T>::findMax(node<T>* root, T error) {
	if (root == NULL)
		return error; 
	if (root->right == NULL) 
		return root->data;
	return findMax(root->right);
}


template <class T>
T BST<T>::findMin() {					//returns smallest item in the tree
	return findMin(root);
}

template <class T>
T BST<T>::findMin(node<T>* root, T error) {
	if (root == NULL)
		return error; 
	if (root->left == NULL) 
		return root->data;
	return findMin(root->left);
}


template <class T>
void BST<T>::printPreOrder() {
	printPreOrder(root);
}

template <class T>
void BST<T>::printPreOrder(node<T>* root) {			//prints elements pre order
	if (root != NULL) {
		cout << root->data << endl;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}


template <class T>
void BST<T>::printPostOrder() {
	printPostOrder(root);
}

template <class T>
void BST<T>::printPostOrder(node<T>* root) {			//prints elements post order
	if (root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		cout << root->data << endl;
	}
}


template <class T>
void BST<T>::printInOrder() {
	printInOrder(root);
}

template <class T>
void BST<T>:: printInOrder(node<T>* root) {			//prints elements in order
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->data << endl;
		printInOrder(root->right);
	}
}
