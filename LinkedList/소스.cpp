#include <iostream>
#include <list>
#include "LinkedList.h"

using namespace std;

int main()
{
	list<int> stlList;

	stlList.push_back(1);
	stlList.push_front(2);
	stlList.pop_back();
	stlList.pop_front();
	stlList.front();
	stlList.back();
}