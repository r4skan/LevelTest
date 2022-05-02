#pragma once
template<typename T>
class LinkedList
{
	Node<T>* tailNode;
	Node<T>* headNode;

public:
	LinkedList()
	{
		tailNode = nullptr;
		headNode = nullptr;
	}


};

template<typename T>
struct Node
{
	Node* nextNode;
	Node* prevNode;
	T data;
};

