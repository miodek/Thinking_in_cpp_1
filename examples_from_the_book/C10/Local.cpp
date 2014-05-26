//: C10:Local.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Skladowe statyczne i klasy lokalne
#include <iostream>
using namespace std;

// Zagniezdzona klasa MOZE posiadac statyczne
// dane skladowe:
class Outer {
  class Inner {
    static int i; // W porzadku
  };
};

int Outer::Inner::i = 47;

// Klasa lokalna nie moze posiadac statycznych
// danych skladowych:
void f() {
  class Local {
  public:
//! static int i;  // Blad
    // (Jak zostaloby zdefiniowane i?)
  } x;
} 

int main() { Outer x; f(); } ///:~
