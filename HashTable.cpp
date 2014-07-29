#include "HashTable.h"

HashTable::HashTable()	{
	std::cout << "Hash table constructor" << std::endl;
	this->table = new LinkedList[101];
	this->prime = 101;
	this->entries = 0;
}

HashTable::HashTable(int n)	{
	n = isitPrime(n);
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

std::vector<std::string> HashTable::intersection(const HashTable & source){
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	std::cout << "entering intersection" << std::endl << "main size: " << this->prime << std::endl <<
	"copy size: " << source.prime << std::endl;

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

std::vector<std::string> HashTable::unions(const HashTable & source){
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	std::cout << "entering union" << std::endl << "main size: " << this->prime << std::endl <<
	"copy size: " << source.prime << std::endl;

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

std::vector<std::string> HashTable::difference(const HashTable & source){
	std::vector<std::string> main;
	std::vector<std::string> copy;
	std::vector<std::string> temp;
	std::vector<std::string> final;

	std::cout << "difference union" << std::endl << "main size: " << this->prime << std::endl <<
	"copy size: " << source.prime << std::endl;

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
