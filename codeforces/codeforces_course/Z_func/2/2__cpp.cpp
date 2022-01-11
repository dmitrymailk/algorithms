#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <regex>
using namespace std;

template <class T>
void print(vector<T> array)
{
  for (auto item : array)
    cout << item << " ";
  cout << "\n";
}

template <class T>
void print(T data)
{
  cout << data << "\n";
}

void print()
{
  cout << "\n";
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
  cout << t << " ";
  print(args...);
}

vector<string> split(const string str, const string regex_str = "\n")
{
  regex regexz(regex_str);
  vector<string> list(sregex_token_iterator(str.begin(), str.end(), regexz, -1),
                      sregex_token_iterator());
  return list;
}

int main()
{
  int data_amount = 4;
  string input_string = R"(abacaba
aaaa
barbarmiakirkudu
abaabaababaab)";
  // print("hello");

  /*
  возможно тут не надо считать в тупую,
  кажется это просто все множества входящие в подмножество,
  только эти множества должны быть рядом идущие
  */
  vector<string> dataset = split(input_string, "\n");

  for (string line : dataset)
  {
    // print(line);
    int line_size = line.size();
    int counter = 0;
    for (int i = 1; i < line.size(); i++)
    {
      // get prefix, sufix
      string prefix = line.substr(0, i);
      string sufix = line.substr(i, line_size - i);
      // print(prefix, sufix);
      // print("---------");
      // search prefix
      int prefix_len = prefix.size();
      int sufix_len = sufix.size();

      for (int pos = 0; pos < line_size - prefix_len; pos++)
      {
        string sub = line.substr(pos, prefix_len);
        if (sub == prefix && sub != sufix)
          counter += 1;
      }

      for (int pos = 0; pos < line_size - sufix_len; pos++)
      {
        string sub = line.substr(pos, sufix_len);
        if (sub != prefix && sub == sufix)
          counter += 1;
      }
    }
    print(counter);
  }
}

/*
a bacaba 
ab acaba 
aba caba
abac aba
abaca ba
abacab a


*/