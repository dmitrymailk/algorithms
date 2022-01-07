#include <iostream>
using namespace std;

void f1(int i, int *j, int &k)
{
  i = 1;
  *j = 2;
  k = 3;
}

int &f2(int a[], const int i)
{
  return a[i];
}

int *f3(int a[], int i)
{
  return &a[i];
}

class C
{
public:
  int &getRefN()
  {
    return n;
  }
  int getN()
  {
    return n;
  }

private:
  int n;
};

int main()
{
  int n = 5, *p = &n, &r = n;

  cout << n << ' ' << *p << ' ' << r << endl;
  n = 10;
  cout << n << ' ' << *p << ' ' << r << endl;
  *p = 7;
  cout << n << ' ' << *p << ' ' << r << endl;
  r = 3;
  cout << n << ' ' << *p << ' ' << r << endl;
  // мы могли использовать вместо записи int &r = n;
  // запись int *const r = &n;
  int *const r2 = &n;
  // важно четко различать int *const и const int *
  // const int * это ссылка на константную переменную
  const int m = 123;
  const int *s = &m;

  // int *const это переменная ссылочного типа, которая константа
  // то есть адрес ее не меняется, значение может менятся
  // как это видели выше
  *r2 = 123;

  // изменять переменные по ссылке полезно при использовании функций
  int n1 = 4, n2 = 5, n3 = 6;
  f1(n1, &n2, n3);
  // в итоге n1 = 4, n2 = 2, n3 = 3

  // также можно объявить функцию, которая будет возвращать
  // адрес на участок памяти
  // можно сказать что конструкция int &var_name
  // дает новое имястарым переменным
  // и любые изменения с var_name или прошлыми переменными, повлияет на них всех
  // также конструкция int& не создает копию объекта при передаче в функцию
  /*
  A reference variable is an alias, that is, another name for an already existing variable.
  Once a reference is initialized with a variable, either the variable name or the
  reference name may be used to refer to the variable.
  */
  int a[] = {1, 2, 3, 4, 5};
  n = f2(a, 3);
  f2(a, 3) = 6;

  // альтернатива операциям выше может служить следующий код
  int *a_p3 = f3(a, 3);
  *f3(a, 3) = 123; // изменит a[3] на 123
  // мы получаем указатель на память массива 3 элемента
  // соответствено согласно указательной арифметике мы сможем
  // обратиться к следующему элементу и изменить его
  *(a_p3 + 1) = 8; // изменит a[4] на 8

  // но references стоит использовать с осторожностью, так как это может открыть
  // скрытые переменные
  C c;
  int &k = c.getRefN();
  k = 7;
  cout << c.getN() << "\n"; // вывод 7
  // видно что переменная n была объявлена private, и по правилам мы не можем ее изменять
  // но в консоли можно увидеть число 7, а значит мы имеем доступ к переменной, к которой не должны
  c.getRefN() = 9;
  cout << c.getN() << "\n"; // вывод 9
}