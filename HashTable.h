#pragma once
#include "LinkedList.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

class HashTable	{

public:

	HashTable();

	HashTable(int n);
/*
	HashTable(const HashTable & source);

	~HashTable();
*/
	bool insert(std::string value);

	bool remove(std::string value);

	bool search(std::string value);

	int size()	const;

	int maxSize()	const;

	int loadFactor()	const;

	std::vector<std::string> intersection(const HashTable & source);

	std::vector<std::string> unions(const HashTable & source);

	std::vector<std::string> difference(const HashTable & source);

private:

	LinkedList* table;
	int prime;
	int entries;

	int hashfunction(std::string value);
	int isitPrime(int n);
};