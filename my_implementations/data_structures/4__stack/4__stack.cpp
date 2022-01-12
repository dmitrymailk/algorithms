#include "./stack.cpp"

int main()
{
  Stack<int> *stack = new Stack<int>();
  stack->Push(10);
  stack->Push(11);
  stack->Push(12);
  stack->Push(13);

  // cout << stack.TopElement()->data << "\n";
}