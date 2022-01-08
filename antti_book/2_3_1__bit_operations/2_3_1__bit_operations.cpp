#include <iostream>
using namespace std;

int main()
{

  int x = 3;
  // logical AND
  if ((x & 1) == 0)
    cout << "even\n";
  else
    cout << "odd\n";
  cout << (x & 1) << "\n";

  // logical OR
  cout << (22 | 26) << "\n"; // 30

  // logical XOR
  /*
  0 & 0 -> 0
  1 & 1 -> 0
  1 & 0 -> 1
  0 & 1 -> 1
  */
  cout << (22 ^ 26) << "\n"; // 12

  // logical NOT
  x = 29;
  cout << (~x) << "\n"; // -30

  // shift
  // операция сдвига влево x << k дописывает в конец k нулей
  // операция сдвига вправо x >> удаляет с конца k бит
  cout << (14 << 2) << "\n"; // 56
  cout << (56 >> 2) << "\n"; // 14

  // create double number representation
  x = 1234;
  int array_x[32];
  for (int k = 31; k >= 0; k--)
  {
    // (1 << k) - это битовая маска, которая содержит k нулей справа к 1
    if (x & (1 << k))
      array_x[31 - k] = 1;
    else
      array_x[31 - k] = 0;
  }
  for (int i = 0; i < 32; i++)
  {
    cout << array_x[i];
  }
  cout << "\n";

  // функции втроенные в компилятор для работы с битовыми представлениями
  /*
  • __builtin_clz(x): количество нулей в начале двоичного представления;
  • __builtin_ctz(x): количество нулей в конце двоичного представления;
  • __builtin_popcount(x): количество единиц в двоичном представлении;
  • __builtin_parity(x): четность количества единиц в двоичном представлении.
  */
  x = 5328;                              // 00000000000000000001010011010000
  cout << __builtin_clz(x) << "\n";      // 19
  cout << __builtin_ctz(x) << "\n";      // 4
  cout << __builtin_popcount(x) << "\n"; // 5
  // cout << __builtin_parity(x) << "\n";   // 1 - подчеркивает, но мой компилятор выполняет эту команду
}