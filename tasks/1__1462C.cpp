// https://codeforces.com/problemset/problem/1462/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int data_amount = 4;
  vector<string> input_string = {"1", "5", "15", "50"};
  int max_sum = 0;

  for (int i = 1; i <= 9; i++)
    max_sum += i;
  cout << "max=" << max_sum << "\n";

  for (string item : input_string)
  {
    int target_sum = stoi(item);
    if (target_sum <= max_sum)
    {
      int num_array[9];
      int pos = 8;
      while (target_sum > 0)
      {
        if (target_sum < 10)
        {
          num_array[pos] = target_sum;
          pos -= 1;
          target_sum = 0;
        }
      }
    }
    else
      cout << "-1\n";
  }
}