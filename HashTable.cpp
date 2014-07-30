#include "HashTable.h"

//Default constructor
//Creates a new hash table with size 101
HashTable::HashTable()	{
	this->table = new LinkedList[101];
	this->prime = 101;
	this->entries = 0;
}
//Constructor with given size
//Param: size of table you want
//Post: Creates a table atleast 2 times bigger than the value given, and is prime
HashTable::HashTable(int n)	{
	n = isitPrime(n);
	this->table = new LinkedList[n];
	this->prime = n;
	this->entries = 0;
}

//destructor
//Post: Frees memory assocaited with the deleted table
HashTable::~HashTable()	{
	deleteTable();
}

//Overloaded assignment operator
//Param: Souce is the hashtable to be copied
//Post: Copies the source to the calling object. Returns calling object
HashTable::HashTable(const HashTable & source)	{
	copyTable(source);
}

HashTable & HashTable::operator= (const HashTable & source)	{
	
	if(this != &source)	{
		deleteTable();
		copyTable(source);
	}
	return *this;
}

//Inserts a value into the hashtable if it doesnt already exist
//Param: the value to be inserted
//Post Value is inserted in its proper position returns true, if it already exist in table
// it does not insert and returns false
bool HashTable::insert(std::string value)	{
	int key;
	bool added;
	//gets the key value for the string to be entered
	key = hashfunction(value);
	added = this->table[key].insert(value);
	this->table[key].print();
	if(added)	{
		entries++;
	}
	return added;
}

//Removes a value from the hashtable if it exists
//Param: the value to be removed
//Post: Value is removed and true is returned, if it did not exist
//in the table false is returned
bool HashTable::remove(std::string value)	{
	int key;
	bool removed;
	key = hashfunction(value);
	removed = this->table[key].remove(value);
	if(removed)	{
		entries--;
	}
	return removed;
}

//Takes the value of each letter of the entry and returns a key
//Param: value to be inserted
//Post: returns a int which is the key for the entry
int HashTable::hashfunction(std::string value)	{
	int hash = 0;
	int index = 0;
	
	index = value.length();
	//Calculates key value using horners method
	for(int i = 0; i < index; i++)	{
		hash = (32 * hash + (value[i] - 96)) % this->prime;
	}
	return hash;
}

//Searches the table for a value
//Param: the value you are looking for
//Post: if value is found returns true, if not found returns false
bool HashTable::search(std::string value)	{
	int key;
	bool found;
	key = hashfunction(value);
	found = this->table[key].search(value);

	return found;
}

//Tells user how many entries are in the table
//Post: returns an int containing the amount of entries
int HashTable::size()	const {
	return this->entries;
}

//Tells the user how many "buckets" are in the table
//Post: returns the number of array positions in the table
int HashTable::maxSize()	const {
	return this->prime;
}

//Tells the user the load factor of the hash table
//Post: returns the Load factor as an INT
int HashTable::loadFactor()	const {
	int temp;
	temp = this->entries/this->prime;
	return temp;
}

//Checks if a number is prime, if not finds the next largest prime number
//Param: number to check if its prime
//Post: returns a prime number
int HashTable::isitPrime(int n)	{
	bool pNum = false;
	if(n == 0)	{
		n=1;
	}
	n = n*2;
	while(pNum == false)	{
		pNum = true;

		for(int i = 2; i < n; i++)	{
			if(n % i == 0)	{
				pNum = false;
			}
		}
		if(pNum == false)	{
			n++;
		}
	}
	return n;
}

//Finds the intersection values of the calling object and its parameter
//Param:Calling object  is compared with the parameter source
//Post: returns a vector final containing all the values that intersect the two tables
std::vector<std::string> HashTable::intersection(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;
	//Makes a vector main containing all the calling objects value
	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}
	//makes the vector copy containing all the parameter values 
	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}
	//Compares the two vectors and puts the value that are intersecting into the vector final
	for(unsigned int v = 0; v < main.size(); v++)	{
		for(unsigned int w = 0; w < copy.size(); w++)	{
			if(main[v] == copy[w])	{
				final.push_back(main[v]);
			}
		}
	}

	return final;

}

//Creates a vector containing unioned values of the calling object and parameter.
//Param: Calling object is compared with the parameter source.
//Post: returns a vector final containing the unioned values of the calling object and source
std::vector<std::string> HashTable::unions(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;
	//Vector main contains the calling objects values
	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}
	//Vector copy contains the parameter source values
	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}

	final = copy;
	bool duplicate = false;
	//Vector final is given the union of the two vectors main and copy
	for(unsigned int v = 0; v < main.size(); v++)	{
		for(unsigned int w = 0; w < copy.size(); w++)	{
			if(main[v] == copy[w])	{
				duplicate = true;
			}
		}
		if(duplicate == false)	{
			final.push_back(main[v]);
		}
		duplicate = false;
	}

	return final;
}

//Creates a vector containing the difference between the calling object and the parameter source
//Param: Calling object is compared with the parameter source
//Post:the vector final is returned containing the difference values of the calling object and parameter
std::vector<std::string> HashTable::difference(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;
	//Vector main contains the calling object values
	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}
	//Vector copy contains the parameter source values
	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}
	bool duplicate = false;
	//Vector final is given the difference of vector main and copy
	for(unsigned int v = 0; v < main.size(); v++)	{
		for(unsigned int w = 0; w < copy.size(); w++)	{
			if(main[v] == copy[w])	{
				duplicate = true;
			}
		}
		if(duplicate == false)	{
			final.push_back(main[v]);
		}
		duplicate = false;
	}

	return final;

}

//Deletes each of the linked list one at a time of the hash table
//Post: de-allocates the memory associated with the hash table
void HashTable::deleteTable()	{
	for(int i = 0; i < this->prime; i++)	{
		this->table[i].deleteList();
	}
}
//Copies the values from the source hashtable into the calling object
//Param: Source is the table to be copied
//Pre: calling table is empty
//Post: calling table contents are identicle to source
void HashTable::copyTable(const HashTable & source)	{
	std::vector<std::string> temp;
	std::string s1;

	this->prime = source.prime;
	this->entries = source.entries;
	this->table = new LinkedList[this->prime];
	//Goes through every bucket of the source and puts the values into a vector
	//Those strings are then added into the calling object
	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		if(temp.size() > 0)	{
			for(unsigned int i = 0; i < temp.size(); i++)	{
				s1 = temp[i];
				this->table[j].insert(s1);
			}
		}
	}
}