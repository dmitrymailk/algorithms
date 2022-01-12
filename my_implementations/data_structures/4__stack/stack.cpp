#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class NodeType>
class DoubleLinkedNode
{
public:
  DoubleLinkedNode *next;
  DoubleLinkedNode *prev;
  NodeType data;

  DoubleLinkedNode()
  {
    next = nullptr;
    prev = nullptr;
  }

  DoubleLinkedNode(NodeType _data,
                   DoubleLinkedNode *_next,
                   DoubleLinkedNode *_prev)
  {
    next = _next;
    prev = _prev;
    data = _data;
  }
};

template <class NodeType>
class Stack
{
private:
  DoubleLinkedNode<NodeType> *tail;
  int size;

public:
  Stack()
  {
    tail = new DoubleLinkedNode<NodeType>();
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
  void Push(NodeType _data)
  {
    DoubleLinkedNode<NodeType> *new_node = new DoubleLinkedNode<NodeType>(_data, tail, nullptr);
    tail->prev = new_node;
    tail = new_node;

    size += 1;
  }

  // удаляет элемент из стека
  NodeType Pop()
  {
    DoubleLinkedNode<NodeType> *top_elem = tail;
    tail = tail->next;
    tail->prev = nullptr;
    top_elem->next = nullptr;

    size -= 1;

    return top_elem->data;
  }

  // просто отдает верхний элемет из стека
  NodeType TopElement()
  {
    return tail->data;
  }
};
