#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

#include "../4__stack/stack.cpp"

string read_file(string filename)
{
  // solution from https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
  ifstream file(filename);
  string file_content;
  stringstream file_stream;
  if (file.is_open())
  {
    file_stream << file.rdbuf();
    file_content = file_stream.str();
    file.close();
  }
  else
  {
    file_content = "";
  }

  return file_content;
}

void delimeter_matcher(string file_content)
{
  Stack<string> *open_brackets = new Stack<string>();
}

int main()
{
  // string file_content = read_file("./test_cpp_file");
  // cout << file_content << "\n";
  Stack<string> *open_brackets = new Stack<string>();
  open_brackets->Push("qweqwe");
  open_brackets->Push("qweqwe123");
  open_brackets->Push("qweqwe345");
}