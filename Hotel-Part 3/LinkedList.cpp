#include "LinkedList.h"



template <class T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
	
}


template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *current = head;
	Node<T> *next;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}

	cout << "List Deleted" << endl;

}


template <class T>
void LinkedList<T>::addNode(T data)
{
	Node<T> *ptr = new Node<T>(data);
	if (!head)
	{
		head = ptr;
	}
	else
	{
		tail->next = ptr;
		
	}
	tail = ptr;
	this->size += 1;
}

template <class T>
void LinkedList<T>::removeNode(T data)
{
	Node<T> *tempNode, *tempNode2;
	if (head == nullptr)
	{
		cout << "List is Empty";
		return;
	}
	else if (head->data == data)
	{
		tempNode = head;
		if (head->next != nullptr)
		{
			head = head->next;
			delete tempNode;
			tempNode = nullptr;
			this->size -= 1;
		}
		else
		{
			delete head;
			head = nullptr;
			delete tempNode;
			tempNode = nullptr;
			this->size -= 1;
			return;
		}
	}
	tempNode2 = head;
	while (tempNode2->next->next != nullptr)
	{
		if (tempNode2->next->data == data)
		{
			tempNode = tempNode2->next;
			tempNode2->next = tempNode->next;
			delete tempNode;
			tempNode = nullptr;
			this->size -= 1;
			return;
		}
		tempNode2 = tempNode2->next;
	}

	if (tempNode2->next->data == data)
	{
		tempNode = tempNode2->next;
		delete tempNode;
		tempNode = nullptr;
		tempNode2->next = nullptr;
		this->size -= 1;
		return;
	
	}

	cout << "Element not found" << endl;
}

/* // BETTER TO USE OPERATOR << FOR THE LINKED LIST RATHER THAN COUT
template <class T>
void LinkedList<T>::printList()
{
	Node<t> *ptr = this->head;
	cout << "Printing the list: " << endl;
	while (ptr != nullptr)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
*/

template <class T>
ostream& operator<<(ostream& os, const LinkedList<T>& hotel)
{
	Node<T> *ptr = this->head;
	cout << "Printing the list: " << endl;
	while (ptr != nullptr)
	{
		os << ptr->data << " ";
		ptr = ptr->next;
	}
	os << endl;
	return os;
}

