//: C03:Union.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Wielkosc unii i jej proste wykorzystanie
#include <iostream>
using namespace std;

union Packed { // Deklaracja podobna do klasy
  char i;
  short j;
  int k;
  long l;
  float f;
  double d;  
  // Unia bedzie miala wielkosc typu double,
  // poniewaz jest to jej najwiekszy element
};  // Srednik konczy deklaracje unii, podobnie jak struktury

int main() {
  cout << "sizeof(Packed) = " 
       << sizeof(Packed) << endl;
  Packed x;
  x.i = 'c';
  cout << x.i << endl;
  x.d = 3.14159;
  cout << x.d << endl;
} ///:~
