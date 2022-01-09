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

class DoubleLinkedList
{
public:
  DoubleLinkedNode *head;
  DoubleLinkedNode *tail;
  int size;
  DoubleLinkedList()
  {
    head = new DoubleLinkedNode();
    tail = new DoubleLinkedNode();
    size = 0;
  }

  void AddItem(int data)
  {
    if (size == 0)
    {
      DoubleLinkedNode *new_item = new DoubleLinkedNode(data, head, head);
      head = new_item;
      tail = new_item;
    }
    else
    {
      DoubleLinkedNode *new_item = new DoubleLinkedNode(data, head, nullptr);
      head->prev = new_item;
      head = new_item;
    }
    size += 1;
  }

  void DeleteItemHead()
  {
    if (size == 0)
    {
      return;
    }
    else if (size == 1)
    {
      delete head;
      delete tail;
    }
    else
    {
      DoubleLinkedNode *temp = head->next;
      delete head;
      temp->prev = nullptr;
      head = temp;
      size -= 1;
    }
  }
};

int main()
{
  DoubleLinkedList *d_list = new DoubleLinkedList();
  d_list->AddItem(10);
  d_list->AddItem(11);
  d_list->AddItem(12);
  d_list->DeleteItemHead();
  d_list->DeleteItemHead();
  d_list->DeleteItemHead();
  d_list->DeleteItemHead();
  d_list->DeleteItemHead();
}