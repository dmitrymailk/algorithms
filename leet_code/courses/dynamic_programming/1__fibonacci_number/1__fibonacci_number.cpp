// https://leetcode.com/problems/fibonacci-number/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
  // https://en.wikipedia.org/wiki/Fibonacci_number
  int fib(int n)
  {
    int current = 1;
    if (n == 0)
      return n;
    else if (n == 1 || n == 2)
    {
      return 1;
    }
    else
    {
      int prev_1 = 1;
      int prev_2 = 1;
      n -= 2;

      for (int i = 0; i < n; i++)
      {
        current = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = current;
      }
    }
    return current;
  }
};

int main()
{
  auto sol = new Solution();
  cout << sol->fib(0) << "\n";
  cout << sol->fib(1) << "\n";
  cout << sol->fib(2) << "\n";
  cout << sol->fib(3) << "\n";
  cout << sol->fib(4) << "\n";
  cout << sol->fib(5) << "\n";
  cout << sol->fib(6) << "\n";
  cout << sol->fib(7) << "\n";
}