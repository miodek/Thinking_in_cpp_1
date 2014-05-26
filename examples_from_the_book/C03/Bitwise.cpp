//: C03:Bitwise.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
//{L} printBinary
// Demonstracja operacji na bitach
#include "printBinary.h"
#include <iostream>
using namespace std;

// Makroinstrukcja, pozwalajaca oszczedzic na pisaniu:
#define PR(STR, EXPR) \
  cout << STR; printBinary(EXPR); cout << endl;  

int main() {
  unsigned int getval;
  unsigned char a, b;
  cout << "Wprowadz liczbe z zakresu od 0 do 255: ";
  cin >> getval; a = getval;
  PR("a w zapisie dwojkowym: ", a);
  cout << "Wprowadz liczbe z zakresu od 0 do 255: ";
  cin >> getval; b = getval;
  PR("b w zapisie dwojkowym: ", b);
  PR("a | b = ", a | b);
  PR("a & b = ", a & b);
  PR("a ^ b = ", a ^ b);
  PR("~a = ", ~a);
  PR("~b = ", ~b);
  // Interesujaca sekwencja bitow:
  unsigned char c = 0x5A; 
  PR("c w zapisie dwojkowym: ", c);
  a |= c;
  PR("a |= c; a = ", a);
  b &= c;
  PR("b &= c; b = ", b);
  b ^= a;
  PR("b ^= a; b = ", b);
} ///:~
