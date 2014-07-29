#include "HashTable.h"

//#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <cmath>

int main()	{
/*
	LinkedList ls;
	ls.insert("apple");
	ls.insert("corn");
	ls.insert("apple");
	ls.insert("pie");
	LinkedList copy = ls;
	ls.print();
	copy.remove("corn");
	copy.insert("cake");
	copy.insert("pudding");
	copy.remove("apple");
	copy.print();
	LinkedList duplicate;
	duplicate = copy;
	duplicate.insert("bike");
	duplicate.print();

	std::vector<std::string> vectorTest;
	vectorTest = duplicate.get();

	std::cout << std::endl << std::endl << "Vector contains: ";
	for(unsigned int i = 0; i < vectorTest.size(); i++)	{
		std::cout << vectorTest[i] << " ";
	}

	std::vector<std::string> v1;
	std::vector<std::string> v2;
	std::vector<std::string> v3;
	std::vector<std::string> v4;
	std::vector<std::string> v5;

	v3.push_back("honda");
	v3.push_back("yamaha");
	v3.push_back("suzuki");
	v2.push_back("accord");
	v2.push_back("civic");
	v2.push_back("corolla");

	v2.insert(v2.end(), v3.begin(), v3.end());

	std::cout << std::endl << "V2 contains: ";
	for(unsigned int i = 0; i < v2.size(); i++)	{
		std::cout << v2[i] << " ";
	}

	v1 = v2;

	std::cout << std::endl << "V1 contains: ";
	for(unsigned int i = 0; i < v1.size(); i++)	{
		std::cout << v1[i] << " ";
	}

	v1.insert(v1.end(), v4.begin(), v4.end());
	std::cout << std::endl << "V1 contains when adding v4 which is empty: ";
	for(unsigned int i = 0; i < v1.size(); i++)	{
		std::cout << v1[i] << " ";
	}

	v5.insert(v5.end(), v4.begin(), v4.end());
	std::cout << std::endl << "V5 is empty adding v4 which is empty: ";
	for(unsigned int i = 0; i < v5.size(); i++)	{
		std::cout << v5[i] << " ";
	}

	int a = 0;
	int b = 2;
	int c = 3;


	a = std::pow(b,c);

	std::cout << std::endl << std::endl << "A = " << a << std::endl;



	LinkedList test[2];
	test[0].insert("apple");
	test[0].insert("orange");
	test[1].insert("derp");
	test[1].insert("herp");
	test[1].print();
	test[0].print();
	test[1].insert("herp");
*/


	HashTable tester(5);
	tester.insert("apple");
	tester.insert("orange");
	tester.insert("banana");

	std::cout <<"inserting in different key" << std::endl;
	tester.insert("grape");
	tester.insert("melon");
	tester.insert("plum");

	HashTable test1(3);
	int p = test1.maxSize();
	std::cout << "Test1 array size: " << p << std::endl;
	test1.insert("fox");
	test1.insert("cat");
	test1.insert("grape");

	test1.insert("dog");
	test1.insert("plum");
	test1.insert("lion");
	test1.insert("wolf");

	int howmany;
	howmany = test1.size();

	std::cout << "Test 1 contains: " << howmany << " entries" << std::endl;

	test1.search("abc");
	test1.search("dog");

	tester.intersection(test1);
	tester.unions(test1);
	tester.difference(test1);

}