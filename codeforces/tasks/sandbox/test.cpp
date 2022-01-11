#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
  cout << "Start program"
       << "\n";
  const char *env_p = getenv("codeforces1");
  if (env_p)
  {
    string new_str(env_p);
    if (new_str == "dimweb")
      cout << "Ok"
           << "\n";
  }

  cout << "end"
       << "\n";
}