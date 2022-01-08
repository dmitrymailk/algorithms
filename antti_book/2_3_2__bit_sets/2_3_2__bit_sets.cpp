#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  /*
  2^8 + 2^4 + 2^3 + 2^1 = 282
  */
  int x = 0;
  x |= (1 << 1);
  x |= (1 << 3);
  x |= (1 << 4);
  x |= (1 << 8);

  for (int i = 0; i < 32; i++)
  {
    if (x & (1 << i))
      cout << i << " ";
  }
  cout << "\n";

  // логические операции над множествами
  /*
  a ∩ b = a & b
  a ∪ b = a | b
  a' = ~a
  a \ b = a & (~b)
  */

  x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
  int y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
  int z = x | y;
  cout << __builtin_popcount(z) << "\n"; // 6

  bitset<8> foo(10);  // 00001010
  bitset<8> foo2(22); // 00010110

  cout << foo.to_string() << "\n";
  cout << foo2.to_string() << "\n";
  cout << (foo & foo2).to_string() << "\n";    // a ∩ b -> 00000010
  cout << (foo | foo2).to_string() << "\n";    // a ∪ b -> 00011110
  cout << (~foo).to_string() << "\n";          // not a -> 11110101
  cout << (foo & (~foo2)).to_string() << "\n"; // a \ b -> 00001000

  // all subsets length K
  int k = 2;
  vector<int> array = {1, 2, 3, 4};
  int n = array.size();

  for (int b = 0; b < (1 << n); b++)
  {
    if (__builtin_popcount(b) == k)
    {
      for (int i = 0; i < n; i++)
      {
        if (b & (1 << i))
        {
          cout << array[i];
        }
      }
      cout << "\n";
    }
  }
}
