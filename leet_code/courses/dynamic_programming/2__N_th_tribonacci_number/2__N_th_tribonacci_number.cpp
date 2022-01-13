// https://leetcode.com/problems/n-th-tribonacci-number/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  int tribonacci(int n)
  {
    int current = 0;
    vector<int> tri_num = {0, 1, 1};
    if (n < 3)
    {
      current = tri_num[n];
    }
    else
    {

      for (int i = 2; i < n; i++)
      {
        current = tri_num[i] + tri_num[i - 1] + tri_num[i - 2];
        tri_num.push_back(current);
      }
    }

    return current;
  };
};

int main()
{
  auto sol = new Solution();
  sol->tribonacci(7);

  for (int i = 0; i < 32; i++)
  {
    cout << i << " " << sol->tribonacci(i) << "\n";
  }
}