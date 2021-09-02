#include <bits/stdc++.h>

using namespace std;

vector<int> permutation;
const int n = 4;
bool chosen[n + 1];

void all_permutations()
{
  if (permutation.size() == n)
  {
    for (int item : permutation)
      cout << item << " ";
    cout << "\n";
  }
  else
  {
    for (int i = 1; i <= n; i++)
    {
      if (chosen[i])
        continue;
      chosen[i] = true;
      permutation.push_back(i);
      all_permutations();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

void all_permutations_buildin()
{
  for (int i = 1; i <= n; i++)
    permutation.push_back(i);

  do
  {
    for (int item : permutation)
      cout << item << " ";
    cout << "\n";
  } while (next_permutation(permutation.begin(), permutation.end()));
}

int main()
{
  // all_permutations();
  all_permutations_buildin();
}