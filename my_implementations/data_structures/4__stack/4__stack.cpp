#include "./stack.cpp"

int main()
{
  Stack *stack = new Stack();
  stack->Push(10);
  stack->Push(11);
  stack->Push(12);
  stack->Push(13);

  cout << stack->TopElement()->data << "\n";
}