#include "Node.h"


template <class T>
Node<T>::Node()
{
	next = nullptr;
}


template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next= nullptr;
}





template <class T>
T& Node<T>::getData() const
{
	return this->data;
}


/*

template <class T>
Node* Node<T>::getNext()
{
	return this->next;
}*/