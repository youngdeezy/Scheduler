  #ifdef CONTAINER_H
  #define CONTAINER_H
  #include <iostream>
  #include <string>
  using namespace std;
 
  template <class C>
  class Container {
 public:
 Container(C thing);
 ~Container();
 C GetThing();
 private:
 C m_thing;
};

template <class C>
Container<C>::Container(C thing) {
m_thing = thing;
}

template <class C>
Container<C>::~Container() {
delete m_thing;
}

template <class C>
C Container<C>::GetThing(){
return m_thing;
}

int main () {
int* int1 = new int(10);
string* string1 = string("test1");
Container<int*> bag1(int1);
cout << bag1.GetThing() << endl;
cout << bag2.GetThing() << endl;
}
#endif