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

private:

	LinkedList* table;
	int prime;
	int entries;

	int hashfunction(std::string value);
};