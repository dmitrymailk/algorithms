#include <string.h>
#include <iostream>
using namespace std;

struct Node
{
  char *name;
  int age;
  Node(const char *n = "", int a = 0)
  {
    name = strdup(n);
    age = a;
  }
};

struct Node2
{
  char *name;
  int age;
  Node2(const char *n = 0, int a = 0)
  {
    name = strdup(n);
    age = a;
  }
  Node2(const Node2 &n)
  { // copy constructor;
    name = strdup(n.name);
    age = n.age;
  }
};

struct Node3
{
  char *name;
  int age;
  Node3(const char *n = 0, int a = 0)
  {
    name = strdup(n);
    age = a;
  }
  Node3(const Node3 &n)
  { // copy constructor;
    name = strdup(n.name);
    age = n.age;
  }
  Node3 &operator=(const Node3 &n)
  {
    if (this != &n)
    {
      // no assignment to itself;
      if (name != 0)
        free(name);
      name = strdup(n.name);
      age = n.age;
    }
    return *this;
  }
};

int main(int argc, const char **argv)
{
  // мы создаем 2 как бы "независимых" объекта,
  // инициализируя второй с теми же данными что и первый

  Node node1("Roger", 20), node2(node1); // or node2 = node1;

  // вроде бы изменяем имя только второму объекту
  strcpy(node2.name, "Wendy");
  node2.age = 30;

  // но оказывается что мы изменили и первый объект
  cout << node1.name << ' ' << node1.age << ' ' << node2.name << ' ' << node2.age << "\n";
  // так как мы не определили свой конструктор, компилятор сделал свой конструктор
  // который выполнил member-by-member копирование. Поэтому ссылка указывала на
  // один и тот же участок памяти  чтобы исправить это нужно объявить правильный конструктор Node2

  Node2 node12("Roger", 20), node22(node12);
  strcpy(node22.name, "Wendy");
  node22.age = 30;
  cout << node12.name << ' ' << node12.age << ' ' << node22.name << ' ' << node22.age << "\n";
  // теперь видно что описанная выше проблема ушла, объекты имеют разные имена
  // но часто по привычке используют следующую операцию

  Node node13("Roger", 20), node23;
  // member-by-member copying, имеет ту же самую проблему что
  // и ранее они ссылаются на один и тот же участок памяти
  node23 = node13;

  strcpy(node23.name, "Wendy");
  node23.age = 30;
  cout << node13.name << ' ' << node13.age << ' ' << node23.name << ' ' << node23.age << "\n";

  // для этого необходимо написать свой оператор,
  // который выполнит правильное копирование
  Node3 node14("Roger", 20), node24;
  node24 = node14;
  strcpy(node24.name, "Wendy");
  node24.age = 30;
  cout << node14.name << ' ' << node14.age << ' ' << node24.name << ' ' << node24.age << "\n";
  return 0;
}