#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
using namespace std;

int main()
{
  stack<int> stack1;              // deque by default
  stack<int, vector<int>> stack2; // vector
  stack<int, list<int>> stack3;   // list
}