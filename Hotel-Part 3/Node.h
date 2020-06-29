#ifndef __NODE_H
#define __NODE_H

#include <iostream>
using namespace std;

template<class T>
class Node
{

protected:
	T data;
	Node* next;


public:
	T& getData() const;

	Node();
	Node(T data);

	Node<T>* getNext() { return next; };

};


#endif /*!__NODE_H*/