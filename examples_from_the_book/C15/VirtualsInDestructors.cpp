//: C15:VirtualsInDestructors.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wirtualne wywolania w destruktorach
#include <iostream>
using namespace std;

class Base {
public:
  virtual ~Base() { 
    cout << "Base1()\n"; 
    f(); 
  }
  virtual void f() { cout << "Base::f()\n"; }
};

class Derived : public Base {
public:
  ~Derived() { cout << "~Derived()\n"; }
  void f() { cout << "Derived::f()\n"; }
};

int main() {
  Base* bp = new Derived; // Rzutowanie w gore
  delete bp;
} ///:~
