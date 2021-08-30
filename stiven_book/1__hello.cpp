#include <iostream>

using namespace std;

int main()
{
  int *some;
  for (int i = 0; i < 100000 * 10000; i++)
  {
    some = new int[1000];
  }
}