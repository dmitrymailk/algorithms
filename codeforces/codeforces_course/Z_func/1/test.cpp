#include <iostream>

using namespace std;

void print() {}

template <typename T, typename... Args>
void print(T t, Args... args)
{
  sizeof...(args) > 0 ? cout << t << " "
                      : cout << t << "\n";

  print(args...);
}

int main()
{
  print("hello", "world", 123123123, true);
}