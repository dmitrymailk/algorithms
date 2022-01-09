#include <iostream>
#include <vector>
using namespace std;

class SinglyLinkedNode
{
public:
  SinglyLinkedNode *next;
  int data;
  SinglyLinkedNode()
  {
    data = 0;
    next = nullptr;
  }
  SinglyLinkedNode(int _data, SinglyLinkedNode *_next)
  {
    data = _data;
    next = _next;
  }
  ~SinglyLinkedNode()
  {
    delete &data;
    delete &next;
  }
};

class SingleLinkedList
{
public:
  SinglyLinkedNode *head;
  SingleLinkedList()
  {
    head = nullptr;
  }

  void AddItem(int data)
  {
    SinglyLinkedNode *temp = new SinglyLinkedNode(data, head);
    this->head = temp;
  }

  void RemoveItem()
  {
    if (head != 0)
    {
      SinglyLinkedNode *temp = head->next;
      delete head;
      head = temp;
    }
  }
};

int main()
{
  SingleLinkedList *s_list = new SingleLinkedList();
  s_list->AddItem(11);
  s_list->AddItem(12);
  s_list->AddItem(13);
  // сейчас они располагаются в памяти в обратном порядке head->13->12->11->0x0
  s_list->RemoveItem();
  s_list->RemoveItem();
  s_list->RemoveItem();
  s_list->RemoveItem();
  s_list->AddItem(10);
  s_list->AddItem(14);
  s_list->AddItem(15);
}