#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class MyStack
{
private:
	vector<T>* m_pArrayData;
	int m_size;

public:
	MyStack()
	{
		m_pArrayData = new vector<T>();
		m_size = 0;
	}
	~MyStack()
	{
		if (m_pArrayData != nullptr)
		{
			m_pArrayData->clear();
			vector<T>().swap(*m_pArrayData);
		}

		m_pArrayData->clear();
		m_size = 0;
	}

	void push(const T& value);
	void pop();
	void print();	// 맨 위의 값을 반환
	bool isEmpty();
};

int main()
{
	MyStack<int> myStack;

	myStack.push(2);
	myStack.push(1);
	myStack.pop();
	myStack.pop();

	myStack.print();

	myStack.push(10);
}

template<typename T>
void MyStack<T>::push(const T& value)
{
	vector<T>* _newArray = new vector<T>();
	_newArray->push_back(value);

	for (unsigned int i = 0; i < m_pArrayData->size(); ++i)
	{
		_newArray->push_back(m_pArrayData->at(i));
	}

	vector<T>().swap(*m_pArrayData);
	m_pArrayData = _newArray;
}

template<typename T>
void MyStack<T>::pop()
{
	if (m_pArrayData->empty()) return;

	vector<T>* _newArray = new vector<T>();

	for (unsigned int i = 0; i < m_pArrayData->size(); ++i)
	{
		// 첫 번째는 pop으로 빠질것이므로
		if (i == 0) continue;
		_newArray->push_back(m_pArrayData->at(i));
	}

	vector<T>().swap(*m_pArrayData);
	m_pArrayData = _newArray;
}

template<typename T>
void MyStack<T>::print()
{
	if (isEmpty())
	{
		cout << "Stack이 비어있습니다." << endl;
		return;
	}

	cout << m_pArrayData->front() << endl;
}

template<typename T>
bool MyStack<T>::isEmpty()
{
	return m_pArrayData->empty();
}
