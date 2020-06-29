#include <iostream>
#include <set>

using namespace std;

template<class T>
class Node
{
private:

public:
	T data;
	Node<T> * next;

	Node<T>(T& d) : data(d), next() {}
	Node<T>(const Node<T>& copyNode) = delete;

	T& getData() { return data;}

};

template<class T>
class LinkedList
{
public:

	Node<T> * head;
	Node<T> * tail;

	LinkedList& operator=(LinkedList byValList);
	LinkedList() : head(nullptr), tail(nullptr) {}
	LinkedList(Node<T> * newNode) : head(newNode), tail(newNode) {}
	LinkedList(const LinkedList& LL);
	~LinkedList();

	void insertToTail(T val);
	void insertToHead(T val);
	void print();
	void printBackwards();
	void removeItem(T val);
	Node<T>* getHead();
};

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& LL) : head(nullptr), tail(nullptr)
{
	Node<T> * curr = LL.head;

	if (!head && curr)
	{
		head = new Node<T>(curr->data);
		tail = head;
		curr = curr->next;
	}

	while (curr)
	{
		Node<T> * newNode = new Node<T>(curr->data);
		tail->next = newNode;
		tail = newNode;
		curr = curr->next;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList byValList)
{
	std::swap(head, byValList.head);
	return *this;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> * curr = head;
	while (head)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
}

template<class T>
void LinkedList<T>::insertToTail(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (tail == nullptr)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}

template<class T>
void LinkedList<T>::insertToHead(T val)
{
	Node<T> * newNode = new Node<T>(val);
	newNode->next = head;
	head = newNode;
	if (head->next == nullptr)
		tail = newNode;
}

template<class T>
void LinkedList<T>::print()
{
	Node<T> * curr = head;
	while (curr)
	{
		cout << curr->data << " --> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

template<class T>
void LinkedList<T>::printBackwards()
{
	Node<T> * curr;
	LinkedList ReversedList(new Node<T>(head->data));
	curr = head->next;
	while (curr)
	{
		ReversedList.insertToHead(curr->data);
		curr = curr->next;
	}

	curr = ReversedList.head;
	while (curr)
	{
		cout << curr->data << " --> ";
		curr = curr->next;
	}
	cout << "NULL\n";
}


template<class T>
void LinkedList<T>::removeItem(T val)
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
				delete temp2;
				break;
			}
	}
}

template<class T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}