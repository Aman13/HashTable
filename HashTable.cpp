#include "HashTable.h"

HashTable::HashTable()	{
	std::cout << "Hash table constructor" << std::endl;
	this->table = new LinkedList[101];
	this->prime = 101;
	this->entries = 0;
}

HashTable::HashTable(int n)	{
	n = isitPrime(n);
	this->table = new LinkedList[n];
	this->prime = n;
	this->entries = 0;
}

HashTable::~HashTable()	{
	deleteTable();
}

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


bool HashTable::insert(std::string value)	{
	std::cout <<"Hash table insert" << std::endl;
	int key;
	bool added;
	key = hashfunction(value);
	added = this->table[key].insert(value);
	this->table[key].print();
	if(added)	{
		entries++;
	}
	return added;
}

bool HashTable::remove(std::string value)	{
	std::cout <<"Hash table remove" << std::endl;
	int key;
	bool removed;
	key = hashfunction(value);
	removed = this->table[key].remove(value);
	if(removed)	{
		entries--;
	}
	return removed;
}

int HashTable::hashfunction(std::string value)	{
	std::cout <<"Hash table hasfunction" << std::endl;
	int hash = 0;
	int index = 0;
	
	index = value.length();

	for(int i = 0; i < index; i++)	{
		hash = (32 * hash + (value[i] - 96)) % this->prime;
	}
	std::cout <<"Hash value is: " << hash << std::endl;
	return hash;
}

bool HashTable::search(std::string value)	{
	int key;
	bool found;
	key = hashfunction(value);
	found = this->table[key].search(value);

	return found;
}

int HashTable::size()	const {
	return this->entries;
}

int HashTable::maxSize()	const {
	return this->prime;
}

int HashTable::loadFactor()	const {
	int temp;
	temp = this->entries/this->prime;
	return temp;
}

int HashTable::isitPrime(int n)	{
	bool pNum = false;
	if(n == 0)	{
		n=1;
	}
	n = n*2;
	while(pNum == false)	{
		pNum = true;

		for(int i = 2; i < sqrt(n); i++)	{
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

std::vector<std::string> HashTable::intersection(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}

	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}

	std::cout << "main and copy vectors have been created" << std::endl;

	for(unsigned int v = 0; v < main.size(); v++)	{
		for(unsigned int w = 0; w < copy.size(); w++)	{
			if(main[v] == copy[w])	{
				final.push_back(main[v]);
			}
		}
	}

	std::cout << std::endl << "Main contains " << main.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;
	
	for(unsigned int a = 0; a < main.size(); a++)	{
		std::cout << main[a] << " ";
	}


	std::cout << std::endl << "Source contains: " << copy.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int c = 0; c < copy.size(); c++)	{
		std::cout << copy[c] << " ";
	}

	std::cout << std::endl << "Final contains: " << final.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int b = 0; b < final.size(); b++)	{
		std::cout << final[b] << " ";
	}



	return final;

}

std::vector<std::string> HashTable::unions(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}

	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}

	std::cout << "main and copy vectors have been created" << std::endl;
	final = copy;
	bool duplicate = false;

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


	std::cout << std::endl << "Main contains " << main.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;
	
	for(unsigned int a = 0; a < main.size(); a++)	{
		std::cout << main[a] << " ";
	}


	std::cout << std::endl << "Source contains: " << copy.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int c = 0; c < copy.size(); c++)	{
		std::cout << copy[c] << " ";
	}

	std::cout << std::endl << "Final contains: " << final.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int b = 0; b < final.size(); b++)	{
		std::cout << final[b] << " ";
	}

	return final;
}

std::vector<std::string> HashTable::difference(const HashTable & source)	const {
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	for(int i = 0; i < this->prime; i++)	{
		temp = this->table[i].get();
		main.insert(main.end(), temp.begin(), temp.end());
	}

	for(int j = 0; j < source.prime; j++)	{
		temp = source.table[j].get();
		copy.insert(copy.end(), temp.begin(), temp.end());
	}
	bool duplicate = false;
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


	std::cout << std::endl << "Main contains " << main.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;
	
	for(unsigned int a = 0; a < main.size(); a++)	{
		std::cout << main[a] << " ";
	}


	std::cout << std::endl << "Source contains: " << copy.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int c = 0; c < copy.size(); c++)	{
		std::cout << copy[c] << " ";
	}

	std::cout << std::endl << "Final contains: " << final.size() << " entries" << std::endl
	<< "those entries are: " << std::endl;

	for(unsigned int b = 0; b < final.size(); b++)	{
		std::cout << final[b] << " ";
	}

	return final;

}

void HashTable::deleteTable()	{
	for(int i = 0; i < this->prime; i++)	{
		this->table[i].deleteList();
	}
}

void HashTable::copyTable(const HashTable & source)	{
	std::vector<std::string> temp;
	std::string s1;

	this->prime = source.prime;
	this->entries = source.entries;
	this->table = new LinkedList[this->prime];

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