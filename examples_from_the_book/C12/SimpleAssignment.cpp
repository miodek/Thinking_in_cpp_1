//: C12:SimpleAssignment.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prosty operator=()
#include <iostream>
using namespace std;

class Value {
  int a, b;
  float c;
public:
  Value(int aa = 0, int bb = 0, float cc = 0.0)
    : a(aa), b(bb), c(cc) {}
  Value& operator=(const Value& rv) {
    a = rv.a;
    b = rv.b;
    c = rv.c;
    return *this;
  }
  friend ostream&
  operator<<(ostream& os, const Value& rv) {
    return os << "a = " << rv.a << ", b = "
      << rv.b << ", c = " << rv.c;
  }
};

int main() {
  Value a, b(1, 2, 3.3);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  a = b;
  cout << "a po przypisaniu: " << a << endl;
} ///:~
