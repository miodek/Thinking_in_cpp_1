//: C10:StaticObjectArrays.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Statyczne tablice obiektow klas
class X {
  int i;
public:
  X(int ii) : i(ii) {}
};

class Stat {
  // To nie dziala, ale byc moze
  // chcialbys tak wlasnie zrobic:
//!  static const X x(100);
  // Zarowno stale statyczne obiekty klas, jak 
  // takie, ktore nie sa stalymi, musza byc 
  // zainicjalizowane zewnetrznie:
  static X x2;
  static X xTable2[];
  static const X x3;
  static const X xTable3[];
};

X Stat::x2(100);

X Stat::xTable2[] = {
  X(1), X(2), X(3), X(4)
};

const X Stat::x3(100);

const X Stat::xTable3[] = {
  X(1), X(2), X(3), X(4)
};

int main() { Stat v; } ///:~
