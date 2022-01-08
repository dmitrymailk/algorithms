#include <vector>
#include <iostream>
using namespace std;
// {1, 2, 3} => {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3} и {1, 2, 3}

vector<int> subset;
vector<int> test_array = {42, 5, 7};
int n = 2;

void all_subsets(int k = 0)
{
  if (k == n)
  {
    for (int item : subset)
      cout << test_array[item] << " ";

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
  all_subsets();
}