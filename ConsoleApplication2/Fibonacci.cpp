#include <iostream>
#include <assert.h>

using namespace std;

int Fibonacci(int index);

int main()
{
    int a = 0;
    a = Fibonacci(1);

    cout << a << endl;
}

int Fibonacci(int index)
{
    if (index == 0)
    {
        assert(index != 0);
    }

    if (index == 1 || index == 2)
    {
        return 1;
    }

    return Fibonacci(index - 1) + Fibonacci(index - 2);
}