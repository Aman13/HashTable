#include "LinkedList.h"

LinkedList::LinkedList()	{
	front = NULL;
}

LinkedList::LinkedList(const LinkedList & source) : front(NULL)	{
	deepCopy(source);
}

LinkedList::~LinkedList()	{
	deleteList();
}

LinkedList & LinkedList::operator= (const LinkedList & source)	{
	if(this != &source)	{
		deleteList();
		deepCopy(source);
	}

	return *this;
}

bool LinkedList::insert(std::string value)	{
	if(front == NULL)	{
		front = new Node(value, this->front);
		return true;
	}else	{
		Node* temp = front;
		while(temp->next != NULL)	{
			temp = temp->next;
		}
		temp->next = new Node(value, temp->next);
		return true;
	}
}

bool LinkedList::remove(std::string value)	{
	Node* temp = front;
	//Linked list is empty
	if(temp == NULL)	{
		return false;
	}
	//The string to be deleted is the first entry
	if(temp->data == value)	{
		front = temp->next;
		delete temp;
		return true;
	}else	{
		while(temp->next != NULL)	{
			//String is found somewhere in the linked list
			if(temp->next->data == value)	{
				Node* toDelete = temp->next;
				temp->next = temp->next->next;
				delete toDelete;
				return true;
			}
			temp = temp->next;
		}

		return false;
		//string not found in linked list
	}
}

bool LinkedList::search(std::string value)	{
	Node* temp = front;
	while(temp != NULL)	{
		if(temp->data == value)	{
			//value found
			return true;
		}
	}
	//entry is not in list
	return false;
}

void LinkedList::print()	const	{
	Node* temp = front;
	while(temp != NULL)	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void LinkedList::deepCopy(const LinkedList & source)	{
	if(source.front == NULL)	{
		this->front = NULL;
	}else	{
		Node* temp = source.front;
		while(temp != NULL)	{
			this->insert(temp->data);
			temp = temp->next;
		}
	}
}

void LinkedList::deleteList()	{
	Node* temp = front;
	while(temp != NULL)	{
		temp = front->next;
		delete front;
		front = temp;
	}
	front = NULL;
}