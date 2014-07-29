#include "HashTable.h"

HashTable::HashTable()	{
	std::cout << "Hash table constructor" << std::endl;
	this->table = new LinkedList[101];
	this->prime = 101;
	this->entries = 0;
}

HashTable::HashTable(int n)	{

	std::cout <<"Custom table size" << std::endl;
	this->table = new LinkedList[n];
	this->prime = n;
	this->entries = 0;
}


bool HashTable::insert(std::string value)	{
	std::cout <<"Hash table insert" << std::endl;
	int key;
	bool added;
	key = hashfunction(value);
	int hex;
	hex = key % this->prime;
	std::cout << "hex: " << hex << std::endl;
	added = this->table[hex].insert(value);
	this->table[hex].print();
	if(added)	{
		entries++;
	}
	return added;
}

bool HashTable::remove(std::string value)	{
	std::cout <<"Hash table remove" << std::endl;
	int key;
	int hex;
	bool removed;
	key = hashfunction(value);
	hex = key % this->prime;
	removed = this->table[hex].remove(value);
	if(removed)	{
		entries--;
	}
	return removed;
}

int HashTable::hashfunction(std::string value)	{
	std::cout <<"Hash table hasfunction" << std::endl;
	int hash = 0;
	int index = 0;
	int exponent = 0;
	index = value.length();

	for(int i = 0; i < index; i++)	{
		exponent = std::pow(32,(index-1-i));
		hash = hash + (value[i] - 96)*exponent;
	}
	std::cout <<"Hash value is: " << hash << std::endl;
	return hash;

}

bool HashTable::search(std::string value)	{
	int key;
	int hex;
	bool found;
	key = hashfunction(value);
	hex = key % this->prime;
	found = this->table[hex].search(value);

	return found;
}

int HashTable::size()	const {
	return entries;
}

int HashTable::maxSize()	const {
	return prime;
}

int HashTable::loadFactor()	const {
	int temp;
	temp = entries/prime;
	return temp;
}