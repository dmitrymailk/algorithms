// task: https://codeforces.com/contest/1624/problem/A
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void read_from_file()
{
  const char *env_p;
  if (env_p = getenv("codeforces"))
  {
    string new_str(env_p);
    if (new_str == "dimweb")
    {
      freopen("input_file", "r", stdin);
    }
  }
}

int main()
{
  read_from_file();

  int data_amount, array_len;
  cin >> data_amount;
  vector<vector<int>> dataset;
  for (int i = 0; i < data_amount; i++)
  {
    vector<int> temp_array;
    cin >> array_len;

    for (int j = 0; j < array_len; j++)
    {
      int number;
      cin >> number;
      temp_array.push_back(number);
    }
    dataset.push_back(temp_array);
  }
  // идея в этой задаче что минимальное количество операций равняется разности минимального
  // и максимального числа, так как мы можем за один раз выбирать неограниченное количество
  // чисел
  for (int i = 0; i < data_amount; i++)
  {
    int min_num, max_num;
    min_num = dataset[i][0];
    max_num = dataset[i][0];

    for (int j = 0; j < dataset[i].size(); j++)
    {
      min_num = min(dataset[i][j], min_num);
      max_num = max(dataset[i][j], max_num);
    }

    cout << max_num - min_num << "\n";
  }
}