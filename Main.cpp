#include "HashTable.h"

//#include "LinkedList.h"
#include <iostream>

int main()	{
/*	LinkedList ls;
	ls.insert("apple");
	ls.insert("corn");
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
*/

	LinkedList test[2];
	test[0].insert("apple");
	test[0].insert("orange");
	test[1].insert("herp");
	test[1].insert("derp");
	test[1].print();
	test[0].print();

	HashTable tester;
	tester.insert("test");
	tester.insert("estt");
	tester.insert("ttes");

	std::cout <<"inserting in different key" << std::endl;
	tester.insert("abcd");
	tester.insert("dcba");
	tester.insert("bcda");

	HashTable test1(11);
	test1.insert("work");
	test1.insert("orkw");
	test1.insert("rkwo");

	test1.insert("abc");
	test1.insert("cba");
	test1.insert("bac");

}