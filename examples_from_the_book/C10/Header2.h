//: C10:Header2.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
#ifndef HEADER2_H
#define HEADER2_H
#include "Header1.h"
// Dodanie do MyLib kolejnych nazw
namespace MyLib { // To nie jest powtorna definicja!
  extern int y;
  void g();
  // ...
} 

#endif // HEADER2_H ///:~
