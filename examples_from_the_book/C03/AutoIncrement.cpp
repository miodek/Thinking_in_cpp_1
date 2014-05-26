//: C03:AutoIncrement.cpp
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Prezentacja uzycia  operatorow automatycznej
// inkrementacji i dekrementacji
#include <iostream>
using namespace std;

int main() {
  int i = 0;
  int j = 0;
  cout << ++i << endl; // Preinkrementacja
  cout << j++ << endl; // Postinkrementacja
  cout << --i << endl; // Predkrementacja
  cout << j-- << endl; // Postdekrementacja
} ///:~
