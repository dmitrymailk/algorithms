#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tail(int i)
{
    if (i > 0)
    {
        cout << i << " ";
        tail(i - 1);
    }
}

void nonTail(int i)
{
    if (i > 0)
    {
        nonTail(i - 1);
        cout << i << ' ';
        nonTail(i - 1);
    }
}

void iterativeEquivalentOfTail(int i)
{
    for (; i > 0; i--)
        cout << i << ' ';
}

int main()
{
    // tail(5);
    nonTail(5);
    // iterativeEquivalentOfTail(5);
}