//: C03:PointerToFunction.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Definicja i wykorzystanie wskaznika do funkcji
#include <iostream>
using namespace std;

void func() {
  cout << "func() wywolana..." << endl;
}

int main() {
  void (*fp)();  // Definicja wskaznika do funkcji
  fp = func;  // Inicjalizacja wskaznika
  (*fp)();    // Wyluskanie powoduje wywolanie funkcji
  void (*fp2)() = func;  // Definicja i inicjalizacja
  (*fp2)();
} ///:~
