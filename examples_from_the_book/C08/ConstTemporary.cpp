//: C08:ConstTemporary.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Obiekty tymczasowe sa stalymi

class X {};

X f() { return X(); } // Wynik zwracany przez wartosc

void g1(X&) {} // Przekazywanie przez referencje nie do stalej
void g2(const X&) {} // Przekazywanie przez referencje do stalej

int main() {
  // Blad: staly obiekt tymczasowy tworzony przez f():
//!  g1(f());
  // W porzadku: g2 pobiera referencje do stalej:
  g2(f());
} ///:~
