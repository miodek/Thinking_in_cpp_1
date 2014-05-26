//: C14:Inheritance.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Proste dziedziczenie
#include "Useful.h"
#include <iostream>
using namespace std;

class Y : public X {
  int i; // Inne niz i klasy X
public:
  Y() { i = 0; }
  int change() {
    i = permute(); // Wywolanie funkcji o innej nazwie
    return i;
  }
  void set(int ii) {
    i = ii;
    X::set(ii); // Wywolanie funkcji o tej samej nazwie
  }
};

int main() {
  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(Y) = "
       << sizeof(Y) << endl;
  Y D;
  D.change();
  // Wykorzystanie funkcji interfejsu klasy X:
  D.read();
  D.permute();
  // Zdefiniowane ponownie funkcje zaslaniaja
  // funkcje klasy podstawowej:
  D.set(12);
} ///:~
