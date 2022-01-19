#include <iostream>
#include <string>
#include <vector>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 1;

    return x * power(x, n - 1);
}

int nonRecPower(int x, unsigned int n)
{
    int result = 1;
    for (result = x; n > 1; --n)
        result *= x;
    return result;
}

int main()
{
    cout << power(3, 2) << "\n";
    cout << power(4, 2) << "\n";
    cout << power(2, 4) << "\n";
}