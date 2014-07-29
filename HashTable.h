#pragma once
#include "LinkedList.h"

#include <iostream>
#include <cstdlib>
#include <string>

class HashTable	{

public:

	HashTable();

	HashTable(int n);
/*
	HashTable(const HashTable & source);

	~HashTable();
*/
	bool insert(std::string value);


private:

	LinkedList* table;
	int prime;
	int size;

	int hashfunction(std::string value);
};