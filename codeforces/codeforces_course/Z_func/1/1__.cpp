#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <vector>
using namespace std;

string read_text(const string filename = "data")
{
  string line, temp;
  ifstream myfile(filename);
  if (myfile.is_open())
  {
    while (getline(myfile, temp))
    {
      line += temp + "\n";
    }
    myfile.close();
  }
  else
  {
    cout << "Unable to open file";
    exit(1);
  }
  return line;
}

vector<string> split(string text, const string delimiter = " ")
{
  string ends_of_word = delimiter;
  vector<string> words;
  int start = 0;
  for (int i = 0; i < text.size(); i++)
  {
    for (int j = 0; j < ends_of_word.size(); j++)
    {
      if (text[i] == ends_of_word[j])
      {
        string sub_str = text.substr(start, i - start);
        if (sub_str.size() > 0)
          words.push_back(sub_str);
        start = i + 1;
      }
    }
  }

  return words;
}

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
  string text = read_text();
  vector<string> dataset = split(text, "\n");
  int data_amount = 8;

  for (auto line : dataset)
  {
    int line_len = line.size();
    for (int i = line_len - 1; i >= 0; i--)
    {
      bool correct = true;
      for (int j = 0; j <= i / 2; j++)
      {
        if (line[j] != line[i - j])
        {
          correct = false;
          break;
        }
      }

      if (correct)
      {
        print(i + 1);
        break;
      }
    }
  }
}