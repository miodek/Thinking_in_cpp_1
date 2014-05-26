//: C05:Private.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Okreslanie granicy

struct B {
private:
  char j;
  float f;
public:
  int i;
  void func();
};

void B::func() {
  i = 0;
  j = '0';
  f = 0.0;
};

int main() {
  B b;
  b.i = 1;    // OK, skladowa publiczna
//!  b.j = '1';  // Niedozwolone, skladowa prywatna
//!  b.f = 1.0;  // Niedozwolone, skladowa prywatna
} ///:~
