// task: https://codeforces.com/contest/1621/problem/A
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
  cout << "hello"
       << "\n";
}