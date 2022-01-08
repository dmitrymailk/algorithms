
#include <iostream>
using namespace std;

/*
An object in OOL is like a watch. As users, we are interested in what the hands
show, but not in the inner workings of the watch. We are aware that there are gears
and springs inside the watch, but because we usually know very little about why all
these parts are in a particular configuration, we should not have access to this mechanism
so that we do not damage it, inadvertently or on purpose. This mechanism is
hidden from us, we have no immediate access to it, and the watch is protected and
works better than when its mechanism is open for everyone to see.
*/

class C
{
public:
  C(char *s = "", int i = 0, double d = 1)
  {
    strcpy(dataMember1, s);
    dataMember2 = i;
    dataMember3 = d;
  }
  void memberFunction1()
  {
    cout << dataMember1 << ' ' << dataMember2 << ' '
         << dataMember3 << endl;
  }
  void memberFunction2(int i, char *s = "unknown")
  {
    dataMember2 = i;
    cout << i << " received from " << s << endl;
  }

protected:
  char dataMember1[20];
  int dataMember2;
  double dataMember3;
};

C object1("object1", 100, 2000), object2("object2"), object3;

template <class genType>
class genClass
{
  genType storage[50];
  //  ...................
};

genClass<int> intObject;
genClass<float> floatObject;

template <class genType, int size = 50>
class genClass2
{
  genType storage[size];
  // ..................
};

genClass2<int> intObject1; // use the default size;
genClass2<int, 100> intObject2;
genClass2<float, 123> floatObject;

template <class genType>
void swap(genType &el1, genType &el2)
{
  genType tmp = el1;
  el1 = el2;
  el2 = tmp;
}