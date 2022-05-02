#pragma once
#include <assert.h>

// 반복자 하려다가 다 못했습니다...

template<typename T>
struct Node
{
	Node* pNextNode;
	Node* pPrevNode;
	T m_data;

	Node()
	{
		pNextNode - nullptr;
		pPrevNode = nullptr;
	}

	Node(T _data, Node* _prev, Node* _next)
	{
		m_data = _data;
		pNextNode = _next;
		pPrevNode = _prev;
	}

	~Node() {}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* pTailNode;
	Node<T>* pHeadNode;

	int m_size;

public:
	LinkedList();
	~LinkedList();

	void push_back(const T& data);
	void pop_back();
	T back();
	T front();

	void clear();

	class iterator
	{
		friend LinkedList;

	private:
		LinkedList<T>*	pList;
		Node<T>*		pNode;
		int				m_index;

	public:
		iterator();
		iterator(LinkedList<T>* targetList, Node<T>* pNode, int index);

		T* operator*() const;
		iterator& operator++();
		iterator& operator--();
	};

	iterator begin();
	iterator end();

	void insert(const iterator& _where, const T& value);
	void erase(const iterator& _where);
};

template<typename T>
LinkedList<T>::LinkedList()
{
	pTailNode = nullptr;
	pHeadNode = nullptr;
	m_size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
void LinkedList<T>::push_back(const T& data)
{
	if (m_size > 0)
	{
		Node<T>* _pNewNode = new Node<T>(data, pTailNode, nullptr);

		pHeadNode = pTailNode;
		pTailNode = _pNewNode;
	}
	else
	{
		Node<T>* _pNewNode = new Node<T>(data, nullptr, nullptr);

		pHeadNode = _pNewNode;
		pTailNode = _pNewNode;
	}

	m_size++;
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	if (m_size > 1)
	{
		m_size -= 1;

		Node<T>* _pPrevNode = pTailNode->pPrevNode;
		delete pTailNode;

		pTailNode = _pPrevNode;
		pTailNode->pNextNode = nullptr;
	}
	else if (m_size == 1)
	{
		delete pTailNode;

		pHeadNode = nullptr;
		pTailNode = nullptr;
		m_size -= 1;
	}
	else
	{
		std::cout << "List에서 제거할 수 있는 Node가 존재하지 않습니다." << std::endl;
		assert(nullptr);
	}
}

template<typename T>
inline T LinkedList<T>::back()
{
	return pTailNode->m_data;
}

template<typename T>
inline T LinkedList<T>::front()
{
	return pHeadNode->m_data;
}

template<typename T>
inline LinkedList<T>::iterator LinkedList<T>::begin()
{
	
}

template<typename T>
inline void LinkedList<T>::insert(const iterator& _where, const T& value)
{
	
}

template<typename T>
inline void LinkedList<T>::erase(const iterator& _where)
{

}

template<typename T>
inline void LinkedList<T>::clear()
{
	int targetSize = m_size;

	for (int i = 0; i < targetSize; ++i)
	{
		pop_back();
	}
}

template<typename T>
inline LinkedList<T>::iterator::iterator()
{
	this->pList = nullptr;
	this->pNode = nullptr;
	m_index = -1;
}

template<typename T>
inline LinkedList<T>::iterator::iterator(LinkedList<T>* targetList, Node<T>* pNode, int index)
{
	this->pList = targetList;
	this->pNode = pNode;
	this->m_index = index;
}

template<typename T>
inline T* LinkedList<T>::iterator::operator*() const
{
	// 1. iterator가 list의 Node가 변경됨에 따라 잘못된 곳을 가리키고 있을 때
	// 2. iterator가 end() iterator 일 때 assert();
	if (pHeadNode != this->pList->pHeadNode || m_index == -1)
		assert(nullptr);

	return pList[m_index];
}

template<typename T>
inline LinkedList<T>::iterator& LinkedList<T>::iterator::operator++()
{
	if (pList->m_size - 1 == m_index)
	{
		m_index = -1;
	}
	else
	{
		m_index++;
	}

	return *this;
}

template<typename T>
inline LinkedList<T>::iterator& LinkedList<T>::iterator::operator--()
{
	if (m_index == 0)
		assert(nullptr);

	if (m_index == -1)
	{
		m_index += pList->m_size + 1;
	}

	m_index--;

	return *this;
}
