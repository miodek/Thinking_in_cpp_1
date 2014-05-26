//: C09:Stash4.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Funkcje inline
#ifndef STASH4_H
#define STASH4_H
#include "../require.h"

class Stash {
  int size;      // Wielkosc kazdego elementu
  int quantity;  // Liczba elementow pamieci
  int next;      // Nastepny pusty element
  // Dynamicznie przydzielana tablica bajtow:
  unsigned char* storage;
  void inflate(int increase);
public:
  Stash(int sz) : size(sz), quantity(0),
    next(0), storage(0) {}
  Stash(int sz, int initQuantity) : size(sz), 
    quantity(0), next(0), storage(0) { 
    inflate(initQuantity); 
  }
  Stash::~Stash() {
    if(storage != 0) 
      delete []storage;
  }
  int add(void* element);
  void* fetch(int index) const {
    require(0 <= index, "Stash::fetch indeks ma wartosc ujemna");
    if(index >= next)
      return 0; // Oznaczenie konca
    // Tworzenie wskaznika do zadanego elementu:
    return &(storage[index * size]);
  }
  int count() const { return next; }
};
#endif // STASH4_H ///:~
