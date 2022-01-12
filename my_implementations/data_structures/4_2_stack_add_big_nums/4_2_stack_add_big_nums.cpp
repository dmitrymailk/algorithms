#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../4__stack/stack.cpp"

// пока что только для сложения
class BigNum
{
  Stack<char> *data;

public:
  string print_num;

  BigNum()
  {
    data = new Stack<char>();
  }

  BigNum(string &number)
  {
    data = new Stack<char>();
    print_num = number;

    for (int i = 0; i < number.length(); i++)
    {
      char digit = number[i] - '0';

      data->Push(digit);
    }
  }
  bool IsEmpty()
  {
    return data->IsEmpty();
  }

  BigNum operator+(BigNum number)
  {
    BigNum result;
    char remainder = 0;
    char overflow = 0;
    int length = min(Size(), number.Size());

    for (int i = 0; i < length; i++)
    {
      char num_1 = this->GetNumber();
      char num_2 = number.GetNumber();
      char res = num_1 + num_2 + overflow;
      remainder = res % 10;
      overflow = (char)(res > 9);
      result.Push(remainder);
    }

    if (Size() > number.Size())
    {
      char num = GetNumber();
      num += overflow;
      result.Push(num);
      if (Size() > 0)
        while (Size() > 0)
        {
          num = GetNumber();
          result.Push(num);
        }
    }
    else if (Size() < number.Size())
    {
      char num = number.GetNumber();
      num += overflow;
      result.Push(num);
      if (number.Size() > 0)
        while (number.Size() > 0)
        {
          num = number.GetNumber();
          result.Push(num);
        }
    }
    else
    {
      if (overflow != 0)
        result.Push(1);
    }

    return result;
  }

  void Push(char digit)
  {
    data->Push(digit);
    print_num.insert(0, 1, digit + '0');
  }

  int Size()
  {
    return data->Size();
  }

  char GetNumber()
  {
    return data->Pop();
  }

  friend ostream &operator<<(ostream &os, BigNum &big_num);
};

// https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
ostream &operator<<(ostream &os, BigNum &big_num)
{
  os << big_num.print_num;
  return os;
}

int main()
{
  // https: // www.calculator.net/big-number-calculator.html?cx=12983817324582304570298347590283745928347509823745982374598273452394875698327598723694573269874569823759&cy=67234656734290909298434578784376734567432677787784327673247632476234276213487349808934980897023467&cp=20&co=plus
  string s_num1 = "12983817324582304570298347590283745928347509823745982374598273452394875698327598723694573269874569823759";
  string s_num2 = "67234656734290909298434578784376734567432677787784327673247632476234276213487349808934980897023467";
  BigNum *num1 = new BigNum(s_num1);
  BigNum *num2 = new BigNum(s_num2);
  BigNum num3 = *num1 + *num2;
  cout << num3 << "\n";
}