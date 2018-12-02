# Assignment_5

This program allows the user to quickly look up items by their UPC code. 

The Universal Product Code (UPC) is a barcode symbology that is widely used in the United States, Canada, United Kingdom, Australia, New Zealand, in Europe and other countries for tracking trade items in stores. UPC consists of numeric digits, that are uniquely assigned to each trade item. 

In this program, searching is implemented through array, BST and hash table. The performance of the search operations are then examined. 

## Build

g++ TestClient.cpp UPC.cpp BarcodeArrayScanner.cpp BarcodeBSTScanner.cpp BarcodeHashScanner.cpp -o scanner 

## Usage

./scanner upc_corpus.txt

## Sample Output
```
UPC Code: 5000167079876
ITEM NAME: 500ml BOOTS Baby Lotion
Array time: 3021 microseconds
BST time: 6 microseconds
Hash Table time: 94 microseconds

```


