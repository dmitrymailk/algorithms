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
  Stack<char> *open_brackets = new Stack<char>();

  // pair <char, bool, bool>

  auto it = file_content.begin();
  while (it != file_content.end())
  {
    char temp_char = *it;
    if (temp_char == '(' || temp_char == '[' || temp_char == '{')
    {
      open_brackets->Push(temp_char);
      it += 1;
    }
    else if (temp_char == ')' || temp_char == ']' || temp_char == '}')
    {
      char open_bracket = open_brackets->Pop();
      if (open_bracket != temp_char)
      {
        cout << "Error, expected" << open_bracket << " Got: " << temp_char << "\n";
      }
      break;
    }
    else if (temp_char == '/')
    {
      char next_char = *(it + 1);
      if (next_char == '*')
      {
        // пока не будет найдена строка */
        // или не достигнут конец файла выполнять поиск
        while (*it != '*' && *(it + 1) != '/' || it != file_content.end())
        {
          it += 1;
        }
        if (it == file_content.end())
        {
          cout << "Error: comment block isn't closed"
               << "\n";
          break;
        }
      }
      else
      {
        it += 1;
      }
    }
    else
      it += 1;
  }
}

int main()
{
  string file_content = read_file("./test_cpp_file_2");
  delimeter_matcher(file_content);
}