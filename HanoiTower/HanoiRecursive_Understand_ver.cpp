#include <iostream>

using namespace std;

int MoveDisks(int n, char from, char dest);

// 거의 변한것은 없지만 어떻게 재귀적으로 작동하는지 이해하고 작성하였다고 생각합니다.
int Hanoi(int n, char from, char via, char dest)
{
    static unsigned int count = 0;

    if (n == 1)
    {
        count += MoveDisks(n, from, dest);
    }
    else
    {
        // n - 1번째는 중앙 기둥에 위치해야함
        Hanoi(n - 1, from, dest, via);
        // 그래야 맨 밑의 n번째가 오른쪽 기둥에 마지막에 위치할 수 있음
        count += MoveDisks(n, from, dest);
        // 그 후 n - 1번째가 오른쪽기둥으로 이동
        Hanoi(n - 1, via, from, dest);
        
        // n - 2, n - 3, ..., 2 까지 모두 같은 방식으로 작동
    }

    return count;
}

int MoveDisks(int n, char from, char dest)
{
    cout << n << "번 디스크가" << from << "에서 " << dest << "로 이동하였습니다." << endl;
    return 1;
}

int main()
{
    int hanoiCount = Hanoi(7, 'A', 'B', 'C');

    cout << hanoiCount << endl;
}