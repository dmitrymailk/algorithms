#include <iostream>
#include <vector>
using namespace std;
// алгоритм находит максимальную сумму подмассива
void solution_O_n2(vector<int> &array)
{
  int best = array[0];
  // полный перебор всех подмножеств сумм
  for (int i = 0; i < array.size(); i++)
  {
    int sum = 0;
    for (int j = i; j < array.size(); j++)
    {
      sum += array[j];
      best = max(best, sum);
    }
  }
  cout << best << "\n";
}

void solution_O_n(vector<int> &array)
{
  int best = array[0];
  int sum = 0;
  for (int i = 0; i < array.size(); i++)
  {
    // если даже вся сумма предыдущих ПЛЮС текущий элемент не может превзойти текущий элемент
    // значит там очень много отрицательных чисел, поэтому мы можем выкинуть прошлую часть
    // и взять только текущий элемент
    sum = max(array[i], sum + array[i]);
    best = max(best, sum);
  }
  cout << best << "\n";
}

int main()
{
  vector<int> array = {-1, 2, 4, -3, 5, 2, -5, 2};
  solution_O_n2(array);
  solution_O_n(array);
}