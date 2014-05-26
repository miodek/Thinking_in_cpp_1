//: C10:NamespaceOverriding1.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "NamespaceMath.h"
int main() {
  using namespace Math;
  Integer a; // Zaslania Math::a;
  a.setSign(negative);
  // Teraz uzycie operatora zasiegu do
  // wybrania Math::a jest niezbedne:
  Math::a.setSign(positive);
} ///:~
