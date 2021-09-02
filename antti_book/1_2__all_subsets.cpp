#include <bits/stdc++.h>

using namespace std;
// {1, 2, 3} => {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3} и {1, 2, 3}

vector<int> subset;
vector<int> test_array = {42, 5, 7};
int n = 3;

void all_subsets(int k)
{
  if (k == n + 1)
  {
    for (int item : subset)
    {
      cout << test_array[item - 1] << " ";
    }
    cout << "\n";
  }
  else
  {
    subset.push_back(k);
    all_subsets(k + 1);
    subset.pop_back();
    all_subsets(k + 1);
  }
}

int main()
{
  all_subsets(1);
}