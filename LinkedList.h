#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class LinkedList	{

public:

	LinkedList();

	LinkedList(const LinkedList & source);

	~LinkedList();

	LinkedList & operator= (const LinkedList & source);

	bool insert(std::string);

	bool remove(std::string);

	bool search(std::string);

	void print()	const;

	void deleteList();

	void deepCopy(const LinkedList & source);

	std::vector<std::string> get()	const;

private:

	class Node	{
	public:
		std::string data;
		Node* next;

		Node(std::string value): data(value), next(NULL) {};
		Node(std::string value, Node* nd): data(value), next(nd) {};
	};

	Node* front;
};