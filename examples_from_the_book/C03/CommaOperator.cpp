//: C03:CommaOperator.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#include <iostream>
using namespace std;
int main() {
  int a = 0, b = 1, c = 2, d = 3, e = 4;
  a = (b++, c++, d++, e++);
  cout << "a = " << a << endl;
  // Powyzszy nawias jest konieczny. Bez niego
  // instrukcja bylaby wykonywana jako:
  (a = b++), c++, d++, e++;
  cout << "a = " << a << endl;
} ///:~
