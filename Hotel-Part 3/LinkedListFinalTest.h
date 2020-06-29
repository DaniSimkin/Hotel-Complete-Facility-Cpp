#ifndef __LinkedListFinalTest_H
#define __LinkedListFinalTest_H

#include <iostream>
//#include "Node.h"
using namespace std;
template <class T>
class Node;

template <class T>
class Linked_List
{

private:
	Node<T>* head;
	Node<T>* tail = nullptr;

public:
	void addToEnd(T val);
	void removeItem(T val);
	void printList();
	Node<T>* getTail();
	Node<T>* getHead();
};

template<class T>
class Node
{
	friend class Linked_List<T>;

private:
	T val;
	Node<T>* next;

public:
	Node<T>(const T& val) = delete;
	T getVal() { return val; }
	Node<T>* getNext() {
		/*cout << "next " << next << endl;*/
		return next;
	}
};

template<class T>
void Linked_List<T>::addToEnd(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
}
template<class T>
void Linked_List<T>::removeItem(T val)
{
	Node<T>* temp = head;
	if (temp->val == val)
		head = head->next;
	else
	{
		while (temp->next != nullptr)
			if (temp->next->val == val)
			{
				Node<T>* temp2 = temp->next;
				temp->next = temp->next->next;
				delete[] temp2;
				break;
			}
	}
}

template<class T>
void Linked_List<T>::printList()
{
	if (head == nullptr)
		cout << "List is empty" << endl;
	else
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

//template<class T>
//inline T Linked_List<T>::getTail()
//{
//	return T();
//}

template<class T>
Node<T>* Linked_List<T>::getTail()
{
	return tail;
}

template<class T>
Node<T>* Linked_List<T>::getHead() 
{
	return head;
}
#endif // __LinkedListFinalTest_H