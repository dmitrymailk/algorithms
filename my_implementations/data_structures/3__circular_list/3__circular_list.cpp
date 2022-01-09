#include <iostream>
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

class CircularList
{
public:
  DoubleLinkedNode *tail;
  int size;
  CircularList()
  {
    size = 0;
  }

  void AddItem(int data)
  {
    if (size == 0)
    {
      tail = new DoubleLinkedNode(data, tail, tail);
      tail->prev = tail;
      tail->next = tail;
    }
    else if (size == 1)
    {
      DoubleLinkedNode *new_item = new DoubleLinkedNode(data, tail, tail);
      tail->prev = new_item;
      tail->next = new_item;
      tail = new_item;
    }
    else
    {
      DoubleLinkedNode *new_item = new DoubleLinkedNode(data, tail, tail->prev);
      new_item->next->prev = new_item;
      new_item->prev->next = new_item;
      tail = new_item;
    }
    size += 1;
  }
};

int main()
{
  CircularList *c_list = new CircularList();
  c_list->AddItem(10);
  c_list->AddItem(11);
  c_list->AddItem(12);
  c_list->AddItem(13);
  c_list->AddItem(14);
}