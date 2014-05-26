//: C12:OperatorOverloadingSyntax.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;

class Integer {
  int i;
public:
  Integer(int ii) : i(ii) {}
  const Integer
  operator+(const Integer& rv) const {
    cout << "operator+" << endl;
    return Integer(i + rv.i);
  }
  Integer&
  operator+=(const Integer& rv) {
    cout << "operator+=" << endl;
    i += rv.i;
    return *this;
  }
};

int main() {
  cout << "typy wbudowane:" << endl;
  int i = 1, j = 2, k = 3;
  k += i + j;
  cout << "typy zdefiniowane przez uzytkownika:" << endl;
  Integer ii(1), jj(2), kk(3);
  kk += ii + jj;
} ///:~
