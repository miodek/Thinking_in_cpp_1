//: C14:OperatorInheritance.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Dziedziczenie przeciazonych operatorow
#include "../C12/Byte.h"
#include <fstream>
using namespace std;
ofstream out("ByteTest.out");

class Byte2 : public Byte {
public:
  // Konstruktory nie sa dziedziczone:
  Byte2(unsigned char bb = 0) : Byte(bb) {}  
  // operator= nie podlega dziedziczeniu, ale jest
  // generowany dla przypisania za posrednictwem 
  // elementow skladowych. Jednakze, generowany 
  // jest tylko operator= umozliwiajacy przypisanie 
  // w stosunku obiektow tego samego typu, wiec inne
  // operatory przypisania musza byc utworzone jawnie:
  Byte2& operator=(const Byte& right) {
    Byte::operator=(right);
    return *this;
  }
  Byte2& operator=(int i) { 
    Byte::operator=(i);
    return *this;
  }
};

// Funkcje testowe podobne do zawartych w pliku C12:ByteTest.cpp:
void k(Byte2& b1, Byte2& b2) {
  b1 = b1 * b2 + b2 % b1;

  #define TRY2(OP) \
    out << "b1 = "; b1.print(out); \
    out << ", b2 = "; b2.print(out); \
    out << ";  b1 " #OP " b2 daje "; \
    (b1 OP b2).print(out); \
    out << endl;

  b1 = 9; b2 = 47;
  TRY2(+) TRY2(-) TRY2(*) TRY2(/)
  TRY2(%) TRY2(^) TRY2(&) TRY2(|)
  TRY2(<<) TRY2(>>) TRY2(+=) TRY2(-=)
  TRY2(*=) TRY2(/=) TRY2(%=) TRY2(^=)
  TRY2(&=) TRY2(|=) TRY2(>>=) TRY2(<<=)
  TRY2(=) // Operator przypisania

  // Operatory warunkowe:
  #define TRYC2(OP) \
    out << "b1 = "; b1.print(out); \
    out << ", b2 = "; b2.print(out); \
    out << ";  b1 " #OP " b2 daje "; \
    out << (b1 OP b2); \
    out << endl;

  b1 = 9; b2 = 47;
  TRYC2(<) TRYC2(>) TRYC2(==) TRYC2(!=) TRYC2(<=)
  TRYC2(>=) TRYC2(&&) TRYC2(||)

  // Przypisanie lancuchowe:
  Byte2 b3 = 92;
  b1 = b2 = b3;
}

int main() {
  out << "funkcje skladowe:" << endl;
  Byte2 b1(47), b2(9);
  k(b1, b2);
} ///:~
