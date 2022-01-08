#include <iostream>
using namespace std;

// polymorphism обозначает способность принимать несколько форм
// в контексте ООП это обозначает то что одно и тоже имя функции в разных
// объектах обозначает множество других функций
class Class1
{
public:
  virtual void f()
  {
    cout << "Function f() in Class1\n";
  }
  void g()
  {
    cout << "Function g() in Class1\n";
  }
};
class Class2
{
public:
  virtual void f()
  {
    cout << "Function f() in Class2\n";
  }
  void g()
  {
    cout << "Function g() in Class2\n";
  }
};
class Class3
{
public:
  virtual void h()
  {
    cout << "Function h() in Class3\n";
  }
};

int main()
{
  Class1 object1, *p;
  Class2 object2;
  Class3 object3;
  p = &object1;
  p->f(); // Function f() in Class1
  p->g(); // Function g() in Class1
  p = (Class1 *)&object2;
  p->f(); // Function f() in Class2
  p->g(); // Function g() in Class1
  p = (Class1 *)&object3;
  // мы вызвали h() при вызове f() не потому что между ними есть какая-то связь
  // а потому что компилятор ищем виртуальную функцию с именем f, не находит и дает
  // первую попавшуюся
  p->f(); // Function h() in Class3
  p->g(); // Function g() in Class1
  // p->h(); // h() is not a member of Class1;

  // из консольного вывода можно увидеть что те функции, которые
  // были объявлены virtual они вызвались как и ожидалось, то есть они переназначились
  // просто void функции не изменили своего поведения
  // это связано с тем что решение какая функция будет исполнена принимается по разному
  // для virtual решение принимается про процессе исполнения кода (dynamic binding)
  // а для обычных на моменте компиляции (static binding)
  return 0;
}