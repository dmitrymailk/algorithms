#include <iostream>
#include "./intSLList.h"

int main(int argc, char const *argv[])
{
  IntSLList *l_list = new IntSLList();

  IntSLLNode *l_node = new IntSLLNode(10);
  l_list->addToHead(123);
  l_list->addToHead(12);
  l_list->addToTail(32);
  l_list->addToTail(23);
  return 0;
}
