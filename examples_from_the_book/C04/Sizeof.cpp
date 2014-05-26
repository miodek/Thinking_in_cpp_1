//: C04:Sizeof.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wielkosci struktur
#include "CLib.h"
#include "CppLib.h"
#include <iostream>
using namespace std;

struct A {
  int i[100];
};

struct B {
  void f();
};

void B::f() {}

int main() {
  cout << "wielkosc struktury A = " << sizeof(A)
       << " bajtow" << endl;
  cout << "wielkosc struktury B = " << sizeof(B)
       << " bajtow" << endl;
  cout << "wielkosc CStash w C = " 
       << sizeof(CStash) << " bajtow" << endl;
  cout << "wielkosc Stash w C++ = " 
       << sizeof(Stash) << " bajtow" << endl;
} ///:~
