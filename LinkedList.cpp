#include "LinkedList.h"

//Default Constructor
//Post: Creates empty list
LinkedList::LinkedList()	{
	front = NULL;
}

//Copy Constructor
//Param: Source is the list to be copied by the calling object
//Post: creates an object that is a copy of Source
LinkedList::LinkedList(const LinkedList & source) : front(NULL)	{
	deepCopy(source);
}

//Destructor
//Post: de allocates memory associated with the list
LinkedList::~LinkedList()	{
	deleteList();
}

//Overloaded assignment operator
//Param: source is the object to be copied to the calling object
//Post: Copies source to the calling boject. returns calling object.
LinkedList & LinkedList::operator= (const LinkedList & source)	{
	if(this != &source)	{
		deleteList();
		deepCopy(source);
	}

	return *this;
}

//Inserts a element into the list if its not already in the linkedlist
//Param: Value (string) to be inserted
//Post: value is inserted at the back of the linked list if it doesnt already exist
bool LinkedList::insert(std::string value)	{
	bool exists;
	exists = search(value);
	if(front == NULL)	{
		front = new Node(value, this->front);
		return true;
	}else	{
		if(exists)	{
			return false;
			//cannot insert multiple

		}else	{
			Node* temp = front;
			while(temp->next != NULL)	{
				temp = temp->next;
			}
			temp->next = new Node(value, temp->next);
			return true;
		}	
	}
}

//Removes an element from the linked list if it exists
//Param: the element to be removed
//Post: returns true if value is removed, false if it did not exist in the list
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

//Looks for a value (string) in the linked list
//Param: value you are looking for
//Post: return true if it is found, false if it does not exist in the list
bool LinkedList::search(std::string value)	{
	Node* temp = front;
	while(temp != NULL)	{
		if(temp->data == value)	{
			//value found
			return true;
		}
		temp = temp->next;
	}
	//entry is not in list
	return false;
}

//Prints the list from front to back
//Post: prints out the list from front to back
void LinkedList::print()	const	{
	Node* temp = front;
	while(temp != NULL)	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

//Puts the value of the linkedlist into a vector
//Post: returns a vector holding all the values in the linkedlist
std::vector<std::string> LinkedList::get()	const	{
	std::vector<std::string> myVector;
	Node* temp = front;
	while(temp != NULL)	{
		myVector.push_back(temp->data);
		temp = temp->next;
	}
	return myVector;

}

//Makes a deep copy of the deque.
//Param: Source is the linked list to be copied
//Pre: Calling linkedlist is empty
//Post: Linked list contens are identical to the source
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

//Removes all elements from the linkedlist and deallocates dynamic memory
//Post: Linkedlist is empty
void LinkedList::deleteList()	{
	Node* temp = front;
	while(temp != NULL)	{
		temp = front->next;
		delete front;
		front = temp;
	}
	front = NULL;
}