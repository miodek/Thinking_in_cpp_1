//: C10:UsingDeclaration1.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "UsingDeclaration.h"
void h() {
  using namespace U; // Dyrektywa using
  using V::f; // Deklaracja using
  f(); // Wywolanie V::f();
  U::f(); // Nazwa funkcji musi byc w pelni okreslona
}
int main() {} ///:~
