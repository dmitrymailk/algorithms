#include <iostream>
using namespace std;

int main()
{
  int i1, i2, k, n, length, i;
  int a[] = {1, 8, 1, 2, 5, 10, -11, 12};
  n = 8;

  for (i = 0, length = 1; i < n; i++)
  {
    for (i1 = i2 = k = i; k < n && a[k] < a[k + 1]; k++, i2++)
      if (length < i2 - i1 + 1)
        length = i2 - i1 + 1;
  }

  cout << length << "\n";
}