#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DoubleLinkedNode
{
public:
  DoubleLinkedNode *next;
  DoubleLinkedNode *prev;
  int data;
  DoubleLinkedNode()
  {
    next = nullptr;
    prev = nullptr;
    data = 0;
  }

  DoubleLinkedNode(int _data,
                   DoubleLinkedNode *_next,
                   DoubleLinkedNode *_prev)
  {
    next = _next;
    prev = _prev;
    data = _data;
  }
};

class Stack
{
private:
  DoubleLinkedNode *tail;
  int size;

public:
  Stack()
  {
    tail = new DoubleLinkedNode();
    size = 0;
  }

  // полностью очищает стек
  void Clear()
  {
    while (tail->next != nullptr)
      Pop();
  }

  // проверка на пустоту стека
  bool IsEmpty()
  {
    return size == 0;
  }

  // добавляет новый элемент в стек
  void Push(int _data)
  {
    DoubleLinkedNode *new_node = new DoubleLinkedNode(_data, tail, nullptr);
    tail->prev = new_node;
    tail = new_node;

    size += 1;
  }

  // удаляет элемент из стека
  DoubleLinkedNode *Pop()
  {
    DoubleLinkedNode *top_elem = tail;
    tail = tail->next;
    tail->prev = nullptr;
    top_elem->next = nullptr;

    size -= 1;

    return top_elem;
  }

  // просто отдает верхний элемет из стека
  DoubleLinkedNode *TopElement()
  {
    return tail;
  }
};
