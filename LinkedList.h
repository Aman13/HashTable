#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class LinkedList	{

public:
	//Default constructor
	LinkedList();
	//Copy constructor
	LinkedList(const LinkedList & source);
	//Destructor
	~LinkedList();
	//Overloaded assignment oeprator
	LinkedList & operator= (const LinkedList & source);
	//Inserts a value if it doesnt already exist
	bool insert(std::string);
	//Removes a value if it exists
	bool remove(std::string);
	//Finds a value in the linkedlist
	bool search(std::string);
	//Prints the linked list from front to back
	void print()	const;
	//Deletes the linkedlist
	void deleteList();
	//Copies the source values into the calling object
	void deepCopy(const LinkedList & source);
	//Puts all the values in the linkedlist into a vector
	std::vector<std::string> get()	const;

private:
	//Node class defines what a node contains
	class Node	{
	public:
		std::string data;
		Node* next;

		Node(std::string value): data(value), next(NULL) {};
		Node(std::string value, Node* nd): data(value), next(nd) {};
	};
	//Keeps track of the front of the linkedlist
	Node* front;
};