#include <iostream>

using namespace std;

int Hanoi(int count, char start, char end, char via);

int main()
{
    const short diskCount = 3;

    int count = Hanoi(diskCount, 'A', 'C', 'B');

    cout << count << "번 이동함" << endl;
}

void MoveDisk(int count, char start, char end);

int Hanoi(int count, char start, char end, char via)
{
    static int moveCount = 0;

    if (count == 1)
    {
        moveCount++;
        MoveDisk(1, start, end);
    }
    else
    {
        moveCount++;
        Hanoi(count - 1, start, via, end);
        MoveDisk(count, start, end);
        Hanoi(count - 1, via, end, start);
    }

    return moveCount;
}

void MoveDisk(int count, char start, char end)
{
    cout << count << "번 원반을" << start << "에서 " << end << "로 이동함" << endl;
}