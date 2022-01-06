#include <bits/stdc++.h>

using namespace std;

vector<int> permutation;
const int n = 4;
bool chosen[n];

void all_permutations()
{
  if (permutation.size() == n)
  {
    for (int item : permutation)
      cout << item << " ";
    cout << "\n";
  }
  else
    for (int i = 0; i < n; i++)
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

int main()
{
  all_permutations();
}
