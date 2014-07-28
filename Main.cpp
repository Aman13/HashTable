//#include "HashTable.h"

#include "LinkedList.h"
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
	return 0;
}