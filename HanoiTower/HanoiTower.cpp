#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Hanoi(int count, char start, char end, char via);

int main()
{
	const short diskCount = 3;

    Hanoi(diskCount, 'A', 'C', 'B');
}

void MoveDisk(int count, char start, char end);

void Hanoi(int count, char start, char end, char via)
{
    if (count == 1)
    {
        MoveDisk(1, start, end);
    }
    else
    {
        Hanoi(count - 1, start, via, end);
        MoveDisk(count, start, end);
        Hanoi(count - 1, via, end, start);
    }
}

void MoveDisk(int count, char start, char end)
{
    cout << count << "번 원반을" << start << "에서 " << end << "로 이동함" << endl;
}