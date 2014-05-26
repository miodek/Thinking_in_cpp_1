//: C10:OverridingAmbiguity.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "NamespaceMath.h"
#include "NamespaceOverriding2.h"
void s() {
  using namespace Math;
  using namespace Calculation;
  // Wszystko jest w porzadku, az do instrukcji:
  //! divide(1, 2); // Dwuznacznosc
}
int main() {} ///:~
