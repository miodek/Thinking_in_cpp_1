//: C10:Technique2.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include "Dependency2.h"
using namespace std;

// Funkcja zwraca wartosc, dzieki czemu
// moze zostac wywolana jako globalny inicjator:
int separator() {
  cout << "---------------------" << endl;
  return 1;
}

// Symulacja problemu zaleznosci:
extern Dependency1 dep1;
Dependency2 dep2(dep1);
Dependency1 dep1;
int x1 = separator();

// Ale w tej kolejnosci wszystko jest w porzadku:
Dependency1 dep1b;
Dependency2 dep2b(dep1b);
int x2 = separator();

// Umieszczenie statycznych obiektow w funkcjach
// zapewnia prawidlowe dzialanie
Dependency1& d1() {
  static Dependency1 dep1;
  return dep1;
}

Dependency2& d2() {
  static Dependency2 dep2(d1());
  return dep2;
}

int main() {
  Dependency2& dep2 = d2();
} ///:~
