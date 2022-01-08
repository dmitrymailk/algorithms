
class IntSLLNode
{
public:
  IntSLLNode()
  {
    next = 0;
  }
  IntSLLNode(int i, IntSLLNode *in = 0)
  {
    info = i;
    next = in;
  }
  int info;
  IntSLLNode *next;
};

int main(int argc, const char **argv)
{
  IntSLLNode *p = new IntSLLNode(10);
  p->next = new IntSLLNode(8);
  p->next->next = new IntSLLNode(123);
  return 0;
}