#pragma once
#include "LinkedList.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class HashTable	{

public:
	//Default Constructor
	HashTable();
	//Constructor hashtable with value given
	HashTable(int n);
	//Copy constructor
	HashTable(const HashTable & source);
	//Overloaded Assignment operator
	HashTable & operator= (const HashTable & source);
	//Destructor
	~HashTable();
	//Inserts a value if it doesnt already exist
	bool insert(std::string value);
	//removes a value if it exists 
	bool remove(std::string value);
	//Finds a value if it exists in hashtable
	bool search(std::string value);
	//Returns the number of elements in the hashtable
	int size()	const;
	//Returns the number of "buckets" in the hashtable
	int maxSize()	const;
	//returns the element/buckets of the table
	int loadFactor()	const;
	//Returns a vector with the elements that are intersection of the source and calling object
	std::vector<std::string> intersection(const HashTable & source)	const;
	//Returns a vector with the elements that are the union of the calling object and parameter
	std::vector<std::string> unions(const HashTable & source)	const;
	//Returns a vector with the elements that are teh difference of the calling object and parameter
	std::vector<std::string> difference(const HashTable & source)	const;

private:
	//Pointer to the table
	LinkedList* table;
	//Table size = prime number
	int prime;
	//Number of entries in the table
	int entries;
	//Takes the string and returns key value
	int hashfunction(std::string value);
	//Primes the number when table is given a size
	int isitPrime(int n);
	//Deletes the values in table
	void deleteTable();
	//copies a table so the calling object is the same as the source
	void copyTable(const HashTable & source);
};