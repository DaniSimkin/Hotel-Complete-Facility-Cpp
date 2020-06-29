#ifndef __LinkedList_H
#define __LinkedList_H

#include <iostream>
#include "Node.h"
using namespace std;


template<class T>
class LinkedList
{
private:
	
	int size;
	Node<T> *head;
	Node<T> *tail;
	
public:
	LinkedList();
	~LinkedList();

	void addNode(T);
	//void printList();
	void removeNode(T);
	Node<T>* getHead() { return head; }
	


	friend ostream& operator<<(ostream& os, const LinkedList<T>& list);
};

#endif /*__LinkedList_H*/