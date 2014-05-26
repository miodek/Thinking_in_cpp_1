//: C11:FreeStandingReferences.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;

// Zwykle, samodzielne referencje:
int y;
int& r = y;
// Podczas tworzenia, referencja musi
// zostac zainicjowana istniejacym obiektem.
// Mozna jednak rowniez napisac:
const int& q = 12;  // (1)
// Referencje sa zwiazane z obszarem pamieci 
// jakiegos innego obiektu:
int x = 0;          // (2)
int& a = x;         // (3)
int main() {
  cout << "x = " << x << ", a = " << a << endl;
  a++;
  cout << "x = " << x << ", a = " << a << endl;
} ///:~
