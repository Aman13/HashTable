#include "HashTable.h"

HashTable::HashTable()	{
	std::cout << "Hash table constructor" << std::endl;
	this->table = new LinkedList[101];
	this->prime = 101;
}

HashTable::HashTable(int n)	{

	std::cout <<"Custom table size" << std::endl;
	this->table = new LinkedList[n];
	this->prime = n;

}


bool HashTable::insert(std::string value)	{
	std::cout <<"Hash table insert" << std::endl;
	int key;
	key = hashfunction(value);
	int hex;
	hex = key % prime;
	std::cout << "hex: " << hex << std::endl;
	this->table[hex].insert(value);
	this->table[hex].print();

}

int HashTable::hashfunction(std::string value)	{
	std::cout <<"Hash table hasfunction" << std::endl;
	int hash = 0;
	int index = 0;
	index = value.length();

	for(int i = 0; i < index; i++)	{
		hash = hash + value[i] - 96;
	}
	std::cout <<"Hash value is: " << hash << std::endl;
	return hash;

}
