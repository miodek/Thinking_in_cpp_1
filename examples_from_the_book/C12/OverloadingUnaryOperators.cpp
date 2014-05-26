//: C12:OverloadingUnaryOperators.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;

// Funkcje niebedace funkcjami skladowymi:
class Integer {
  long i;
  Integer* This() { return this; }
public:
  Integer(long ll = 0) : i(ll) {}
  // Brak skutkow ubocznych - argumenty sa
  // referencjami do stalych:
  friend const Integer&
    operator+(const Integer& a);
  friend const Integer
    operator-(const Integer& a);
  friend const Integer
    operator~(const Integer& a);
  friend Integer*
    operator&(Integer& a);
  friend int
    operator!(const Integer& a);
  // Wystepuja skutki uboczne - argumenty nie sa
  // referencjami do stalych:
  // Operator przedrostkowy:
  friend const Integer&
    operator++(Integer& a);
  // Operator przyrostkowy:
  friend const Integer
    operator++(Integer& a, int);
  // Operator przedrostkowy:
  friend const Integer&
    operator--(Integer& a);
  // Operator przyrostkowy:
  friend const Integer
    operator--(Integer& a, int);
};

// Operatory globalne:
const Integer& operator+(const Integer& a) {
  cout << "+Integer\n";
  return a; // Jednoargumentowy operator + nic nie robi
}
const Integer operator-(const Integer& a) {
  cout << "-Integer\n";
  return Integer(-a.i);
}
const Integer operator~(const Integer& a) {
  cout << "~Integer\n";
  return Integer(~a.i);
}
Integer* operator&(Integer& a) {
  cout << "&Integer\n";
  return a.This(); // &a jest rekurencyjne!
}
int operator!(const Integer& a) {
  cout << "!Integer\n";
  return !a.i;
}
// Operator przedrostkowy - zwraca wartosc po inkrementacji:
const Integer& operator++(Integer& a) {
  cout << "++Integer\n";
  a.i++;
  return a;
}
// Operator przyrostkowy - zwraca wartosc przed inkrementacja:
const Integer operator++(Integer& a, int) {
  cout << "Integer++\n";
  Integer before(a.i);
  a.i++;
  return before;
}
// Operator przedrostkowy - zwraca wartosc po dekrementacji:
const Integer& operator--(Integer& a) {
  cout << "--Integer\n";
  a.i--;
  return a;
}
// Operator przyrostkowy - zwraca wartosc przed dekrementacja:
const Integer operator--(Integer& a, int) {
  cout << "Integer--\n";
  Integer before(a.i);
  a.i--;
  return before;
}

// Prezentacja dzialania przeciazanych operatorow:
void f(Integer a) {
  +a;
  -a;
  ~a;
  Integer* ip = &a;
  !a;
  ++a;
  a++;
  --a;
  a--;
}

// Funkcje skladowe (niejawny argument "this"):
class Byte {
  unsigned char b;
public:
  Byte(unsigned char bb = 0) : b(bb) {}
  // Brak skutkow ubocznych - stale funkcje skladowe:
  const Byte& operator+() const {
    cout << "+Byte\n";
    return *this;
  }
  const Byte operator-() const {
    cout << "-Byte\n";
    return Byte(-b);
  }
  const Byte operator~() const {
    cout << "~Byte\n";
    return Byte(~b);
  }
  Byte operator!() const {
    cout << "!Byte\n";
    return Byte(!b);
  }
  Byte* operator&() {
    cout << "&Byte\n";
    return this;
  }
  // Wystepuja skutki uboczne - funkcje skladowe
  // nie bedace stalymi:
  const Byte& operator++() { // Przedrostek
    cout << "++Byte\n";
    b++;
    return *this;
  }
  const Byte operator++(int) { // Przyrostek
    cout << "Byte++\n";
    Byte before(b);
    b++;
    return before;
  }
  const Byte& operator--() { // Przedrostek
    cout << "--Byte\n";
    --b;
    return *this;
  }
  const Byte operator--(int) { // Przyrostek
    cout << "Byte--\n";
    Byte before(b);
    --b;
    return before;
  }
};

void g(Byte b) {
  +b;
  -b;
  ~b;
  Byte* bp = &b;
  !b;
  ++b;
  b++;
  --b;
  b--;
}

int main() {
  Integer a;
  f(a);
  Byte b;
  g(b);
} ///:~
