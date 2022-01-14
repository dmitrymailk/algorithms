#include <vector>
using namespace std;

/* Returns either the index of the location in the array,
  or -1 if the array did not contain the targetValue */
int doSearch(vector<int> &array, int targetValue)
{
  int min = 0;
  int max = array.size() - 1;
  int guess;

  while (min <= max)
  {
    guess = (max + min) / 2;
    if (array[guess] < targetValue)
    {
      min = guess + 1;
    }
    else if (array[guess] > targetValue)
    {
      max = guess - 1;
    }
    else
    {
      return guess;
    }
  }

  return -1;
};
