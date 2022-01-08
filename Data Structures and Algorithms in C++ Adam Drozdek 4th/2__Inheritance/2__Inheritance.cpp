#include <iostream>
using namespace std;

class BaseClass
{
public:
  BaseClass() {}
  void public_func(const char *s = "unknown")
  {
    cout << "Function public_func() in BaseClass called from " << s << endl;
    private_func();
  }

protected:
  void protected_func(const char *s = "unknown")
  {
    cout << "Function protected_func() in BaseClass called from " << s << endl;
  }

private:
  void private_func()
  {
    cout << "Function private_func() in BaseClass\n";
  }
};
class Derived1Level1 : public virtual BaseClass
{
public:
  void public_func(const char *s = "unknown")
  {
    cout << "Function public_func() in Derived1Level1 called from " << s << endl;
    protected_func("Derived1Level1");
    private_func("Derived1Level1");
  }
  void private_func(const char *s = "unknown")
  {
    cout << "Function private_func() in Derived1Level1 called from " << s << endl;
  }
};
class Derived2Level1 : public virtual BaseClass
{
public:
  void public_func(const char *s = "unknown")
  {
    cout << "Function public_func() in Derived2Level1 called from " << s << endl;
    protected_func("Derived2Level1");
    // private_func(); // error: BaseClass::private_func() is not accessible
  }
};

/*
However, DerivedLevel2 also inherits the same member functions from BaseClass twice
because both classes used in the definition of DerivedLevel2
are derived from BaseClass. This is redundant at best, and at worst can
cause a compilation error, "member is ambiguous BaseClass::g() and
BaseClass::g()." To prevent this from happening, the definitions of the
two classes include the modifier virtual, which means that DerivedLevel2
contains only one copy of each member function from BaseClass. A similar problem
arises if f() in DerivedLevel2 calls h() without the preceding
scope operator and class name, Derived1Level1::h(). It does not matter
that h() is private in BaseClass and inaccessible to DerivedLevel2. An
error would be printed, "member is ambiguous Derived1Level1::h() and
BaseClass::h()."
*/
class DerivedLevel2 : public Derived1Level1, public Derived2Level1
{
public:
  void public_func(const char *s = "unknown")
  {
    cout << "Function public_func() in DerivedLevel2 called from " << s << endl;
    protected_func("DerivedLevel2");
    Derived1Level1::private_func("DerivedLevel2");
    BaseClass::public_func("DerivedLevel2");
  }
};

int main()
{
  BaseClass bc;
  Derived1Level1 d1l1;
  Derived2Level1 d2l1;
  DerivedLevel2 dl2;
  bc.public_func("main(1)");
  // bc.protected_func(); // error: BaseClass::protected_func() is not accessible
  // bc.private_func(); // error: BaseClass::private_func() is not accessible
  d1l1.public_func("main(2)");
  // d1l1.protected_func(); // error: BaseClass::protected_func() is not accessible
  d1l1.private_func("main(3)");

  d2l1.public_func("main(4)");
  // d2l1.protected_func(); // error: BaseClass::protected_func() is not accessible
  // d2l1.private_func(); // error: BaseClass::private_func() is not accessible

  dl2.public_func("main(5)");
  // dl2.protected_func(); // error: BaseClass::protected_func() is not accessible
  dl2.private_func();
  return 0;
}