//: C06:Multiarg.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Konstruktory z wieloma argumentami,
// uzywane do inicjalizacji agregatowej
#include <iostream>
using namespace std;

class Z {
  int i, j;
public:
  Z(int ii, int jj);
  void print();
};

Z::Z(int ii, int jj) {
  i = ii;
  j = jj;
}

void Z::print() {
  cout << "i = " << i << ", j = " << j << endl;
}

int main() {
  Z zz[] = { Z(1,2), Z(3,4), Z(5,6), Z(7,8) };
  for(int i = 0; i < sizeof zz / sizeof *zz; i++)
    zz[i].print();
} ///:~
