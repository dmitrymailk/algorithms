#include <iostream>
using namespace std;

double f(double x)
{
  return 1 * x;
}

// такое определение позволит предавать нам функцию по ссылке как обычную переменную
// причем если бы мы написали
// double *f(double)
// то это бы значило то, что мы объявили функцию которая возвращает указатель
// на переменную типа double
double sum(double (*f)(double), int n, int m)
{
  double result = 0;
  for (int i = n; i <= m; i++)
    result += f(i);
  return result;
}

int main()
{
  // 1 + 2 + 3 + 4 = 10
  double res = sum(f, 1, 4); // res = 10
  cout << sum(f, 1, 4) << endl;
}