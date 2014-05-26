//: C07:Stash3.h
// Kod zrodlowy pochodzacy z ksiazki
// "Thinking in C++. Edycja polska"
// (c) Bruce Eckel 2000
// Informacje o prawie autorskim znajduja sie w pliku Copyright.txt
// Przeciazanie nazw funkcji
#ifndef STASH3_H
#define STASH3_H

class Stash {
  int size;      // Wielkosc kazdego elementu
  int quantity;  // Liczba elementow pamieci
  int next;      // Nastepny pusty element
  // Dynamicznie przydzielana tablica bajtow:
  unsigned char* storage;
  void inflate(int increase);
public:
  Stash(int size); // Zerowa liczba elementow
  Stash(int size, int initQuantity);
  ~Stash();
  int add(void* element);
  void* fetch(int index);
  int count();
};
#endif // STASH3_H ///:~
