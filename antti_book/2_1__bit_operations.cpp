#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x = -43;
  unsigned int y = x;
  cout << x << "\n"; // -43
  cout << y << "\n"; // 4294967253
  x = 2147483647;
  cout << x << "\n"; // 2147483647
  x++;
  cout << x << "\n"; // -2147483648

  x = 3;
  // logical AND
  if ((x & 1) == 0)
    cout << "even\n";
  else
    cout << "odd\n";
  cout << (x & 1) << "\n";

  // logical OR
  cout << (22 | 26) << "\n"; // 30

  // logical XOR
  /*
  0 & 0 -> 0
  1 & 1 -> 0
  1 & 0 -> 1
  0 & 1 -> 1
  */
  cout << (22 ^ 26) << "\n"; // 12

  // logical NOT
  x = 29;
  cout << (~x) << "\n"; // -30

  // shift
  cout << (14 << 2) << "\n"; // 56
  cout << (56 >> 2) << "\n"; // 14

  // create double number representation
  x = 1234;
  int array_x[32];
  for (int k = 31; k >= 0; k--)
  {
    if (x & (1 << k))
      // cout << 1;
      array_x[31 - k] = 1;
    else
      array_x[31 - k] = 0;
    // cout << 0;
    // cout << (x & (1 << k)); // decomposition on powers 2
    // cout << "\n";
  }
  for (int i = 0; i < 32; i++)
  {
    cout << array_x[i];
  }
  cout << "\n";
}