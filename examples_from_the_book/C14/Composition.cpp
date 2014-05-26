//: C14:Composition.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Powtorne wykorzystanie kodu za pomoca kompozycji
#include "Useful.h"

class Y {
  int i;
public:
  X x; // Osadzony obiekt
  Y() { i = 0; }
  void f(int ii) { i = ii; }
  int g() const { return i; }
};

int main() {
  Y y;
  y.f(47);
  y.x.set(37); // Dostep do osadzonego obiektu
} ///:~
