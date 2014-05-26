//: C10:Singleton.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Statyczna skladowa tego samego typu gwarantuje
// ze istnieje tylko jeden obiekt tego typu.
// Jest to rowniez nazywane wzorcem "singla".
#include <iostream>
using namespace std;

class Egg {
  static Egg e;
  int i;
  Egg(int ii) : i(ii) {}
  Egg(const Egg&); // Blokada konstruktora kopiujacego
public:
  static Egg* instance() { return &e; }
  int val() const { return i; }
};

Egg Egg::e(47);

int main() {
//!  Egg x(1); // Blad - nie mozna utworzyc obiektu klasy Egg
  // Mozna odwolywac siê tylko do jej pojedynczego egzemplarza:
  cout << Egg::instance()->val() << endl;
} ///:~
