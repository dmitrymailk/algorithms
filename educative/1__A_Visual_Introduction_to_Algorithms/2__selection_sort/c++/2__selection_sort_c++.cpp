#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int> &array, int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int indexOfMinimum(vector<int> array, int startIndex)
{
    int minValue = array[startIndex];
    int minIndex = startIndex;

    for (int i = minIndex + 1; i < array.size(); i++)
    {
        if (array[i] < minValue)
        {
            minIndex = i;
            minValue = array[i];
        }
    }
    return minIndex;
};

void selectionSort(vector<int> &array)
{
    // Write this method
    for (int i = 0; i < array.size(); i++)
    {
        int min_i = indexOfMinimum(array, i);
        cout << min_i << " " << i << "\n";
        swap(array, i, min_i);
    }
};

int main()
{
    vector<int> array = {4, 3, 2, 1};
    selectionSort(array);
}